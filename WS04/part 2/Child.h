#ifndef SDDS_CHILD_H_
#define SDDS_CHILD_H_
#include <iostream>
namespace sdds {
   class Child {
      const sdds::Toy** m_toys;
   public:
      Child(std::string name, int age, const Toy* toys[], size_t count);
      size_t size() const;
   };
}
#endif // !SDDS_CHILD_H_
