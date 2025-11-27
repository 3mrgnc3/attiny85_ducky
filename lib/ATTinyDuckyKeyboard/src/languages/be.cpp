// Belgian AZERTY keyboard layout for ATTiny85


// Based on USB Rubber Ducky be.json mapping
// ASCII characters 32-126 mapped to USB HID keycodes

#include "languages.h"

const uint16_t lang_be[] PROGMEM = {
    KEY_SPACE,                                      // 32 ' '
    KEY_8,                                          // 33 !
    KEY_3,                                          // 34 "
    (KEY_MOD_LSHIFT << 8) | KEY_3,                         // 35 # (Shift+3 on AZERTY)
    KEY_RIGHTBRACE,                                 // 36 $
    (KEY_MOD_LSHIFT << 8) | KEY_APOSTROPHE,                // 37 %
    KEY_1,                                          // 38 &
    KEY_4,                                          // 39 '
    KEY_5,                                          // 40 (
    KEY_MINUS,                                      // 41 )
    (KEY_MOD_LSHIFT << 8) | KEY_RIGHTBRACE,                // 42 *
    KEY_EQUAL,                                      // 43 +
    KEY_M,                                          // 44 ,
    KEY_6,                                          // 45 -
    (KEY_MOD_LSHIFT << 8) | KEY_COMMA,                     // 46 .
    (KEY_MOD_LSHIFT << 8) | KEY_DOT,                       // 47 /
    (KEY_MOD_LSHIFT << 8) | KEY_SEMICOLON,                 // 48 0
    KEY_SEMICOLON,                                  // 49 1
    KEY_APOSTROPHE,                                 // 50 2
    KEY_COMMA,                                      // 51 3
    KEY_GRAVE,                                      // 52 4
    (KEY_MOD_LSHIFT << 8) | KEY_MINUS,                     // 53 5
    KEY_7,                                          // 54 6
    (KEY_MOD_LSHIFT << 8) | KEY_8,                         // 55 7
    KEY_9,                                          // 56 8
    (KEY_MOD_LSHIFT << 8) | KEY_9,                         // 57 9
    KEY_DOT,                                        // 58 :
    KEY_COMMA,                                      // 59 ;
    KEY_102ND,                                      // 60 <
    (KEY_MOD_LSHIFT << 8) | KEY_EQUAL,                     // 61 =
    (KEY_MOD_LSHIFT << 8) | KEY_102ND,                     // 62 >
    (KEY_MOD_LSHIFT << 8) | KEY_M,                         // 63 ?
    (KEY_MOD_RALT << 8) | KEY_APOSTROPHE,           // 64 @ (AltGr+2)
    (KEY_MOD_LSHIFT << 8) | KEY_Q,                         // 65 A
    (KEY_MOD_LSHIFT << 8) | KEY_B,                         // 66 B
    (KEY_MOD_LSHIFT << 8) | KEY_C,                         // 67 C
    (KEY_MOD_LSHIFT << 8) | KEY_D,                         // 68 D
    (KEY_MOD_LSHIFT << 8) | KEY_E,                         // 69 E
    (KEY_MOD_LSHIFT << 8) | KEY_F,                         // 70 F
    (KEY_MOD_LSHIFT << 8) | KEY_G,                         // 71 G
    (KEY_MOD_LSHIFT << 8) | KEY_H,                         // 72 H
    (KEY_MOD_LSHIFT << 8) | KEY_I,                         // 73 I
    (KEY_MOD_LSHIFT << 8) | KEY_J,                         // 74 J
    (KEY_MOD_LSHIFT << 8) | KEY_K,                         // 75 K
    (KEY_MOD_LSHIFT << 8) | KEY_L,                         // 76 L
    (KEY_MOD_LSHIFT << 8) | KEY_SEMICOLON,                 // 77 M
    (KEY_MOD_LSHIFT << 8) | KEY_N,                         // 78 N
    (KEY_MOD_LSHIFT << 8) | KEY_O,                         // 79 O
    (KEY_MOD_LSHIFT << 8) | KEY_P,                         // 80 P
    (KEY_MOD_LSHIFT << 8) | KEY_A,                         // 81 Q
    (KEY_MOD_LSHIFT << 8) | KEY_R,                         // 82 R
    (KEY_MOD_LSHIFT << 8) | KEY_S,                         // 83 S
    (KEY_MOD_LSHIFT << 8) | KEY_T,                         // 84 T
    (KEY_MOD_LSHIFT << 8) | KEY_U,                         // 85 U
    (KEY_MOD_LSHIFT << 8) | KEY_V,                         // 86 V
    (KEY_MOD_LSHIFT << 8) | KEY_Z,                         // 87 W
    (KEY_MOD_LSHIFT << 8) | KEY_X,                         // 88 X
    (KEY_MOD_LSHIFT << 8) | KEY_Y,                         // 89 Y
    (KEY_MOD_LSHIFT << 8) | KEY_W,                         // 90 Z
    (KEY_MOD_RALT << 8) | KEY_5,                    // 91 [ (AltGr+5)
    (KEY_MOD_RALT << 8) | KEY_102ND,                // 92 \ (AltGr+<)
    (KEY_MOD_RALT << 8) | KEY_MINUS,                // 93 ] (AltGr+))
    (KEY_MOD_LSHIFT << 8) | KEY_7,                         // 94 ^
    (KEY_MOD_LSHIFT << 8) | KEY_6,                         // 95 _
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
    (KEY_MOD_LSHIFT << 8) | KEY_EQUAL                      // 126 ~
};