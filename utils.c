/*
*Multi-Hello-World: Common utility library.
*Copyright (C) 2026 liavunn
* 
*This file contains the implementation of helper functions.s                               
*Full documentastion and license details are located in utils,h.
*/


#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "utils.h"


// === string ===


// Convert uppercase to lowercase.
int ToLowercase(char* str) {
  if (str == NULL) {
    return -1;
  }

  for (size_t i = 0; str[i] != '\0'; ++i) {
    str[i] = (char)tolower((unsigned char)str[i]);
  }
  return 0;
}

// Removes all whitespace characters from the string.
int RemoveAllWhitespace(char* str) {
  if (str == NULL) {
    return -1;
  }

  char* j = str;
  for (const char* i = str; *i  != '\0'; ++i) {
    if (!isspace((unsigned char)*i)) {
      *j = *i;
      ++j;
    }
  }
  *j = '\0';

  return 0;
}

// Merges two strings into one, inserting a '|' separator in between.
int CombineParts(char* dest, size_t dest_size, const char* front, const char* back) {
  if (dest == NULL || front == NULL || back == NULL || dest_size == 0) {
  return -1;
  }

  int str_len = snprintf(dest, dest_size, "%s|%s", front, back); 
  if (str_len < 0 || (size_t)str_len >= dest_size) {
  return -2;
  }

  return 0;
}

// Fetches an input string from the user.
int FetchUserInput(char* buffer, size_t buffer_size) {
  if (fgets(buffer, (int)buffer_size, stdin) == NULL) {
    return -1;
  }
  
  size_t str_len = strlen(buffer);
  while (str_len != 0 && (buffer[str_len - 1] == '\n' || buffer[str_len -1] == '\r')) {
    buffer[--str_len] = '\0';
  }

  return 0;
}


// === system ===


// Implements system country code retrieval via the standard C locale library.
void GetSystemCountryCode(char* buffer, size_t buffer_size) {
  char* system_locale = setlocale(LC_CTYPE, "");

  if (system_locale != NULL) {
    snprintf(buffer, buffer_size, "%s", system_locale);
    ToLowercase(buffer);
  } else {
    snprintf(buffer, buffer_size, "en_us");
  }
}


// === file ===


// Creates a file with the name specified by the argument.
int CreateFile(const char* filename) {
  if (filename == NULL) {
    return -1;
  }

  FILE* file_ptr = fopen(filename, "w");
  if (file_ptr == NULL) {
    return -1;
  }

  fclose(file_ptr);

  return 0;
}


