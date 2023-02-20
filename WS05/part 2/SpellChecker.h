/*
*****************************************************************************
								  w5p2
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NCC
Date       : 2/19/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_SPELLCHECKER_H_
#define SDDS_SPELLCHECKER_H_
#include <iostream>
namespace sdds {
	class SpellChecker {
		std::string m_badWords[6]{};
		std::string m_goodWords[6]{};
		unsigned m_counter[6]{ 0 };
	public:
		SpellChecker() {};
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out);
	};
}
#endif // !SDDS_SPELLCHECKER_H_
