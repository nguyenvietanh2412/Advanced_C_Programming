#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "morse_code.h"
#define MAX_LEN 1000

Node *create_node(char data){
    Node *p_new_node = (Node *)malloc(sizeof(Node));
    p_new_node->data = data;
    p_new_node->left = p_new_node->right = NULL;
    return p_new_node;
}
bool is_alpha_character(char *text){
    int i;
    for (i = 0; text[i] != '\0'; i++){
        if (!isalpha(text[i]) && !isspace(text[i]) && !isalnum(text[i])){
            return false;
        }
    }
    return true;
}
void check_alphabet(char *text){
    printf("Enter a string: ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = '\0';
    while(strlen(text) == 0 || is_alpha_character(text) == false){
        printf("Invalid string. Enter again.\nEnter a string:");
        fgets(text, 100, stdin);
        text[strcspn(text, "\n")] = '\0';
    }
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
void build_tree(Node *p_root) {
    FILE *p_file;
    p_file = fopen("morse.txt","r");
    char character, morse_code[100];
    while (fscanf(p_file, "%c %s\n", &character, morse_code) != EOF){
        insert_node(p_root, character, morse_code);
    }
    fclose(p_file);
}
void search_letter(Node *p_root, char data, char *str){
    int n = strlen(str);
    if (p_root == NULL){
        return;
    }
    if (p_root->data == data){
        printf("%s", data);
    }
    str[n] = '.';
    str[n+1] = '\0';
    search_letter(p_root->left, data, str);
    str[n] = '-';
    search_letter(p_root->right, data, str);
    str[n] = '\0';
}
void encode_to_morse(Node *p_root, char *str){
    int i;
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
            char str[100] = "";
            search_letter(p_root, str[i], str);
        }
        else if (isalnum(str[i])){
            char str[100] = "";
            search_letter(p_root, str[i], str);
        }
        else printf("/ ");
    }
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
