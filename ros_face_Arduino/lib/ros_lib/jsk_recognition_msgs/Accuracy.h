#ifndef _ROS_jsk_recognition_msgs_Accuracy_h
#define _ROS_jsk_recognition_msgs_Accuracy_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class Accuracy : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _accuracy_type;
      _accuracy_type accuracy;

    Accuracy():
      header(),
      accuracy(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_accuracy;
      u_accuracy.real = this->accuracy;
      *(outbuffer + offset + 0) = (u_accuracy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accuracy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accuracy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accuracy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accuracy);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_accuracy;
      u_accuracy.base = 0;
      u_accuracy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accuracy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_accuracy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_accuracy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->accuracy = u_accuracy.real;
      offset += sizeof(this->accuracy);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/Accuracy"; };
    const char * getMD5(){ return "198da9dc2684aac2aa03a85a3344f5ef"; };

  };

}
#endif
