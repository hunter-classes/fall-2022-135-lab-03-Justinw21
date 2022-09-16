/*
Author: Justin Wong
Course: CSCI-135
Instructor: Mr. Zamansky
Assignment: Lab4

Runs all programs in main
*/


#include <iostream>
#include "reservoir.h"
#include <string.h>
#include "reverseorder.h"

int main()
{
  std::string date = "01/04/2018";
  std::string date2 = "01/09/2018";
  get_east_storage(date);
  get_min_east();
  get_max_east();
  compare_basins(date);
  reverse_order(date, date2);
  return 0;
}
