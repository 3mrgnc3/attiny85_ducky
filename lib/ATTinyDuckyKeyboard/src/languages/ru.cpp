// Russian ЙЦУКЕН (JCUKEN) keyboard layout for ATTiny85


// Standard Russian keyboard layout for Latin ASCII characters
// ASCII characters 32-126 mapped to USB HID keycodes
// Note: This layout supports typing Latin characters on Russian keyboards

#include "languages.h"

const uint16_t lang_ru[] PROGMEM = {
    KEY_SPACE,                                      // 32 ' '
    (KEY_MOD_LSHIFT << 8) | KEY_1,                         // 33 !
    (KEY_MOD_LSHIFT << 8) | KEY_2,                         // 34 "
    (KEY_MOD_LSHIFT << 8) | KEY_3,                         // 35 #
    (KEY_MOD_LSHIFT << 8) | KEY_4,                         // 36 $
    (KEY_MOD_LSHIFT << 8) | KEY_5,                         // 37 %
    (KEY_MOD_LSHIFT << 8) | KEY_7,                         // 38 &
    KEY_BACKSLASH,                                  // 39 '
    (KEY_MOD_LSHIFT << 8) | KEY_9,                         // 40 (
    (KEY_MOD_LSHIFT << 8) | KEY_0,                         // 41 )
    (KEY_MOD_LSHIFT << 8) | KEY_8,                         // 42 *
    (KEY_MOD_LSHIFT << 8) | KEY_EQUAL,                     // 43 +
    (KEY_MOD_LSHIFT << 8) | KEY_SLASH,                     // 44 ,
    KEY_MINUS,                                      // 45 -
    KEY_SLASH,                                      // 46 .
    KEY_DOT,                                        // 47 /
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
    (KEY_MOD_LSHIFT << 8) | KEY_6,                         // 58 :
    (KEY_MOD_LSHIFT << 8) | KEY_DOT,                       // 59 ;
    (KEY_MOD_LSHIFT << 8) | KEY_COMMA,                     // 60 <
    KEY_EQUAL,                                      // 61 =
    KEY_COMMA,                                      // 62 >
    (KEY_MOD_LSHIFT << 8) | KEY_MINUS,                     // 63 ?
    KEY_APOSTROPHE,                                 // 64 @
    (KEY_MOD_LSHIFT << 8) | KEY_A,                         // 65 A
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
    (KEY_MOD_LSHIFT << 8) | KEY_M,                         // 77 M
    (KEY_MOD_LSHIFT << 8) | KEY_N,                         // 78 N
    (KEY_MOD_LSHIFT << 8) | KEY_O,                         // 79 O
    (KEY_MOD_LSHIFT << 8) | KEY_P,                         // 80 P
    (KEY_MOD_LSHIFT << 8) | KEY_Q,                         // 81 Q
    (KEY_MOD_LSHIFT << 8) | KEY_R,                         // 82 R
    (KEY_MOD_LSHIFT << 8) | KEY_S,                         // 83 S
    (KEY_MOD_LSHIFT << 8) | KEY_T,                         // 84 T
    (KEY_MOD_LSHIFT << 8) | KEY_U,                         // 85 U
    (KEY_MOD_LSHIFT << 8) | KEY_V,                         // 86 V
    (KEY_MOD_LSHIFT << 8) | KEY_W,                         // 87 W
    (KEY_MOD_LSHIFT << 8) | KEY_X,                         // 88 X
    (KEY_MOD_LSHIFT << 8) | KEY_Y,                         // 89 Y
    (KEY_MOD_LSHIFT << 8) | KEY_Z,                         // 90 Z
    KEY_LEFTBRACE,                                  // 91 [
    (KEY_MOD_LSHIFT << 8) | KEY_BACKSLASH,                 // 92 \ (backslash)
    KEY_RIGHTBRACE,                                 // 93 ]
    (KEY_MOD_LSHIFT << 8) | KEY_LEFTBRACE,                 // 94 ^
    (KEY_MOD_LSHIFT << 8) | KEY_MINUS,                     // 95 _
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
    (KEY_MOD_LSHIFT << 8) | KEY_LEFTBRACE,                 // 123 {
    KEY_BACKSLASH,                                  // 124 |
    (KEY_MOD_LSHIFT << 8) | KEY_RIGHTBRACE,                // 125 }
    (KEY_MOD_LSHIFT << 8) | KEY_GRAVE                      // 126 ~
};