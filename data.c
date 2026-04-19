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

const char* kDefaultCountryCode = "en_us";

// Stores country code and its greeting message.
const Greeting kGreetings[]= {
  {"zh_CN", "zh_cn", "你好，世界"},
  {"zh_TW", "zh_tw", "你好，世界"},
  {"en_US", "en_us", "Hello World"},
  {"en_GB", "en_gb", "Hello World"},
  {"es_ES", "es_es", "Hola Mundo"},
  {"fr_FR", "fr_fr", "Bonjour, le Monde"},
  {"ja_JP", "ja_jp", "こんにちは,世界"},
  {"ru_RU", "ru_ru", "Привет, мир"},
  {"de_DE", "de_de", "Hallo Welt"},
  {"pt_BR", "pt_br", "Olá Mundo"}
};

const size_t kNumGreetings = sizeof(kGreetings)/sizeof(kGreetings[0]);

const char* get_greeting(const char* country_code) {
  for (size_t i = 0; i < kNumGreetings; ++i) {
    if (strncmp(country_code, kGreetings[i].country_code, 6) == 0) {
      return kGreetings[i].country_greeting;
    }
  }

  return NULL;
}

// Prompts the user for input, retrieves it, and converts the result to lowercase.
int get_user_input(char* buffer, size_t read_limit, size_t total_size) {
  printf("Please enter a country code:");
  for (size_t i = 0; i < kNumGreetings; ++i) {
    printf("%s", kGreetings[i].display_country_code);
    if (i < kNumGreetings - 1) {
      printf(", ");
    }
  }
  printf("\n");

  get_fetch_input(buffer, read_limit);

  if (to_lowercase(buffer) == -1) {
    snprintf(buffer, total_size, "%s", kDefaultCountryCode);
  }

  return 0;
}

// Display the final greeting message based on the country code in the buffer.
int display_final_greeting(char* buffer, size_t buffer_size, char* locale) {
  const char* result_greeting = get_greeting(buffer);

  if (result_greeting != NULL) {
    printf("%s\n", result_greeting);
    return 0;
  }

  printf("Country code error / Not within program scope\n");
  result_greeting = get_greeting(locale);
  if (result_greeting != NULL) {
    printf("Attempting to use system language: %s\n", result_greeting);
    return 0;
    } 

  result_greeting = get_greeting(kDefaultCountryCode); 
  printf("Not within program scope\n");
  printf("Use default language:%s\n", result_greeting);
  return 0;
  }

