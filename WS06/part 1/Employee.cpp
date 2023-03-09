#include <iostream>
#include "Employee.h"
using namespace std;
namespace sdds {
   Employee::Employee(istream& is) {

   }

   string Employee::status() const {
      
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

   }

   string Employee::clrSpace(const string str) {
      string strcleared = str.substr(0, str.find_first_of(','));
      strcleared.erase(0, strcleared.find_first_not_of(' '));
      strcleared.erase(strcleared.find_last_not_of(' ') + 1);
      return strcleared;
   }
}