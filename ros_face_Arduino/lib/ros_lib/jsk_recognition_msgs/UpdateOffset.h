#ifndef _ROS_SERVICE_UpdateOffset_h
#define _ROS_SERVICE_UpdateOffset_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/TransformStamped.h"

namespace jsk_recognition_msgs
{

static const char UPDATEOFFSET[] = "jsk_recognition_msgs/UpdateOffset";

  class UpdateOffsetRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::TransformStamped _transformation_type;
      _transformation_type transformation;

    UpdateOffsetRequest():
      transformation()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->transformation.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->transformation.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return UPDATEOFFSET; };
    const char * getMD5(){ return "72c98a75ad1f2a3dcf256e7c072420a2"; };

  };

  class UpdateOffsetResponse : public ros::Msg
  {
    public:

    UpdateOffsetResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return UPDATEOFFSET; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class UpdateOffset {
    public:
    typedef UpdateOffsetRequest Request;
    typedef UpdateOffsetResponse Response;
  };

}
#endif
