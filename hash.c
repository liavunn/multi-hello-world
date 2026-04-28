/*
* Multi-Hello-World: General Hash Table Implementation (Chaining).
* Copyright (C) 2026 liavunn
* 
* This file contains the implementation of functions to handle the sequence table
* for managing and parsing INI configuration files.
* Full documentation and license details are located in hash.h.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

Node* hash_table[kHashSize] = {NULL};

// DJB2 hash algorithm: generates a hash value for the given string.
static unsigned long HashFunc(char* str) {
  unsigned long hash = 5381;
  int c;
  while ((c = *str++)) {
    hash = ((hash << 5) + hash) + c;
  }
  return hash;
}

// Inserts a key-value pair into the hash table.
int HashInsert(const char* section, const char* key, const char* value, size_t value_len) {
  char composite_key[256] = {0};
  snprintf(composite_key, sizeof(composite_key), "%s|%s", section, key);
  size_t composite_key_str_len = strlen(composite_key);

  unsigned long hash = HashFunc(composite_key);
  unsigned long index = hash % kHashSize;

  // Check if key already exists to update value.
  if (hash_table[index] != NULL) {
    Node* current = hash_table[index];

    while (current != NULL) {
      if (hash == current->hash && composite_key_str_len == current->composite_key_str_len && 
          memcmp(current->composite_key, composite_key, composite_key_str_len) == 0) {
	char* new_value = calloc(1, value_len + 1);

        if (new_value == NULL) {
          return -1;
	}

        memcpy(new_value, value, value_len);
        new_value[value_len] = '\0';

        free(current->value);

        current->value = new_value;
	current->value_len = value_len;

	return 0;
      }

      current = current->next;
    }
  }

  // Create a new node if key was not found.
  Node* newNode = calloc(1, sizeof(Node));

  if (newNode == NULL) {
  return -1;
  }

  newNode->composite_key = calloc(1, composite_key_str_len + 1); 

  if (newNode->composite_key == NULL) {
  free(newNode);
  return -1;
  }
  newNode->value = calloc(1, value_len + 1);

  memcpy(newNode->composite_key, composite_key, composite_key_str_len);
  newNode->composite_key[composite_key_str_len] = '\0';
  memcpy(newNode->value, value, value_len);
  newNode->value[value_len] = '\0';

  newNode->hash = hash;
  newNode->composite_key_str_len = composite_key_str_len;
  newNode->value_len = value_len;

  newNode->next = hash_table[index];
  hash_table[index] = newNode;

  return 0;
}

// Searches for a value associated with a given key.
char* HashSearch(const char* section, const char* key, char* search_results, size_t search_result_len) {
  if (section == NULL || key == NULL) {
    return NULL;
  }

  char composite_key[256] = {0};
  snprintf(composite_key, sizeof(composite_key), "%s|%s", section, key);
  size_t composite_key_str_len = strlen(composite_key);

  unsigned long hash = HashFunc(composite_key);
  unsigned long index = hash % kHashSize;

  if (hash_table[index] == NULL) {
    return NULL;
  }
  
  Node* current = hash_table[index];

   while (current != NULL) {
      if (hash == current->hash && composite_key_str_len == current->composite_key_str_len && 
          memcmp(current->composite_key, composite_key, composite_key_str_len) == 0 &&
	  current->value_len < search_result_len) {
        snprintf(search_results, current->value_len + 1, "%s", current->value);
	return search_results;
      }

      current = current->next;
    }
  return NULL;
}

// Removes a key-value pair from the hash table.
int HashDelete(const char* section, const char* key) {
  if (key == NULL || section == NULL) {
  return -1;
  }

  char composite_key[256] = {0};
  snprintf(composite_key, sizeof(composite_key), "%s|%s", section, key);
  size_t composite_key_str_len = strlen(composite_key);

  unsigned long hash = HashFunc(composite_key);
  unsigned long index = hash % kHashSize;

  Node* current = hash_table[index];
  Node* prev = NULL;

  while (current != NULL) {
    Node* next = current->next;

    if (composite_key_str_len == current->composite_key_str_len &&
        memcmp(current->composite_key, composite_key, composite_key_str_len) == 0) {
     if (prev == NULL) {
       hash_table[index] = next;
      } else {
        prev->next = next;
      }

      free(current->composite_key);
      free(current->value);
      free(current);
      return 0;
    }
    prev = current;
    current = next;
  }

  return -1;
}

// Frees all memory allocated for the hash table.
void HashFree() {
  for (size_t i = 0; i < kHashSize; ++i) {
  Node* current = hash_table[i];

    while (current != NULL) {
      Node* next = current->next;

      free(current->composite_key);
      free(current->value);
      free(current);

      current = next;
    }
    hash_table[i] = NULL;
  }
}
