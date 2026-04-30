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
  int displayfinalgreeting_result = 0;

  char locale[10] = {0};
  GetSystemCountryCode(locale, 6, kDefaultCountryCode);
  HashInsert("system", "language", locale, strlen(locale));

  printf("\nLoading configuration...");
  int loadconfig_result = LoadConfig("Config.ini");

  // Check if the configuration was loaded successfully.
  if (loadconfig_result != -1 && loadconfig_result != -2) {
    int file_status = 0;

    char* search_ptr = HashSearch("user", "language", user_country_code, sizeof(user_country_code));

    if (search_ptr == NULL) {
    printf("\nUser language configuration corrupted or missing.");
    file_status = -1;
    }
  
    if (file_status == 0) {
      printf("  Done.\n");

      DisplayFinalGreeting(user_country_code, &displayfinalgreeting_result);
    } else if (file_status == -1) {
      printf("  Error.\n");

      remove("Config.ini");
      CreateFile("Config.ini");
      HashFree();

      printf("File reset.\n");

      GetUserInputCountryCode(user_country_code, 7, sizeof(user_country_code));

      DisplayFinalGreeting(user_country_code, &displayfinalgreeting_result);
      if (displayfinalgreeting_result == 0) {
        HashInsert("user", "language", user_country_code, strlen(user_country_code));
      }
    }
  // Handle invalid filename arguments by using default values. 
  } else if (loadconfig_result == -1) {
    printf("\nUnable to read configuration file. Applying default values instead...\n");

    GetUserInputCountryCode(user_country_code, 7, sizeof(user_country_code));
  
    DisplayFinalGreeting(user_country_code, &displayfinalgreeting_result);
  // File not found: create a new configuration and prompt for input. 
  } else if (loadconfig_result == -2) {
    CreateFile("Config.ini");

    printf("\nConfiguration file not found. Created a new one.\n");

    GetUserInputCountryCode(user_country_code, 7, sizeof(user_country_code));
  
    DisplayFinalGreeting(user_country_code, &displayfinalgreeting_result);
    if (displayfinalgreeting_result == 0) {
      HashInsert("user", "language", user_country_code, strlen(user_country_code));
    }
  }

  // Save the final settings and clean up resources.
  GetSystemCountryCode(locale, 6, kDefaultCountryCode);
  HashInsert("system", "language", locale, strlen(locale));

  SaveConfig("Config.ini");

  HashFree();

  return 0;
}
