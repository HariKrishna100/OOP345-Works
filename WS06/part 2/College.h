#ifndef SDDS_COLLEGE_H_
#define SDDS_COLLEGE_H_
#include <iostream>
#include <vector>
#include <list>
#include "Person.h"
namespace sdds {
   class College {
      std::vector<Person*> m_persons;
   public:
      College() = default;
      College(const College& notToCopy) = delete;
      College& operator=(const College& notToCopy) = delete;
      ~College();
      College& operator +=(Person* thePerson);
      void display(std::ostream& out) const;
      template<typename T>
      void select(const T& test, std::list<const Person*>& persons) {
         for (auto li : m_persons) {
            if (test(li)) Person.pushback(li);
         }
      }
   };
}
#endif // !SDDS_COLLEGE_H_
