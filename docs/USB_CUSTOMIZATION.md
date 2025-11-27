# Customizing USB Device Identity

Your ATTiny85 Ducky now supports customizable USB VID, PID, Vendor Name, and Device Name!

## Quick Start (NEW: DuckyScript ATTACKMODE)

### Method 1: Use ATTACKMODE in payload.ducky (Recommended!)

Simply add an `ATTACKMODE` command at the top of your `ducky_scripts/payload.ducky`:

```duckyscript
REM Configure USB identity
ATTACKMODE HID VID_16c0 PID_27db MAN_DigiKey PROD_ATTiny85_Ducky SERIAL_1337

REM Your payload starts here
DELAY 3000
GUI r
STRINGLN notepad
```

**That's it!** The pre-build script automatically:
1. Parses the `ATTACKMODE` command
2. Extracts VID, PID, manufacturer, product, and serial
3. Generates `usb_device_config.h` with your settings
4. Compiles with the spoofed USB identity

**Syntax:**
```
ATTACKMODE HID [VID_xxxx] [PID_xxxx] [MAN_xxx] [PROD_xxx] [SERIAL_xxx]
```

All parameters are optional. Only include what you want to customize.

**Examples:**

Spoof as Razer keyboard:
```duckyscript
ATTACKMODE HID VID_1532 PID_011e MAN_Razer PROD_Edge SERIAL_13370010
```

Spoof as Microsoft keyboard:
```duckyscript
ATTACKMODE HID VID_045e PID_00f0 MAN_Microsoft PROD_Natural_Keyboard
```

Spoof as Dell keyboard:
```duckyscript
ATTACKMODE HID VID_413c PID_211a MAN_Dell PROD_KB216
```

Just change VID/PID (no manufacturer/product strings):
```duckyscript
ATTACKMODE HID VID_16c0 PID_27db
```

### Method 2: Use a Preset Configuration

Edit `platformio.ini` and add one of these presets to `build_flags`:

```ini
[env:digispark-tiny]
platform = atmelavr
board = digispark-tiny
framework = arduino
upload_protocol = micronucleus
upload_flags = --no-ansi
lib_ldf_mode = deep+
extra_scripts = pre:pre_build_duckyscript.py

# Add this line:
build_flags = -DUSB_DEVICE_MICROSOFT_KEYBOARD
```

**Note:** If using `ATTACKMODE` in payload.ducky, this method is not needed.

**Available Presets:**
- `-DUSB_DEVICE_MICROSOFT_KEYBOARD` - Microsoft Natural (VID: 0x045e, PID: 0x00f0)
- `-DUSB_DEVICE_DELL_KEYBOARD` - Dell KB216 (VID: 0x413c, PID: 0x211a)

### Method 3: Custom Configuration via platformio.ini

Define your own VID/PID and strings in `platformio.ini`:

```ini
build_flags = 
    -DUSB_VID_LOW=0x6d
    -DUSB_VID_HIGH=0x04
    -DUSB_PID_LOW=0x1e
    -DUSB_PID_HIGH=0xc3
    '-DUSB_VENDOR_NAME=M,y,C,o,m,p,a,n,y'
    -DUSB_VENDOR_NAME_LEN=9
    '-DUSB_DEVICE_NAME=M,y,K,e,y,b,o,a,r,d'
    -DUSB_DEVICE_NAME_LEN=10
```

**Note:** If using `ATTACKMODE` in payload.ducky, this method is not needed.

**Important Notes:**
- VID/PID are in **little-endian** format (low byte, high byte)
- Strings must be **comma-separated single characters** with single quotes
- String length **must match** the actual character count
- Wrap string definitions in **single quotes** for platformio.ini

### Method 4: Edit Header Directly

Edit `lib/ATTinyDuckyKeyboard/src/usb_device_config.h` and modify the defaults:

```c
#define USB_VID_LOW     0x6d
#define USB_VID_HIGH    0x04
#define USB_PID_LOW     0x1e
#define USB_PID_HIGH    0xc3
#define USB_VENDOR_NAME     'M','y','C','o','m','p','a','n','y'
#define USB_VENDOR_NAME_LEN 9
#define USB_DEVICE_NAME     'M','y','K','e','y','b','o','a','r','d'
#define USB_DEVICE_NAME_LEN 10
```

