#include <iostream>
#include "Utilities.h"
#include "Employee.h"
#include "Student.h"
#include "Professor.h"
using namespace std;
namespace sdds {
    Person* buildInstance(std::istream& in) {
       char tag{};
       in >> tag;

       if (tag == 'e' || tag == 'E') {
          return new Employee(in);
       }
       else if (tag == 's' || tag == 'S') {
          return new Student(in);
       }
       else if (tag == 'p' || tag == 'P') {
          return new Professor(in);
       }

       in.ignore(1000, '\n');
       return nullptr;
    }
}