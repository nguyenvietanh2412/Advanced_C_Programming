#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "caesar_cipher.h"
#include "file_handling.h"

// Function to validate and retrieve a valid encryption shift
int check_encrypting_shift()
{
    float shift;
    printf("Encrypting shift: ");
    // Loop until a valid negative integer input is provided
    while (scanf("%f", &shift) != 1 || shift <= 0 || shift > 26 || shift - (int)shift != 0) 
    {
        printf("Invalid encrypting shift. Enter again:\nEncrypting shift: ");
        while(getchar() != '\n');
    }
    return (int)shift;
}

// Function to validate and retrieve a valid decryption shift
int check_decrypting_shift()
{
    float shift;
    printf("Decrypting shift: ");
    
    // Loop until a valid negative integer input is provided
    while (scanf("%f", &shift) != 1 || (shift >= 0 || shift < -26) || shift - (int)shift != 0) 
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
    open_file();
    // Process each character in the input file
    char c;
    while ((c = fgetc(p_file_input)) != EOF)
    {
        // printf("%c", c);
        char encrypt_c = convert_caesar_cipher(c, shift);
        // Write encrypted/decrypted character to the output file
        if (fputc(encrypt_c, p_file_output) == EOF)
        {
            printf("Error writing to file.");
            exit(1);
        }
    }

    // Close files
    fclose(p_file_input);
    fclose(p_file_output);
    // Display the content of the output file
    p_file_output = fopen(file_name_output, "r");
    while ((c = fgetc(p_file_output)) != EOF)
    {
        printf("%c", c);
    }
    printf("\n");
    fclose(p_file_output);
}
