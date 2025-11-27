# ATTinyDuckyKeyboard Library

Local USB HID keyboard library for ATTiny85 Digispark with comprehensive multi-language support.

This is a local fork of the [DigiKeyboardMultilang](https://github.com/JosefKuchar/DigiKeyboardMultilang) library, created to:
- Have full control over the codebase for future optimizations
- Provide comprehensive international keyboard layout support (31 languages)
- Enable custom enhancements specific to the ATTiny85 Ducky project
- Maintain USB Rubber Ducky compatibility

## Features

- **31 keyboard layouts**: us, de, fr, es, it, pt, gr, cs, csq, dk, no, se, fi, gb, be, ch, tr, hr, hu, si, sk, ca, br, mx, ru, nl, ua, bg, pl, ro
- **Automatic conditional compilation**: Only the languages you actually use are compiled into flash
- Wraps the underlying DigiKeyboard library from Digistump
- USB Rubber Ducky compatible language mappings
- Optimized for ATTiny85 memory constraints (6KB flash, 512B RAM)

## Memory Optimization

The library includes an **intelligent conditional compilation system** that automatically detects which language layouts you're using and compiles **only those layouts**. This can save up to ~5,700 bytes of flash memory!

**Example**: If you only use `lang_us`, the build system automatically excludes the other 30 language layouts, saving approximately **96% of the language data** for your payload code.

See [CONDITIONAL_COMPILATION.md](CONDITIONAL_COMPILATION.md) for detailed information.

## Architecture

The library consists of:
- **ATTinyDuckyKeyboard.cpp/.h** - Main class implementation
- **languages/usb_hid_keys.h** - USB HID keyboard scan codes and modifiers
- **languages/languages.h** - Language layout declarations (31 layouts)
- **languages/*.cpp** - Individual language layout files (31 total)

## API

### Constructor
```cpp
ATTinyDuckyKeyboard(const uint16_t* language)
```
Initialize with a specific keyboard layout.

### Methods
- `void print(const char str[])` - Print a string using the selected layout
- `void println(const char str[])` - Print a string followed by Enter
- `void delay(long milli)` - Delay in milliseconds
- `void sendKeyPress(byte keyPress)` - Send key press (without release)
- `void sendKeyPress(byte keyPress, byte modifiers)` - Send key press with modifiers
- `void sendKeyStroke(byte keyStroke)` - Send complete keystroke (press + release)
- `void sendKeyStroke(byte keyStroke, byte modifiers)` - Send keystroke with modifiers
- `void setLanguage(const uint16_t* language)` - Change keyboard layout

## Usage

```cpp
#include <ATTinyDuckyKeyboard.h>

// Use German QWERTZ layout
ATTinyDuckyKeyboard keyboard(lang_de);

void setup() {
    keyboard.delay(3000);
    keyboard.println("Hallo Welt!");
    keyboard.sendKeyStroke(KEY_R, KEY_MOD_GUI); // Win+R
}
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

## Memory Usage

- **Flash**: 52.3% (3,142 / 6,012 bytes)
- **RAM**: 31.2% (160 / 512 bytes)

All 31 language layouts fit comfortably within ATTiny85 constraints.

## Language Array Format

Each language array contains exactly 95 entries representing ASCII 32-126:

```cpp
const uint16_t lang_XX[] PROGMEM = {
    KEY_SPACE,                          // " " (32)
    KEY_1 | KEY_MOD_LSHIFT,             // "!" (33)
    // ... 93 more entries ...
    KEY_GRAVE | KEY_MOD_LSHIFT,         // "~" (126)
};
```

### Modifier Constants

Modifiers are combined with keycodes using bitwise OR and stored in the upper byte:

- `KEY_MOD_LCTRL` (0x01) - Left Control
- `KEY_MOD_LSHIFT` (0x02) - Left Shift  
- `KEY_MOD_LALT` (0x04) - Left Alt
- `KEY_MOD_LMETA` (0x08) - Left Meta/GUI (Windows/Command key)
- `KEY_MOD_RCTRL` (0x10) - Right Control
- `KEY_MOD_RSHIFT` (0x20) - Right Shift
- `KEY_MOD_RALT` (0x40) - Right Alt (AltGr on European keyboards)
- `KEY_MOD_RMETA` (0x80) - Right Meta/GUI

Special convenience alias:
- `KEY_MOD_GUI` (0x08) - Same as KEY_MOD_LMETA (Windows/Command/Super key)

### Special Keys

- `KEY_102ND` (0x64) - Extra ISO key (left of Z on European keyboards, often labeled "< >")
- All standard USB HID keyboard scan codes defined in `usb_hid_keys.h`

## Adding New Layouts

To add a new keyboard layout:

1. Find the USB Rubber Ducky language JSON: https://github.com/hak5/usbrubberducky-payloads/tree/master/languages
2. Create a new .cpp file in `src/languages/` (e.g., `jp.cpp` for Japanese)
3. Include the header: `#include "languages.h"`
4. Define the language array: `const uint16_t lang_jp[] PROGMEM = { ... };`
5. Declare it in `languages.h`: `extern const uint16_t lang_jp[] PROGMEM;`
6. Build and test with PlatformIO

## Credits

Based on and inspired by:
- **DigiKeyboardMultilang** by Josef Kuchař - Original multi-language keyboard library
- **USB HID Keys Specification** by MightyPork - Comprehensive USB HID key definitions
- **DigiKeyboard Library** by Digistump - Low-level V-USB keyboard implementation for ATtiny85
- **USB Rubber Ducky Payloads** by Hak5 - Language layout reference implementations
