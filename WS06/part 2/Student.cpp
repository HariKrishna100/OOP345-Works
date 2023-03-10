#include <iostream>
#include <iomanip>
#include "Student.h"
using namespace std;
namespace sdds {
   Student::Student(std::istream& is) {
      string str{};
      getline(is, str);

      str.erase(0, str.find_first_of(',') + 1);
      m_name = clrSpace(str);

      str.erase(0, str.find_first_of(',') + 1);
      m_age = clrSpace(str);

      for (auto& age : m_age) {
         if (isdigit(age) == 0) {
            throw m_name + "++Invalid record!";
         }
      }

      str.erase(0, str.find_first_of(',') + 1);
      m_id = clrSpace(str);

      if (tolower(m_id[0]) != 'e') {
         throw m_name + "++Invalid record!";
      }

      str.erase(0, str.find_first_of(',') + 1);
      m_count = stod(str.substr(0, str.find_first_of(',')));

      for (auto& num : m_count) {
         if (isdigit(num) == 0)
            throw m_name + "++Invalid record!";
      }
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
      out << std::left;
      out << "| " << setw(10) << "Student" << "| ";
      out << setw(10) << m_id << "| ";
      out << setw(20) << m_name << " | ";
      out << setw(3) << m_age << " |";
      out << m_courses;
   }

   string Student::clrSpace(const string str) {
      string strcleared = str.substr(0, str.find_first_of(','));
      strcleared.erase(0, strcleared.find_first_not_of(' '));
      strcleared.erase(strcleared.find_last_not_of(' ') + 1);
      return strcleared;
   }
}