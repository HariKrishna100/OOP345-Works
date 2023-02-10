#ifndef SDDS_TIMEDTASK_H_
#define SDDS_TIMEDTASK_H_
#include <iostream>
#include <chrono>
namespace sdds {
   struct Task {
      std::string m_taskName{};
      std::string m_unitsOfTime{};
      std::chrono::steady_clock::duration m_taskDuration{};
   };

   class TimedTask {
      int m_noOfRecords{};
      std::chrono::steady_clock::time_point m_startTime{};
      std::chrono::steady_clock::time_point m_endTime{};
      Task m_tasks[10]{};
   public:
      TimedTask() = default;
      void startClock();
      void stopClock();
      void addTask(const char* taskName);
      friend std::ostream& operator<<(std::ostream& ostr, const TimedTask& T);
   };
}
#endif // !SDDS_TIMEDTASK_H_
