#include <stdlib.h>
#include <string.h>
#include "file_handling.h"
FILE *p_file;
FILE *p_file_result;

void open_file(){
    char file_name[100], file_name_result[100];
    printf("Enter file to open:");
    scanf("%s", file_name);
    p_file = fopen(file_name, "r");

    printf("Enter file to write:");
    scanf("%s", file_name_result);
    p_file_result = fopen(file_name_result, "w");

    if (p_file == NULL){
        perror("Error opening file to read");
        exit(1);
    }
    if (p_file_result == NULL){
        perror("Error opening file to write");
        exit(1);
    }
}