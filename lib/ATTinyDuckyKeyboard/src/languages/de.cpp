#include "languages.h"



// German (QWERTZ) keyboard layout
// Based on USB Rubber Ducky language file
// Ref: https://github.com/hak5/usbrubberducky-payloads/blob/master/languages/de.json
// Characters are mapped from ASCII 32 (space) to ASCII 126 (~)

const uint16_t lang_de[] PROGMEM = {
    KEY_SPACE,                          // " " (32) - space
    (KEY_MOD_LSHIFT << 8) | KEY_1,             // "!" (33) - exclamation
    (KEY_MOD_LSHIFT << 8) | KEY_2,             // """ (34) - double quote
    KEY_BACKSLASH,                      // "#" (35) - hash/number sign (on German keyboard, # is the key right of Ä)
    (KEY_MOD_LSHIFT << 8) | KEY_4,             // "$" (36) - dollar
    (KEY_MOD_LSHIFT << 8) | KEY_5,             // "%" (37) - percent
    (KEY_MOD_LSHIFT << 8) | KEY_6,             // "&" (38) - ampersand
    (KEY_MOD_LSHIFT << 8) | KEY_BACKSLASH,     // "'" (39) - single quote/apostrophe (Shift+# key)
    (KEY_MOD_LSHIFT << 8) | KEY_8,             // "(" (40) - left parenthesis
    (KEY_MOD_LSHIFT << 8) | KEY_9,             // ")" (41) - right parenthesis
    (KEY_MOD_LSHIFT << 8) | KEY_RIGHTBRACE,    // "*" (42) - asterisk
    KEY_RIGHTBRACE,                     // "+" (43) - plus
    KEY_COMMA,                          // "," (44) - comma
    KEY_SLASH,                          // "-" (45) - minus/hyphen
    KEY_DOT,                            // "." (46) - period/dot
    (KEY_MOD_LSHIFT << 8) | KEY_7,             // "/" (47) - forward slash
    KEY_0,                              // "0" (48)
    KEY_1,                              // "1" (49)
    KEY_2,                              // "2" (50)
    KEY_3,                              // "3" (51)
    KEY_4,                              // "4" (52)
    KEY_5,                              // "5" (53)
    KEY_6,                              // "6" (54)
    KEY_7,                              // "7" (55)
    KEY_8,                              // "8" (56)
    KEY_9,                              // "9" (57)
    (KEY_MOD_LSHIFT << 8) | KEY_DOT,           // ":" (58) - colon
    (KEY_MOD_LSHIFT << 8) | KEY_COMMA,         // ";" (59) - semicolon
    KEY_102ND,                          // "<" (60) - less than (key left of 'Z')
    (KEY_MOD_LSHIFT << 8) | KEY_0,             // "=" (61) - equals
    (KEY_MOD_LSHIFT << 8) | KEY_102ND,         // ">" (62) - greater than
    (KEY_MOD_LSHIFT << 8) | KEY_MINUS,         // "?" (63) - question mark
    (KEY_MOD_RALT << 8) | KEY_Q,               // "@" (64) - at sign (AltGr+Q)
    (KEY_MOD_LSHIFT << 8) | KEY_A,             // "A" (65)
    (KEY_MOD_LSHIFT << 8) | KEY_B,             // "B" (66)
    (KEY_MOD_LSHIFT << 8) | KEY_C,             // "C" (67)
    (KEY_MOD_LSHIFT << 8) | KEY_D,             // "D" (68)
    (KEY_MOD_LSHIFT << 8) | KEY_E,             // "E" (69)
    (KEY_MOD_LSHIFT << 8) | KEY_F,             // "F" (70)
    (KEY_MOD_LSHIFT << 8) | KEY_G,             // "G" (71)
    (KEY_MOD_LSHIFT << 8) | KEY_H,             // "H" (72)
    (KEY_MOD_LSHIFT << 8) | KEY_I,             // "I" (73)
    (KEY_MOD_LSHIFT << 8) | KEY_J,             // "J" (74)
    (KEY_MOD_LSHIFT << 8) | KEY_K,             // "K" (75)
    (KEY_MOD_LSHIFT << 8) | KEY_L,             // "L" (76)
    (KEY_MOD_LSHIFT << 8) | KEY_M,             // "M" (77)
    (KEY_MOD_LSHIFT << 8) | KEY_N,             // "N" (78)
    (KEY_MOD_LSHIFT << 8) | KEY_O,             // "O" (79)
    (KEY_MOD_LSHIFT << 8) | KEY_P,             // "P" (80)
    (KEY_MOD_LSHIFT << 8) | KEY_Q,             // "Q" (81)
    (KEY_MOD_LSHIFT << 8) | KEY_R,             // "R" (82)
    (KEY_MOD_LSHIFT << 8) | KEY_S,             // "S" (83)
    (KEY_MOD_LSHIFT << 8) | KEY_T,             // "T" (84)
    (KEY_MOD_LSHIFT << 8) | KEY_U,             // "U" (85)
    (KEY_MOD_LSHIFT << 8) | KEY_V,             // "V" (86)
    (KEY_MOD_LSHIFT << 8) | KEY_W,             // "W" (87)
    (KEY_MOD_LSHIFT << 8) | KEY_X,             // "X" (88)
    (KEY_MOD_LSHIFT << 8) | KEY_Z,             // "Y" (89) - QWERTZ: Y/Z swapped
    (KEY_MOD_LSHIFT << 8) | KEY_Y,             // "Z" (90) - QWERTZ: Y/Z swapped
    (KEY_MOD_RALT << 8) | KEY_8,               // "[" (91) - left bracket (AltGr+8)
    (KEY_MOD_RALT << 8) | KEY_MINUS,           // "\\" (92) - backslash (AltGr+ß, ß is on MINUS key position)
    (KEY_MOD_RALT << 8) | KEY_9,               // "]" (93) - right bracket (AltGr+9)
    KEY_GRAVE,                          // "^" (94) - caret (dead key on German keyboard)
    (KEY_MOD_LSHIFT << 8) | KEY_SLASH,         // "_" (95) - underscore
    (KEY_MOD_LSHIFT << 8) | KEY_EQUAL,         // "`" (96) - grave accent (Shift+=)
    KEY_A,                              // "a" (97)
    KEY_B,                              // "b" (98)
    KEY_C,                              // "c" (99)
    KEY_D,                              // "d" (100)
    KEY_E,                              // "e" (101)
    KEY_F,                              // "f" (102)
    KEY_G,                              // "g" (103)
    KEY_H,                              // "h" (104)
    KEY_I,                              // "i" (105)
    KEY_J,                              // "j" (106)
    KEY_K,                              // "k" (107)
    KEY_L,                              // "l" (108)
    KEY_M,                              // "m" (109)
    KEY_N,                              // "n" (110)
    KEY_O,                              // "o" (111)
    KEY_P,                              // "p" (112)
    KEY_Q,                              // "q" (113)
    KEY_R,                              // "r" (114)
    KEY_S,                              // "s" (115)
    KEY_T,                              // "t" (116)
    KEY_U,                              // "u" (117)
    KEY_V,                              // "v" (118)
    KEY_W,                              // "w" (119)
    KEY_X,                              // "x" (120)
    KEY_Z,                              // "y" (121) - QWERTZ: Y/Z swapped
    KEY_Y,                              // "z" (122) - QWERTZ: Y/Z swapped
    (KEY_MOD_RALT << 8) | KEY_7,               // "{" (123) - left brace (AltGr+7)
    (KEY_MOD_RALT << 8) | KEY_102ND,           // "|" (124) - pipe (AltGr+<)
    (KEY_MOD_RALT << 8) | KEY_0,               // "}" (125) - right brace (AltGr+0)
    (KEY_MOD_RALT << 8) | KEY_RIGHTBRACE,      // "~" (126) - tilde (AltGr++)
};

// Extended character support for German umlauts and special characters
// Note: These are typically accessed via dead keys or special key combinations
// ä = 0x34 (KEY_APOSTROPHE on German keyboard)
// ö = 0x33 (KEY_SEMICOLON on German keyboard)  
// ü = 0x2f (KEY_LEFTBRACE on German keyboard)
// ß = 0x2d (KEY_MINUS on German keyboard)
// Ä = Shift + ä
// Ö = Shift + ö
// Ü = Shift + ü
// § = Shift + 3 (0x20)
// € = AltGr + E (0x08)