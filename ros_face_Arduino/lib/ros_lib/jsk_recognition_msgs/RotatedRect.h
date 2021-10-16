#ifndef _ROS_jsk_recognition_msgs_RotatedRect_h
#define _ROS_jsk_recognition_msgs_RotatedRect_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_recognition_msgs
{

  class RotatedRect : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _width_type;
      _width_type width;
      typedef float _height_type;
      _height_type height;
      typedef float _angle_type;
      _angle_type angle;

    RotatedRect():
      x(0),
      y(0),
      width(0),
      height(0),
      angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->width);
      offset += serializeAvrFloat64(outbuffer + offset, this->height);
      offset += serializeAvrFloat64(outbuffer + offset, this->angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->width));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->height));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angle));
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/RotatedRect"; };
    const char * getMD5(){ return "e970c93bbd35a570f7d9acc8228e9280"; };

  };

}
#endif
