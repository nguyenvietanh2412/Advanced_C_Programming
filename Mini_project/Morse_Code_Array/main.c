#include <stdio.h>
#include "morse_code.h"

int main() {
    char text[100], morse[100];
    
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("\n");
    
    encode_to_morse(text);
    
    printf("Enter morse: ");
    fgets(morse, sizeof(morse), stdin);
    morse[strcspn(morse, "\n")] = '\0';
    
    decode_from_morse(morse);
    
    return 0;
}
