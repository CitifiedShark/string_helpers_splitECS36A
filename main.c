#include <stdio.h>
#include <stdlib.h>
#include "string_helpers.h"

void print_strings( char**  strings, int num_strings);
void delete_strings(char** strings, int num_strings);

void print_strings( char**  strings, int num_strings){
    for(int i = 0; i < num_strings; ++i){
        printf("%d. %s\n", i + 1, strings[i]);
    }
}

void delete_strings(char** strings, int num_strings){
    for(int i = 0; i < num_strings; ++i){
        free(strings[i]);
    }
    free(strings);
}



int main(){

    char* string_to_split;
    char* delimeter;

    char** strings;
    int num_strings;

    printf("Enter the string to be broken apart: ");
    string_to_split = read_any_len_line();
    
    printf("Enter the string to split by: ");
    delimeter = read_any_len_line();

    split(string_to_split, delimeter, &strings, &num_strings);

    free(string_to_split);
    free(delimeter);

    print_strings(strings, num_strings);

    delete_strings(strings, num_strings);


    return 0; 
}