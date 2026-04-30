/*
*Multi-Hello-World: Language data definitions and processing logic.
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


#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "data.h"
#include "utils.h"
#include "hash.h"
#include "config.h"

const char* kDefaultCountryCode = "en-us";

// Stores country code and its greeting message.
const struct Greeting kGreetings[]= {
  {"zh-CN", "zh-cn", "你好，世界"},
  {"zh-TW", "zh-tw", "你好，世界"},
  {"en-US", "en-us", "Hello World"},
  {"en-GB", "en-gb", "Hello World"},
  {"es-ES", "es-es", "Hola Mundo"},
  {"fr-FR", "fr-fr", "Bonjour, le Monde"},
  {"ja-JP", "ja-jp", "こんにちは,世界"},
  {"ru-RU", "ru-ru", "Привет, мир"},
  {"de-DE", "de-de", "Hallo Welt"},
  {"pt-BR", "pt-br", "Olá Mundo"},
};

const size_t kNumGreetings = sizeof(kGreetings)/sizeof(kGreetings[0]);

const char* GetGreeting(const char* country_code) {
  for (size_t i = 0; i < kNumGreetings; ++i) {
    if (strncmp(country_code, kGreetings[i].country_code, 6) == 0) {
      return kGreetings[i].country_greeting;
    }
  }

  return NULL;
}

// Prompts the user for input, retrieves it, and converts the result to lowercase.
int GetUserInputCountryCode(char* buffer, size_t read_limit, size_t total_size) {
  printf("Please enter a country code:");
  for (size_t i = 0; i < kNumGreetings; ++i) {
    printf("%s", kGreetings[i].display_country_code);
    if (i < kNumGreetings - 1) {
      printf(", ");
    }
  }
  printf("\n");

  if (FetchUserInput(buffer, read_limit) == -1) {
    return -1;
  }

  if (ToLowercase(buffer) == -1) {
    snprintf(buffer, total_size, "%s", kDefaultCountryCode);
  }

  if (ToHyphen(buffer) == -1) {
    snprintf(buffer, total_size, "%s", kDefaultCountryCode);
  }


  return 0;
}

// Display the final greeting message based on the country code in the buffer.
int DisplayFinalGreeting(char* buffer, int* status) {
  const char* result_greeting = GetGreeting(buffer);

  if (result_greeting != NULL) {
    printf("%s\n", result_greeting);
    *status = 0;
    return 0;
  }

  printf("Country code error or Not within program scope\n");
  char locale[256] = {0};
  HashSearch("system", "language", locale, sizeof(locale));
  result_greeting = GetGreeting(locale);
  if (result_greeting != NULL) {
    printf("Attempting to use system language: %s\n", result_greeting);
    *status = -1;
    return 0;
    } 

  result_greeting = GetGreeting(kDefaultCountryCode); 
  printf("Unable to use system language.\n");
  printf("Use default language:%s\n", result_greeting);
  *status = -2;
  return 0;
  }

