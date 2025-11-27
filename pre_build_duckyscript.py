"""
PlatformIO Pre-Build Script for DuckyScript Compilation
Automatically compiles .txt files from ducky_scripts/ to src/main.cpp
Parses ATTACKMODE commands to configure USB device identity
"""

import os
import sys
import subprocess
import re

Import("env")

# Add tools directory to Python path
tools_dir = os.path.join(env.get("PROJECT_DIR"), "tools")
sys.path.insert(0, tools_dir)


def parse_attackmode_usb_config(payload_file):
    """
    Parse ATTACKMODE commands from DuckyScript to extract USB configuration

    Supports syntax like:
    ATTACKMODE HID VID_1532 PID_011e MAN_Razer PROD_Edge SERIAL_13370010

    Returns dict with keys: vid, pid, manufacturer, product, serial
    """
    usb_config = {}

    if not os.path.exists(payload_file):
        return usb_config

    with open(payload_file, "r", encoding="utf-8") as f:
        content = f.read()

    # Pattern to match ATTACKMODE with USB parameters
    # Matches: ATTACKMODE [HID/STORAGE] VID_xxxx PID_xxxx MAN_xxx PROD_xxx SERIAL_xxx
    attackmode_pattern = r"ATTACKMODE\s+(?:(?:HID|STORAGE|OFF)\s+)*(?:VID_([0-9a-fA-F]+))?\s*(?:PID_([0-9a-fA-F]+))?\s*(?:MAN_(\S+))?\s*(?:PROD_(\S+))?\s*(?:SERIAL_([0-9a-fA-F]+))?"

    # Find all ATTACKMODE commands (including those in FUNCTION blocks)
    for match in re.finditer(attackmode_pattern, content, re.MULTILINE):
        vid, pid, man, prod, serial = match.groups()

        # Only update if HID mode is specified (we're a keyboard, not storage)
        if "HID" in match.group(0):
            if vid:
                usb_config["vid"] = vid
            if pid:
                usb_config["pid"] = pid
            if man:
                usb_config["manufacturer"] = man
            if prod:
                # Clean up product name (replace underscores with spaces)
                usb_config["product"] = prod.strip().replace("_", " ")
            if serial:
                usb_config["serial"] = serial

            # Use the first valid HID ATTACKMODE found
            if vid and pid:
                break

    return usb_config


def generate_usb_config_header(usb_config, header_path):
    """
    Generate or update usb_device_config.h with values from ATTACKMODE
    """
    if not usb_config:
        return  # No USB config to apply

    # Convert VID/PID from hex string to little-endian bytes
    def hex_to_little_endian(hex_str):
        """Convert hex string like '1532' to little-endian low,high bytes"""
        val = int(hex_str, 16)
        low_byte = val & 0xFF
        high_byte = (val >> 8) & 0xFF
        return f"0x{low_byte:02x}", f"0x{high_byte:02x}"

    # Convert string to USB descriptor format: 'R','a','z','e','r'
    def string_to_usb_format(s):
        """Convert string to comma-separated single-char format"""
        return ",".join(f"'{c}'" for c in s)

    config_lines = [
        "/*",
        " * USB Device Configuration - Auto-generated from payload.ducky",
        " * DO NOT EDIT - This file is overwritten on each build",
        " */",
        "",
        "#ifndef USB_DEVICE_CONFIG_H",
        "#define USB_DEVICE_CONFIG_H",
        "",
    ]

    if "vid" in usb_config:
        low, high = hex_to_little_endian(usb_config["vid"])
        config_lines.extend(
            [
                f"// VID: 0x{usb_config['vid']}",
                f"#define USB_VID_LOW     {low}",
                f"#define USB_VID_HIGH    {high}",
                "",
            ]
        )

    if "pid" in usb_config:
        low, high = hex_to_little_endian(usb_config["pid"])
        config_lines.extend(
            [
                f"// PID: 0x{usb_config['pid']}",
                f"#define USB_PID_LOW     {low}",
                f"#define USB_PID_HIGH    {high}",
                "",
            ]
        )

    if "manufacturer" in usb_config:
        man_str = string_to_usb_format(usb_config["manufacturer"])
        config_lines.extend(
            [
                f"// Manufacturer: {usb_config['manufacturer']}",
                f"#define USB_VENDOR_NAME     {man_str}",
                f"#define USB_VENDOR_NAME_LEN {len(usb_config['manufacturer'])}",
                "",
            ]
        )

    if "product" in usb_config:
        prod_str = string_to_usb_format(usb_config["product"])
        config_lines.extend(
            [
                f"// Product: {usb_config['product']}",
                f"#define USB_DEVICE_NAME     {prod_str}",
                f"#define USB_DEVICE_NAME_LEN {len(usb_config['product'])}",
                "",
            ]
        )

    if "serial" in usb_config:
        serial_str = string_to_usb_format(usb_config["serial"])
        config_lines.extend(
            [
                f"// Serial: {usb_config['serial']}",
                f"#define USB_SERIAL_NUMBER     {serial_str}",
                f"#define USB_SERIAL_NUMBER_LEN {len(usb_config['serial'])}",
                "",
            ]
        )

    config_lines.extend(["#endif // USB_DEVICE_CONFIG_H", ""])

    # Write the header file
    with open(header_path, "w", encoding="utf-8") as f:
        f.write("\n".join(config_lines))


