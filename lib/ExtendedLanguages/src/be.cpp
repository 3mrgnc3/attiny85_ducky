// Belgian AZERTY keyboard layout for ATTiny85
// Based on USB Rubber Ducky be.json mapping
// ASCII characters 32-126 mapped to USB HID keycodes

#include "extendedLanguages.h"

const uint16_t lang_be[] PROGMEM = {
    KEY_SPACE,                                      // 32 ' '
    KEY_8,                                          // 33 !
    KEY_3,                                          // 34 "
    KEY_3 | KEY_MOD_LSHIFT,                         // 35 # (Shift+3 on AZERTY)
    KEY_RIGHTBRACE,                                 // 36 $
    KEY_APOSTROPHE | KEY_MOD_LSHIFT,                // 37 %
    KEY_1,                                          // 38 &
    KEY_4,                                          // 39 '
    KEY_5,                                          // 40 (
    KEY_MINUS,                                      // 41 )
    KEY_RIGHTBRACE | KEY_MOD_LSHIFT,                // 42 *
    KEY_EQUAL,                                      // 43 +
    KEY_M,                                          // 44 ,
    KEY_6,                                          // 45 -
    KEY_COMMA | KEY_MOD_LSHIFT,                     // 46 .
    KEY_DOT | KEY_MOD_LSHIFT,                       // 47 /
    KEY_SEMICOLON | KEY_MOD_LSHIFT,                 // 48 0
    KEY_SEMICOLON,                                  // 49 1
    KEY_APOSTROPHE,                                 // 50 2
    KEY_COMMA,                                      // 51 3
    KEY_GRAVE,                                      // 52 4
    KEY_MINUS | KEY_MOD_LSHIFT,                     // 53 5
    KEY_7,                                          // 54 6
    KEY_8 | KEY_MOD_LSHIFT,                         // 55 7
    KEY_9,                                          // 56 8
    KEY_9 | KEY_MOD_LSHIFT,                         // 57 9
    KEY_DOT,                                        // 58 :
    KEY_COMMA,                                      // 59 ;
    KEY_102ND,                                      // 60 <
    KEY_EQUAL | KEY_MOD_LSHIFT,                     // 61 =
    KEY_102ND | KEY_MOD_LSHIFT,                     // 62 >
    KEY_M | KEY_MOD_LSHIFT,                         // 63 ?
    (KEY_MOD_RALT << 8) | KEY_APOSTROPHE,           // 64 @ (AltGr+2)
    KEY_Q | KEY_MOD_LSHIFT,                         // 65 A
    KEY_B | KEY_MOD_LSHIFT,                         // 66 B
    KEY_C | KEY_MOD_LSHIFT,                         // 67 C
    KEY_D | KEY_MOD_LSHIFT,                         // 68 D
    KEY_E | KEY_MOD_LSHIFT,                         // 69 E
    KEY_F | KEY_MOD_LSHIFT,                         // 70 F
    KEY_G | KEY_MOD_LSHIFT,                         // 71 G
    KEY_H | KEY_MOD_LSHIFT,                         // 72 H
    KEY_I | KEY_MOD_LSHIFT,                         // 73 I
    KEY_J | KEY_MOD_LSHIFT,                         // 74 J
    KEY_K | KEY_MOD_LSHIFT,                         // 75 K
    KEY_L | KEY_MOD_LSHIFT,                         // 76 L
    KEY_SEMICOLON | KEY_MOD_LSHIFT,                 // 77 M
    KEY_N | KEY_MOD_LSHIFT,                         // 78 N
    KEY_O | KEY_MOD_LSHIFT,                         // 79 O
    KEY_P | KEY_MOD_LSHIFT,                         // 80 P
    KEY_A | KEY_MOD_LSHIFT,                         // 81 Q
    KEY_R | KEY_MOD_LSHIFT,                         // 82 R
    KEY_S | KEY_MOD_LSHIFT,                         // 83 S
    KEY_T | KEY_MOD_LSHIFT,                         // 84 T
    KEY_U | KEY_MOD_LSHIFT,                         // 85 U
    KEY_V | KEY_MOD_LSHIFT,                         // 86 V
    KEY_Z | KEY_MOD_LSHIFT,                         // 87 W
    KEY_X | KEY_MOD_LSHIFT,                         // 88 X
    KEY_Y | KEY_MOD_LSHIFT,                         // 89 Y
    KEY_W | KEY_MOD_LSHIFT,                         // 90 Z
    (KEY_MOD_RALT << 8) | KEY_5,                    // 91 [ (AltGr+5)
    (KEY_MOD_RALT << 8) | KEY_102ND,                // 92 \ (AltGr+<)
    (KEY_MOD_RALT << 8) | KEY_MINUS,                // 93 ] (AltGr+))
    KEY_7 | KEY_MOD_LSHIFT,                         // 94 ^
    KEY_6 | KEY_MOD_LSHIFT,                         // 95 _
    KEY_LEFTBRACE,                                  // 96 `
    KEY_Q,                                          // 97 a
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
    KEY_SEMICOLON,                                  // 109 m
    KEY_N,                                          // 110 n
    KEY_O,                                          // 111 o
    KEY_P,                                          // 112 p
    KEY_A,                                          // 113 q
    KEY_R,                                          // 114 r
    KEY_S,                                          // 115 s
    KEY_T,                                          // 116 t
    KEY_U,                                          // 117 u
    KEY_V,                                          // 118 v
    KEY_Z,                                          // 119 w
    KEY_X,                                          // 120 x
    KEY_Y,                                          // 121 y
    KEY_W,                                          // 122 z
    (KEY_MOD_RALT << 8) | KEY_GRAVE,                // 123 { (AltGr+4)
    (KEY_MOD_RALT << 8) | KEY_SEMICOLON,            // 124 | (AltGr+1)
    (KEY_MOD_RALT << 8) | KEY_EQUAL,                // 125 } (AltGr+=)
    KEY_EQUAL | KEY_MOD_LSHIFT                      // 126 ~
};
