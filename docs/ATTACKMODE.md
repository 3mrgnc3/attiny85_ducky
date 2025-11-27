# DuckyScript ATTACKMODE Command

## Overview

The ATTiny85 Ducky now supports the standard DuckyScript `ATTACKMODE` command for configuring USB device identity directly in your payload.

## Syntax

```duckyscript
ATTACKMODE HID [VID_xxxx] [PID_xxxx] [MAN_xxx] [PROD_xxx] [SERIAL_xxx]
```

**Parameters (all optional):**
- `VID_xxxx` - Vendor ID in hexadecimal (4 digits)
- `PID_xxxx` - Product ID in hexadecimal (4 digits)  
- `MAN_xxx` - Manufacturer name (underscores converted to spaces)
- `PROD_xxx` - Product name (underscores converted to spaces)
- `SERIAL_xxx` - Serial number in hexadecimal

## Examples

### Basic USB Configuration

```duckyscript
REM Configure USB identity
ATTACKMODE HID VID_16c0 PID_27db MAN_DigiKey PROD_ATTiny85_Ducky SERIAL_0001

DELAY 3000
GUI r
STRINGLN notepad
```

### Real-World Examples

**Razer Edge Keyboard:**
```duckyscript
ATTACKMODE HID VID_1532 PID_011e MAN_Razer PROD_Edge SERIAL_00010010
```

**Microsoft Natural Keyboard:**
```duckyscript
ATTACKMODE HID VID_045e PID_00f0 MAN_Microsoft PROD_Natural_Keyboard
```

**Dell KB216:**
```duckyscript
ATTACKMODE HID VID_413c PID_211a MAN_Dell PROD_KB216
```

**DigiKey Default (VID/PID only):**
```duckyscript
ATTACKMODE HID VID_16c0 PID_27db
```

### Using Functions (Hak5 Style)

```duckyscript
REM Function to spoof Innostor flash drive
FUNCTION SPOOF_INNOSTOR()
    ATTACKMODE HID VID_1f75 PID_0917 MAN_Innostor PROD_IS917_Mass_storage SERIAL_00100011
END_FUNCTION

REM Your payload here
DELAY 3000
GUI r
STRINGLN notepad

REM Switch identity later (not executed - ATTiny85 can't change USB at runtime)
REM SPOOF_INNOSTOR()
```

**Note:** The ATTiny85 cannot change USB identity at runtime. ATTACKMODE is parsed during build and sets the compile-time USB descriptors. Functions containing ATTACKMODE are also parsed but won't execute at runtime.

## How It Works

1. **Pre-Build Parsing**: The `pre_build_duckyscript.py` script scans `payload.ducky` for ATTACKMODE commands
2. **USB Config Generation**: Extracts VID/PID/strings and generates `lib/ATTinyDuckyKeyboard/src/usb_device_config.h`
3. **Compilation**: The firmware is compiled with your custom USB identity
4. **Upload**: Device appears to the OS with the spoofed identity

## Parameter Details

### VID/PID Format

VID and PID must be **4-digit hexadecimal** values (without `0x` prefix):

- `VID_16c0` → DigiKey/VOTI (0x16c0)
- `PID_27db` → Product 0x27db
- `VID_1532` → Razer (0x1532)

The pre-build script automatically converts to little-endian format for the USB descriptor.

### Manufacturer/Product Names

Use underscores for spaces:
- `MAN_Razer_USA` → "Razer USA"
- `PROD_ATTiny85_Ducky` → "ATTiny85 Ducky"
- `PROD_IS917_Mass_storage` → "IS917 Mass storage"

### Serial Numbers

Serial numbers should be hexadecimal strings:
- `SERIAL_00010001` → "00010001"
- `SERIAL_ABCD1234` → "ABCD1234"

## Compatibility Notes

### Differences from Official Hak5 DuckyScript

**Supported:**
- ✅ `ATTACKMODE HID` with USB parameters
- ✅ VID, PID, MAN, PROD, SERIAL parameters
- ✅ Function-scoped ATTACKMODE (parsed but not executed)

**Not Supported (ATTiny85 Limitations):**
- ❌ `ATTACKMODE STORAGE` - ATTiny85 has no storage capability
- ❌ `ATTACKMODE OFF` - No power control
- ❌ Runtime USB identity switching - USB descriptors are compile-time only
- ❌ Multiple ATTACKMODE calls - Only the first valid one is used

### Parser Behavior

The parser finds the **first ATTACKMODE HID command** with VID/PID in your payload (including inside FUNCTION blocks) and uses those values for compilation. Subsequent ATTACKMODE commands are ignored.

## Finding Real Device VID/PID

### Windows

**Device Manager Method:**
1. Open Device Manager
2. Find keyboard under "Keyboards"
3. Right-click → Properties → Details → Hardware IDs
4. Look for `VID_xxxx&PID_xxxx`

**PowerShell Method:**
```powershell
Get-PnpDevice -Class Keyboard | Get-PnpDeviceProperty -KeyName DEVPKEY_Device_HardwareIds
```

### Linux

```bash
lsusb -v | grep -E "idVendor|idProduct|iManufacturer|iProduct"
```

### Online Databases

- [USB ID Repository](https://devicehunt.com/)
- [Linux USB IDs](https://usb-ids.gowdy.us/)

## Build Output

When building, you'll see the parsed configuration:

```
Parsing USB configuration from payload.ducky...
Found USB configuration:
  VID: 0x16c0
  PID: 0x27db
  Manufacturer: DigiKey
  Product: ATTiny85 Ducky
  Serial: 0001
Generated USB config: ...usb_device_config.h
```

## Priority Order

If you use multiple configuration methods:

1. **ATTACKMODE in payload.ducky** (highest priority - auto-generates header)
2. Build flags in `platformio.ini`
3. Defaults in `usb_device_config.h`

**Recommendation:** Always use ATTACKMODE in your payload for simplicity and automatic per-payload configuration.

## Troubleshooting

### "No ATTACKMODE USB config found, using defaults"

This is normal if you don't include ATTACKMODE in your payload. The default DigiKey identity (VID 0x16c0, PID 0x27db) will be used.

### Device shows wrong name after upload

USB descriptors are cached by the OS. Solutions:
1. Uninstall the device in Device Manager
2. Plug into a different USB port
3. Reboot the computer

### Parameters not being parsed

Check your syntax:
- ✅ `ATTACKMODE HID VID_16c0 PID_27db`
- ❌ `ATTACKMODE HID VID:16c0 PID:27db` (wrong separator)
- ❌ `ATTACKMODE HID VID_0x16c0` (no 0x prefix)

## Legal & Ethical Use

⚠️ **IMPORTANT:**

Using another manufacturer's VID/PID without permission:
- May violate trademark and IP laws
- Is only legal for authorized security testing
- Should only be used on systems you own or have written permission to test

The hobbyist VID (0x16c0) is free for non-commercial use and does not require spoofing.

---

**See also:**
- [docs/USB_CUSTOMIZATION.md](USB_CUSTOMIZATION.md) - Manual USB configuration methods
- [ducky_scripts/README.md](../ducky_scripts/README.md) - Full DuckyScript syntax reference
