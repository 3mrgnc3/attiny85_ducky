# ExtendedLanguages Library

Extended keyboard layouts for DigiKeyboardMultilang library on ATTiny85 Digispark.

## Overview

This library extends the [DigiKeyboardMultilang](https://github.com/josefkuchar/DigiKeyboardMultilang) library by providing additional international keyboard layouts without modifying the upstream library. It maintains full compatibility with the original library while adding support for keyboards not included in the base distribution.

## Supported Layouts

- **German (QWERTZ)** - `lang_de`
  - Full QWERTZ layout with Y/Z swap
  - Support for umlauts: ä, ö, ü, ß
  - AltGr combinations: @, {, [, ], }, \, |, ~, €
  - Based on USB Rubber Ducky de.json specification

- **French (AZERTY)** - `lang_fr`
  - Full AZERTY layout with Q/A swap, W/Z swap
  - Support for French special characters
  - AltGr combinations: @, #, [, ], {, }, \, |, ~
  - Based on standard French keyboard layout

- **Greek** - `lang_gr`
  - Greek keyboard layout for Latin character input
  - Standard Greek keyboard physical key positions
  - Support for common punctuation and symbols

## Usage

Include the library in your PlatformIO project:

```cpp
#include <Arduino.h>
#include <DigiKeyboardMultilang.h>
#include <languages.h>  // ExtendedLanguages header

// Use German keyboard layout
DigiKeyboardMultilang keyboard(lang_de);

void setup() {
    keyboard.delay(3000);
    keyboard.println("Hallo Welt!");  // Types in German QWERTZ layout
}
```

## Installation

This library is designed to be used as a local PlatformIO library:

1. Place the `ExtendedLanguages` directory in your project's `lib/` folder
2. Ensure your `platformio.ini` includes the DigiKeyboardMultilang dependency:
   ```ini
   lib_deps = josefkuchar/DigiKeyboardMultilang@^1.1.1
   lib_ldf_mode = deep+
   ```
3. Include the header in your code: `#include <extendedLanguages.h>`
4. Use the language array: `DigiKeyboardMultilang keyboard(lang_de);`

## Architecture

The library follows a simple architecture:

- **extendedLanguages.h** - Header file declaring all extended language arrays
- **de.cpp** - German QWERTZ keyboard layout definition
- **fr.cpp** - French AZERTY keyboard layout definition
- **gr.cpp** - Greek keyboard layout definition
- **library.json** - PlatformIO library manifest

Each language array contains 95 entries mapping ASCII characters 32-126 to USB HID keycodes with modifiers.

## Adding New Layouts

To add a new keyboard layout:

1. Find the USB Rubber Ducky language JSON: https://github.com/hak5/usbrubberducky-payloads/tree/master/languages
2. Create a new .cpp file in `src/` (e.g., `fr.cpp` for French)
3. Define the language array: `const uint16_t lang_fr[] PROGMEM = { ... };`
4. Declare it in `extendedLanguages.h`: `extern const uint16_t lang_fr[] PROGMEM;`
5. Test incrementally using PlatformIO

## Language Array Format

Each language array must contain exactly 95 entries representing ASCII 32-126:

```cpp
const uint16_t lang_XX[] PROGMEM = {
    KEY_SPACE,                          // " " (32)
    KEY_1 | KEY_MOD_LSHIFT,             // "!" (33)
    // ... 93 more entries ...
    KEY_GRAVE | KEY_MOD_LSHIFT,         // "~" (126)
};
```

Modifiers:
- `KEY_MOD_LSHIFT` (0x02) - Left Shift
- `KEY_MOD_RALT` (0x40) - Right Alt (AltGr on European keyboards)
- `KEY_102ND` (0x64) - Extra ISO key (left of Z on European keyboards)

## Extended Characters

Note: DigiKeyboardMultilang's `print()` function only supports ASCII 32-126. For extended characters (umlauts, accents), use direct `sendKeyStroke()` calls:

```cpp
// Type German umlaut 'ä'
keyboard.sendKeyStroke(0x34);  // ä key on German keyboard

// Type uppercase 'Ä'
keyboard.sendKeyStroke(0x34, KEY_MOD_LSHIFT);
```

## Memory Considerations

The ATTiny85 has limited resources:
- **Flash**: 6KB total
- **RAM**: 512 bytes total

Each language array occupies approximately 190 bytes of Flash memory (95 entries × 2 bytes). Use only the layouts you need in your payload to conserve memory.

## Compatibility

- **Library**: DigiKeyboardMultilang ^1.1.1
- **Platform**: ATTiny85 Digispark (atmelavr)
- **Framework**: Arduino
- **Build System**: PlatformIO

## Known Limitations

1. The upstream DigiKeyboardMultilang library has a bug in its language files (uses `extern` with initialization). This library works around that by properly separating declarations and definitions.

2. Only printable ASCII characters (32-126) are supported by the `print()` function. Extended characters require manual `sendKeyStroke()` calls.

## References

- USB Rubber Ducky Language Files: https://github.com/hak5/usbrubberducky-payloads/tree/master/languages
- DigiKeyboardMultilang Library: https://github.com/josefkuchar/DigiKeyboardMultilang
- USB HID Keyboard Scan Codes: https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf

## License

This library extends DigiKeyboardMultilang and follows the same licensing terms. See the original library for details.

## Contributing

To add support for additional keyboard layouts:

1. Reference the official USB Rubber Ducky language JSON
2. Create properly formatted language array
3. Test thoroughly on target keyboard layout
4. Submit pull request with documentation

## Version History

- **1.0.0** (2025-11-23) - Initial release with German QWERTZ, French AZERTY, and Greek support
