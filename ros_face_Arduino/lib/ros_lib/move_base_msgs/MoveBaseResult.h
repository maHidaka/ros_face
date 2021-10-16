#ifndef _ROS_move_base_msgs_MoveBaseResult_h
#define _ROS_move_base_msgs_MoveBaseResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace move_base_msgs
{

  class MoveBaseResult : public ros::Msg
  {
    public:

    MoveBaseResult()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return "move_base_msgs/MoveBaseResult"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif
