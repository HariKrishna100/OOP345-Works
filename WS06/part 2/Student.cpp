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
#include <iomanip>
#include "Student.h"
using namespace std;
namespace sdds {
   Student::Student(std::istream& is) {
      std::string str{};
      std::getline(is, str);

      str.erase(0, str.find_first_of(',') + 1);
      m_name = clrSpace(str);

      str.erase(0, str.find_first_of(',') + 1);
      m_age = clrSpace(str);

      for (auto& age : m_age) {
         if (std::isdigit(age) == 0) {
            throw m_name + "++Invalid record!";
         }
      }
      
      str.erase(0, str.find_first_of(',') + 1);
      m_id = clrSpace(str);

      if (tolower(m_id[0]) != 's') {
         throw m_name + "++Invalid record!";
      }

      str.erase(0, str.find_first_of(',') + 1);
      m_count = clrSpace(str);

      for (auto& num : m_count) {
         if (std::isdigit(num) == 0) {
            throw m_name + "++Invalid record!";
         }
      }

      m_iCount = std::stoi(m_count);
      m_courses = new std::string[m_iCount];

      for (int i = 0; i < m_iCount; i++) {
         str.erase(0, str.find_first_of(',') + 1);
         m_courses[i] = clrSpace(str);
      }
   }

   Student::~Student() {
      delete[] m_courses;
   }

   std::string Student::status() const {
      return "Student";
   }

   std::string Student::name() const {
      return m_name;
   }

   std::string Student::id() const {
      return m_id;
   }

   std::string Student::age() const {
      return m_age;
   }

   void Student::display(std::ostream& out) const {
      out << "| " << setw(10) << left << "Student"
          << "| " << setw(10) << left << m_id
          << "| " << setw(20) << left << m_name
          << " | " << setw(3) << left << m_age
          << " |" << m_courses[0];
      for (int i = 1; i < m_iCount; i++) {
         out << ", " << m_courses[i];
      }
   }

   string Student::clrSpace(const string str) {
      string strcleared = str.substr(0, str.find_first_of(','));
      strcleared.erase(0, strcleared.find_first_not_of(' '));
      strcleared.erase(strcleared.find_last_not_of(' ') + 1);
      return strcleared;
   }
}