#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include <iostream>
#include "Person.h"
namespace sdds {
   class Student: public Person {
      std::string m_name{};
      std::string m_age{};
      std::string m_id{};
      std::string* m_courses{};
      int m_count{ 0 };
   public:
      Student() = default;
      Student(std::istream& is);
      Student(const Student& notToCopy) = delete;
      Student& operator=(const Student& notToCopy) = delete;
      std::string status() const;
      std::string name() const;
      std::string id() const;
      std::string age() const;
      void display(std::ostream& out) const;
      std::string clrSpace(const std::string str);
   };
}
#endif // !SDDS_STUDENT_H_
