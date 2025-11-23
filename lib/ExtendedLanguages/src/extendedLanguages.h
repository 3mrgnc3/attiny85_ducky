#ifndef EXTENDED_LANGUAGES_H
#define EXTENDED_LANGUAGES_H

#include <Arduino.h>
#include <DigiKeyboardMultilang.h>

// Extended key definitions
// These provide convenient aliases for commonly used keys
#ifndef KEY_MOD_GUI
#define KEY_MOD_GUI 0x08  // Windows/Command/Super key (same as KEY_MOD_LMETA)
#endif

// Extended language declarations
// These extend DigiKeyboardMultilang's built-in languages (us, cs, csq)
// without modifying the upstream library

// German QWERTZ keyboard layout
extern const uint16_t lang_de[] PROGMEM;

// French AZERTY keyboard layout
extern const uint16_t lang_fr[] PROGMEM;

// Greek keyboard layout
extern const uint16_t lang_gr[] PROGMEM;

// Future language layouts (uncomment when implemented):
// extern const uint16_t lang_es[] PROGMEM;  // Spanish
// extern const uint16_t lang_it[] PROGMEM;  // Italian
// extern const uint16_t lang_pt[] PROGMEM;  // Portuguese
// extern const uint16_t lang_dk[] PROGMEM;  // Danish
// extern const uint16_t lang_no[] PROGMEM;  // Norwegian
// extern const uint16_t lang_se[] PROGMEM;  // Swedish
// extern const uint16_t lang_fi[] PROGMEM;  // Finnish
// extern const uint16_t lang_nl[] PROGMEM;  // Dutch
// extern const uint16_t lang_be[] PROGMEM;  // Belgian

#endif
