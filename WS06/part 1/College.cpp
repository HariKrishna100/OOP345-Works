#include <iostream>
#include "College.h"
using namespace std;
namespace sdds {
   College::~College() {
      for (Person* person : m_persons) delete person;
   }

   College& College::operator+=(Person* thePerson) {
      m_persons.push_back(thePerson);
      return *this;
   }

   void College::display(std::ostream& out) const {
      out << "-----------------------------------------" << endl;
      out << " Test #1 Persons in the college!        |" << endl;
      out << "-----------------------------------------" << endl;

      for (auto i = m_persons.begin(); i != m_persons.end(); i++) {
         (*i)->display(out);
         out << endl;
      }
      out << "-----------------------------------------" << endl;
   }
}