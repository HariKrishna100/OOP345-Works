#include <iostream>
#include <string>
#include "Book.h"
using namespace std;
namespace sdds {
   Book::Book(const std::string& strBook) {
      std::string tempStr{ strBook };
      
   }

   const std::string& Book::title() const {
      return b_title;
   }

   const std::string& Book::country() const {
      return b_pubCountry;
   }

   const size_t& Book::year() const {
      return b_pubYear;
   }

   double& Book::price() {
      return b_price;
   }

   std::ostream& operator<<(std::ostream& os, const Book B) {
      return os;
   }
}