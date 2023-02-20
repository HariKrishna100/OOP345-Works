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
#include <iomanip>
#include <fstream>
#include "SpellChecker.h"
namespace sdds {
	unsigned  counter = 0u;

	SpellChecker::SpellChecker(const char* filename) {
		if (filename)
		{
			//if the file is not exist throw a char* type of exception with msg
			std::ifstream fin(filename);
			if (!fin)
			{
				throw "Bad file name!";
			}

			unsigned noOfWords = 0u;
			while (fin >> m_badWords[noOfWords] >> m_goodWords[noOfWords])
			{
				noOfWords++;
			}
		}
	}

	void SpellChecker::operator()(std::string& text) {
		if (!text.empty())
		{
			for (unsigned i = 0u; i < 6; i++)
			{
				//go throw the whole text to find the bad word and repalce them with good one
				while (text.find(m_badWords[i]) < text.size())
				{
					text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
					m_counter[i]++;
				}
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) {
		out << "Spellchecker Statistics" << std::endl;
		//print the times of replacement for all the bad words
		for (unsigned i = 0; i < 6; i++) {
			out << std::setw(15) << std::right << m_badWords[i] << ": " << m_counter[i] << " replacements" << std::endl;
		}
	}
}