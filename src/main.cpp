#include <iostream>
#include "simforge/EventCalendar.hpp"

int main() {
    std::cout << "SimForge - Real-Time Discrete-Event Simulation Engine" << std::endl;
    
    simforge::EventCalendar calendar;
    
    calendar.schedule(1.5, [](){ std::cout << "Event 1 executed at t=1.5\n"; });
    calendar.schedule(0.5, [](){ std::cout << "Event 2 executed at t=0.5\n"; });
    calendar.schedule(2.0, [](){ std::cout << "Event 3 executed at t=2.0\n"; });
    
    std::cout << "Running simulation until t=3.0..." << std::endl;
    calendar.run_until(3.0);
    
    return 0;
}
