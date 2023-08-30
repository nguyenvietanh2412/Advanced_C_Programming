#ifndef MORSE_CODE_H_
#define MORSE_CODE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char data;
    struct node *left, *right;
}Node;

Node *create_node(char data);
void build_tree(Node *root);
void decode_from_morse(Node* root);
void encode_to_morse(Node *p_root);
#endif