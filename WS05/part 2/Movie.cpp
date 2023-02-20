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
#include <iostream>
#include <string>
#include <iomanip>
#include "Movie.h"
using namespace std;
namespace sdds {
	string Movie::clrSpace(const string strin) {
		string strcleared = strin.substr(0, strin.find_first_of(','));
		strcleared.erase(0, strcleared.find_first_not_of(' '));
		strcleared.erase(strcleared.find_last_not_of(' ') + 1);
		return strcleared;
	}

	const string& Movie::title()const {
		return m_movTitle;
	}

	Movie::Movie(const string& strMovie) {
		if (!strMovie.empty())
		{
			string info = strMovie;
			m_movTitle = clrSpace(info);

			info.erase(0, info.find_first_of(',') + 1);
			m_releaseYear = stoi(info.substr(0, info.find_first_of(',')));

			info.erase(0, info.find_first_of(',') + 1);
			m_movDescription = info.substr(info.find_first_not_of(' '));
		}
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		os << setw(40) << movie.m_movTitle << " | " << movie.m_releaseYear << " | " << movie.m_movDescription << endl;
		return os;
	}

}