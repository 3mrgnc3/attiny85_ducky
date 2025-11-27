# DuckyScript for ATTiny85 Ducky

This directory contains DuckyScript payloads that are automatically compiled into C++ code for the Digispark ATTiny85 Rev.3.

## How It Works

1. Create your payload in `payload.ducky` (required filename)
2. Optionally add `ATTACKMODE` command to spoof USB device identity
3. Run PlatformIO build - the payload is automatically compiled to `src/main.cpp`
4. Upload to your ATTiny85
5. Payload executes on device startup

## Quick Start: USB Spoofing

You can now spoof USB device identity directly in your DuckyScript payload:

```duckyscript
REM Spoof as Logitech K120 Keyboard
ATTACKMODE HID VID_046d PID_c31e MAN_Logitech PROD_K120_Keyboard SERIAL_00010001

REM Your payload here
DELAY 3000
GUI r
STRINGLN notepad
```

**See [docs/ATTACKMODE.md](../docs/ATTACKMODE.md) for complete documentation.**

## Supported DuckyScript Commands

The ATTiny85 Ducky compiler supports a **subset** of the full DuckyScript 3.0 specification. Only commands compatible with the DigiKeyboard library and ATTiny85 hardware constraints are supported.

### ✅ Supported Commands

#### Comments
```
REM This is a comment
REM Comments are ignored by the compiler
```

#### Language Configuration
```
DUCKY_LANG US
DUCKY_LANG DE
DUCKY_LANG FR
```

Supported languages: `US`, `BE`, `BR`, `CA_FR`, `CH_DE`, `CH_FR`, `CZ`, `DE`, `DK`, `ES`, `FI`, `FR`, `GB`, `HR`, `IT`, `NO`, `PT`, `RU`, `SI`, `SK`, `SV`, `TR`

#### USB Device Configuration (ATTACKMODE)
```
REM Spoof USB device identity
ATTACKMODE HID VID_046d PID_c31e MAN_Logitech PROD_K120_Keyboard SERIAL_00010001

REM Parameters (all optional):
REM   VID_xxxx     - Vendor ID (hex)
REM   PID_xxxx     - Product ID (hex)
REM   MAN_xxx      - Manufacturer name
REM   PROD_xxx     - Product name
REM   SERIAL_xxx   - Serial number (hex)
```

**Note:** ATTACKMODE is parsed at build time and generates USB configuration. The ATTiny85 cannot change USB identity at runtime. See [docs/ATTACKMODE.md](../docs/ATTACKMODE.md) for details.

#### Constants (DEFINE)
```
DEFINE #SERVER example.com
DEFINE #WAIT 1000

STRING https://#SERVER
DELAY #WAIT
```

#### Delays
```
DELAY 1000          REM Wait 1000 milliseconds (1 second)
DELAY 500           REM Wait 500ms
```

**Note:** Minimum delay value is implementation-dependent. Use `DELAY 100` or higher for reliability.

#### String Injection
```
STRING Hello World                    REM Type text (no newline)
STRINGLN Hello World                  REM Type text with ENTER at end

STRING https://github.com/3mrgnc3/attiny85_ducky
STRINGLN The quick brown fox jumps over the lazy dog
```

**All strings are stored in PROGMEM** to save precious RAM on the ATTiny85 (512 bytes total).

#### Special Keys
```
ENTER               REM Press Enter/Return key
ESCAPE              REM Press Escape key
TAB                 REM Press Tab key
SPACE               REM Press Space bar

UPARROW             REM Press Up arrow
DOWNARROW           REM Press Down arrow
LEFTARROW           REM Press Left arrow
RIGHTARROW          REM Press Right arrow
```

#### Modifier Key Combinations
```
GUI r               REM Windows Key + R (Run dialog)
GUI d               REM Windows Key + D (Show desktop)

CTRL c              REM Control + C (Copy)
CTRL v              REM Control + V (Paste)
CTRL ALT t          REM Control + Alt + T (Terminal on Linux)
CTRL ALT DELETE     REM Control + Alt + Delete

ALT F4              REM Alt + F4 (Close window)
ALT TAB             REM Alt + Tab (Switch windows)

SHIFT TAB           REM Shift + Tab
```

**Available Modifiers:** `GUI`, `CTRL`, `ALT`, `SHIFT`

---

### ❌ NOT Supported (ATTiny85 Limitations)

