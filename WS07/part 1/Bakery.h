#ifndef SDDS_BAKERY_H_
#define SDDS_BAKERY_H_
#include <iostream>
#include <vector>
namespace sdds {
   enum class BakedType {
      BREAD, PASTERY
   };

   struct BakedGood {
      BakedType m_type{};
      std::string m_desc{};
      int m_expDay{0};
      int m_stock{0};
      double m_price{0.0};
   };

   class Bakery {
      std::vector<BakedGood> m_bakedItems;
   public:
      Bakery(const char* filename);
      void showGoods(std::ostream& os) const;
   };
   std::ostream& operator<<(std::ostream& out, const BakedGood& b);
}
#endif // !SDDS_BAKERY_H_
