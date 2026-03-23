#ifndef DATA_H_
#define DATA_H_

//Holds country code and its greeting messege.
typedef struct {
const char* country_code;
const char* country_greeting;
} Greeting;

//Declare an external variable.
extern const Greeting kGreetings[];
extern const int kNumGreetings;

//Identify the country code and return the greeting message.
const char* get_greeting(const char* country_code);

#endif
