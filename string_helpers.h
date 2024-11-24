#ifndef STRING_HELPERS_H
    #define STRING_HELPERS_H


    void split(char* string, const char* const delimiter,
            char** *splits, int *len);
    char* read_any_len_line();


#endif