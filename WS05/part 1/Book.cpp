#include <iostream>
#include <string>
#include "Book.h"
using namespace std;
namespace sdds {
   Book::Book(const std::string& strBook) {
      std::string tempStr{ strBook };
      
      std::string tempBook = strBook;
      b_author = trim(tempBook.substr(0, tempBook.find(",")));
      tempBook.erase(0, tempBook.find(",") + 1);

      b_title = trim(tempBook.substr(0, tempBook.find(",")));
      tempBook.erase(0, tempBook.find(",") + 1);

      b_pubCountry = trim(tempBook.substr(0, tempBook.find(",")));
      tempBook.erase(0, tempBook.find(",") + 1);

      b_price = std::stod(tempBook.substr(0, tempBook.find(",")));
      tempBook.erase(0, tempBook.find(",") + 1);

      b_pubYear = std::stoi(tempBook.substr(0, tempBook.find(",")));
      tempBook.erase(0, tempBook.find(",") + 1);

      b_desc = trim(tempBook.substr(0, tempBook.find(".")));
      tempBook.erase(0, tempBook.find(",") + 1);
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

   std::string Book::ltrim(const std::string& s) {
      size_t start = s.find_first_not_of(" ");
      return (start == std::string::npos) ? "" : s.substr(start);
   }
   
   std::string Book::rtrim(const std::string& s) {
      size_t end = s.find_last_not_of(" ");
      return (end == std::string::npos) ? "" : s.substr(0, end + 1);
   }

   std::string Book::trim(const std::string& s) {
      return rtrim(ltrim(s));
   }

   std::ostream& operator<<(std::ostream& os, const Book B) {
      os.width(20);
      os << B.b_author<< " | ";

      os.width(22);
      os << B.title() << " | ";

      os.width(5);
      os << B.country() << " | ";

      os.width(4);
      os << B.year() << " | ";

      os.width(6);
      os.setf(std::ios::fixed);
      os.precision(2);
      os << B.b_price << " | ";

      os.setf(std::ios::left);
      os << B.b_desc << "." << std::endl;
      os.unsetf(std::ios::left);
      return os;
   }
}