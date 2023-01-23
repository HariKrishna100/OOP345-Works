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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "foodorder.h"
using namespace std;

// global variables
double g_taxrate = 0;
double g_dailydiscount = 0;

namespace sdds {
   // default constructor
   foodorder::foodorder() {
      setEmpty();
   }

   // copy constructor
   foodorder::foodorder(const foodorder& toCopy) {
      setEmpty();
      operator=(toCopy);
   }

   // assignment operator
   foodorder& foodorder::operator=(const foodorder& toCopy) {
      if (this != &toCopy) {
         if (toCopy.m_custName) {
            m_custName = new char[strlen(toCopy.m_custName) + 1];
            strcpy(m_custName, toCopy.m_custName);
         }
         else {
            m_custName = nullptr;
         }

         if (toCopy.m_foodDesc) {
            m_foodDesc = new char[strlen(toCopy.m_foodDesc) + 1];
            strcpy(m_foodDesc, toCopy.m_foodDesc);
         }
         else {
            m_foodDesc = nullptr;
         }

         m_price = toCopy.m_price;
         m_dailySpecial = toCopy.m_dailySpecial;
      }
      return *this;
   }

   // destructor
   foodorder::~foodorder() {
      delete[] m_custName;
      delete[] m_foodDesc;
   }

   // set empty
   void foodorder::setEmpty() {
      m_custName = nullptr;
      m_foodDesc = nullptr;
      m_price = 0.0;
      m_dailySpecial = false;
   }

   // read order data
   istream& foodorder::read(istream& istr) {
      char name[256], food[256], special[256];
      if (istr) {
         delete[] m_custName;
         delete[] m_foodDesc;

         istr.getline(name, 256, ',');

         if (strlen(name) > 0) {
            m_custName = new char[strlen(name) + 1];
            strcpy(m_custName, name);

            istr.getline(food, 256, ',');
            m_foodDesc = new char[strlen(food) + 1];
            strcpy(m_foodDesc, food);

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

      if (m_custName != nullptr) {
         cout.width(10);
         cout.setf(ios::left);
         cout << m_custName << "|";
         cout.unsetf(ios::left);

         cout.width(25);
         cout.setf(ios::left);
         cout << m_foodDesc << "|";
         cout.unsetf(ios::left);

         cout.width(12);
         cout.setf(ios::left);
         cout << setprecision(2) << fixed;
         cout << m_price + (m_price * g_taxrate) << "|";
         cout.unsetf(ios::left);

         if (m_dailySpecial) {
            cout.width(13);
            cout.setf(ios::right);
            cout << setprecision(2) << fixed;
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