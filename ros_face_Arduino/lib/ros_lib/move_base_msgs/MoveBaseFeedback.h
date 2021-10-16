#ifndef _ROS_move_base_msgs_MoveBaseFeedback_h
#define _ROS_move_base_msgs_MoveBaseFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace move_base_msgs
{

  class MoveBaseFeedback : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _base_position_type;
      _base_position_type base_position;

    MoveBaseFeedback():
      base_position()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->base_position.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->base_position.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "move_base_msgs/MoveBaseFeedback"; };
    const char * getMD5(){ return "3fb824c456a757373a226f6d08071bf0"; };

  };

}
#endif
