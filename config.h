/*
* Multi-Hello-World: Sequence Table Implementation for INI configuration files.
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


// Checks if a line should be ignored during parsing.
//
//   line_buffer: The normalized string to validate.
//
//   Returns 1 if the line is skipped.
//   Returns 0 if the line is valid.
int ShouldSkipLine(const char* line_buffer);

// Loads configuration pairs from a file into the hash table.
//
//   filename: The path and name of the .ini file.
//
//   Returns 0 on success
//   Returns -1 if the filename is NULL.
//   Returns -2 if the file does not exist or cannot be opened.
int LoadConfig(const char* filename);

// Writes all current hash table entries to a configuration file.
//
//   filename: The path and name of the .ini file.
//
//   Returns the number of entries loaded on success.
//   Returns -1 if the filename is NULL or the file cannot be created/opened for writing.
int SaveConfig(const char* filename);

// Removes a key from the hash table and synchronizes the change to the file.
//
//   filename: The path and name of the .ini file.
//   key: The string key to be deleted.
//
//   Returns 0 on success, or -1 if the key is missing or file update fails.
int DeleteConfig(const char* filename, const char* section, const char* key);
