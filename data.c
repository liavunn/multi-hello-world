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
#include <locale.h>
#include <ctype.h>

#include "data.h"

//Stores country code and its greeting messege.
const Greeting kGreetings[]= {
  {"zh_CN", "zh_cn", "你好，世界"},
  {"zh_TW", "zh_tw", "你好，世界"},
  {"en_US", "en_us", "Hello World"},
  {"en_GB", "en_gb", "Hello World"},
  {"es_ES", "es_es", "Hola mundo"},
  {"fr_FR", "fr_fr", "Bonjour, le Monde"},
  {"ja_JP", "ja_jp", "こんにちは,世界"},
  {"ru_RU", "ru_ru", "Привет, мир"},
  {"de_DE", "de_de", "Hallo Welt"},
  {"pt_BR", "pt_br", "Olá Mundo"}
};

//Computes the number of entries in kGreetings.
const size_t kNumGreetings = sizeof(kGreetings)/sizeof(kGreetings[0]);

//Lookup the country code and return the greeting message.
const char* get_greeting(const char* country_code) {
  for (size_t i = 0; i < kNumGreetings; ++i) {
    if (strncmp(country_code, kGreetings[i].country_code, 6) == 0) {
      return kGreetings[i].country_greeting;
    }
  }
  //Return NULL if no match is found. 
  return NULL;
}

//Convert uppercase to lowercase.
int to_lowercase(char* str) {
  if (str == NULL) {
    return -1;
  }
  for (size_t i = 0; str[i] != '\0'; ++i) {
    str[i] = (char)tolower((unsigned char)str[i]);
  }
  return 0;
}

//Implements system country code retrieval via the standard C locale library.
void get_system_country_code(char* buffer, size_t buffer_size) {
  //Retrieves the current system language setting.
  char* system_locale = setlocale(LC_CTYPE, "");

  //Falls back to to match the system language as a fallback; use "en_us" if detection fails.
  if (system_locale != NULL) {
    snprintf(buffer, buffer_size, "%s", system_locale);

    to_lowercase(buffer);
  }
  else {
    //Falls back to "en_us" if the system locale cannot be detected.
    snprintf(buffer, buffer_size, "en_us");
  }
}
