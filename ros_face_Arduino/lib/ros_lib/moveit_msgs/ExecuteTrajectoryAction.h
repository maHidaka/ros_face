#ifndef _ROS_moveit_msgs_ExecuteTrajectoryAction_h
#define _ROS_moveit_msgs_ExecuteTrajectoryAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/ExecuteTrajectoryActionGoal.h"
#include "moveit_msgs/ExecuteTrajectoryActionResult.h"
#include "moveit_msgs/ExecuteTrajectoryActionFeedback.h"

namespace moveit_msgs
{

  class ExecuteTrajectoryAction : public ros::Msg
  {
    public:
      typedef moveit_msgs::ExecuteTrajectoryActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef moveit_msgs::ExecuteTrajectoryActionResult _action_result_type;
      _action_result_type action_result;
      typedef moveit_msgs::ExecuteTrajectoryActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    ExecuteTrajectoryAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/ExecuteTrajectoryAction"; };
    const char * getMD5(){ return "24e882ecd7f84f3e3299d504b8e3deae"; };

  };

}
#endif
