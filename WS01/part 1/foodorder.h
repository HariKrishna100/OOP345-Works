#ifndef SDDS_FOODOERDER_H
#define SDDS_FOODOERDER_H
#include <iostream>

// defining global variables
extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {
   class FoodOrder {
      char m_custName[10];
      char m_foodDesc[25];
      double m_price;
      bool m_dailySpecial;
   public:
      FoodOrder();
      std::istream& read(std::istream& istr);
      void display();
   };
}
#endif // !SDDS_FOODOERDER_H
