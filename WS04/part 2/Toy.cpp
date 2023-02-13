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
#include <iostream>
#include <string>
#include "Toy.h"
using namespace std;
using namespace sdds;
namespace sdds {
   Toy::Toy(const std::string& toy) {
      size_t stringStart = {};
      size_t stringEnd = toy.find(':');

      m_orderId = std::stoi(toy.substr(stringStart, (stringEnd - stringStart)));
      stringStart = stringEnd + 1;
      stringEnd = toy.find(':', stringStart);

      m_name = toy.substr(stringStart, (stringEnd - stringStart));
      m_name.erase(0, m_name.find_first_not_of(" \t\r\n"));
      m_name.erase(m_name.find_last_not_of(" \t\r\n") + 1);

      stringStart = stringEnd + 1;
      stringEnd = toy.find(':', stringStart);

      m_noOfItems = std::stoi(toy.substr(stringStart, (stringEnd - stringStart)));
      stringStart = stringEnd + 1;
      stringEnd = toy.find(':', stringStart);

      m_price = std::stod(toy.substr(stringStart, (stringEnd - stringStart)));
   }
   void Toy::update(int numItems) {
      m_noOfItems = numItems;
   }
   std::ostream& operator<<(std::ostream& os, const Toy T) {
      double subtotal = T.m_price * T.m_noOfItems;
      double tax = subtotal * (T.m_salesTax / 100);
      double total = subtotal + tax;

      os << "Toy";
      os.width(8);
      os.setf(ios::right);
      os << T.m_orderId << ":";
      os.unsetf(ios::right);

      os.width(18);
      os.setf(ios::right);
      os << T.m_name;
      os.unsetf(ios::right);

      os.width(3);
      os.setf(ios::right);
      os << T.m_noOfItems << " items";
      os.unsetf(ios::right);

      os.width(8);
      os.setf(ios::right);
      os << T.m_price << "/item  subtotal:";
      os.unsetf(ios::right);

      os.width(7);
      os.setf(ios::right);
      os.precision(2);
      os << std::fixed;
      os << subtotal;
      os.unsetf(ios::right);

      os << " tax:";
      os.width(6);
      os.setf(ios::right);
      os << tax;
      os.unsetf(ios::right);

      os << " total:";
      os.width(7);
      os.setf(ios::right);
      os << total << endl;
      os.unsetf(ios::right);

      return os;
   }
}