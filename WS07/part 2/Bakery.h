/*
*****************************************************************************
                          w7p2
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NCC
Date       : 3/172022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_BAKERY_H_
#define SDDS_BAKERY_H_
#include <iostream>
#include <list>
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
      std::vector<BakedGood> m_collection;
   public:
      Bakery() = default;
      Bakery(const char* filename);
      void showGoods(std::ostream& os) const;
      void sortBakery(std::string str);
      std::vector<BakedGood> combine(Bakery& Bk);
      bool inStock(const std::string str, const BakedType& Bt) const;
      std::list<BakedGood> outOfStock(BakedType Bt) const;
      std::string clrSpace(const std::string& str);
   };
   std::ostream& operator<<(std::ostream& out, const BakedGood& b);
}
#endif // !SDDS_BAKERY_H_
