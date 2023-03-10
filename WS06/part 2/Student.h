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
      size_t m_count{ 0 };
   public:
      Student() = default;
      Student(std::istream& in);
      Student(const Student& notToCopy) = delete;
      Student& operator=(const Student& notToCopy) = delete;
      ~Student();
      std::string status() const;
      std::string name() const;
      void display(std::ostream& out) const;
   };
}
#endif // !SDDS_STUDENT_H_
