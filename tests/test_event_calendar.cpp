#include <gtest/gtest.h>
#include "simforge/EventCalendar.hpp"

using namespace simforge;

TEST(EventCalendarTest, EventsExecuteInTimeOrder) {
    EventCalendar cal;
    std::vector<int> execution_order;
    
    cal.schedule(2.0, [&](){ execution_order.push_back(3); });
    cal.schedule(0.5, [&](){ execution_order.push_back(1); });
    cal.schedule(1.0, [&](){ execution_order.push_back(2); });
    
    cal.run_until(3.0);
    
    ASSERT_EQ(execution_order.size(), 3);
    EXPECT_EQ(execution_order[0], 1);
    EXPECT_EQ(execution_order[1], 2);
    EXPECT_EQ(execution_order[2], 3);
    EXPECT_DOUBLE_EQ(cal.current_time(), 3.0);
}

TEST(EventCalendarTest, EventsExecuteInPriorityOrder) {
    EventCalendar cal;
    std::vector<int> execution_order;
    
    cal.schedule(1.0, [&](){ execution_order.push_back(1); }, 0); // lower priority
    cal.schedule(1.0, [&](){ execution_order.push_back(2); }, 1); // higher priority
    
    cal.run_until(2.0);
    
    ASSERT_EQ(execution_order.size(), 2);
    EXPECT_EQ(execution_order[0], 2);
    EXPECT_EQ(execution_order[1], 1);
}
