#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include <spellchecker.h>
namespace sdds {
   class Book {
      std::string b_author{};
      std::string b_title{};
      std::string b_pubCountry{};
      size_t b_pubYear{};
      double b_price{};
      std::string b_desc{};
   public:
      Book() = default;
      const std::string& title() const;
      const std::string& country() const;
      const size_t& year() const;
      double& price();
      std::string ltrim(const std::string& s);
      std::string rtrim(const std::string& s);
      std::string trim(const std::string& s);
      Book(const std::string& strBook);
      template<typename T>
      void fixSpelling(T& spellChecker) {
         spellChecker(m_description);
      }
      friend std::ostream& operator<<(std::ostream& os, const Book B);
   };
}
#endif // !SDDS_BOOK_H_
