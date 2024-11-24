
#include "string_helpers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



void split(char* string, const char* const delimiter,
           char** *splits, int *len){
    /*
      Split string on delimiter into an array of strings.
      @param string: the string to split
      @param delimiter: the delimiter to split on
      @output_param splits: The output array to store the strings 
      into. Assume the value at *splits is uninitialized.   
      @output_param len: The number of strings in splits.
        Assume the value at *len is uninitialized.
    */
  char* start_substring = string; // We know there is a string before the first delimiter is spotted
  char* end_substring;
  int substring_array = 0;

  // Count how many substrings there are 
  *len = 1;
  while ((end_substring = strstr(start_substring, delimiter)) != NULL) {

    (*len)++;
    start_substring = end_substring + strlen(delimiter); // Iterate to the end of the delimiter
  }

  // Allocate memory for splits
  *splits = (char**)malloc((*len) * sizeof(char*));

  start_substring = string;
  // Allocate memory for the number of array of strings and the length of the substring
  // Also start adding the substring to an array
  while ((end_substring = strstr(start_substring, delimiter)) != NULL) {

    int length_substring = end_substring - start_substring;
    
    (*splits)[substring_array] = (char*)malloc(length_substring + 1); // +1 Account for the null character too
    strncpy((*splits)[substring_array], start_substring, length_substring); // Then we allocate the substring into splits
    
    (*splits)[substring_array][length_substring] = '\0'; // We make the end the null character to indicate ending of string
   
    substring_array++; // We iterate to the next array
    start_substring = end_substring + strlen(delimiter); // Move over to the end of the delimiter
  }

  // The last substring after the final delimiter
  (*splits)[substring_array] = (char*)malloc(strlen(start_substring) + 1); // Once again accounting for null character
  strcpy((*splits)[substring_array], start_substring);

}

char* read_any_len_line() {
    /*
    Read a line of any length from the user input. 
    @returns: The next line of characters from the input stream.
    The newline character, while read, is not included in the returned string.
    @modifies: stdin
    */

  int size = 100;
  char* line = malloc(size);
  int length = 0;
  
  while (fgets(line + length, size - length, stdin)) {
  
    length += strlen(line + length);

    if (line[length - 1] == '\n') {
      line[length - 1] = '\0';
      return line;
    }
    
    size = size *  2;
    line = realloc(line, size);
  }

  return line;
}



