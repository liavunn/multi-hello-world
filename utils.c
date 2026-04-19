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
int to_lowercase(char* str) {
  if (str == NULL) {
    return -1;
  }

  for (size_t i = 0; str[i] != '\0'; ++i) {
    str[i] = (char)tolower((unsigned char)str[i]);
  }
  return 0;
}


// Fetches an input string from the user.
int get_fetch_input(char* buffer, size_t buffer_size) {
  if (fgets(buffer, (int)buffer_size, stdin) == NULL) {
    return -1;
  }
  
  size_t str_len = strlen(buffer);
  if (str_len != 0 && buffer[str_len - 1] == '\n') {
    buffer[str_len - 1] = '\0';
  }
  return 0;
}


// === system ===


// Implements system country code retrieval via the standard C locale library.
void get_system_country_code(char* buffer, size_t buffer_size) {
  char* system_locale = setlocale(LC_CTYPE, "");

  if (system_locale != NULL) {
    snprintf(buffer, buffer_size, "%s", system_locale);
    to_lowercase(buffer);
  } else {
    snprintf(buffer, buffer_size, "en_us");
  }
}
