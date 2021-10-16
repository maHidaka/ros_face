#ifndef _ROS_jsk_recognition_msgs_SimpleHandle_h
#define _ROS_jsk_recognition_msgs_SimpleHandle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"

namespace jsk_recognition_msgs
{

  class SimpleHandle : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef float _handle_width_type;
      _handle_width_type handle_width;

    SimpleHandle():
      header(),
      pose(),
      handle_width(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->handle_width);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->handle_width));
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/SimpleHandle"; };
    const char * getMD5(){ return "3a87e21f72b9ed7090c46a47617b0740"; };

  };

}
#endif
