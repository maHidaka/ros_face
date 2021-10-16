#ifndef _ROS_ros_face_msgs_Ch_h
#define _ROS_ros_face_msgs_Ch_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_face_msgs
{

  class Ch : public ros::Msg
  {
    public:
      typedef bool _state_type;
      _state_type state;

    Ch():
      state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->state = u_state.real;
      offset += sizeof(this->state);
     return offset;
    }

    const char * getType(){ return "ros_face_msgs/Ch"; };
    const char * getMD5(){ return "001fde3cab9e313a150416ff09c08ee4"; };

  };

}
#endif
