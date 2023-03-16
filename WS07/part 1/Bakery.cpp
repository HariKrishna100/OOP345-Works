#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "Bakery.h"
using namespace std;
namespace sdds {
   Bakery::Bakery(const char* filename) {
      ifstream file(filename);
      string data{};

      if (!file) throw "Incorrect file";
      
      while (getline(file, data)) {
         BakedGood bItems{};
         string baketyp{};

         baketyp = data.substr(0, data.find(" "));
         transform(baketyp.begin(), baketyp.end(), baketyp.begin(), ::toupper);
         bItems.m_type = clrSpace(baketyp) == "BREAD" ? BakedType::BREAD : BakedType::PASTERY;
         bItems.m_desc = clrSpace(data.substr(8, 20));
         bItems.m_expDay = stoi(clrSpace(data.substr(28, 14)));
         bItems.m_stock = stoi(clrSpace(data.substr(42, 8)));
         bItems.m_price = stod(clrSpace(data.substr(50, 6)));

         m_bakedItems.push_back(bItems);
      }
      file.close();
   }

   void Bakery::showGoods(ostream& os) const {
      for_each(m_bakedItems.begin(), m_bakedItems.end(), [&os](const BakedGood& B) { os << B; });
   }

   ostream& operator<<(ostream& out, const BakedGood& b) {
      out << "* " << left << setw(10) << (b.m_type == BakedType::BREAD ? "Bread" : "Pastry");
      out << " * " << left << setw(20) << b.m_desc;
      out << " * " << left << setw(5) << b.m_expDay;
      out << " * " << left << setw(5) << b.m_stock;
      out << " * " << right << fixed << setprecision(2) << setw(8) << b.m_price;
      out << " * " << endl;
      return out;
   }

   string Bakery::clrSpace(const string& str) {
      auto first = find_if_not(str.begin(), str.end(), [](auto c) { return isspace(c); });
      auto last = find_if_not(str.rbegin(), str.rend(), [](auto c) { return isspace(c); }).base();
      return (first >= last) ? "" : string(first, last);
   }
}