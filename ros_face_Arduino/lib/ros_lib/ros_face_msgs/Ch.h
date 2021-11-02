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
      typedef float _time_type;
      _time_type time;

    Ch():
      state(0),
      time(0)
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
      union {
        float real;
        uint32_t base;
      } u_time;
      u_time.real = this->time;
      *(outbuffer + offset + 0) = (u_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time);
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
      union {
        float real;
        uint32_t base;
      } u_time;
      u_time.base = 0;
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->time = u_time.real;
      offset += sizeof(this->time);
     return offset;
    }

    const char * getType(){ return "ros_face_msgs/Ch"; };
    const char * getMD5(){ return "9ffa82afcde9bfe81b242e5b61986135"; };

  };

}
#endif
