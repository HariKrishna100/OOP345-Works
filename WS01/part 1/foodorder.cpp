#include <iostream>
#include "foodorder.h"
using namespace std;

// global variables
double g_taxrate;
double g_dailydiscount;

namespace sdds {
   // default constructor
   FoodOrder::FoodOrder() {
      m_custName[0] = '\n';
      m_foodDesc[0] = '\n';
      m_price = 0.0;
   }

   // read order data
   istream& FoodOrder::read(istream& istr) {
      char temp[2];
      if (istr) {
         istr.getline(m_custName, 10, ',');
         istr.getline(m_foodDesc, 25, ',');
         istr >> m_price;
         istr.ignore(1);
         istr.getline(temp, 1, '\n');
         if (temp[0] == 'Y') {
            m_dailySpecial = true;
         }
         else if (temp[0] == 'N') {
            m_dailySpecial = false;
         }
      }
      return istr;
   }

   // display content of food order
   void FoodOrder::display() {
      static int counter = 1;

      cout.width(2);
      cout.setf(ios::left);
      cout << counter << " . ";
      cout.unsetf(ios::left);

      if (m_custName) {
         cout.width(10);
         cout.setf(ios::left);
         cout << m_custName;
         cout.unsetf(ios::left);

         cout.width(25);
         cout.setf(ios::left);
         cout << m_foodDesc;
         cout.unsetf(ios::left);

         cout.width(12);
         cout.precision(2);
         cout.setf(ios::left);
         cout << m_price * (1 + g_taxrate);
         cout.unsetf(ios::left);

         cout.width(13);
         cout.precision(2);
         cout.setf(ios::right);
         cout << m_price * (1 + g_taxrate);
         cout.unsetf(ios::right);
      }
      else {
         cout << "No Order";
      }
   }
}