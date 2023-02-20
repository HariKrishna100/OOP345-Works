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
#ifndef SDDS_MOVIES_H_
#define SDDS_MOVIES_H_
#include <iostream>
namespace sdds {
	class Movie {
		std::string m_movTitle{};
		size_t m_releaseYear{ 0 };
		std::string m_movDescription{};
		std::string clrSpace(const std::string strin);
	public:
		Movie() {};
		const std::string& title()const;
		Movie(const std::string& strMovie);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_movTitle);
			spellChecker(m_movDescription);
		}
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};
}
#endif // !SDDS_MOVIES_H_
