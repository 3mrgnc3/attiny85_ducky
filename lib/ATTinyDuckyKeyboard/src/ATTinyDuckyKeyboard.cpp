#include "Arduino.h"
#include "ATTinyDuckyKeyboard.h"
#include "DigiKeyboard.h"
#include <avr/pgmspace.h>

ATTinyDuckyKeyboard::ATTinyDuckyKeyboard(const uint16_t* language) {
    this->setLanguage(language);
}

void ATTinyDuckyKeyboard::_printChar(char c) {
    if (c - 32 < 0) {
        DigiKeyboard.sendKeyStroke(c);
    } else {
        uint16_t code = pgm_read_word_near(_lang + c - 32);
        DigiKeyboard.sendKeyStroke((char)(code & 0xFF), code >> 8);
    }
}

void ATTinyDuckyKeyboard::print(const char str[]) {
    // RAM string
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        _printChar(str[i]);
    }
}

void ATTinyDuckyKeyboard::print(const __FlashStringHelper* str) {
    // PROGMEM string
    const char* p = (const char*)str;
    char c;
    int i = 0;
    while ((c = pgm_read_byte(&p[i++])) != '\0') {
        _printChar(c);
    }
}

void ATTinyDuckyKeyboard::println(const char str[]) {
    this->print(str);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void ATTinyDuckyKeyboard::println(const __FlashStringHelper* str) {
    this->print(str);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void ATTinyDuckyKeyboard::delay(long milli) {
    DigiKeyboard.delay(milli);
}

void ATTinyDuckyKeyboard::sendKeyPress(byte keyPress) {
    DigiKeyboard.sendKeyPress(keyPress);
}

void ATTinyDuckyKeyboard::sendKeyPress(byte keyPress, byte modifiers) {
    DigiKeyboard.sendKeyPress(keyPress, modifiers);
}

void ATTinyDuckyKeyboard::sendKeyStroke(byte keyStroke) {
    DigiKeyboard.sendKeyStroke(keyStroke);
}

void ATTinyDuckyKeyboard::sendKeyStroke(byte keyStroke, byte modifiers) {
    DigiKeyboard.sendKeyStroke(keyStroke, modifiers);
}

void ATTinyDuckyKeyboard::setLanguage(const uint16_t* language) {
    _lang = language;
}
