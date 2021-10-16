#ifndef _ROS_jsk_recognition_msgs_Line_h
#define _ROS_jsk_recognition_msgs_Line_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_recognition_msgs
{

  class Line : public ros::Msg
  {
    public:
      typedef float _x1_type;
      _x1_type x1;
      typedef float _y1_type;
      _y1_type y1;
      typedef float _x2_type;
      _x2_type x2;
      typedef float _y2_type;
      _y2_type y2;

    Line():
      x1(0),
      y1(0),
      x2(0),
      y2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x1);
      offset += serializeAvrFloat64(outbuffer + offset, this->y1);
      offset += serializeAvrFloat64(outbuffer + offset, this->x2);
      offset += serializeAvrFloat64(outbuffer + offset, this->y2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y2));
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/Line"; };
    const char * getMD5(){ return "3010fad09b09b8d3fdecdd94d144f7a1"; };

  };

}
#endif
