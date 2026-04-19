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
#include "utils.h"

int main(void) {
  char user_country_code[10] ={0};
  char locale[10] = {0};

  get_system_country_code(locale, 6);

  get_user_input(user_country_code, 7, 10);
  
  display_final_greeting(user_country_code, 10, locale);

  return 0;
}
