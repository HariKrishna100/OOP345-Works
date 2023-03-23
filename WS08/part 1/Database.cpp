#include <iostream>
#include <fstream>
#include "Database.h"
using namespace std;
namespace sdds {
   Database::Database(const std::string& filename) {

   }

   shared_ptr<Database> Database::getInstance(const std::string& filename) {

   }

   Err_Status Database::GetValue(const std::string& key, std::string& value) {
      
   }

   Err_Status Database::SetValue(const std::string& key, const std::string& value) {
     
   }

   Database::~Database() {

   }
}