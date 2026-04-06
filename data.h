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

//Holds country code and its greeting message.
typedef struct {
const char* display_country_code;
const char* country_code;
const char* country_greeting;
} Greeting;

//Lookup table for greeting messages.
extern const Greeting kGreetings[];
//Number of entries in the kGreetings table.
extern const size_t kNumGreetings;

//Lookup the country code and return the greeting message.
//Returns NULL if no match is found.
const char* get_greeting(const char* country_code);

//Retrieve the current system language setting.
//If retrieval fails, defaults to "en_us".
//
//Arguments:
//  buffer: Character array for storing country codes. 
//  buffer_size: Buffer size, recommended to be 6 (e.g., "en_us").
void get_system_country_code(char* buffer, size_t buffer_size);

//Convert uppercase to lowercase.
// 
// Arguments:
//   str: Pointer to the string to be converted.
//
// Returns:
//    Returns 0 on success, or -1 if the input pointer is NULL.  
int to_lowercase(char* str);

#endif
