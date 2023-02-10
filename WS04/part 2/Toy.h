#ifndef SDDS_TOY_H_
#define SDDS_TOY_H_
#include <iostream>
namespace sdds {
   class Toy {
      int m_orderId{};
      std::string m_name{};
      int m_noOfItems{};
      double m_price{};
      double m_salesTax{ 13 };
   public:
      Toy() = default;
      Toy(const std::string& toy);
      void update(int numItems);
      friend std::ostream& operator<<(std::ostream& os, const Toy T);
   };
}
#endif // !SDDS_TOY_H_
