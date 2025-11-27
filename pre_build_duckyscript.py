"""
PlatformIO Pre-Build Script for DuckyScript Compilation
Automatically compiles .txt files from ducky_scripts/ to src/main.cpp
"""

import os
import sys
import subprocess

Import("env")

# Add tools directory to Python path
tools_dir = os.path.join(env.get("PROJECT_DIR"), "tools")
sys.path.insert(0, tools_dir)


def compile_duckyscript(source, target, env):
    """Pre-build hook to compile DuckyScript"""
    project_dir = env.get("PROJECT_DIR")
    ducky_scripts_dir = os.path.join(project_dir, "ducky_scripts")
    src_dir = os.path.join(project_dir, "src")
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
        print(f"DUCKY_LANG US")
        print(f"DELAY 6000")
        print(f"GUI r")
        print(f"DELAY 1200")
        print(f"STRINGLN notepad")
        print(f"ENTER{RESET}")
        print(f"{CYAN}{'-' * 80}{RESET}\n")
        print(f"{YELLOW}See ducky_scripts/README.md for full DuckyScript syntax{RESET}")
        print(f"{RED}{BOLD}{'=' * 80}{RESET}\n")
        sys.exit(1)

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
