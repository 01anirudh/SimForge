#include "simforge/EventCalendar.hpp"

namespace simforge {

void EventCalendar::schedule(double time, std::function<void()> action, int priority) {
    if (time < current_time_) {
        // Can't schedule in the past
        return; 
    }
    events_.push({time, priority, std::move(action)});
}

void EventCalendar::run_until(double t_end) {
    while (!events_.empty() && events_.top().time <= t_end) {
        auto evt = events_.top();
        events_.pop();
        
        current_time_ = evt.time;
        if (evt.action) {
            evt.action();
        }
    }
    current_time_ = std::max(current_time_, t_end);
}

double EventCalendar::current_time() const {
    return current_time_;
}

} // namespace simforge
