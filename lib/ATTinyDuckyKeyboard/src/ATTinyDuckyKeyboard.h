#ifndef ATTINYDUCKYKEYBOAD_H
#define ATTINYDUCKYKEYBOAD_H

#include "Arduino.h"
#include "languages/languages.h"

class ATTinyDuckyKeyboard {
    public:
        ATTinyDuckyKeyboard(const uint16_t* language);
        void print(const char str[]);
        void print(const __FlashStringHelper* str);
        void println(const char str[]);
        void println(const __FlashStringHelper* str);
        void delay(long milli);
        void sendKeyPress(byte keyPress);
        void sendKeyPress(byte keyPress, byte modifiers);
        void sendKeyStroke(byte keyStroke);
        void sendKeyStroke(byte keyStroke, byte modifiers);
        void setLanguage(const uint16_t* language);
    private:
        const uint16_t* _lang;
        void _printChar(char c);
};

#endif