def compile_duckyscript(source, target, env):
    """Pre-build hook to compile DuckyScript"""
    project_dir = env.get("PROJECT_DIR")
    ducky_scripts_dir = os.path.join(project_dir, "ducky_scripts")
    src_dir = os.path.join(project_dir, "src")
    lib_dir = os.path.join(project_dir, "lib", "ATTinyDuckyKeyboard", "src")
    compiler_script = os.path.join(project_dir, "tools", "duckyscript_compiler.py")

    # Look for payload.ducky specifically
    payload_file = os.path.join(ducky_scripts_dir, "payload.ducky")

    # ANSI color codes
    RED = "\033[91m"
    YELLOW = "\033[93m"
    GREEN = "\033[92m"
    CYAN = "\033[96m"
    BOLD = "\033[1m"
    RESET = "\033[0m"

    if not os.path.exists(payload_file):
        print(f"\n{RED}{BOLD}{'=' * 80}{RESET}")
        print(f"{RED}{BOLD}FAILURE: payload.ducky not found!{RESET}")
        print(f"{RED}{BOLD}{'=' * 80}{RESET}\n")
        print(f"{YELLOW}To create your payload:{RESET}")
        print(f"  {CYAN}1.{RESET} Create file: {GREEN}{payload_file}{RESET}")
        print(f"  {CYAN}2.{RESET} Add your DuckyScript payload (see examples below)")
        print(f"  {CYAN}3.{RESET} Build again\n")
        print(f"{YELLOW}Example payload.ducky content:{RESET}")
        print(f"{CYAN}{'-' * 80}{RESET}")
        print(f"{GREEN}REM My Custom Payload")
        print("DUCKY_LANG US")
        print("DELAY 6000")
        print("GUI r")
        print("DELAY 1200")
        print("STRINGLN notepad")
        print(f"ENTER{RESET}")
        print(f"{CYAN}{'-' * 80}{RESET}\n")
        print(f"{YELLOW}See ducky_scripts/README.md for full DuckyScript syntax{RESET}")
        print(f"{RED}{BOLD}{'=' * 80}{RESET}\n")
        sys.exit(1)

    # Parse ATTACKMODE commands for USB configuration
    print(f"{CYAN}Parsing USB configuration from payload.ducky...{RESET}")
    usb_config = parse_attackmode_usb_config(payload_file)

    if usb_config:
        print(f"{GREEN}Found USB configuration:{RESET}")
        if "vid" in usb_config:
            print(f"  VID: 0x{usb_config['vid']}")
        if "pid" in usb_config:
            print(f"  PID: 0x{usb_config['pid']}")
        if "manufacturer" in usb_config:
            print(f"  Manufacturer: {usb_config['manufacturer']}")
        if "product" in usb_config:
            print(f"  Product: {usb_config['product']}")
        if "serial" in usb_config:
            print(f"  Serial: {usb_config['serial']}")

        # Generate USB config header
        usb_config_header = os.path.join(lib_dir, "usb_device_config.h")
        generate_usb_config_header(usb_config, usb_config_header)
        print(f"{GREEN}Generated USB config: {usb_config_header}{RESET}")

        # Patch the framework's DigisparkKeyboard library usbconfig.h
        framework_usbconfig = os.path.join(
            env.PioPlatform().get_package_dir("framework-arduino-avr-digistump"),
            "libraries",
            "DigisparkKeyboard",
            "usbconfig.h",
        )

        if os.path.exists(framework_usbconfig):
            import re

            # Read the framework usbconfig.h
            with open(framework_usbconfig, "r", encoding="utf-8") as f:
                usbconfig_content = f.read()

            modified = False

            # Check if we've already patched it with include
            if '#include "usb_device_config.h"' not in usbconfig_content:
                # Find the line with USB_CFG_VENDOR_ID and insert include before it
                pattern = r"(#define\s+USB_CFG_VENDOR_ID)"
                replacement = r'#include "usb_device_config.h"\n\n\1'
                usbconfig_content = re.sub(
                    pattern, replacement, usbconfig_content, count=1
                )
                modified = True

            # Replace hardcoded VID values with macros
            if re.search(
                r"#define\s+USB_CFG_VENDOR_ID\s+0x[0-9a-fA-F]+,\s*0x[0-9a-fA-F]+",
                usbconfig_content,
            ):
                usbconfig_content = re.sub(
                    r"#define\s+USB_CFG_VENDOR_ID\s+0x[0-9a-fA-F]+,\s*0x[0-9a-fA-F]+",
                    "#define USB_CFG_VENDOR_ID USB_VID_LOW, USB_VID_HIGH",
                    usbconfig_content,
                )
                modified = True

            # Replace hardcoded PID values with macros
            if re.search(
                r"#define\s+USB_CFG_DEVICE_ID\s+0x[0-9a-fA-F]+,\s*0x[0-9a-fA-F]+",
                usbconfig_content,
            ):
                usbconfig_content = re.sub(
                    r"#define\s+USB_CFG_DEVICE_ID\s+0x[0-9a-fA-F]+,\s*0x[0-9a-fA-F]+",
                    "#define USB_CFG_DEVICE_ID USB_PID_LOW, USB_PID_HIGH",
                    usbconfig_content,
                )
                modified = True

            # Replace vendor name if it's hardcoded
            if (
                "'d','i','g','i','s','t','u','m','p'" in usbconfig_content
                or "'o','b','d','e','v'" in usbconfig_content
            ):
                usbconfig_content = re.sub(
                    r"#define\s+USB_CFG_VENDOR_NAME\s+.*?$",
                    "#define USB_CFG_VENDOR_NAME USB_VENDOR_NAME",
                    usbconfig_content,
                    flags=re.MULTILINE,
                )
                usbconfig_content = re.sub(
                    r"#define\s+USB_CFG_VENDOR_NAME_LEN\s+\d+",
                    "#define USB_CFG_VENDOR_NAME_LEN USB_VENDOR_NAME_LEN",
                    usbconfig_content,
                )
                modified = True

            # Replace device name if it's hardcoded
            if (
                "'D','i','g','i'" in usbconfig_content
                or "'K','e','y'" in usbconfig_content
            ):
                usbconfig_content = re.sub(
                    r"#define\s+USB_CFG_DEVICE_NAME\s+.*?$",
                    "#define USB_CFG_DEVICE_NAME USB_DEVICE_NAME",
                    usbconfig_content,
                    flags=re.MULTILINE,
                )
                usbconfig_content = re.sub(
                    r"#define\s+USB_CFG_DEVICE_NAME_LEN\s+\d+",
                    "#define USB_CFG_DEVICE_NAME_LEN USB_DEVICE_NAME_LEN",
                    usbconfig_content,
                )
                modified = True

            if modified:
                # Write back
                with open(framework_usbconfig, "w", encoding="utf-8") as f:
                    f.write(usbconfig_content)
                print(f"{GREEN}Patched framework usbconfig.h with USB macros{RESET}")

            # Copy our usb_device_config.h to the framework library
            import shutil

            framework_config_dest = os.path.join(
                os.path.dirname(framework_usbconfig), "usb_device_config.h"
            )
            shutil.copy2(usb_config_header, framework_config_dest)
            print(f"{GREEN}Copied USB config to framework library{RESET}")
    else:
        print(f"{YELLOW}No ATTACKMODE USB config found, using defaults{RESET}")

    output_path = os.path.join(src_dir, "main.cpp")
    print(f"{GREEN}Compiling DuckyScript: payload.ducky{RESET}")

    # Run the compiler
    try:
        result = subprocess.run(
            [sys.executable, compiler_script, payload_file, output_path],
            capture_output=True,
            text=True,
            check=True,
        )
        print(result.stdout)
    except subprocess.CalledProcessError as e:
        print(f"{RED}Error compiling DuckyScript: {e.stderr}{RESET}")
        sys.exit(1)


# Register the pre-build hook
env.AddPreAction("buildprog", compile_duckyscript)
