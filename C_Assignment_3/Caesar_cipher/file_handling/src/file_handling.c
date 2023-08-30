#include "file_handling.h"
#include <stdlib.h>
FILE *p_file_input;
FILE *p_file_output;
char file_name_output[100];
void open_file(){
    
    char file_name_input[100];
    

    // Prompt user for input and output file names
    printf("Enter file to open: ");
    scanf("%s", file_name_input);
    p_file_input = fopen(file_name_input, "r");
    int ch;
    while ((ch = getc(p_file_input)) != EOF){
        putchar(ch);
    }
    rewind(p_file_input);
    printf("\nEnter file to save result: ");
    scanf("%s", file_name_output);

    // Open input and output files
    
    p_file_output = fopen(file_name_output, "w");

    // Check if files are opened successfully
    if (p_file_input == NULL)
    {
        perror("Error opening input file");
        exit(1);
    }
    if (p_file_output == NULL)
    {
        perror("Error opening output file");
        exit(1);
    }
}