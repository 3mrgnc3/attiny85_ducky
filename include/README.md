# Include Directory - Project Headers

This directory contains project-level header files for the ATTiny85 Ducky project.

## Project Headers

### `attiny85_ducky.h`

**Main project header** - Include this in your payload source files to get access to all necessary functionality.

This header provides:
- Arduino core framework
- ATTinyDuckyKeyboard library
- USB HID key definitions and modifiers
- Hardware pin definitions for Digispark Rev.3
- Language layout references
- Utility macros

#### Usage

Instead of including multiple headers in your payload files:

```cpp
// OLD WAY - Multiple includes
#include <Arduino.h>
#include <ATTinyDuckyKeyboard.h>

// NEW WAY - Single project header
#include "attiny85_ducky.h"
```

This simplifies your payload code and ensures consistent includes across all files.

#### Example Payload

```cpp
#include "attiny85_ducky.h"

ATTinyDuckyKeyboard keyboard(lang_us);

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    
    keyboard.delay(5000);
    keyboard.sendKeyStroke(KEY_R, KEY_MOD_GUI); // Win+R
    keyboard.delay(800);
    keyboard.println("notepad");
    
    digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
    // Empty
}
```

## Benefits of Using Project Headers

1. **Consistency**: All source files use the same includes
2. **Simplicity**: One include instead of multiple
3. **Maintainability**: Changes to required headers only need to be made in one place
4. **Documentation**: All available features are documented in one location
5. **Best Practice**: Follows PlatformIO project structure conventions

## PlatformIO Include Paths

PlatformIO automatically adds the following to the include path:
- `include/` - Project headers (this directory)
- `src/` - Source files
- `lib/*/src/` - Library source directories
- Framework includes (Arduino.h, etc.)

You can use `#include "header.h"` (quotes) for project headers and `#include <library.h>` (angle brackets) for library/framework headers.
