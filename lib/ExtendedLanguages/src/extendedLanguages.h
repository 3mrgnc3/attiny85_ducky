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
extern const uint16_t lang_us[] PROGMEM;
extern const uint16_t lang_de[] PROGMEM;
extern const uint16_t lang_fr[] PROGMEM;
extern const uint16_t lang_es[] PROGMEM;
extern const uint16_t lang_it[] PROGMEM;
extern const uint16_t lang_pt[] PROGMEM;
extern const uint16_t lang_gr[] PROGMEM;
extern const uint16_t lang_dk[] PROGMEM;
extern const uint16_t lang_no[] PROGMEM; 
extern const uint16_t lang_se[] PROGMEM;
extern const uint16_t lang_fi[] PROGMEM;
extern const uint16_t lang_be[] PROGMEM;
extern const uint16_t lang_gb[] PROGMEM;
extern const uint16_t lang_ch[] PROGMEM;
extern const uint16_t lang_tr[] PROGMEM;
extern const uint16_t lang_hr[] PROGMEM;
extern const uint16_t lang_hu[] PROGMEM;
extern const uint16_t lang_si[] PROGMEM;
extern const uint16_t lang_sk[] PROGMEM;
extern const uint16_t lang_ca[] PROGMEM;
extern const uint16_t lang_br[] PROGMEM;
extern const uint16_t lang_mx[] PROGMEM;
extern const uint16_t lang_ru[] PROGMEM;
extern const uint16_t lang_nl[] PROGMEM;
extern const uint16_t lang_ua[] PROGMEM;
extern const uint16_t lang_bg[] PROGMEM;
extern const uint16_t lang_pl[] PROGMEM;
extern const uint16_t lang_ro[] PROGMEM;

#endif
