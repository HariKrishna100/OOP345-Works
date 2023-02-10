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
