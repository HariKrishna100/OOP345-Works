#ifndef SDDS_EMPLOYEE_H_
# define SDDS_EMPLOYEE_H_
#include <iostream>
#include "Person.h"
namespace sdds {
   class Employee: public Person {
      std::string m_name{};
      int m_age{};
      std::string m_id{};
   public:
      Employee(std::istream& is);
      std::string status() const;
      std::string name() const;
      std::string id() const;
      std::string age() const;
      void display(std::ostream& out) const;
   };
}
#endif // !SDDS_EMPLOYEE_H_
