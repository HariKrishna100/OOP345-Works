#include <iostream>
#include <string>
#include "Toy.h"
using namespace std;
using namespace sdds;
namespace sdds {
   Toy::Toy(const std::string& toy) {
      size_t startIndex = {};
      size_t endIndex = toy.find(':');

      m_orderId = std::stoi(toy.substr(startIndex, (endIndex - startIndex)));
      startIndex = endIndex + 1;
      endIndex = toy.find(':', startIndex);

      m_name = toy.substr(startIndex, (endIndex - startIndex));

      m_name.erase(0, m_name.find_first_not_of(" \t\r\n"));
      m_name.erase(m_name.find_last_not_of(" \t\r\n") + 1);

      startIndex = endIndex + 1;
      endIndex = toy.find(':', startIndex);

      m_noOfItems = std::stoi(toy.substr(startIndex, (endIndex - startIndex)));
      startIndex = endIndex + 1;
      endIndex = toy.find(':', startIndex);

      m_price = std::stod(toy.substr(startIndex, (endIndex - startIndex)));
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