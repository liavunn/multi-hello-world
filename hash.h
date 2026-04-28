/*
* Multi-Hello-World: General Hash Table Implementation (Chaining).
* Copyright (C) 2026 liavunn
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


#ifndef HASH_H_
#define HASH_H_

#define kHashSize 256

//Represents a node in the hash table.
typedef struct Node {
  char* composite_key;
  char* value;

  unsigned long hash;
  size_t composite_key_str_len;
  size_t value_len;

  struct Node* next;
} Node;

// Inserts a key-value pair into the hash table.
//
//   section: The name of the section to categorize the key.
//   key: The string key to identify the data.
//   value: The integer value associated with the key.
//
//   Returns 0 on success, or -1 if memory allocation fails.
int HashInsert(const char* section, const char* key, const char* value, size_t value_len);

// Searches for a value associated with a given key.
//
//   section: The name of the section to categorize the key.
//   key: The string key to look for.
//
//   Returns the pointer to the value if found; 
//   Returns NULL if the key is not found or the hash bucket is empty.
char* HashSearch(const char* section, const char* key, char* search_results, size_t search_results_len);

// Removes a key-value pair from the hash table.
//
//   section: The name of the section to categorize the key.
//   key: The composite string key to be deleted
//
//   Returns 0 on success, or -1 if the key was not found or input was NULL.
int HashDelete(const char* section, const char* key);

// Frees all memory allocated for the hash table.
//
// Cleans up both the nodes and the duplicated key strings.
void HashFree();

#endif // HASH_H_
