#ifndef SDDS_COLLEGE_H_
#define SDDS_COLLEGE_H_
#include <iostream>
#include "Person.h"
namespace sdds {
   class College {
   public:
      College(const College& notToCopy);
      College& operator=(const College& notToCopy);
      College& operator +=(Person* thePerson);
      void display(std::ostream& out) const;
   };
}
#endif // !SDDS_COLLEGE_H_
