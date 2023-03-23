#ifndef SDDS_DATABASE_H_
#define SDDS_DATABASE_H_
#include <iostream>
#include <memory>
namespace sdds {
   const int m_maxEntry = 20;
   enum class Err_Status
   {
      Err_Success,
      Err_NotFound,
      Err_OutOfMemory,
   };
   class Database {
      static std::shared_ptr<Database> m_database;
      int m_noOfEntry = 0;
      std::string m_key[20]{};
      std::string m_value[20]{};
      std::string m_filename{};
      Database(const std::string& filename);
   public:
      static std::shared_ptr<Database> getInstance(const std::string& filename);
      Err_Status GetValue(const std::string& key, std::string& value);
      Err_Status SetValue(const std::string& key, const std::string& value);
      ~Database();
   };
}
#endif // !SDDS_DATABASE_H_
