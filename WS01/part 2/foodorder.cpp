#include <iostream>
#include "foodorder.h"
using namespace std;

// global variables
double g_taxrate;
double g_dailydiscount;

namespace sdds {
   // default constructor
   foodorder::foodorder() {
      setEmpty();
   }

   foodorder::foodorder(const foodorder& toCopy) {
      setEmpty();
      operator=(toCopy);
   }

   foodorder& foodorder::operator=(const foodorder& toCopy) {
      if (this != &toCopy) {
         delete[] m_foodDesc;

         strcpy(m_custName, toCopy.m_custName);

         m_foodDesc = new char[strlen(toCopy.m_foodDesc) + 1];
         strcpy(m_foodDesc, toCopy.m_foodDesc);

         m_price = toCopy.m_price;
         m_dailySpecial = toCopy.m_dailySpecial;
      }
      return *this;
   }

   foodorder::~foodorder() {
      delete[] m_custName;
      delete m_foodDesc;
      setEmpty();
   }

   void foodorder::setEmpty() {
      m_custName[0] = '\n';
      m_foodDesc = {};
      m_price = 0.0;
   }

   // read order data
   istream& foodorder::read(istream& istr) {
      char temp[256], special[256];
      if (istr) {
         delete[] m_foodDesc;

         istr.getline(m_custName, 10, ',');

         if (m_custName) {
            istr.getline(temp, 256, ',');

            m_foodDesc = new char[strlen(temp) + 1];
            strcpy(m_foodDesc, temp);

            istr >> m_price;
            istr.ignore(1);

            istr.getline(special, 256, '\n');
            if (special[0] == 'Y') {
               m_dailySpecial = true;
            }
            else if (special[0] == 'N') {
               m_dailySpecial = false;
            }
         }
         else {
            setEmpty();
         }
      }
      return istr;
   }

   // display content of food order
   void foodorder::display() {
      static int counter = 1;

      cout.width(2);
      cout.setf(ios::left);
      cout << counter << ". ";
      cout.unsetf(ios::left);

      if (m_custName) {
         cout.width(10);
         cout.setf(ios::left);
         cout << m_custName << "|";
         cout.unsetf(ios::left);

         cout.width(25);
         cout.setf(ios::left);
         cout << m_foodDesc << "|";
         cout.unsetf(ios::left);

         cout.width(12);
         cout.precision(2);
         cout.setf(ios::left);
         cout << m_price + (m_price * g_taxrate) << "|";
         cout.unsetf(ios::left);

         if (m_dailySpecial) {
            cout.width(13);
            cout.precision(2);
            cout.setf(ios::right);
            cout << m_price + (m_price * g_taxrate) - g_dailydiscount << endl;
            cout.unsetf(ios::right);
         }
         else {
            cout << endl;
         }
      }
      else {
         cout << "No Order" << endl;
      }
      counter++;
   }
}