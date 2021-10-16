#ifndef _ROS_SERVICE_RequestMarkerOperate_h
#define _ROS_SERVICE_RequestMarkerOperate_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_rviz_plugins/TransformableMarkerOperate.h"

namespace jsk_rviz_plugins
{

static const char REQUESTMARKEROPERATE[] = "jsk_rviz_plugins/RequestMarkerOperate";

  class RequestMarkerOperateRequest : public ros::Msg
  {
    public:
      typedef jsk_rviz_plugins::TransformableMarkerOperate _operate_type;
      _operate_type operate;

    RequestMarkerOperateRequest():
      operate()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->operate.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->operate.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return REQUESTMARKEROPERATE; };
    const char * getMD5(){ return "5d5e6dca1cfed7e0be1a8c17221d0619"; };

  };

  class RequestMarkerOperateResponse : public ros::Msg
  {
    public:

    RequestMarkerOperateResponse()
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

    const char * getType(){ return REQUESTMARKEROPERATE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class RequestMarkerOperate {
    public:
    typedef RequestMarkerOperateRequest Request;
    typedef RequestMarkerOperateResponse Response;
  };

}
#endif
