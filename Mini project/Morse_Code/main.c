#include "morse_code.h"
#include <string.h>
int main()
{
    char text[100];
    FILE *p_file;
    printf("Enter file to decode:");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text,"\n")] = '\0';
    p_file = fopen(text, "r");
    Node *root = create_node('\0');
    build_tree(root);
    decode_from_morse(root, p_file);
    return 0;
}
// HERE IS AN EXAMPLE OF CODE THAT NEEDS TO BE DECODED
// .... . .-. . / .. ... / .- -. / . -..- .- -- .--. .-.. . / --- ..-. / -.-. --- -.. . / - .... .- - / -. . . -.. ... / - --- / -... . / -.. . -.-. --- -.. . -..
// TODAY IS A BEAUTIFUL DAY 
// - --- / -.. .- -.-- / .. ... / .- / -... . .- ..- - .. ..-. ..- .-.. / -.. .- -.-- 