#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "morse_code.h"

const char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
    ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
    ".--", "-..-", "-.--", "--..",
    "-----", ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----."
};

const char *encode_morse_character(char c) {
    if (isalpha(c)) {
        return morse_code[toupper(c) - 'A'];
    } else if (isdigit(c)) {
        return morse_code[c - '0' + 26];
    } else if (c == ' ') {
        return " ";
    } else {
        return "";
    }
}

void encode_to_morse(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c == ' ') {
            printf(" / ");
        } else {
            printf("%s ", encode_morse_character(c));
        }
    }
    printf("\n");
}

char decode_morse_character(const char *morse) {
    for (int i = 0; i < 36; i++) {
        if (strcmp(morse, morse_code[i]) == 0) {
            if (i < 26) {
                return 'A' + i;
            } else {
                return '0' + i - 26;
            }
        }
    }
    return '\0';
}

void decode_from_morse(const char *morse) {
    int length = strlen(morse);
    int i = 0;

    while (i < length) {
        if (morse[i] == '/') {
            printf(" ");
            i += 2;
        } else {
            char str[10] = "";
            int j = 0;
            while (i < length && morse[i] != ' ') {
                str[j] = morse[i];
                i++;
                j++;
            }
            printf("%c", decode_morse_character(str));
            i++;
        }
    }

    printf("\n");
}