/*
*****************************************************************************
                          w6p2
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NCC
Date       : 3/11/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "Professor.h"
using namespace std;
namespace sdds {
   Professor::Professor(istream& is): Employee(is) {
      m_department = Employee::m_dept;
   }

   void Professor::display(ostream& out) const {
      Employee::display(out);
      out << m_department;
      out << "| Professor";
   }

   string Professor::status() const {
      return "Professor";
   }

   string Professor::department() const {
      return m_department;
   }
}