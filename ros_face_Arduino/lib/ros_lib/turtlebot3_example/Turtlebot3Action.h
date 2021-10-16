#ifndef _ROS_turtlebot3_example_Turtlebot3Action_h
#define _ROS_turtlebot3_example_Turtlebot3Action_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "turtlebot3_example/Turtlebot3ActionGoal.h"
#include "turtlebot3_example/Turtlebot3ActionResult.h"
#include "turtlebot3_example/Turtlebot3ActionFeedback.h"

namespace turtlebot3_example
{

  class Turtlebot3Action : public ros::Msg
  {
    public:
      typedef turtlebot3_example::Turtlebot3ActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef turtlebot3_example::Turtlebot3ActionResult _action_result_type;
      _action_result_type action_result;
      typedef turtlebot3_example::Turtlebot3ActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    Turtlebot3Action():
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

    const char * getType(){ return "turtlebot3_example/Turtlebot3Action"; };
    const char * getMD5(){ return "86a69578ab4eb5bb3e55984730f14503"; };

  };

}
#endif
