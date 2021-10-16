#ifndef _ROS_shape_msgs_Plane_h
#define _ROS_shape_msgs_Plane_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace shape_msgs
{

  class Plane : public ros::Msg
  {
    public:
      float coef[4];

    Plane():
      coef()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 4; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->coef[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 4; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->coef[i]));
      }
     return offset;
    }

    const char * getType(){ return "shape_msgs/Plane"; };
    const char * getMD5(){ return "2c1b92ed8f31492f8e73f6a4a44ca796"; };

  };

}
#endif
