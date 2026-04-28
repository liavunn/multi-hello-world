/*
*Multi-Hello-World: Main entry point and user interaction logic.
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


#include <stdio.h>
#include <string.h>
 
#include "data.h"
#include "utils.h"
#include "hash.h"
#include "config.h"

int main(void) {
  char user_country_code[10] ={0};
  char locale[10] = {0};
  int file_error = 0;

  printf("\nLoading configuration...");
  int results = LoadConfig("Config.ini");

  // Check if the configuration was loaded successfully.
  if (results != -1 && results != -2) {

    char* search_ptr = HashSearch("user", "language", user_country_code, sizeof(user_country_code));

    if (search_ptr == NULL) {
    printf("\nUser language configuration corrupted or missing.");
    file_error = -1;
    }
  
    if (file_error == 0) {
    printf("  Done.\n");
    
    DisplayFinalGreeting(user_country_code);
    } else if (file_error == -1) {
    printf("  Error.\n");

    remove("Config.ini");
    CreateFile("Config.ini");
    LoadConfig("Config.ini");

    printf("File reset.\n");

    GetUserInput(user_country_code, 7, 10);
  
    DisplayFinalGreeting(user_country_code);

    }
  // Handle invalid filename arguments by using default values. 
  } else if (results == -1) {
    printf("\nUnable to read configuration file. Applying default values instead...\n");

    GetUserInput(user_country_code, 7, 10);
  
    DisplayFinalGreeting(user_country_code);
  // File not found: create a new configuration and prompt for input. 
  } else if (results == -2) {
    CreateFile("Config.ini");

    printf("\nConfiguration file not found. Created a new one.\n");

    GetUserInput(user_country_code, 7, 10);
  
    DisplayFinalGreeting(user_country_code);
  }

  // Save the final settings and clean up resources.
  GetSystemCountryCode(locale, 6);
  HashInsert("system", "language", locale, strlen(locale));

  SaveConfig("Config.ini");

  HashFree();

  return 0;
}
