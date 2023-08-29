#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "caesar_cipher.h"

// Function to validate and retrieve a valid encryption shift
int check_encrypting_shift()
{
    float shift;
    printf("Encrypting shift: ");
    
    // Loop until a valid negative integer input is provided
    while (scanf("%f", &shift) != 1 || (shift < 0 && shift > -26) || shift - (int)shift != 0) 
    {
        printf("Invalid encrypting shift. Enter again:\nEncrypting shift: ");
        while (getchar() != '\n');
    }
    return (int)shift;
}

// Function to validate and retrieve a valid decryption shift
int check_decrypting_shift()
{
    float shift;
    printf("Decrypting shift: ");
    
    // Loop until a valid negative integer input is provided
    while (scanf("%f", &shift) != 1 || (shift < 0 && shift > -26) || shift - (int)shift != 0) 
    {
        printf("Invalid decrypting shift. Enter again:\nDecrypting shift: ");
        while (getchar() != '\n');
    }
    return (int)shift;
}

// Function to perform the Caesar cipher encryption/decryption for a character
char convert_caesar_cipher(char c, int shift)
{
    if (isalpha(c))
    {
        c = toupper(c);
        char base = 'A';
        c = (c - base + shift + 26) % 26 + base; // Shifted value [0-25]
    }
    return c;
}

// Function to perform Caesar cipher encryption/decryption on a file
void encrypt_and_decrypt(int shift)
{
    FILE *p_file;
    FILE *p_file_result;
    char p_file_name[100];
    char p_file_name_result[100];

    // Prompt user for input and output file names
    printf("Enter file to open: ");
    scanf("%s", p_file_name);
    printf("Enter file to save result: ");
    scanf("%s", p_file_name_result);

    // Open input and output files
    p_file = fopen("encrypt.txt", "r");
    p_file_result = fopen("decrypt.txt", "w");

    // Check if files are opened successfully
    if (p_file == NULL)
    {
        perror("Error opening input file");
        exit(1);
    }
    if (p_file_result == NULL)
    {
        perror("Error opening output file");
        exit(1);
    }
    
    // Process each character in the input file
    char c;
    while ((c = fgetc(p_file)) != EOF)
    {
        char encrypt_c = convert_caesar_cipher(c, shift);
        
        // Write encrypted/decrypted character to the output file
        if (fputc(encrypt_c, p_file_result) == EOF)
        {
            printf("Error writing to file.");
            exit(1);
        }
    }
    
    // Close files
    fclose(p_file);
    fclose(p_file_result);
}
