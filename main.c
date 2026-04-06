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
 
#include "data.h"

const char* kDefaultCountryCode = "en_us";

int main(void) {
  //Stores the country code entered by the user.
  char user_country_code[10] ={0};
  //Buffer to hold the detected system locale codew(e.g., "en_us")
  char locale[10] = {0};

  //Retrieves the system's country code; defaults to "en_us" on failure.
  get_system_country_code(locale, 6);
 
  //Display the input prompt and the list of supported country codes.
  printf("Please enter a country code:");
  for (size_t i = 0; i < kNumGreetings; ++i) {
    printf("%s", kGreetings[i].display_country_code);
    if (i < kNumGreetings - 1) {
      printf(", ");
    }
  }
  printf("\n");

  //List supported country codes.
  scanf("%5s", user_country_code);

  //Normalize user input to lowercase for lookup.
  if (to_lowercase(user_country_code) == -1) {
    snprintf(user_country_code, sizeof(user_country_code), "%s", kDefaultCountryCode);
  }

  //Get the greeting message corresponding to the country code.
  const char* result_greeting = get_greeting(user_country_code);

  //Verify and display the greeting.
  if (result_greeting != NULL) {
    printf("%s\n", result_greeting);
  } else {
    result_greeting = get_greeting(locale);
    if (result_greeting != NULL) {
      printf("Country code error / Not within program scope\n");
      printf("Attempting to use system language: %s\n", result_greeting);
    } else {
      //Fetch the greeting message for the default country code.
      result_greeting = get_greeting(kDefaultCountryCode);
  
      //Notify user of error and display the fallback message.
      printf("Country code error / Not within program scope\n");
      printf("Use default language:%s\n", result_greeting);
    }
  }
return 0;
}
