#ifndef _ROS_SERVICE_CallSnapIt_h
#define _ROS_SERVICE_CallSnapIt_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_recognition_msgs/SnapItRequest.h"
#include "geometry_msgs/Pose.h"

namespace jsk_recognition_msgs
{

static const char CALLSNAPIT[] = "jsk_recognition_msgs/CallSnapIt";

  class CallSnapItRequest : public ros::Msg
  {
    public:
      typedef jsk_recognition_msgs::SnapItRequest _request_type;
      _request_type request;

    CallSnapItRequest():
      request()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->request.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->request.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return CALLSNAPIT; };
    const char * getMD5(){ return "5bf1ef2f060949ff03f39c08eb7bc6de"; };

  };

  class CallSnapItResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _transformation_type;
      _transformation_type transformation;

    CallSnapItResponse():
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

    const char * getType(){ return CALLSNAPIT; };
    const char * getMD5(){ return "d787e2767b5ea7b19a81c647df92a8de"; };

  };

  class CallSnapIt {
    public:
    typedef CallSnapItRequest Request;
    typedef CallSnapItResponse Response;
  };

}
#endif
