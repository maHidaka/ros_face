#ifndef _ROS_moveit_msgs_MoveGroupAction_h
#define _ROS_moveit_msgs_MoveGroupAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/MoveGroupActionGoal.h"
#include "moveit_msgs/MoveGroupActionResult.h"
#include "moveit_msgs/MoveGroupActionFeedback.h"

namespace moveit_msgs
{

  class MoveGroupAction : public ros::Msg
  {
    public:
      typedef moveit_msgs::MoveGroupActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef moveit_msgs::MoveGroupActionResult _action_result_type;
      _action_result_type action_result;
      typedef moveit_msgs::MoveGroupActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    MoveGroupAction():
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

    const char * getType(){ return "moveit_msgs/MoveGroupAction"; };
    const char * getMD5(){ return "be9c7984423000efe94194063f359cfc"; };

  };

}
#endif
