/*
*****************************************************************************
                          part - #2
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NCC
Date       : 12/2/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_CHILD_H_
#define SDDS_CHILD_H_
#include <iostream>
namespace sdds {
   class Child {
      std::string c_name;
      int c_age{ 0 };
      const Toy** c_toys{ nullptr };
      size_t c_noOfToys{ 0 };
   public:
      Child() = default;
      Child(std::string name, int age, const Toy* toys[], size_t count);
      Child(const Child& toCopy);
      Child& operator=(const Child& toCopy);
      Child(Child&& toMove);
      Child& operator=(Child&& toMove);
      ~Child();
      size_t size() const;
      void deallocate();
      friend std::ostream& operator<<(std::ostream& os, const Child& C);
   };
}
#endif // !SDDS_CHILD_H_
