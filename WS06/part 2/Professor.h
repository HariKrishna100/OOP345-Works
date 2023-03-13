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
#ifndef SDDS_PROFESSOR_H_
#define SDDS_PROFESSOR_H_
#include <iostream>
#include "Employee.h"
namespace sdds {
   class Professor: public Employee {
      std::string m_department{};
   public:
      Professor(std::istream& is);
      void display(std::ostream& out) const;
      std::string status() const;
      std::string department() const;
   };
}
#endif // !SDDS_PROFESSOR_H_
