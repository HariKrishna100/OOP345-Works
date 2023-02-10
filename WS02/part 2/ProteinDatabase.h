/*
*****************************************************************************
                          w2p2
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NCC
Date       : 1/28/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef PROTEINDATABASE_H_
#define PROTEINDATABASE_H_
#include <iostream>
namespace sdds {
   class ProteinDatabase {
      int m_noOfStr{};
      std::string* m_proteinSeqArr{};
   public:
      ProteinDatabase() = default;
      ProteinDatabase(const char* filename);
      ProteinDatabase(const ProteinDatabase& toCopy);
      ProteinDatabase& operator=(const ProteinDatabase& toCopy);
      ProteinDatabase(ProteinDatabase&& toMove) noexcept;
      ProteinDatabase& operator=(ProteinDatabase&& toMove) noexcept;
      ~ProteinDatabase();
      int size();
      std::string operator[](int);
   };
}
#endif // !PROTEINDATABASE_H_
