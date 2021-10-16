#ifndef _ROS_jsk_recognition_msgs_TrackingStatus_h
#define _ROS_jsk_recognition_msgs_TrackingStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class TrackingStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _is_lost_type;
      _is_lost_type is_lost;

    TrackingStatus():
      header(),
      is_lost(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_lost;
      u_is_lost.real = this->is_lost;
      *(outbuffer + offset + 0) = (u_is_lost.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_lost);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_lost;
      u_is_lost.base = 0;
      u_is_lost.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_lost = u_is_lost.real;
      offset += sizeof(this->is_lost);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/TrackingStatus"; };
    const char * getMD5(){ return "2e374cd736cf06cc3e69b0c76b8cb117"; };

  };

}
#endif
