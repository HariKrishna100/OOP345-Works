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

   shared_ptr<Database> Database::getInstance(const std::string& filename) {
      if(m_database)
   }

   Err_Status Database::GetValue(const std::string& key, std::string& value) {
      
   }

   Err_Status Database::SetValue(const std::string& key, const std::string& value) {
     
   }

   Database::~Database() {

   }
}