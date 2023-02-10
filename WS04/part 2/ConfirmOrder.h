#ifndef SDDS_CONFIRMORDER_H_
#define SDDS_CONFIRMORDER_H_
#include <iostream>
#include "Toy.h"
namespace sdds {
   class ConfirmOrder {
      const sdds::Toy** m_toys;
   public:
      ConfirmOrder& operator+=(const Toy& toy);
      ConfirmOrder& operator-=(const Toy& toy);
   };
}
#endif // !SDDS_CONFIRMORDER_H_
