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
#ifndef SDDS_EMPLOYEE_H_
# define SDDS_EMPLOYEE_H_
#include <iostream>
#include "Person.h"
namespace sdds {
   class Employee: public Person {
      std::string m_name{};
      std::string m_age{};
      std::string m_id{};
   public:
      Employee(std::istream& is);
      std::string status() const;
      std::string name() const;
      std::string id() const;
      std::string age() const;
      std::string m_dept{};
      void display(std::ostream& out) const;
      std::string clrSpace(const std::string str);
   };
}
#endif // !SDDS_EMPLOYEE_H_
