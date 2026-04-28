/*
* Multi-Hello-World: Sequence Table Implementation for INI configuration files.
* Copyright (C) 2026 liavunn
* 
* This file contains the implementation of functions to handle the sequence table
* for managing and parsing INI configuration files.
* Full documentation and license details are located in config.h.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hash.h"
#include "utils.h"

extern Node* hash_table[];

// Checks if a line should be ignored during parsing.
int ShouldSkipLine(const char* line_buffer) {
  if (line_buffer == NULL || line_buffer[0] == '\0') {
    return 1;
  }

  if (line_buffer[0] == '[') {
    char* right_bracket = strchr(line_buffer, ']');
    if (right_bracket == NULL || right_bracket <= line_buffer +1) {
      return 1;
    }

    return 0;
  }

  if (strchr(line_buffer, '=') == NULL) {
    return 1;
  }

  return 0;
}

// Loads configuration pairs from a file into the hash table.
int LoadConfig(const char* filename) {
  if (filename == NULL) {
    return -1;
  }

  FILE* ini_file = fopen(filename, "r");
  if (ini_file == NULL) {
    return -2;
  }

  char line_buffer[512] = {0};
  int count = 0;
  char* current_section = NULL;
  while (fgets(line_buffer, sizeof(line_buffer), ini_file) != NULL) {
    RemoveAllWhitespace(line_buffer);

    if (ShouldSkipLine(line_buffer)) {
      continue;
    }

    if (line_buffer[0] == '[') {
      char* right_bracket = strchr(line_buffer, ']');
      if (right_bracket != NULL) {
        *right_bracket = '\0';
        }

      if (current_section != NULL) {
	free(current_section);
	}

      if (right_bracket != NULL) {
        current_section = strdup(line_buffer + 1);
        continue;
      }
    }

    char* equals_sign = strchr(line_buffer, '=');
    *equals_sign = '\0';

    char* key = line_buffer;
    char* value = equals_sign + 1;

    char* section = current_section;
    int value_len = strlen(value);

    ToLowercase(section);
    ToLowercase(key);

    HashInsert(section, key, value, value_len);

    ++count;
  }
  fclose(ini_file);

  return count;
}

// Writes all current hash table entries to a configuration file.
int SaveConfig(const char* filename) {
  if (filename == NULL) {
    return -1;
  }

  FILE* ini_file = fopen(filename, "w");
  if (ini_file == NULL) {
    return -1;
  }

  
  for (size_t i = 0; i < kHashSize; ++i) {

    Node* current = hash_table[i];
      while (current != NULL) {
        Node* next = current->next;

        char* pipe_position = strchr(current->composite_key, '|');
        if (pipe_position != NULL) {
          *pipe_position = '\0';
          char* section = current->composite_key;
          char* key = pipe_position + 1;

          fprintf(ini_file, "[%s]\n", section);
          fprintf(ini_file, "%s=%s\n\n", key, current->value);

          *pipe_position = '|';
        }

        current = next;
      }
    }

  fclose(ini_file);

  return 0;
}

// Removes a key from the hash table and synchronizes the change to the file.
int DeleteConfig(const char* filename, const char* section, const char* key) {
  if (filename == NULL || section == NULL || key == NULL) {
    return -1;
  }
  

  if (HashDelete(section, key) == 0) {
  SaveConfig(filename);
  } else {
  return -1;
  }

  return 0;
}
