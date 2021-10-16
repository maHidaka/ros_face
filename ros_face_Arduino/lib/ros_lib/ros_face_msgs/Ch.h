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
      typedef int8_t _mode_type;
      _mode_type mode;
      typedef int8_t _time_type;
      _time_type time;

    Ch():
      mode(0),
      time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_mode;
      u_mode.real = this->mode;
      *(outbuffer + offset + 0) = (u_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      union {
        int8_t real;
        uint8_t base;
      } u_time;
      u_time.real = this->time;
      *(outbuffer + offset + 0) = (u_time.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_mode;
      u_mode.base = 0;
      u_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mode = u_mode.real;
      offset += sizeof(this->mode);
      union {
        int8_t real;
        uint8_t base;
      } u_time;
      u_time.base = 0;
      u_time.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->time = u_time.real;
      offset += sizeof(this->time);
     return offset;
    }

    const char * getType(){ return "ros_face_msgs/Ch"; };
    const char * getMD5(){ return "0c50212cd9e0b383e239e06a5842957d"; };

  };

}
#endif
