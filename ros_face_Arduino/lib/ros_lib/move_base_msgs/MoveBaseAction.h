#ifndef _ROS_move_base_msgs_MoveBaseAction_h
#define _ROS_move_base_msgs_MoveBaseAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "move_base_msgs/MoveBaseActionGoal.h"
#include "move_base_msgs/MoveBaseActionResult.h"
#include "move_base_msgs/MoveBaseActionFeedback.h"

namespace move_base_msgs
{

  class MoveBaseAction : public ros::Msg
  {
    public:
      typedef move_base_msgs::MoveBaseActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef move_base_msgs::MoveBaseActionResult _action_result_type;
      _action_result_type action_result;
      typedef move_base_msgs::MoveBaseActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    MoveBaseAction():
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

    const char * getType(){ return "move_base_msgs/MoveBaseAction"; };
    const char * getMD5(){ return "70b6aca7c7f7746d8d1609ad94c80bb8"; };

  };

}
#endif
