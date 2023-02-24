#include <iostream>
#include <fstream>
#include <string>
using namespace std;
namespace sdds {
   class ProteinDatabase {
      int m_noOfStr{};
      std::string* m_proteinSeqArr{};
   public:
      ProteinDatabase() = default;
      ProteinDatabase(const char* filename) {
         string temp{};
         int i = 0;
         ifstream file;
         file.open(filename);
         if (file) {
            while (file) {
               char type = '\0';
               file.get(type);
               if (type == '>') {
                  m_noOfStr++;
               }
            }
            file.clear();
            file.seekg(0);

            m_proteinSeqArr = new string[m_noOfStr];
            file.ignore(1000, '\n');

            while (getline(file, temp)) {
               if (temp[0] != '>') {
                  m_proteinSeqArr[i] += temp;
               }
               else {
                  if (i < m_noOfStr) i++;
               }
            }
         }
      }
      ProteinDatabase(const ProteinDatabase& toCopy) { operator=(toCopy); }
      ProteinDatabase& operator=(const ProteinDatabase& toCopy) {
         if (this != &toCopy) {
            delete[] m_proteinSeqArr;
            m_proteinSeqArr = nullptr;

            m_noOfStr = toCopy.m_noOfStr;

            m_proteinSeqArr = new string[toCopy.m_noOfStr + 1];
            for (int i = 0; i < toCopy.m_noOfStr; i++) {
               m_proteinSeqArr[i] = toCopy.m_proteinSeqArr[i];
            }
         }
         return *this;
      }
      ProteinDatabase(ProteinDatabase&& toMove) noexcept { operator=(move(toMove)); }
      ProteinDatabase& operator=(ProteinDatabase&& toMove) noexcept {
         if (this != &toMove) {
            delete[] m_proteinSeqArr;
            m_proteinSeqArr = toMove.m_proteinSeqArr;
            toMove.m_proteinSeqArr = nullptr;

            m_noOfStr = toMove.m_noOfStr;
            toMove.m_noOfStr = 0;
         }
         return *this;
      }
      ~ProteinDatabase() { delete[] m_proteinSeqArr; }
      int size() { return m_noOfStr; }
      std::string operator[](int index) {
         if (index > m_noOfStr - 1 || m_noOfStr == 0) {
            return "";
         }
         return m_proteinSeqArr[index];
      }
   };
}