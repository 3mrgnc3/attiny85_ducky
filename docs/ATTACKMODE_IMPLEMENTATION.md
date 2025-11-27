# ATTACKMODE USB Configuration - Implementation Summary

## What Was Added

The ATTiny85 Ducky now supports **automatic USB device configuration** via the DuckyScript `ATTACKMODE` command, matching the official Hak5 DuckyScript syntax.

## New Files

1. **`docs/ATTACKMODE.md`** - Complete documentation for ATTACKMODE usage
2. **`ducky_scripts/examples/USBSpoofDemo/razer_spoof.ducky`** - Example payload demonstrating USB spoofing

## Modified Files

1. **`pre_build_duckyscript.py`** - Added USB configuration parser
   - New function: `parse_attackmode_usb_config()` - Extracts VID/PID/strings from ATTACKMODE
   - New function: `generate_usb_config_header()` - Creates usb_device_config.h
   - Modified: `compile_duckyscript()` - Calls parser before compilation

2. **`ducky_scripts/README.md`** - Updated with ATTACKMODE documentation
   - Added Quick Start section for USB spoofing
   - Added ATTACKMODE to supported commands
   - Added ATTACKMODE limitations to NOT supported section

3. **`docs/USB_CUSTOMIZATION.md`** - Updated priority order
   - Method 1: ATTACKMODE in payload.ducky (NEW - highest priority)
   - Method 2-4: Previous manual methods

4. **`ducky_scripts/payload.ducky`** - Added example ATTACKMODE

## How It Works

### Build Process Flow

```
1. User creates payload.ducky with ATTACKMODE command:
   ATTACKMODE HID VID_16c0 PID_27db MAN_DigiKey PROD_ATTiny85_Ducky

2. Pre-build script runs (pre_build_duckyscript.py):
   ├─ parse_attackmode_usb_config(payload.ducky)
   │  └─ Extracts: VID=16c0, PID=27db, MAN=DigiKey, PROD=ATTiny85 Ducky
   │
   ├─ generate_usb_config_header(config, usb_device_config.h)
   │  └─ Generates C header with USB_VID_LOW/HIGH, USB_PID_LOW/HIGH, etc.
   │
   └─ Compile DuckyScript to main.cpp (existing functionality)

3. PlatformIO builds firmware:
   ├─ usbconfig.h includes usb_device_config.h
   ├─ USB descriptors use values from auto-generated header
   └─ Firmware compiled with spoofed USB identity

4. Upload to ATTiny85:
   └─ Device enumerates with custom VID/PID/strings
```

### Parser Regex

```python
attackmode_pattern = r'ATTACKMODE\s+(?:(?:HID|STORAGE|OFF)\s+)*(?:VID_([0-9a-fA-F]+))?\s*(?:PID_([0-9a-fA-F]+))?\s*(?:MAN_(\S+))?\s*(?:PROD_(\S+))?\s*(?:SERIAL_([0-9a-fA-F]+))?'
```

**Matches:**
- `ATTACKMODE HID VID_16c0 PID_27db` ✅
- `ATTACKMODE HID VID_1532 PID_011e MAN_Razer PROD_Edge SERIAL_13370010` ✅
- `ATTACKMODE STORAGE VID_1f75 PID_0917` ✅ (parsed but STORAGE not functional)
- `ATTACKMODE HID` ✅ (no USB params - uses defaults)

### Generated Header Format

```c
/*
 * USB Device Configuration - Auto-generated from payload.ducky
 * DO NOT EDIT - This file is overwritten on each build
 */

#ifndef USB_DEVICE_CONFIG_H
#define USB_DEVICE_CONFIG_H

// VID: 0x16c0
#define USB_VID_LOW     0xc0   // Little-endian low byte
#define USB_VID_HIGH    0x16   // Little-endian high byte

// PID: 0x27db
#define USB_PID_LOW     0xdb
#define USB_PID_HIGH    0x27

// Manufacturer: DigiKey
#define USB_VENDOR_NAME     'D','i','g','i','K','e','y'
#define USB_VENDOR_NAME_LEN 7

// Product: ATTiny85 Ducky
#define USB_DEVICE_NAME     'A','T','T','i','n','y','8','5',' ','D','u','c','k','y'
#define USB_DEVICE_NAME_LEN 14

#endif // USB_DEVICE_CONFIG_H
```

