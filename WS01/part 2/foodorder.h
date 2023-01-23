#ifndef SDDS_FOODOERDER_H
#define SDDS_FOODOERDER_H
#include <iostream>

// defining global variables
extern double g_taxrate = 0;
extern double g_dailydiscount = 0;

namespace sdds {
   class foodorder {
      char* m_custName;
      char* m_foodDesc;
      double m_price;
      bool m_dailySpecial;
   public:
      foodorder();
      foodorder(const foodorder& toCopy);
      foodorder& operator=(const foodorder& toCopy);
      ~foodorder();
      void setEmpty();
      std::istream& read(std::istream& istr);
      void display();
   };
}
#endif // !SDDS_FOODOERDER_H