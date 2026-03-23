#include <stdio.h>
 
#include "data.h"

int main(void){
  char  user_country_code[6] ={0};
 
  //Display the input prompt and the list of supported country codes.
  printf("Please enter a country code:");
  for (int i = 0; i <  kNumGreetings; ++i) {
    printf("%s", kGreetings[i].country_code);
    if (i < kNumGreetings - 1) {
    printf(", ");
    }
  }
  printf("\n");

  //List supported country codes.
  scanf("%5s", user_country_code);

  //Get the greeting message corresponding to the country code.
  const char* result_greeting = get_greeting(user_country_code);

  //Verify and display the greeting.
  if (result_greeting != NULL) {
    printf("%s\n", result_greeting);
  }
  else {
    printf("country code error / Not within program scope\n");
  }

return 0;
}