The following DuckyScript features are **not supported** on the ATTiny85 Ducky due to hardware and memory constraints:

#### Advanced Language Features
```
REM_BLOCK / END_REM            ❌ Block comments
STRING / END_STRING blocks      ❌ Multi-line string blocks  
STRINGLN / END_STRINGLN blocks  ❌ Multi-line stringln blocks
```

#### Attack Mode Features
```
ATTACKMODE STORAGE              ❌ ATTiny85 has no storage capability
ATTACKMODE OFF                  ❌ No power control
Runtime USB switching           ❌ USB identity set at compile-time only
```

**Note:** `ATTACKMODE HID` with USB parameters (VID/PID/MAN/PROD/SERIAL) **IS supported** for compile-time USB configuration. See [docs/ATTACKMODE.md](../docs/ATTACKMODE.md).

#### Variables & Operators
```
VAR $FOO = 42                   ❌ Variables
$FOO = ($FOO + 1)              ❌ Math operators
IF / ELSE / END_IF             ❌ Conditional statements
WHILE / END_WHILE              ❌ Loops
FUNCTION / END_FUNCTION        ❌ Functions
RETURN                         ❌ Return values
```

#### Randomization
```
RANDOM_CHAR                     ❌ Random character injection
$_RANDOM_INT                    ❌ Random integers
VID_RANDOM / PID_RANDOM        ❌ Random USB identifiers
```

#### Lock Keys & Detection
```
CAPSLOCK / NUMLOCK             ❌ Lock key toggle
WAIT_FOR_CAPS_ON               ❌ Lock key detection
$_CAPSLOCK_ON                  ❌ Lock key state variables
SAVE_HOST_KEYBOARD_LOCK_STATE  ❌ Lock state save/restore
```

#### Button Control
```
WAIT_FOR_BUTTON_PRESS          ❌ No physical button on ATTiny85
BUTTON_DEF / END_BUTTON        ❌ Button event handlers
ENABLE_BUTTON / DISABLE_BUTTON ❌ Button control
```

#### LED Control
```
LED_OFF / LED_R / LED_G        ❌ Specific LED commands
```
*(The ATTiny85 has one built-in LED which lights during payload execution)*

#### Attack Modes & Advanced Features
```
ATTACKMODE HID STORAGE         ❌ USB mode switching
SAVE_ATTACKMODE                ❌ Attack mode state management
HIDE_PAYLOAD / RESTORE_PAYLOAD ❌ Payload hiding
EXFIL / $_EXFIL_MODE_ENABLED  ❌ Keystroke reflection exfiltration
```

#### Key Hold/Release
```
HOLD a / RELEASE a             ❌ Holding keys
INJECT_MOD WINDOWS             ❌ Standalone modifier injection
```

#### Payload Control
```
RESTART_PAYLOAD                ❌ Payload restart
STOP_PAYLOAD                   ❌ Payload stop
RESET                          ❌ Keystroke buffer reset
```

#### Jitter & Timing
```
$_JITTER_ENABLED               ❌ Randomized typing delay
$_JITTER_MAX                   ❌ Jitter configuration
```

---

## Example Payloads

### Basic Example - Open GitHub Repository
```
REM Open GitHub repository in browser
DELAY 1000
GUI r
DELAY 500
STRINGLN https://github.com/3mrgnc3/attiny85_ducky
DELAY 100
ENTER
```

### Using DEFINE for Reusable Values
```
REM Example with constants
DEFINE #WAIT 500
DEFINE #URL github.com/3mrgnc3

DELAY 1000
GUI r
DELAY #WAIT
STRING https://#URL
ENTER
```

### Multi-Language Support
```
REM German keyboard layout
DUCKY_LANG DE

DELAY 1000
GUI r
DELAY 500
STRINGLN notepad
DELAY 800
STRINGLN Hallo Welt! Dies ist ein deutscher Text.
```

### Linux Terminal Commands
```
REM Open terminal and run commands (Linux)
DELAY 1000
CTRL ALT t
DELAY 1000
STRINGLN uname -a
DELAY 500
STRINGLN whoami
DELAY 500
STRINGLN exit
```

### Windows PowerShell Example
```
REM Windows PowerShell payload
DELAY 1000
GUI r
DELAY 500
STRINGLN powershell
DELAY 1500
STRINGLN Write-Host "System Information:" -ForegroundColor Cyan
DELAY 300
STRINGLN Get-ComputerInfo | Select-Object CsName, WindowsVersion, OsArchitecture
DELAY 300
STRINGLN exit
```