**Note:** If using `ATTACKMODE` in payload.ducky, this file is auto-generated and will be overwritten.

---

## Priority Order (when multiple methods are used)

1. **ATTACKMODE in payload.ducky** (highest priority - auto-generates header)
2. Build flags in platformio.ini
3. Defaults in usb_device_config.h

**Recommendation:** Use `ATTACKMODE` in your payload.ducky for simplicity and per-payload customization.

## Converting VID/PID to Little-Endian

USB VID/PID are 16-bit values stored in little-endian format.

**Example:** DigiKey VID `0x16c0` (decimal 5824)

1. Split into bytes: `0x16` (high) and `0xc0` (low)
2. Reverse order: **low byte first**, then high byte
3. Result: `0xc0, 0x16`

**Quick Conversion Formula:**
```
VID/PID in hex: 0xABCD
Low byte:  0xCD
High byte: 0xAB
Define as: 0xCD, 0xAB
```

**Examples:**
| Device | VID (hex) | PID (hex) | Low,High Format |
|--------|-----------|-----------|-----------------|
| DigiKey | 0x16c0 | 0x27db | `0xc0,0x16` and `0xdb,0x27` |
| Microsoft | 0x045e | 0x00f0 | `0x5e,0x04` and `0xf0,0x00` |
| Dell | 0x413c | 0x211a | `0x3c,0x41` and `0x1a,0x21` |

## Testing Your Configuration

1. Build and upload your payload:
   ```bash
   platformio run --target upload
   ```

2. Check Device Manager (Windows) or `lsusb` (Linux):
   ```bash
   # Linux
   lsusb
   
   # Windows PowerShell
   Get-PnpDevice -Class Keyboard | Select-Object FriendlyName, InstanceId
   ```

3. Verify the VID/PID and device name match your configuration

## Finding Real Device VID/PID

**Windows:**
```powershell
Get-PnpDevice -Class Keyboard | Get-PnpDeviceProperty -KeyName DEVPKEY_Device_HardwareIds
```

**Linux:**
```bash
lsusb -v | grep -E "idVendor|idProduct|iManufacturer|iProduct"
```

**Online Database:**
- [USB ID Repository](https://devicehunt.com/)
- [Linux USB IDs](https://usb-ids.gowdy.us/)

## Legal Considerations

⚠️ **IMPORTANT LEGAL NOTICE:**

1. **Shared VID/PID (Default):**
   - VID `0x16c0` is shared for hobbyist/educational use
   - Free to use for non-commercial projects
   - Must include your domain name in vendor string

2. **Commercial Products:**
   - MUST obtain official VID from [usb.org](https://www.usb.org/getting-vendor-id) (~$5000)
   - Or license PID from existing VID holder

3. **Spoofing Other Devices:**
   - Using another manufacturer's VID/PID without permission is **illegal**
   - May violate trademark and IP laws
   - Only for authorized security testing on systems you own
   - The authors assume **no liability** for misuse

4. **Ethical Use:**
   - Only test on systems you own or have explicit written permission
   - Unauthorized access is illegal in most jurisdictions
   - Follow responsible disclosure practices

## Troubleshooting

### Device Not Recognized
- Windows may cache old drivers - uninstall device and replug
- Try a different USB port
- Verify VID/PID format is correct (little-endian)

### Build Errors
- Check that string length matches character count
- Ensure strings are comma-separated with single quotes
- Verify platformio.ini syntax (strings need wrapping quotes)

### Device Shows Wrong Name
- USB descriptors are cached by OS
- Uninstall device completely from Device Manager
- Replug or reboot to force re-enumeration

## Advanced: Serial Numbers

To add a unique serial number:

**In platformio.ini:**
```ini
build_flags = 
    '-DUSB_SERIAL_NUMBER=0,0,0,1'
    -DUSB_SERIAL_NUMBER_LEN=4
```

**Or in usb_device_config.h:**
```c
#define USB_SERIAL_NUMBER     '0','0','0','1'
#define USB_SERIAL_NUMBER_LEN 4
```

Serial numbers should be **unique per device** for proper driver handling.

---

**Remember:** This modifies the USB descriptors at compile time. You cannot change VID/PID at runtime on ATTiny85 hardware.
