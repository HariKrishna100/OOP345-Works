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
      
      while (!file.eof()) {
         BakedGood bItems{};
         getline(file, data);

      }
   }

   void Bakery::showGoods(ostream& os) const {

   }

   ostream& operator<<(ostream& out, const BakedGood& b) {
      
   }
}