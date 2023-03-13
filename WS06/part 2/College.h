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
#ifndef SDDS_COLLEGE_H_
#define SDDS_COLLEGE_H_
#include <iostream>
#include <vector>
#include <list>
#include "Person.h"
namespace sdds {
   class College {
      std::vector<Person*> m_persons;
   public:
      College() = default;
      College(const College& notToCopy) = delete;
      College& operator=(const College& notToCopy) = delete;
      ~College();
      College& operator +=(Person* thePerson);
      void display(std::ostream& out) const;
      template<typename T>
      void select(const T& test, std::list<const Person*>& persons) {
         for (auto li : m_persons) {
            if (test(li)) persons.push_back(li);
         }
      }
   };
}
#endif // !SDDS_COLLEGE_H_
