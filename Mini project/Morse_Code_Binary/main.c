#include "morse_code.h"
#include <string.h>
int main()
{
    char code[100], text[100]; 
    FILE *p_file_1, *p_file_2;
    Node *p_root = create_node('\0');
    build_tree(p_root);

    printf("Enter file to decode:");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code,"\n")] = '\0';
    p_file_1 = fopen(code, "r");
    printf("Decoded message:\n");
    decode_from_morse(p_root, p_file_1);
    printf("\n\n");

    printf("Enter file to encode:");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text,"\n")] = '\0';
    p_file_2 = fopen(text, "r");
    printf("Encoded message: ");
    encode_to_morse(p_root, p_file_2);

    return 0;
}
// HERE IS AN EXAMPLE OF CODE THAT NEEDS TO BE DECODED
// .... . .-. . / .. ... / .- -. / . -..- .- -- .--. .-.. . / --- ..-. / -.-. --- -.. . / - .... .- - / -. . . -.. ... / - --- / -... . / -.. . -.-. --- -.. . -..
// TODAY IS A BEAUTIFUL DAY 
// - --- / -.. .- -.-- / .. ... / .- / -... . .- ..- - .. ..-. ..- .-.. / -.. .- -.-- 