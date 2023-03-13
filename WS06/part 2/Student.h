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
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include <iostream>
#include "Person.h"
namespace sdds {
   class Student: public Person {
      std::string m_name{};
      std::string m_age{};
      std::string m_id{};
      std::string* m_courses{};
      std::string m_count{ 0 };
      int m_iCount{};
   public:
      Student() = default;
      Student(std::istream& is);
      Student(const Student& notToCopy) = delete;
      Student& operator=(const Student& notToCopy) = delete;
      ~Student();
      std::string status() const;
      std::string name() const;
      std::string id() const;
      std::string age() const;
      void display(std::ostream& out) const;
      std::string clrSpace(const std::string str);
   };
}
#endif // !SDDS_STUDENT_H_
