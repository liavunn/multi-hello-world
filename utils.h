/*
*Multi-Hello-World: Common utility library.
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


#ifndef UTILS_H_
#define UTILS_H_


// === string ===


// Convert uppercase to lowercase.
// 
//   str: Pointer to the string to be converted.
//
//   Returns 0 on success, or -1 if the input pointer is NULL.  
int ToLowercase(char* str);

// Removes all whitespace characters from the string.
//
//   str: Pointer to the string to be converted.
//
//   Returns 0 on success, or -1 if the input pointer is NULL.  
int RemoveAllWhitespace(char* str);

// Merges two strings into one, inserting a '|' separator in between.
//
//   dest: Buffer to store the result.
//   dest_size: Capacity of the destination buffer.
//   front: The first string part.
//   back: The second string part.
//
//   Returns 0 on success.
//   Returns -1 if any pointer is NULL or dest_size is 0.
//   Returns -2 if the destination buffer is too small.
int CombineParts(char* dest, size_t dest_size, const char* front, const char* back);

// Fetches an input string from the user.
// 
//   buffer: the array to store the input.
//   buffer_size: Maximum characters to read.
//   
//   Returns 0 on success, or -1 if an error occurred. 
int FetchUserInput(char* buffer, size_t buffer_size);


// === system ===


// Retrieve the current system language setting.
// If retrieval fails, defaults to "en_us".
//
//   buffer: Character array for storing country codes. 
//   buffer_size: Buffer size, recommended to be 6 (e.g., "en_us").
void GetSystemCountryCode(char* buffer, size_t buffer_size);


// === file ===


// Creates a file with the name specified by the argument.
//
//   filename: The filename to be created.
//
//   Returns: 0 on success, -1 on failure.
int CreateFile(const char* filename);

#endif // UTILS_H_