---

## Memory Constraints

The ATTiny85 has very limited resources:
- **Flash:** 6,012 bytes usable (8KB total)
- **RAM:** 512 bytes
- **EEPROM:** 512 bytes (unused by this project)

### String Storage Strategy

All payload strings are automatically stored in **PROGMEM** (Flash memory) instead of RAM using the F() macro:

**Generated Code Example:**
```cpp
// Strings stored in Flash using F() macro
keyboard.println(F("https://github.com/3mrgnc3/attiny85_ducky"));
```

This saves RAM for the keyboard library and system stack.

### Payload Size Guidelines

- **Short payloads** (< 20 commands): ✅ Always work
- **Medium payloads** (20-50 commands): ✅ Usually work  
- **Large payloads** (50+ commands): ⚠️ May exceed flash capacity

**Tip:** Keep payloads focused on a single task. For complex operations, use multiple smaller payloads.

---

## Language Support

The compiler uses the ATTinyDuckyKeyboard library with support for 30+ international keyboard layouts.

### Available Languages

| Code | Language | Layout |
|------|----------|--------|
| `US` | English | US QWERTY |
| `BE` | Belgian | Belgian AZERTY |
| `BR` | Brazilian | ABNT2 |
| `CA_FR` | Canadian French | Canadian Multilingual |
| `CH_DE` | Swiss German | Swiss QWERTZ |
| `CH_FR` | Swiss French | Swiss French |
| `CZ` | Czech | Czech QWERTY |
| `DE` | German | German QWERTZ |
| `DK` | Danish | Danish QWERTY |
| `ES` | Spanish | Spanish QWERTY |
| `FI` | Finnish | Finnish QWERTY |
| `FR` | French | French AZERTY |
| `GB` | English UK | UK QWERTY |
| `HR` | Croatian | Croatian QWERTZ |
| `IT` | Italian | Italian QWERTY |
| `NO` | Norwegian | Norwegian QWERTY |
| `PT` | Portuguese | Portuguese QWERTY |
| `RU` | Russian | Russian ЙЦУКЕН |
| `SI` | Slovenian | Slovenian QWERTZ |
| `SK` | Slovak | Slovak QWERTY |
| `SV` | Swedish | Swedish QWERTY |
| `TR` | Turkish | Turkish F-keyboard |

**Default:** `US` (if no `DUCKY_LANG` specified)

### Using International Layouts

```
REM French keyboard layout
DUCKY_LANG FR

STRING Bonjour le monde!
STRINGLN Voici un message en français.
```

```
REM German keyboard layout  
DUCKY_LANG DE

STRING Über den Wolken
STRINGLN ÄÖÜ äöü ß
```

---

## Compilation Process

### Automatic Compilation (Recommended)

The build system automatically compiles `payload.ducky` when you build your project:

```bash
platformio run
```

**Build Process:**
1. PlatformIO pre-build hook runs `pre_build_duckyscript.py`
2. Script checks for `ducky_scripts/payload.ducky`
3. If found: compiles to `src/main.cpp` using `tools/duckyscript_compiler.py`
4. If missing: **build fails** with colored error message
5. PlatformIO compiles generated C++ code
6. Upload to ATTiny85

### Manual Compilation (Advanced)

You can manually compile any DuckyScript file:

```bash
python tools/duckyscript_compiler.py ducky_scripts/my_payload.ducky src/main.cpp
```

This overwrites `src/main.cpp` with the compiled payload.

---

## Creating Your First Payload

1. **Create `payload.ducky` in this directory:**
   ```
   REM My first payload
   DELAY 1000
   GUI r
   DELAY 500
   STRINGLN notepad
   DELAY 1000
   STRINGLN Hello from ATTiny85 Ducky!
   ```

2. **Build the project:**
   ```bash
   platformio run
   ```

3. **Upload to ATTiny85:**
   ```bash
   platformio run --target upload
   ```
   *Insert Digispark when prompted (within 60 seconds)*

4. **Test the payload:**
   - Unplug and replug the ATTiny85
   - Payload executes automatically
   - Built-in LED lights during execution

---

## Troubleshooting

### Build fails: "payload.ducky not found"

**Solution:** Create `ducky_scripts/payload.ducky` with your payload code.

