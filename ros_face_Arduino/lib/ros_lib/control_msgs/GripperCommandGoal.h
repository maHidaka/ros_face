#ifndef _ROS_control_msgs_GripperCommandGoal_h
#define _ROS_control_msgs_GripperCommandGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "control_msgs/GripperCommand.h"

namespace control_msgs
{

  class GripperCommandGoal : public ros::Msg
  {
    public:
      typedef control_msgs::GripperCommand _command_type;
      _command_type command;

    GripperCommandGoal():
      command()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->command.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->command.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "control_msgs/GripperCommandGoal"; };
    const char * getMD5(){ return "86fd82f4ddc48a4cb6856cfa69217e43"; };

  };

}
#endif
