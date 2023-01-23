/*
*****************************************************************************
                          part - #2
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NAA
Date       : 1/21/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_FOODOERDER_H
#define SDDS_FOODOERDER_H
#include <iostream>

// defining global variables
extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {
   class foodorder {
      char* m_custName;
      char* m_foodDesc;
      double m_price;
      bool m_dailySpecial;
   public:
      foodorder();
      foodorder(const foodorder& toCopy);
      foodorder& operator=(const foodorder& toCopy);
      ~foodorder();
      void setEmpty();
      std::istream& read(std::istream& istr);
      void display();
   };
}
#endif // !SDDS_FOODOERDER_H