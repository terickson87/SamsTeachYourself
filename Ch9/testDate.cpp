
#include "Date.h"
#include <iostream>

int main()
{
   Date date{2020,1,12};
   std::cout << "The Date is: " << date << "." << std::endl;

   Date dayToAdd{0,7,42};
   std::cout << "The Date to add is: " << dayToAdd << "." << std::endl;

   Date finalDate = date + dayToAdd;
   std::cout << "The final Date is: " << finalDate << "." << std::endl;

   return 0;
}
