#pragma once

#include <functional>

namespace simforge {

struct SimEvent {
    double time;
    int priority;
    std::function<void()> action;

    // For priority_queue, we want the *smallest* time to be on top.
    // So this returns true if this event is "greater" than o.
    bool operator<(const SimEvent& o) const {
        if (time == o.time) {
            return priority > o.priority; // higher priority executes first if times are equal
        }
        return time > o.time;
    }
};

} // namespace simforge
