#ifndef _ROS_jsk_recognition_msgs_ImageDifferenceValue_h
#define _ROS_jsk_recognition_msgs_ImageDifferenceValue_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class ImageDifferenceValue : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _difference_type;
      _difference_type difference;

    ImageDifferenceValue():
      header(),
      difference(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_difference;
      u_difference.real = this->difference;
      *(outbuffer + offset + 0) = (u_difference.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_difference.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_difference.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_difference.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->difference);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_difference;
      u_difference.base = 0;
      u_difference.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_difference.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_difference.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_difference.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->difference = u_difference.real;
      offset += sizeof(this->difference);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/ImageDifferenceValue"; };
    const char * getMD5(){ return "80b6f355db87c1b2d8b04d2f620fe0a7"; };

  };

}
#endif