The build system displays:
```
================================================================================
FAILURE: payload.ducky not found!
================================================================================

To fix this:

  1. Create the required payload file:
     ducky_scripts/payload.ducky

  2. Add your DuckyScript payload code

  3. Run the build again
```

### "Unsupported command" warning

The compiler ignores unsupported commands silently. Check this README for supported commands.

### String contains special characters (quotes, backslashes)

The compiler automatically escapes `"` and `\` in strings. You can use them normally:

```
STRINGLN He said "Hello!"
STRINGLN Path: C:\Windows\System32
```

Generated code:
```cpp
const char str_0[] PROGMEM = "He said \"Hello!\"";
const char str_1[] PROGMEM = "Path: C:\\Windows\\System32";
```

### Payload doesn't work on target OS

1. **Check keyboard layout**: Use `DUCKY_LANG` to match target system
2. **Increase delays**: Slower systems need longer `DELAY` values
3. **Test manually**: Type the same key sequence to verify it works

### Compilation successful but upload fails

1. **Install Micronucleus drivers** (Windows)
2. **Check USB port** and try a different cable
3. **Insert device within 60 seconds** when prompted
4. **Try a powered USB hub** if using USB-C adapters

---

## Payload Development Tips

### 1. Start with Delays
Always add initial delay to let the target system enumerate the USB device:
```
DELAY 1000
REM Your payload here
```

### 2. Add Delays Between Commands
Give the OS time to process each command:
```
GUI r
DELAY 500          REM Wait for Run dialog to open
STRINGLN notepad
DELAY 800          REM Wait for Notepad to launch
```

### 3. Test Incrementally
Build your payload step-by-step and test frequently. Don't write 100 lines before testing!

### 4. Use Comments
Document your payload so you remember what it does:
```
REM ======================================
REM Payload: System Info Grabber
REM Target: Windows 10/11
REM Author: Your Name
REM ======================================
```

### 5. Check Flash Usage
After building, check memory usage:
```
RAM:   [===       ]  31.2% (used 160 bytes from 512 bytes)
Flash: [=====     ]  52.3% (used 3144 bytes from 6012 bytes)
```

Stay under 90% flash to avoid issues.

---

## Additional Resources

### Official DuckyScript Documentation
- [DuckyScript Quick Reference](https://docs.hak5.org/hak5-usb-rubber-ducky/duckyscript-quick-reference/)
- [Hak5 Payload Hub](https://github.com/hak5/usbrubberducky-payloads)

### ATTiny85 Resources
- [Digispark Wiki](http://digistump.com/wiki/digispark)
- [DigiKeyboard Documentation](https://github.com/digistump/DigistumpArduino/blob/master/digistump-avr/libraries/DigisparkKeyboard/DigiKeyboard.h)

### This Project
- [ATTiny85 Ducky GitHub](https://github.com/3mrgnc3/attiny85_ducky)
- [Library Source](../lib/ATTinyDuckyKeyboard/)
- [Compiler Source](../tools/duckyscript_compiler.py)

---

## Example Payloads Included

Check the `examples/` subdirectory for complete payload examples:

- **`YTRoll/ScattRoll.ducky`** - YouTube auto-fullscreen prank
- **`WiFiCredsDemo/wifi_creds.ducky`** - WiFi credential dumper for Windows
- **`PopupsPrank/popups_prank.ducky`** - Downloads and executes popup prank script from GitHub

Each example includes the `.ducky` payload file and any supporting scripts.

---

## Security & Legal Notice

⚠️ **This tool is for authorized security testing and educational purposes only.**

- Only test on systems you own or have explicit permission to test
- Unauthorized access to computer systems is illegal in most jurisdictions
- The authors assume no liability for misuse of this tool

**Responsible Disclosure:** If you discover vulnerabilities using this tool, follow responsible disclosure practices and report to the vendor.

---

## Contributing

Found a bug in the compiler? Want to add support for more DuckyScript commands?

1. Fork the repository
2. Create a feature branch
3. Test your changes thoroughly
4. Submit a pull request

**Wishlist for Future Versions:**
- `REPEAT` command support
- Basic `IF`/`ELSE` for simple conditions (if memory allows)
- `MENU`, `PAGEUP`, `PAGEDOWN` keys
- More comprehensive error checking

---

## License

This project is released under the MIT License. See [LICENSE](../LICENSE) for details.

DuckyScript™ is a trademark of Hak5 LLC.

---

**Happy Ducking! 🦆**
