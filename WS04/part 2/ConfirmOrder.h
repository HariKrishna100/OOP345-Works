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
#ifndef SDDS_CONFIRMORDER_H_
#define SDDS_CONFIRMORDER_H_
#include <iostream>
#include "Toy.h"
namespace sdds {
   class ConfirmOrder {
      const sdds::Toy** c_toys = {nullptr};
      size_t c_noOfToys = 0;
   public:
      ConfirmOrder() = default;
      ConfirmOrder(const ConfirmOrder& toCopy);
      ConfirmOrder& operator=(const ConfirmOrder& toCopy);
      ConfirmOrder(ConfirmOrder&& toMove) noexcept;
      ConfirmOrder& operator=(ConfirmOrder && toMove) noexcept;
      ~ConfirmOrder();
      ConfirmOrder& operator+=(const Toy& toy);
      ConfirmOrder& operator-=(const Toy& toy);
      friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& Co);
   };
}
#endif // !SDDS_CONFIRMORDER_H_
