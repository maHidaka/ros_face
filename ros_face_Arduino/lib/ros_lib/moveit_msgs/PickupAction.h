#ifndef _ROS_moveit_msgs_PickupAction_h
#define _ROS_moveit_msgs_PickupAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/PickupActionGoal.h"
#include "moveit_msgs/PickupActionResult.h"
#include "moveit_msgs/PickupActionFeedback.h"

namespace moveit_msgs
{

  class PickupAction : public ros::Msg
  {
    public:
      typedef moveit_msgs::PickupActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef moveit_msgs::PickupActionResult _action_result_type;
      _action_result_type action_result;
      typedef moveit_msgs::PickupActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    PickupAction():
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

    const char * getType(){ return "moveit_msgs/PickupAction"; };
    const char * getMD5(){ return "966c9238fcaad4ba8d20e116b676ccc1"; };

  };

}
#endif
