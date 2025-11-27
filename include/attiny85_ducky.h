/**
 * ATTiny85 Ducky - Project Header
 * 
 * This is the main project header file that should be included in your payloads.
 * It provides all the necessary includes and definitions for creating USB Rubber 
 * Ducky-style payloads on the ATTiny85 Digispark platform.
 * 
 * @file attiny85_ducky.h
 * @version 1.0.0
 * @date 2025-11-26
 */

#ifndef ATTINY85_DUCKY_H
#define ATTINY85_DUCKY_H

// ===== Core Arduino Framework =====
#include <Arduino.h>

// ===== ATTinyDuckyKeyboard Library =====
// Provides keyboard emulation with international layout support
#include <ATTinyDuckyKeyboard.h>

// ===== USB HID Key Definitions =====
// Direct access to USB HID key codes and modifiers
// Normally you don't need to include this directly, but it's here if needed
// #include <usb_hid_keys.h>

// ===== Common Key Modifiers =====
// These are already defined in usb_hid_keys.h (included by ATTinyDuckyKeyboard.h)
// Listed here for quick reference:
//
// KEY_MOD_LCTRL   (0x01) - Left Control
// KEY_MOD_LSHIFT  (0x02) - Left Shift  
// KEY_MOD_LALT    (0x04) - Left Alt
// KEY_MOD_LMETA   (0x08) - Left GUI/Windows/Command
// KEY_MOD_GUI     (0x08) - Alias for KEY_MOD_LMETA (more readable)
// KEY_MOD_RCTRL   (0x10) - Right Control
// KEY_MOD_RSHIFT  (0x20) - Right Shift
// KEY_MOD_RALT    (0x40) - Right Alt (AltGr on European keyboards)
// KEY_MOD_RMETA   (0x80) - Right GUI/Windows/Command

// ===== Supported Language Layouts =====
// The following language arrays are available:
//
// lang_be  - Belgian AZERTY         lang_no  - Norwegian QWERTY
// lang_bg  - Bulgarian БДС          lang_pl  - Polish QWERTY
// lang_br  - Brazilian Portuguese   lang_pt  - Portuguese QWERTY
// lang_ca  - Catalan QWERTY         lang_ro  - Romanian QWERTY
// lang_ch  - Swiss German QWERTZ    lang_ru  - Russian ЙЦУКЕН
// lang_cs  - Czech QWERTZ           lang_se  - Swedish QWERTY
// lang_csq - Czech QWERTY           lang_si  - Slovenian QWERTZ
// lang_de  - German QWERTZ          lang_sk  - Slovak QWERTZ
// lang_dk  - Danish QWERTY          lang_tr  - Turkish Q
// lang_es  - Spanish QWERTY         lang_ua  - Ukrainian ЙЦУКЕН
// lang_fi  - Finnish QWERTY         lang_us  - US English QWERTY
// lang_fr  - French AZERTY
// lang_gb  - UK English QWERTY
// lang_gr  - Greek
// lang_hr  - Croatian QWERTZ
// lang_hu  - Hungarian QWERTZ
// lang_it  - Italian QWERTY
// lang_mx  - Mexican Spanish QWERTY
// lang_nl  - Dutch QWERTY
//
// Note: All languages are compiled into the firmware. Each language uses ~190 bytes of flash.

// ===== Hardware Pin Definitions =====
// Standard Digispark Rev.3 pinout
// #define LED_BUILTIN 1    // Built-in red LED on P1
#define P0 0             // P0 - I/O
#define P1 1             // P1 - I/O (Built-in LED)
#define P2 2             // P2 - I/O
#define P3 3             // P3 - USB+ (also usable as I/O when USB not in use)
#define P4 4             // P4 - USB- (also usable as I/O when USB not in use)
#define P5 5             // P5 - I/O

// ===== Utility Macros =====
// Convenience macros for common operations

// Create keyboard instance with specified language
// Usage: KEYBOARD_INIT(lang_us);
#define KEYBOARD_INIT(lang) ATTinyDuckyKeyboard keyboard(lang)

// Common keyboard shortcuts (platform-specific)
#ifdef _WIN32
    #define OS_GUI_KEY KEY_MOD_GUI  // Windows key
#elif defined(__APPLE__)
    #define OS_GUI_KEY KEY_MOD_GUI  // Command key
#else
    #define OS_GUI_KEY KEY_MOD_GUI  // Super key (Linux)
#endif

#endif // ATTINY85_DUCKY_H
