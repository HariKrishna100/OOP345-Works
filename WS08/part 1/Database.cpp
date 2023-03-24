#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "Database.h"
using namespace std;
namespace sdds {
   Database::Database(const std::string& filename) {
      m_filename = filename;
      ifstream file(filename);
      string key{}, value{};

      cout << "[" << this << "]" << " Database(const std::string&)" << endl;
      while (file >> key >> value) {
         replace(key.begin(), key.end(), '-', ' ');
         SetValue(key, value);
      }
      file.close();
   }

   std::shared_ptr<Database> Database::getInstance(const std::string& filename) {
      return (m_database) ? m_database : m_database = std::shared_ptr<Database>(new Database(filename));
   }

   Err_Status Database::GetValue(const std::string& key, std::string& value) {
      Err_Status status{ Err_Status::Err_NotFound };
      int flag = 0;
      for (int i = 0; i < m_noOfEntry && flag == 0; i++){
         if (m_key[i] == key) 
            m_value[i] = value;
         status = { Err_Status::Err_Success };
         flag = 1;
      }
      return status;
   }

   Err_Status Database::SetValue(const std::string& key, const std::string& value) {
      Err_Status status{ Err_Status::Err_OutOfMemory };
      if (m_noOfEntry < m_maxEntry) {
         status = { Err_Status::Err_Success };
         m_noOfEntry++;
         m_key[m_noOfEntry] = key;
         m_value[m_noOfEntry] = value;
      }
      return status;
   }

   Database::~Database() {
      for (int i = 0; i < m_noOfEntry; i++) {
         cout << "[" << this << "]" << "~Database()";
         ofstream databaseBackup(m_filename + ".bkp.txt");
         for (int i = 0; i < m_noOfEntry; i++) {
            databaseBackup << setw(25) << left << m_key[i] << " -> " << m_value[i] << endl;
         }
      }
   }
}