#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;
namespace sdds {
   Employee::Employee(istream& is) {
      string tempStr{};

      getline(is, tempStr);

      tempStr.erase(0, tempStr.find_first_of(',') + 1);
      m_name = clrSpace(tempStr);

      tempStr.erase(0, tempStr.find_first_of(',') + 1);
      m_age = clrSpace(tempStr);

      for (auto& age: m_age) {
         if (isdigit(age) == 0) {
            throw m_name + " ++Invalid record!";
         }
      }

      tempStr.erase(0, tempStr.find_first_of(',') + 1);
      m_id = clrSpace(tempStr);

      if (tolower(m_id[0]) != 'e') {
         throw m_name + "++Invalid record!";
      }
   }

   string Employee::status() const {
      return "Employee";
   }

   string Employee::name() const {
      return m_name;
   }

   string Employee::id() const {
      return m_id;
   }

   string Employee::age() const {
      return m_age;
   }

   void Employee::display(ostream& out) const {
      out << std::left;
      out << "| " << setw(10) << "Employee" << "| ";
      out << setw(10) << m_id << "| ";
      out << setw(21) << m_name << "| ";
      out << setw(4) << m_age << "|";
   }

   string Employee::clrSpace(const string str) {
      string strcleared = str.substr(0, str.find_first_of(','));
      strcleared.erase(0, strcleared.find_first_not_of(' '));
      strcleared.erase(strcleared.find_last_not_of(' ') + 1);
      return strcleared;
   }
}