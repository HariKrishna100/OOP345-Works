#include <iostream>
#include "ProteinDatabase.h"
using namespace std;
namespace sdds {
   ProteinDatabase::ProteinDatabase() {
      m_noOfStr = 0;
      m_proteinSeqArr = nullptr;
   }

   ProteinDatabase::ProteinDatabase(const char* filename) {

   }

   ProteinDatabase::ProteinDatabase(const ProteinDatabase& toCopy) {

   }

   ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& toCopy) {
      // TODO: insert return statement here
   }

   ProteinDatabase::ProteinDatabase(ProteinDatabase&& toMove) {

   }

   ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& toMove) {
      // TODO: insert return statement here
   }

   ProteinDatabase::~ProteinDatabase() {

   }

   size_t ProteinDatabase::size() {
      return size_t();
   }

   std::string ProteinDatabase::operator[](size_t) {
      return std::string();
   }
}