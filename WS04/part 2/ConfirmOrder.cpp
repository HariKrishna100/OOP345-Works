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
#include "ConfirmOrder.h"
using namespace std;
namespace sdds {
    ConfirmOrder::ConfirmOrder(const ConfirmOrder& toCopy) {
       operator=(toCopy);
    }

    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& toCopy) {
       if (this != &toCopy) {
          delete[] c_toys;
          c_toys = {};

          c_noOfToys = toCopy.c_noOfToys;

          c_toys = new const Toy * [c_noOfToys];
          for (size_t i = 0; i < c_noOfToys; i++) {
             c_toys[i] = toCopy.c_toys[i];
          }
       }
       return *this;
    }

    ConfirmOrder::ConfirmOrder(ConfirmOrder&& toMove) noexcept {
       operator=(move(toMove));
    }

    ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& toMove) noexcept {
       if (this != &toMove) {
          delete[] c_toys;

          c_toys = toMove.c_toys;
          toMove.c_toys = nullptr;
          c_noOfToys = toMove.c_noOfToys;
          toMove.c_noOfToys = 0;
       }
       return *this;
    }

    ConfirmOrder::~ConfirmOrder() {
       delete[] c_toys;
    }

    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
       bool success = false;

       for (size_t i = 0; i < c_noOfToys; i++) {
          if (c_toys[i] == &toy) {
             success = true;
             break;
          }
       }

       if (!success) {
          const Toy** tempArr = new const Toy * [c_noOfToys + 1];

          for (size_t i = 0; i < c_noOfToys; i++) {
             tempArr[i] = c_toys[i];
          }
          tempArr[c_noOfToys] = &toy;
          c_noOfToys++;
          delete[] c_toys;
          c_toys = tempArr;
       }
       return *this;
    }

    ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
       bool success = false;
       size_t match = -1;

       for (size_t i = 0; i < c_noOfToys; i++) {
          if (c_toys[i] == &toy) {
             match = i;
             success = true;
             break;
          }
       }

       if (success) {
          const Toy** tempArr = new const Toy * [c_noOfToys - 1];
          size_t stringStart{ 0 };

          for (size_t i = 0; i < c_noOfToys; i++) {
             if (i != match) {
                tempArr[stringStart] = c_toys[i];
                stringStart++;
             }
          }

          c_noOfToys--;
          delete[] c_toys;
          c_toys = tempArr;
       }
       return *this;
    }

    ostream& operator<<(ostream& os, const ConfirmOrder& Co) {
       os << "--------------------------" << endl;
       os << "Confirmations to Send" << endl;
       os << "--------------------------" << endl;

       if (Co.c_noOfToys > 0) {
          for (size_t i = 0; i < Co.c_noOfToys; i++) {
             os << *Co.c_toys[i];
          }
       }
       else {
          os << "There are no confirmations to send!" << std::endl;
       }
       os << "--------------------------" << endl;

       return os;
    }
}