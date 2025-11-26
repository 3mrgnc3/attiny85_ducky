// Romanian keyboard layout
// Standard Romanian QWERTY layout
// Based on standard Romanian keyboard layout specifications

#include "extendedLanguages.h"

const uint16_t lang_ro[] PROGMEM = {
    KEY_SPACE,                                      // 32
    KEY_1 | KEY_MOD_LSHIFT,                        // 33 !
    KEY_2 | KEY_MOD_LSHIFT,                        // 34 "
    KEY_3 | KEY_MOD_LSHIFT,                        // 35 #
    KEY_4 | KEY_MOD_LSHIFT,                        // 36 $
    KEY_5 | KEY_MOD_LSHIFT,                        // 37 %
    KEY_7 | KEY_MOD_LSHIFT,                        // 38 &
    KEY_APOSTROPHE,                                 // 39 '
    KEY_9 | KEY_MOD_LSHIFT,                        // 40 (
    KEY_0 | KEY_MOD_LSHIFT,                        // 41 )
    KEY_8 | KEY_MOD_LSHIFT,                        // 42 *
    KEY_EQUAL | KEY_MOD_LSHIFT,                    // 43 +
    KEY_COMMA,                                      // 44 ,
    KEY_SLASH,                                      // 45 -
    KEY_DOT,                                        // 46 .
    KEY_SLASH | KEY_MOD_LSHIFT,                    // 47 /
    KEY_0,                                          // 48 0
    KEY_1,                                          // 49 1
    KEY_2,                                          // 50 2
    KEY_3,                                          // 51 3
    KEY_4,                                          // 52 4
    KEY_5,                                          // 53 5
    KEY_6,                                          // 54 6
    KEY_7,                                          // 55 7
    KEY_8,                                          // 56 8
    KEY_9,                                          // 57 9
    KEY_DOT | KEY_MOD_LSHIFT,                      // 58 :
    KEY_COMMA | KEY_MOD_LSHIFT,                    // 59 ;
    KEY_102ND,                                      // 60 <
    KEY_EQUAL,                                      // 61 =
    KEY_102ND | KEY_MOD_LSHIFT,                    // 62 >
    KEY_MINUS | KEY_MOD_LSHIFT,                    // 63 ?
    (KEY_MOD_RALT << 8) | KEY_2,                   // 64 @ (AltGr+2)
    KEY_A | KEY_MOD_LSHIFT,                        // 65 A
    KEY_B | KEY_MOD_LSHIFT,                        // 66 B
    KEY_C | KEY_MOD_LSHIFT,                        // 67 C
    KEY_D | KEY_MOD_LSHIFT,                        // 68 D
    KEY_E | KEY_MOD_LSHIFT,                        // 69 E
    KEY_F | KEY_MOD_LSHIFT,                        // 70 F
    KEY_G | KEY_MOD_LSHIFT,                        // 71 G
    KEY_H | KEY_MOD_LSHIFT,                        // 72 H
    KEY_I | KEY_MOD_LSHIFT,                        // 73 I
    KEY_J | KEY_MOD_LSHIFT,                        // 74 J
    KEY_K | KEY_MOD_LSHIFT,                        // 75 K
    KEY_L | KEY_MOD_LSHIFT,                        // 76 L
    KEY_M | KEY_MOD_LSHIFT,                        // 77 M
    KEY_N | KEY_MOD_LSHIFT,                        // 78 N
    KEY_O | KEY_MOD_LSHIFT,                        // 79 O
    KEY_P | KEY_MOD_LSHIFT,                        // 80 P
    KEY_Q | KEY_MOD_LSHIFT,                        // 81 Q
    KEY_R | KEY_MOD_LSHIFT,                        // 82 R
    KEY_S | KEY_MOD_LSHIFT,                        // 83 S
    KEY_T | KEY_MOD_LSHIFT,                        // 84 T
    KEY_U | KEY_MOD_LSHIFT,                        // 85 U
    KEY_V | KEY_MOD_LSHIFT,                        // 86 V
    KEY_W | KEY_MOD_LSHIFT,                        // 87 W
    KEY_X | KEY_MOD_LSHIFT,                        // 88 X
    KEY_Y | KEY_MOD_LSHIFT,                        // 89 Y
    KEY_Z | KEY_MOD_LSHIFT,                        // 90 Z
    (KEY_MOD_RALT << 8) | KEY_LEFTBRACE,           // 91 [ (AltGr+[)
    (KEY_MOD_RALT << 8) | KEY_BACKSLASH,           // 92 \ (AltGr+\)
    (KEY_MOD_RALT << 8) | KEY_RIGHTBRACE,          // 93 ] (AltGr+])
    KEY_SEMICOLON | KEY_MOD_LSHIFT,                // 94 ^
    KEY_MINUS,                                      // 95 _
    KEY_GRAVE,                                      // 96 `
    KEY_A,                                          // 97 a
    KEY_B,                                          // 98 b
    KEY_C,                                          // 99 c
    KEY_D,                                          // 100 d
    KEY_E,                                          // 101 e
    KEY_F,                                          // 102 f
    KEY_G,                                          // 103 g
    KEY_H,                                          // 104 h
    KEY_I,                                          // 105 i
    KEY_J,                                          // 106 j
    KEY_K,                                          // 107 k
    KEY_L,                                          // 108 l
    KEY_M,                                          // 109 m
    KEY_N,                                          // 110 n
    KEY_O,                                          // 111 o
    KEY_P,                                          // 112 p
    KEY_Q,                                          // 113 q
    KEY_R,                                          // 114 r
    KEY_S,                                          // 115 s
    KEY_T,                                          // 116 t
    KEY_U,                                          // 117 u
    KEY_V,                                          // 118 v
    KEY_W,                                          // 119 w
    KEY_X,                                          // 120 x
    KEY_Y,                                          // 121 y
    KEY_Z,                                          // 122 z
    (KEY_MOD_RALT << 8) | KEY_LEFTBRACE | KEY_MOD_LSHIFT,   // 123 { (AltGr+Shift+[)
    (KEY_MOD_RALT << 8) | KEY_BACKSLASH | KEY_MOD_LSHIFT,   // 124 | (AltGr+Shift+\)
    (KEY_MOD_RALT << 8) | KEY_RIGHTBRACE | KEY_MOD_LSHIFT,  // 125 } (AltGr+Shift+])
    KEY_GRAVE | KEY_MOD_LSHIFT                     // 126 ~
};
