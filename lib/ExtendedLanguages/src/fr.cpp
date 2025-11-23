#include "extendedLanguages.h"

// French (AZERTY) keyboard layout
// Based on standard French AZERTY layout
// Characters are mapped from ASCII 32 (space) to ASCII 126 (~)
const uint16_t lang_fr[] PROGMEM = {
    KEY_SPACE,                          // " " (32) - space
    KEY_SLASH,                          // "!" (33) - exclamation
    KEY_3,                              // """ (34) - double quote
    KEY_3 | KEY_MOD_RALT,               // "#" (35) - hash/number sign (AltGr+3)
    KEY_RIGHTBRACE,                     // "$" (36) - dollar
    KEY_APOSTROPHE | KEY_MOD_LSHIFT,    // "%" (37) - percent
    KEY_1,                              // "&" (38) - ampersand
    KEY_4,                              // "'" (39) - single quote/apostrophe
    KEY_5,                              // "(" (40) - left parenthesis
    KEY_MINUS,                          // ")" (41) - right parenthesis
    KEY_BACKSLASH,                      // "*" (42) - asterisk
    KEY_EQUAL | KEY_MOD_LSHIFT,         // "+" (43) - plus
    KEY_M,                              // "," (44) - comma
    KEY_6,                              // "-" (45) - minus/hyphen
    KEY_COMMA | KEY_MOD_LSHIFT,         // "." (46) - period/dot
    KEY_DOT | KEY_MOD_LSHIFT,           // "/" (47) - forward slash
    KEY_0 | KEY_MOD_LSHIFT,             // "0" (48)
    KEY_1 | KEY_MOD_LSHIFT,             // "1" (49)
    KEY_2 | KEY_MOD_LSHIFT,             // "2" (50)
    KEY_3 | KEY_MOD_LSHIFT,             // "3" (51)
    KEY_4 | KEY_MOD_LSHIFT,             // "4" (52)
    KEY_5 | KEY_MOD_LSHIFT,             // "5" (53)
    KEY_6 | KEY_MOD_LSHIFT,             // "6" (54)
    KEY_7 | KEY_MOD_LSHIFT,             // "7" (55)
    KEY_8 | KEY_MOD_LSHIFT,             // "8" (56)
    KEY_9 | KEY_MOD_LSHIFT,             // "9" (57)
    KEY_DOT,                            // ":" (58) - colon
    KEY_COMMA,                          // ";" (59) - semicolon
    KEY_102ND,                          // "<" (60) - less than
    KEY_EQUAL,                          // "=" (61) - equals
    KEY_102ND | KEY_MOD_LSHIFT,         // ">" (62) - greater than
    KEY_M | KEY_MOD_LSHIFT,             // "?" (63) - question mark
    KEY_0 | KEY_MOD_RALT,               // "@" (64) - at sign (AltGr+0)
    KEY_Q | KEY_MOD_LSHIFT,             // "A" (65)
    KEY_B | KEY_MOD_LSHIFT,             // "B" (66)
    KEY_C | KEY_MOD_LSHIFT,             // "C" (67)
    KEY_D | KEY_MOD_LSHIFT,             // "D" (68)
    KEY_E | KEY_MOD_LSHIFT,             // "E" (69)
    KEY_F | KEY_MOD_LSHIFT,             // "F" (70)
    KEY_G | KEY_MOD_LSHIFT,             // "G" (71)
    KEY_H | KEY_MOD_LSHIFT,             // "H" (72)
    KEY_I | KEY_MOD_LSHIFT,             // "I" (73)
    KEY_J | KEY_MOD_LSHIFT,             // "J" (74)
    KEY_K | KEY_MOD_LSHIFT,             // "K" (75)
    KEY_L | KEY_MOD_LSHIFT,             // "L" (76)
    KEY_SEMICOLON | KEY_MOD_LSHIFT,     // "M" (77)
    KEY_N | KEY_MOD_LSHIFT,             // "N" (78)
    KEY_O | KEY_MOD_LSHIFT,             // "O" (79)
    KEY_P | KEY_MOD_LSHIFT,             // "P" (80)
    KEY_A | KEY_MOD_LSHIFT,             // "Q" (81)
    KEY_R | KEY_MOD_LSHIFT,             // "R" (82)
    KEY_S | KEY_MOD_LSHIFT,             // "S" (83)
    KEY_T | KEY_MOD_LSHIFT,             // "T" (84)
    KEY_U | KEY_MOD_LSHIFT,             // "U" (85)
    KEY_V | KEY_MOD_LSHIFT,             // "V" (86)
    KEY_Z | KEY_MOD_LSHIFT,             // "W" (87)
    KEY_X | KEY_MOD_LSHIFT,             // "X" (88)
    KEY_Y | KEY_MOD_LSHIFT,             // "Y" (89)
    KEY_W | KEY_MOD_LSHIFT,             // "Z" (90)
    KEY_5 | KEY_MOD_RALT,               // "[" (91) - left bracket (AltGr+5)
    KEY_8 | KEY_MOD_RALT,               // "\\" (92) - backslash (AltGr+8)
    KEY_MINUS | KEY_MOD_RALT,           // "]" (93) - right bracket (AltGr+-)
    KEY_9 | KEY_MOD_RALT,               // "^" (94) - caret (AltGr+9)
    KEY_8,                              // "_" (95) - underscore
    KEY_7 | KEY_MOD_RALT,               // "`" (96) - backtick/grave accent (AltGr+7)
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
    KEY_4 | KEY_MOD_RALT,               // "{" (123) - left brace (AltGr+4)
    KEY_6 | KEY_MOD_RALT,               // "|" (124) - pipe (AltGr+6)
    KEY_EQUAL | KEY_MOD_RALT,           // "}" (125) - right brace (AltGr+=)
    KEY_2 | KEY_MOD_RALT,               // "~" (126) - tilde (AltGr+2)
};
