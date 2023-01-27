#ifndef PROTEINDATABASE_H_
#define PROTEINDATABASE_H_
#include <iostream>
namespace sdds {
   class ProteinDatabase {
      size_t m_noOfStr;
      std::string* m_proteinSeqArr;
   public:
      ProteinDatabase();
      ProteinDatabase(const char* filename);
      ProteinDatabase(const ProteinDatabase& toCopy);
      ProteinDatabase& operator=(const ProteinDatabase& toCopy);
      //ProteinDatabase(ProteinDatabase&& toMove);
      //ProteinDatabase& operator=(ProteinDatabase&& toMove);
      ~ProteinDatabase();
      size_t size();
      std::string operator[](size_t);
   };
}
#endif // !PROTEINDATABASE_H_
