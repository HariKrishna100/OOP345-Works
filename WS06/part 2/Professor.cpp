#include <iostream>
#include "Professor.h"
using namespace std;
namespace sdds {
   Professor::Professor(istream& is): Employee(is) {
      string str{};
      getline(is, str);

      m_department = str;
   }

   void Professor::display(ostream& out) const {
      Employee::display(out);
      out << endl;
      out << "| Professor" << endl;
   }

   string Professor::status() const {
      return "Professor";
   }

   string Professor::department() const {
      return m_department;
   }
}