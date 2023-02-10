/*
*****************************************************************************
                          w2p2
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NCC
Date       : 1/28/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "TimedTask.h"
using namespace std;
namespace sdds {
   void TimedTask::startClock() {
      m_startTime = std::chrono::steady_clock::now();
   }

   void TimedTask::stopClock() {
      m_endTime = std::chrono::steady_clock::now();
   }

   void TimedTask::addTask(const char* taskName) {
      if (m_noOfRecords < 10) {
         if (taskName) {
            m_tasks[m_noOfRecords].m_taskName = taskName;
            m_tasks[m_noOfRecords].m_unitsOfTime = "nanoseconds";
            m_tasks[m_noOfRecords].m_taskDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
            m_noOfRecords++;
         }
      }
   }

   std::ostream& operator<<(std::ostream& ostr, const TimedTask& T) {
      ostr << "--------------------------" << endl;
      ostr << "Execution Times:" << endl;
      ostr << "--------------------------" << endl;
      for (int i = 0; i < T.m_noOfRecords; i++) {
         ostr.width(23);
         ostr.setf(ios::left);
         ostr << T.m_tasks[i].m_taskName;
         ostr.unsetf(ios::left);

         ostr.width(23);
         ostr.setf(ios::right);
         ostr << T.m_tasks[i].m_taskDuration.count() << " " << T.m_tasks[i].m_unitsOfTime << endl;
         ostr.unsetf(ios::right);
      }
      ostr << "--------------------------" << endl;

      return ostr;
   }
}