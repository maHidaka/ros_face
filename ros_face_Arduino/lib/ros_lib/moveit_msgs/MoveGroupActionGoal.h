#ifndef _ROS_moveit_msgs_MoveGroupActionGoal_h
#define _ROS_moveit_msgs_MoveGroupActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "moveit_msgs/MoveGroupGoal.h"

namespace moveit_msgs
{

  class MoveGroupActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef moveit_msgs::MoveGroupGoal _goal_type;
      _goal_type goal;

    MoveGroupActionGoal():
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

    const char * getType(){ return "moveit_msgs/MoveGroupActionGoal"; };
    const char * getMD5(){ return "df11ac1a643d87b6e6a6fe5af1823709"; };

  };

}
#endif