## Supported Syntax

### Basic Form
```duckyscript
ATTACKMODE HID VID_16c0 PID_27db MAN_DigiKey PROD_ATTiny85_Ducky SERIAL_1337
```

### With Mode Prefixes
```duckyscript
ATTACKMODE HID STORAGE VID_1f75 PID_0917  # Parses HID params, ignores STORAGE
ATTACKMODE OFF  # Ignored (no USB config)
```

### Inside Functions
```duckyscript
FUNCTION SPOOF_RAZER()
    ATTACKMODE HID VID_1532 PID_011e MAN_Razer PROD_Edge
END_FUNCTION

# ATTACKMODE is parsed from function but function is not executed
```

### Underscores in Strings
```duckyscript
ATTACKMODE HID MAN_Razer_USA PROD_Gaming_Keyboard_Edge
# Becomes: "Razer USA" and "Gaming Keyboard Edge"
```

## Configuration Priority

1. **ATTACKMODE in payload.ducky** ← Highest (auto-generates header)
2. Build flags in platformio.ini
3. Manual edits to usb_device_config.h
4. Library defaults

## Limitations

**Supported:**
- ✅ VID/PID configuration (4-digit hex)
- ✅ Manufacturer/Product strings (underscores → spaces)
- ✅ Serial number (hex string)
- ✅ Parse from FUNCTION blocks
- ✅ Compile-time USB configuration

**NOT Supported:**
- ❌ `ATTACKMODE STORAGE` - ATTiny85 has no storage
- ❌ `ATTACKMODE OFF` - No power control
- ❌ Runtime USB switching - Must recompile/upload
- ❌ Multiple active ATTACKMODE - First HID one wins

## Testing

Build output shows parsed configuration:

```
Parsing USB configuration from payload.ducky...
Found USB configuration:
  VID: 0x16c0
  PID: 0x27db
  Manufacturer: DigiKey
  Product: ATTiny85 Ducky
  Serial: 0001
Generated USB config: lib/ATTinyDuckyKeyboard/src/usb_device_config.h
Compiling DuckyScript: payload.ducky
```

## Security Considerations

⚠️ **Using another manufacturer's VID/PID without permission:**
- May violate trademark laws
- Only legal for authorized security testing
- Use responsibly on systems you own

The shared hobbyist VID (0x16c0) is free for non-commercial use.

## Examples

### DigiKey Default
```duckyscript
ATTACKMODE HID VID_16c0 PID_27db MAN_DigiKey PROD_ATTiny85_Ducky SERIAL_1337
```

### Razer Edge
```duckyscript
ATTACKMODE HID VID_1532 PID_011e MAN_Razer PROD_Edge SERIAL_13370010
```

### Microsoft Natural
```duckyscript
ATTACKMODE HID VID_045e PID_00f0 MAN_Microsoft PROD_Natural_Keyboard
```

### Dell KB216
```duckyscript
ATTACKMODE HID VID_413c PID_211a MAN_Dell PROD_KB216
```

## Future Enhancements

Potential improvements:
- [ ] Support multiple ATTACKMODE commands (array of configs)
- [ ] Add VID/PID validation against USB-IF database
- [ ] Add warning for well-known manufacturer VID/PIDs
- [ ] Generate .inf file for Windows driver installation
- [ ] Support HID descriptor customization (report IDs)

## Compatibility

- ✅ Windows 10/11 - Tested
- ✅ Linux - Should work (V-USB compatible)
- ✅ macOS - Should work (V-USB compatible)

## Documentation

- **User Guide:** [docs/ATTACKMODE.md](../docs/ATTACKMODE.md)
- **USB Config Methods:** [docs/USB_CUSTOMIZATION.md](../docs/USB_CUSTOMIZATION.md)
- **DuckyScript Syntax:** [ducky_scripts/README.md](../ducky_scripts/README.md)
- **Example Payload:** [ducky_scripts/examples/USBSpoofDemo/razer_spoof.ducky](../ducky_scripts/examples/USBSpoofDemo/razer_spoof.ducky)
