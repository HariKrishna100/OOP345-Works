/*
*****************************************************************************
                          part - #2
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NCC
Date       : 12/2/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_TOY_H_
#define SDDS_TOY_H_
#include <iostream>
namespace sdds {
   class Toy {
      int m_orderId{};
      std::string m_name{};
      int m_noOfItems{};
      double m_price{};
      double m_salesTax{ 13 };
   public:
      Toy() = default;
      Toy(const std::string& toy);
      void update(int numItems);
      friend std::ostream& operator<<(std::ostream& os, const Toy T);
   };
}
#endif // !SDDS_TOY_H_
