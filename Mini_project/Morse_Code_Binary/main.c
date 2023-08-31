#include "morse_code.h"
#include "file_handling.h"
#include <string.h>
int main()
{
    int choice;
    char text[100];
    Node *p_root = create_node('\0');
    build_tree(p_root);
    // Loop to continuously prompt the user for action
    while(1)
    {
        printf("1. Decode\n");
        printf("2. Encode\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character
        
        switch (choice)
        {
        case 1:
            open_file();
            printf("Decoded message:\n");
            decode_from_morse(p_root);
            printf("\n\n");
            break;
        case 2:
            open_file();
            printf("Encoded message:\n");
            encode_to_morse(p_root);
            printf("\n\n");      
            break;
        case 0:
            // Exit the program when the user selects '0'
            return 0;
            break;
        default:
            // Handle invalid choices gracefully
            printf("Invalid choice. Please select a valid option.\n");
            break;
        }
    }
    
    return 0;
}
// HERE IS AN EXAMPLE OF CODE THAT NEEDS TO BE DECODED
// .... . .-. . / .. ... / .- -. / . -..- .- -- .--. .-.. . / --- ..-. / -.-. --- -.. . / - .... .- - / -. . . -.. ... / - --- / -... . / -.. . -.-. --- -.. . -..
// TODAY IS A BEAUTIFUL DAY 
// - --- / -.. .- -.-- / .. ... / .- / -... . .- ..- - .. ..-. ..- .-.. / -.. .- -.-- 