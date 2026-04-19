/*
*Multi-Hello-World: Header file containing constants and structures.
*Copyright (C) 2026 liavunn
* 
*This program is free software: you can redistribute it and/or modify
*it under the terms of the GNU General Public License as published by
*the Free Software Foundation, either version 3 of the License, or
*(at your option) any later version.
* 
*This program is distributed in the hope that it will be useful,
*but WITHOUT ANY WARRANTY; without even the implied warranty of
*MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*GNU General Public License for more details.
* 
*You should have received a copy of the GNU General Public License
*along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


#ifndef DATA_H_
#define DATA_H_

extern const char* kDefaultCountryCode;

// Holds country code and its greeting message.
typedef struct {
const char* display_country_code;
const char* country_code;
const char* country_greeting;
} Greeting;

// Lookup table for greeting messages.
extern const Greeting kGreetings[];
// Number of entries in the kGreetings table.
extern const size_t kNumGreetings;

// Lookup the country code and return the greeting message.
// Returns NULL if no match is found.
const char* get_greeting(const char* country_code);

// Prompts the user for input, retrieves it, and converts the result to lowercase.
// 
//   buffer: A pointer to the memory (from main) where the input will be stored.
//   buffer_size: The maximum capacity of the buffer to ensure safety.
// 
//   Returns 0 on succerss, or -1 if the input fails or an error occurs.
int get_user_input(char* buffer, size_t read_limit, size_t total_size);


// Display the final greeting message based on the country code in the buffer.
// If the lookup fails, it falls back to the system locale or default code.
// 
//   buffer: The buffer containing the user-provided country code.
//   buffer_size: The total size of the allocated buffer.
int display_final_greeting(char* buffer, size_t buffer_size, char* locale); 

#endif // DATA_H
