#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "morse_code.h"
#define MAX_LEN 1000
Node *create_node(char data){
    Node *p_new_node = (Node *)malloc(sizeof(Node));
    p_new_node->data = data;
    p_new_node->left = p_new_node->right = NULL;
    return p_new_node;
}
void insert_node(Node *root, char letter, char *code) {
    Node *current = root;
    for (int i = 0; i < strlen(code); i++) {
        if (code[i] == '.') {
            if (current->left == NULL)
                current->left = create_node('\0');
            current = current->left;
        } else {
            if (current->right == NULL)
                current->right = create_node('\0');
            current = current->right;
        }
    }
    current->data = letter;
}
// Node *insert_node(Node *p_root, char character, char *p_morse_code) {
//     if (p_root == NULL) {
//         p_root = create_node('\0');
//     }

//     if (strlen(p_morse_code) == 0) {
//         p_root->data = character;
//     } 
//     else {
//         if (p_morse_code[0] == '.') {
//             p_root->left = insert_node(p_root->left, character, p_morse_code + 1);
//         } else {
//             p_root->right = insert_node(p_root->right, character, p_morse_code + 1);
//         }
//     }
//     return p_root;
// }
void build_tree(Node *p_root) {
    FILE *p_file;
    p_file = fopen("morse.txt","r");
    char character, morse_code[100];
    while (fscanf(p_file, "%c %s\n", &character, morse_code) != EOF){
        insert_node(p_root, character, morse_code);
    }
    fclose(p_file);
    // char character[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    // char *p_morse_code[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    //                        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-",
    //                        "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-",
    //                        ".....", "-....", "--...", "---..", "----." };

    // for (int i = 0; i < 36; i++) {
    //     p_root = insert_node(p_root, character[i], p_morse_code[i]);
    // }
}
void decode_from_morse(Node *p_root, FILE *p_file) {
  
    Node *p_current = p_root;
    char p_str[100];
    // file_to_be_decoded.txt
    while(fgets(p_str, 100, p_file) != NULL){ 
        for (int i = 0; i < strlen(p_str); i++) {
            if (p_str[i] == '.')
                p_current = p_current->left;
            else if (p_str[i] == '-')
                p_current = p_current->right;
            else if (p_str[i] == ' '){
                if (p_current != p_root) {
                    printf("%c", p_current->data);
                    p_current = p_root;
                }
                if (p_str[i+1] == '/') {
                    printf(" ");
                }
            }
            else if (p_str[i] == '\n'){
                printf("%c\n", p_current->data);
                p_current = p_root;
            }
        }
        if (p_current != p_root) {
        printf("%c", p_current->data);
        p_current = p_root;
        }
    }
    fclose(p_file);
}
