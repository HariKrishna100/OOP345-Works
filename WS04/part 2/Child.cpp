/*
*****************************************************************************
                          part - #2
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NCC
Date       : 12/2/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "Child.h"
#include "Toy.h"
using namespace std;
namespace sdds {
   Child::Child(std::string name, int age, const Toy* toys[], size_t count) {
      c_name = { name };
      c_age = age;
      c_toys = {};
      c_noOfToys = count;

      if (count > 0) {
         c_toys = new const Toy* [c_noOfToys];
         for (size_t i = 0; i < c_noOfToys; i++) {
            c_toys[i] = new Toy(*toys[i]);
         }
      }
      else {
         c_toys = {};
      }
   }

   Child::Child(const Child& toCopy) {
      operator=(toCopy);
   }

   Child& Child::operator=(const Child& toCopy) {
      if (this != &toCopy) {
         deallocate();
         c_toys = nullptr;

         c_name = toCopy.c_name;
         c_age = toCopy.c_age;
         c_noOfToys = toCopy.c_noOfToys;

         c_toys = new const Toy * [c_noOfToys];
         for (size_t i = 0; i < c_noOfToys; i++) {
            c_toys[i] = new Toy(*(toCopy.c_toys[i]));
         }
      }
      return *this;
   }

   Child::Child(Child&& toMove) {
      operator=(move(toMove));
   }

   Child& Child::operator=(Child&& toMove) {
      if (this != &toMove) {
         deallocate();
         c_toys = nullptr;

         c_toys = toMove.c_toys;
         toMove.c_toys = nullptr;

         c_name = toMove.c_name;
         toMove.c_name = "";

         c_age = toMove.c_age;
         toMove.c_age = 0;

         c_noOfToys = toMove.c_noOfToys;
         toMove.c_noOfToys = 0;
      }
      return *this;
   }

   Child::~Child() {
      deallocate();
   }

   size_t Child::size() const {
      return c_noOfToys;
   }

   void Child::deallocate() {
      for (size_t i = 0; i < c_noOfToys; i++) {
         delete c_toys[i];
      }
      delete[] c_toys;
   }

   ostream& operator<<(ostream& os, const Child& C) {
      static int noOfCalls{ 1 };
      os << "--------------------------" << endl;
      os << "Child " << noOfCalls << ": " << C.c_name 
         << " " << C.c_age << " years old:" << endl;
      os << "--------------------------" << endl;
      if (C.size() > 0) {
         for (size_t i = 0; i < C.size(); i++) {
            os << *C.c_toys[i];
         }
      }
      else {
         os << "This child has no toys!" << endl;
      }
      os << "--------------------------" << endl;
      noOfCalls++;

      return os;
   }
}