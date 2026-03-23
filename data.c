#include <string.h>
#include <stdio.h>

#include "data.h"

//Holds country code and its greeting messege.
const Greeting kGreetings[]= {
  {"zh_CN", "你好，世界"},
  {"zh_TW", "你好，世界"},
  {"en_US", "Hello World"},
  {"en_GB", "Hello World"},
  {"es_ES", "Hola mundo"},
  {"fr_FR", "Bonjour, le Monde"},
  {"ja_JP", "こんにちは,世界"},
  {"ru_RU", "Привет, мир"},
  {"de_DE", "Hallo Welt"},
  {"pt_BR", "Olá Mundo"}
};

//Compute the number of entries in kGreetings.
const int kNumGreetings = sizeof(kGreetings)/sizeof(kGreetings[0]);

//Identify the country code and return the greeting message.
const char* get_greeting(const char* country_code) {
for(int i = 0; i < kNumGreetings; ++i)
  if (strcmp(country_code, kGreetings[i].country_code) == 0) {
    return kGreetings[i].country_greeting;
  }
  //Return NULL if no match is found. 
  return NULL;
}
