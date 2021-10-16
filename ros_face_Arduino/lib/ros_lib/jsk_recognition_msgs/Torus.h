#ifndef _ROS_jsk_recognition_msgs_Torus_h
#define _ROS_jsk_recognition_msgs_Torus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"

namespace jsk_recognition_msgs
{

  class Torus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _failure_type;
      _failure_type failure;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef float _large_radius_type;
      _large_radius_type large_radius;
      typedef float _small_radius_type;
      _small_radius_type small_radius;

    Torus():
      header(),
      failure(0),
      pose(),
      large_radius(0),
      small_radius(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_failure;
      u_failure.real = this->failure;
      *(outbuffer + offset + 0) = (u_failure.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->failure);
      offset += this->pose.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->large_radius);
      offset += serializeAvrFloat64(outbuffer + offset, this->small_radius);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_failure;
      u_failure.base = 0;
      u_failure.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->failure = u_failure.real;
      offset += sizeof(this->failure);
      offset += this->pose.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->large_radius));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->small_radius));
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/Torus"; };
    const char * getMD5(){ return "7172d433485e406ce56f4cf6e9ab1062"; };

  };

}
#endif
