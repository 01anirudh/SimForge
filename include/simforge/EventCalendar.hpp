#pragma once

#include <queue>
#include <functional>
#include "SimEvent.hpp"

namespace simforge {

class EventCalendar {
public:
    void schedule(double time, std::function<void()> action, int priority = 0);
    void run_until(double t_end);
    double current_time() const;

private:
    std::priority_queue<SimEvent> events_;
    double current_time_ = 0.0;
};

} // namespace simforge
