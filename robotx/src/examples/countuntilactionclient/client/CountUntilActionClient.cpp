
#include "CountUntilActionClient.h"


CountUntilActionClient::CountUntilActionClient(Node *parent, std::string const &service)
    : ActionClient(parent, service)
{

}

void CountUntilActionClient::setGoal(int targetNumber, double period)
{
    _goal.target_number = targetNumber;
    _goal.period = period;
}

void CountUntilActionClient::goalResponseCallback(CountUntilGoalHandle::SharedPtr const& response)
{
    if (!response)
    {
        RCLCPP_INFO(getLogger(), "Goal got rejected");
    }
    else
    {
        RCLCPP_INFO(getLogger(), "Goal got accepted");
    }
}

void CountUntilActionClient::goalResultCallback(CountUntilGoalHandle::WrappedResult const &result)
{
    RCLCPP_INFO(getLogger(), "Result: %ld", result.result->reached_number);
}