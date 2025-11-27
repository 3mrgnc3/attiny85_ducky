#include "languages.h"



// French (AZERTY) keyboard layout
// Based on standard French AZERTY layout
// Characters are mapped from ASCII 32 (space) to ASCII 126 (~)

const uint16_t lang_fr[] PROGMEM = {
    KEY_SPACE,                          // " " (32) - space
    KEY_SLASH,                          // "!" (33) - exclamation
    KEY_3,                              // """ (34) - double quote
    (KEY_MOD_RALT << 8) | KEY_3,               // "#" (35) - hash/number sign (AltGr+3)
    KEY_RIGHTBRACE,                     // "$" (36) - dollar
    (KEY_MOD_LSHIFT << 8) | KEY_APOSTROPHE,    // "%" (37) - percent
    KEY_1,                              // "&" (38) - ampersand
    KEY_4,                              // "'" (39) - single quote/apostrophe
    KEY_5,                              // "(" (40) - left parenthesis
    KEY_MINUS,                          // ")" (41) - right parenthesis
    KEY_BACKSLASH,                      // "*" (42) - asterisk
    (KEY_MOD_LSHIFT << 8) | KEY_EQUAL,         // "+" (43) - plus
    KEY_M,                              // "," (44) - comma
    KEY_6,                              // "-" (45) - minus/hyphen
    (KEY_MOD_LSHIFT << 8) | KEY_COMMA,         // "." (46) - period/dot
    (KEY_MOD_LSHIFT << 8) | KEY_DOT,           // "/" (47) - forward slash
    (KEY_MOD_LSHIFT << 8) | KEY_0,             // "0" (48)
    (KEY_MOD_LSHIFT << 8) | KEY_1,             // "1" (49)
    (KEY_MOD_LSHIFT << 8) | KEY_2,             // "2" (50)
    (KEY_MOD_LSHIFT << 8) | KEY_3,             // "3" (51)
    (KEY_MOD_LSHIFT << 8) | KEY_4,             // "4" (52)
    (KEY_MOD_LSHIFT << 8) | KEY_5,             // "5" (53)
    (KEY_MOD_LSHIFT << 8) | KEY_6,             // "6" (54)
    (KEY_MOD_LSHIFT << 8) | KEY_7,             // "7" (55)
    (KEY_MOD_LSHIFT << 8) | KEY_8,             // "8" (56)
    (KEY_MOD_LSHIFT << 8) | KEY_9,             // "9" (57)
    KEY_DOT,                            // ":" (58) - colon
    KEY_COMMA,                          // ";" (59) - semicolon
    KEY_102ND,                          // "<" (60) - less than
    KEY_EQUAL,                          // "=" (61) - equals
    (KEY_MOD_LSHIFT << 8) | KEY_102ND,         // ">" (62) - greater than
    (KEY_MOD_LSHIFT << 8) | KEY_M,             // "?" (63) - question mark
    (KEY_MOD_RALT << 8) | KEY_0,               // "@" (64) - at sign (AltGr+0)
    (KEY_MOD_LSHIFT << 8) | KEY_Q,             // "A" (65)
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
    (KEY_MOD_LSHIFT << 8) | KEY_SEMICOLON,     // "M" (77)
    (KEY_MOD_LSHIFT << 8) | KEY_N,             // "N" (78)
    (KEY_MOD_LSHIFT << 8) | KEY_O,             // "O" (79)
    (KEY_MOD_LSHIFT << 8) | KEY_P,             // "P" (80)
    (KEY_MOD_LSHIFT << 8) | KEY_A,             // "Q" (81)
    (KEY_MOD_LSHIFT << 8) | KEY_R,             // "R" (82)
    (KEY_MOD_LSHIFT << 8) | KEY_S,             // "S" (83)
    (KEY_MOD_LSHIFT << 8) | KEY_T,             // "T" (84)
    (KEY_MOD_LSHIFT << 8) | KEY_U,             // "U" (85)
    (KEY_MOD_LSHIFT << 8) | KEY_V,             // "V" (86)
    (KEY_MOD_LSHIFT << 8) | KEY_Z,             // "W" (87)
    (KEY_MOD_LSHIFT << 8) | KEY_X,             // "X" (88)
    (KEY_MOD_LSHIFT << 8) | KEY_Y,             // "Y" (89)
    (KEY_MOD_LSHIFT << 8) | KEY_W,             // "Z" (90)
    (KEY_MOD_RALT << 8) | KEY_5,               // "[" (91) - left bracket (AltGr+5)
    (KEY_MOD_RALT << 8) | KEY_8,               // "\\" (92) - backslash (AltGr+8)
    (KEY_MOD_RALT << 8) | KEY_MINUS,           // "]" (93) - right bracket (AltGr+-)
    (KEY_MOD_RALT << 8) | KEY_9,               // "^" (94) - caret (AltGr+9)
    KEY_8,                              // "_" (95) - underscore
    (KEY_MOD_RALT << 8) | KEY_7,               // "`" (96) - backtick/grave accent (AltGr+7)
    KEY_Q,                              // "a" (97)
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
    KEY_SEMICOLON,                      // "m" (109)
    KEY_N,                              // "n" (110)
    KEY_O,                              // "o" (111)
    KEY_P,                              // "p" (112)
    KEY_A,                              // "q" (113)
    KEY_R,                              // "r" (114)
    KEY_S,                              // "s" (115)
    KEY_T,                              // "t" (116)
    KEY_U,                              // "u" (117)
    KEY_V,                              // "v" (118)
    KEY_Z,                              // "w" (119)
    KEY_X,                              // "x" (120)
    KEY_Y,                              // "y" (121)
    KEY_W,                              // "z" (122)
    (KEY_MOD_RALT << 8) | KEY_4,               // "{" (123) - left brace (AltGr+4)
    (KEY_MOD_RALT << 8) | KEY_6,               // "|" (124) - pipe (AltGr+6)
    (KEY_MOD_RALT << 8) | KEY_EQUAL,           // "}" (125) - right brace (AltGr+=)
    (KEY_MOD_RALT << 8) | KEY_2,               // "~" (126) - tilde (AltGr+2)
};