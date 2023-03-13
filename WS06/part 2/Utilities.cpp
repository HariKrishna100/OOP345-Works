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