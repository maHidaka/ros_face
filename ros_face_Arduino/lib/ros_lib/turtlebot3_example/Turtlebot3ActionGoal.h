#ifndef _ROS_turtlebot3_example_Turtlebot3ActionGoal_h
#define _ROS_turtlebot3_example_Turtlebot3ActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "turtlebot3_example/Turtlebot3Goal.h"

namespace turtlebot3_example
{

  class Turtlebot3ActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef turtlebot3_example::Turtlebot3Goal _goal_type;
      _goal_type goal;

    Turtlebot3ActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "turtlebot3_example/Turtlebot3ActionGoal"; };
    const char * getMD5(){ return "629663823fea578d64180162f10bec87"; };

  };

}
#endif
