/*
*****************************************************************************
                          w7p2
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NCC
Date       : 3/17/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
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
         bItems.m_expDay = stoi(clrSpace(data.substr(28, 15)));
         bItems.m_stock = stoi(clrSpace(data.substr(43, 8)));
         bItems.m_price = stod(clrSpace(data.substr(50, 6)));

         m_collection.push_back(bItems);
      }
      file.close();
   }

   void Bakery::showGoods(ostream& os) const {
      for_each(m_collection.begin(), m_collection.end(), [&os](const BakedGood& Bg) { 
         os << Bg << endl;
      });

      int stock = accumulate(m_collection.begin(), m_collection.end(), (int)0, [](int& result, const BakedGood& Bg) {
         return result + Bg.m_stock;
      });

      double price = accumulate(m_collection.begin(), m_collection.end(), (double)0.0, [](double& result, const BakedGood& Bg) {
         return result + Bg.m_price;
      });

      os << "Total Stock: " << stock << endl;
      os << "Total Price: " << setprecision(2) << fixed << price << endl;
   }

   void Bakery::sortBakery(string str) {
      transform(str.begin(), str.end(), str.begin(), ::toupper);
      sort(m_collection.begin(), m_collection.end(), [str](const BakedGood& Bk1, const BakedGood Bk2) {
         bool sort{};

         if (str == "DESCRIPTION") {
            sort = Bk2.m_desc > Bk1.m_desc;
         }
         else if (str == "SHELF") {
            sort = Bk2.m_expDay > Bk1.m_expDay;
         }
         else if (str == "STOCK") {
            sort = Bk2.m_stock > Bk1.m_stock;
         }
         else if (str == "PRICE") {
            sort = Bk2.m_price > Bk1.m_price;
         }
         return sort;
      });
   }

   vector<BakedGood> Bakery::combine(Bakery& Bk) {
      vector<BakedGood> combined(m_collection.size() + Bk.m_collection.size());
      sortBakery("Price");
      Bk.sortBakery("Price");

      merge(m_collection.begin(), m_collection.end(), Bk.m_collection.begin(), Bk.m_collection.end(), combined.begin(), [](const BakedGood& Bg1, const BakedGood& Bg2) {
         return Bg2.m_price > Bg1.m_price;
      });
      return combined;
   }

   bool Bakery::inStock(const string str, const BakedType& Bt) const {
      bool inStock{};
      inStock = any_of(m_collection.begin(), m_collection.end(), [str, Bt](const BakedGood& Bg) {
         return Bg.m_desc == str && Bg.m_type == Bt;
      });
      return inStock;
   }

   list<BakedGood> Bakery::outOfStock(BakedType Bt) const {
      list<BakedGood> outOfStk;
      copy_if(m_collection.begin(), m_collection.end(), back_inserter(outOfStk), [Bt](const BakedGood& Bg) {
         return Bg.m_type == Bt && Bg.m_stock == 0;
      });

      outOfStk.sort([](const BakedGood& Bg1, const BakedGood& Bg2) {
         return Bg2.m_price > Bg1.m_price;
      });
      return outOfStk;
   }

   ostream& operator<<(ostream& out, const BakedGood& b) {
      out << "* " << left << setw(10) << (b.m_type == BakedType::BREAD ? "Bread" : "Pastry");
      out << " * " << left << setw(20) << b.m_desc;
      out << " * " << left << setw(5) << b.m_expDay;
      out << " * " << left << setw(5) << b.m_stock;
      out << " * " << right << fixed << setprecision(2) << setw(8) << b.m_price;
      out << " * ";
      return out;
   }

   string Bakery::clrSpace(const string& str) {
      auto first = find_if_not(str.begin(), str.end(), [](auto c) { return isspace(c); });
      auto last = find_if_not(str.rbegin(), str.rend(), [](auto c) { return isspace(c); }).base();
      return (first >= last) ? "" : string(first, last);
   }
}