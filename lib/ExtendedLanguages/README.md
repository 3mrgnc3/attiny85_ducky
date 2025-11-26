# ExtendedLanguages Library

Extended keyboard layouts for DigiKeyboardMultilang library on ATTiny85 Digispark.

## Overview

This library extends the [DigiKeyboardMultilang](https://github.com/josefkuchar/DigiKeyboardMultilang) library by providing additional international keyboard layouts without modifying the upstream library. It maintains full compatibility with the original library while adding support for keyboards not included in the base distribution.

### Extended Key Definitions

This library also provides convenient key code aliases:

- **`KEY_MOD_GUI`** - Alias for Windows/Command/Super key (value: `0x08`)
  - Use instead of the raw hex value `0x08` for better code readability
  - Equivalent to `KEY_MOD_LMETA` in the USB HID specification
  - Works cross-platform: Windows key, macOS Command key, Linux Super key

Example:
```cpp
// Both are equivalent, but KEY_MOD_GUI is more readable:
keyboard.sendKeyStroke(KEY_R, KEY_MOD_GUI);  // Win+R
keyboard.sendKeyStroke(KEY_R, 0x08);         // Same thing
```

## Supported Layouts

All layouts support ASCII characters 32-126 (95 printable characters) with proper modifier keys (Shift, AltGr).

### Romance Languages

- **Spanish (ES)** - `lang_es`
  - Spanish QWERTY layout
  - AltGr combinations: @(AltGr+2), [(AltGr+`), ](AltGr+'), {(AltGr+Shift+`), }(AltGr+Shift+'), |(AltGr+1), ~(AltGr+4)
  - Based on USB Rubber Ducky es.json

- **Italian (IT)** - `lang_it`
  - Italian QWERTY layout
  - AltGr combinations: #(AltGr+'), @(AltGr+`), [(AltGr+[), ](AltGr+]), {(AltGr+Shift+[), }(AltGr+Shift+]), ~(AltGr+=)
  - Based on USB Rubber Ducky it.json

- **Portuguese (PT)** - `lang_pt`
  - Portuguese QWERTY layout
  - AltGr combinations: @(AltGr+2), [(AltGr+8), ](AltGr+9), {(AltGr+7), }(AltGr+0)
  - Based on USB Rubber Ducky pt.json

- **French (AZERTY)** - `lang_fr`
  - French AZERTY layout with Q/A swap, W/Z swap
  - AltGr combinations: @, #, [, ], {, }, \, |, ~
  - Based on standard French keyboard layout

### Germanic Languages

- **German (QWERTZ)** - `lang_de`
  - German QWERTZ layout with Y/Z swap
  - Support for umlauts: ä, ö, ü, ß
  - AltGr combinations: @, {, [, ], }, \, |, ~, €
  - Based on USB Rubber Ducky de.json

- **Swiss German (QWERTZ)** - `lang_ch`
  - Swiss German QWERTZ layout with Y/Z swap
  - AltGr combinations: #(AltGr+3), @(AltGr+2), [(AltGr+ü), \(AltGr+<), ](AltGr+¨), {, |, }, ~
  - Based on USB Rubber Ducky ch.json

### Nordic Languages

- **Danish (DK)** - `lang_dk`
  - Danish QWERTY layout
  - Special keys: æ, ø, å
  - AltGr combinations: $(AltGr+4), @(AltGr+2), [(AltGr+8), \(AltGr+<), ](AltGr+9), {(AltGr+7), |(AltGr+´), }(AltGr+0)
  - Based on USB Rubber Ducky dk.json

- **Norwegian (NO)** - `lang_no`
  - Norwegian QWERTY layout
  - Special keys: æ, ø, å
  - AltGr combinations: $(AltGr+4), @(AltGr+2), [(AltGr+8), \(AltGr+<), ](AltGr+9), {(AltGr+7), |(AltGr+´), }(AltGr+0)
  - Based on USB Rubber Ducky no.json

- **Swedish (SE)** - `lang_se`
  - Swedish QWERTY layout
  - Special keys: å, ä, ö
  - AltGr combinations: $(AltGr+4), @(AltGr+2), [(AltGr+8), \(AltGr+<), ](AltGr+9), {(AltGr+7), |(AltGr+´), }(AltGr+0)
  - Based on USB Rubber Ducky se.json

- **Finnish (FI)** - `lang_fi`
  - Finnish QWERTY layout
  - Special keys: ä, ö, å
  - AltGr combinations: $(AltGr+4), @(AltGr+2), [(AltGr+8), \(AltGr+<), ](AltGr+9), {(AltGr+7), |(AltGr+´), }(AltGr+0)
  - Based on USB Rubber Ducky fi.json

### English Variants

- **US English (QWERTY)** - `lang_us`
  - Standard US QWERTY layout
  - No AltGr combinations needed
  - Based on USB Rubber Ducky us.json

- **UK English (QWERTY)** - `lang_gb`
  - UK English QWERTY layout
  - Key differences from US: @, ", #, £ positions
  - Non-US backslash key (key next to left shift)
  - Based on USB Rubber Ducky gb.json

### Other European Languages

- **Belgian (AZERTY)** - `lang_be`
  - Belgian AZERTY layout
  - Similar to French AZERTY with regional differences
  - AltGr combinations: @(AltGr+2), [(AltGr+5), \(AltGr+<), ](AltGr+)), {(AltGr+4), |(AltGr+1), }(AltGr+=)
  - Based on USB Rubber Ducky be.json

- **Turkish (Q)** - `lang_tr`
  - Turkish Q keyboard layout
  - AltGr combinations: @(AltGr+Q), ^(AltGr+3), [(AltGr+8), \(AltGr+-), ](AltGr+9), {(AltGr+7), |(AltGr+*), }(AltGr+0), ~(AltGr+ü)
  - Based on USB Rubber Ducky tr.json

- **Greek** - `lang_gr`
  - Greek keyboard layout for Latin character input
  - Standard Greek keyboard physical key positions
  - Support for common punctuation and symbols

### Central/Eastern European Languages (QWERTZ)

- **Croatian (HR)** - `lang_hr`
  - Croatian QWERTZ layout with Y/Z swap
  - AltGr combinations: @(AltGr+V), [(AltGr+F), \(AltGr+Q), ](AltGr+G), {(AltGr+B), |(AltGr+W), }(AltGr+N)
  - Based on USB Rubber Ducky hr.json

- **Hungarian (HU)** - `lang_hu`
  - Hungarian QWERTZ layout with Y/Z swap
  - Complex number row arrangement unique to Hungarian
  - AltGr combinations: $(AltGr+é), &(AltGr+C), *(AltGr+-), ;(AltGr+,), @(AltGr+V), [(AltGr+F), \(AltGr+Q), ](AltGr+G), `(AltGr+7), {(AltGr+B), |(AltGr+W), }(AltGr+N), ~(AltGr+1)
  - Based on USB Rubber Ducky hu.json

- **Slovenian (SI)** - `lang_si`
  - Slovenian QWERTZ layout with Y/Z swap
  - AltGr combinations: @(AltGr+V), [(AltGr+F), \(AltGr+Q), ](AltGr+G), {(AltGr+B), |(AltGr+W), }(AltGr+N)
  - Based on USB Rubber Ducky si.json

- **Slovak (SK)** - `lang_sk`
  - Slovak QWERTZ layout with Y/Z swap
  - Unique Slovak number/symbol arrangement
  - AltGr combinations: $(AltGr+ô), &(AltGr+C), @(AltGr+V), [(AltGr+F), \(AltGr+Q), ](AltGr+G), `(AltGr+ú), {(AltGr+B), |(AltGr+W), }(AltGr+N), ~(AltGr+1)
  - Based on USB Rubber Ducky sk.json

### Latin American Languages

- **Catalan (CA)** - `lang_ca`
  - Catalan QWERTY layout
  - AltGr combinations: @(AltGr+2), [(AltGr+`), \(AltGr+'), ](AltGr++), ^(AltGr+Shift+`), {(AltGr+Shift+'), |(AltGr+1), }(AltGr+Shift++), ~(AltGr+4)
  - Based on USB Rubber Ducky ca.json

- **Brazilian Portuguese (BR)** - `lang_br`
  - Brazilian Portuguese ABNT2 layout (different from European Portuguese)
  - Unique ABNT2 key positions and character arrangement
  - AltGr combinations: @(AltGr+2), |(AltGr+\)
  - Based on USB Rubber Ducky br.json

- **Mexican Spanish (MX)** - `lang_mx`
  - Mexican Spanish layout (Latin American variant)
  - Different from European Spanish layout
  - AltGr combinations: @(AltGr+Q), [(AltGr+´), ](AltGr++), {(AltGr+{), |(AltGr+|), }(AltGr+}), ~(AltGr+~)
  - Based on USB Rubber Ducky mx.json

### Cyrillic Languages

- **Russian (RU)** - `lang_ru`
  - Russian ЙЦУКЕН (JCUKEN) keyboard layout
  - Allows typing Latin ASCII characters on Russian keyboards
  - Standard Russian keyboard physical key positions
  - Created from standard Russian keyboard layout (no official USB Rubber Ducky reference)

- **Ukrainian (UA)** - `lang_ua`
  - Ukrainian ЙЦУКЕН (JCUKEN) keyboard layout
  - Allows typing Latin ASCII characters on Ukrainian keyboards
  - Standard Ukrainian keyboard physical key positions
  - Created from standard Ukrainian keyboard layout

- **Bulgarian (BG)** - `lang_bg`
  - Bulgarian БДС (BDS) keyboard layout
  - Allows typing Latin ASCII characters on Bulgarian keyboards
  - Standard Bulgarian keyboard physical key positions
  - Created from standard Bulgarian keyboard layout

### Other European Languages (continued)

- **Dutch (NL)** - `lang_nl`
  - Dutch QWERTY layout
  - AltGr combinations: $(AltGr+5), @(AltGr+'), [(AltGr+8), \(AltGr+-), ](AltGr+9), ^(AltGr+6), `(AltGr+`), {(AltGr+7), |(AltGr+<), }(AltGr+0), ~(AltGr+=)
  - Created from standard Dutch keyboard layout

- **Polish (PL)** - `lang_pl`
  - Polish QWERTY layout
  - AltGr combinations: @(AltGr+V), [(AltGr+F), \(AltGr+Q), ](AltGr+G), {(AltGr+B), |(AltGr+W), }(AltGr+N)
  - Created from standard Polish keyboard layout

- **Romanian (RO)** - `lang_ro`
  - Romanian QWERTY layout
  - AltGr combinations: @(AltGr+2), [(AltGr+[), \(AltGr+\), ](AltGr+]), {(AltGr+Shift+[), |(AltGr+Shift+\), }(AltGr+Shift+])
  - Created from standard Romanian keyboard layout

## Usage

Include the library in your PlatformIO project:

```cpp
#include <Arduino.h>
#include <DigiKeyboardMultilang.h>
#include <extendedLanguages.h>  // ExtendedLanguages header

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
