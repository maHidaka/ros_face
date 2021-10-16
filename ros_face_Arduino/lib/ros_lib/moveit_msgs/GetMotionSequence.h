#ifndef _ROS_SERVICE_GetMotionSequence_h
#define _ROS_SERVICE_GetMotionSequence_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/MotionSequenceRequest.h"
#include "moveit_msgs/MotionSequenceResponse.h"

namespace moveit_msgs
{

static const char GETMOTIONSEQUENCE[] = "moveit_msgs/GetMotionSequence";

  class GetMotionSequenceRequest : public ros::Msg
  {
    public:
      typedef moveit_msgs::MotionSequenceRequest _request_type;
      _request_type request;

    GetMotionSequenceRequest():
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

    const char * getType(){ return GETMOTIONSEQUENCE; };
    const char * getMD5(){ return "bae3996834a2cd1013b32c29e6a79b4e"; };

  };

  class GetMotionSequenceResponse : public ros::Msg
  {
    public:
      typedef moveit_msgs::MotionSequenceResponse _response_type;
      _response_type response;

    GetMotionSequenceResponse():
      response()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->response.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->response.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETMOTIONSEQUENCE; };
    const char * getMD5(){ return "039cee462ada3f0feb5f4e2e12baefae"; };

  };

  class GetMotionSequence {
    public:
    typedef GetMotionSequenceRequest Request;
    typedef GetMotionSequenceResponse Response;
  };

}
#endif
