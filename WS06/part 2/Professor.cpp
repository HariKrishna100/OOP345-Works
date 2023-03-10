#include <iostream>
#include "Professor.h"
using namespace std;
namespace sdds {
   Professor::Professor(istream& in): Employee(in) {
      string str;
      getline(in, str);

      m_department = stod(str);
   }

   void Professor::display(ostream& out) const {

   }

   string Professor::status() const {
      
   }

   string Professor::department() const {
      
   }
}