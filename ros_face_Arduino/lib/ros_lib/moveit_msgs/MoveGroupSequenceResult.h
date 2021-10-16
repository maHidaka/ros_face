#ifndef _ROS_moveit_msgs_MoveGroupSequenceResult_h
#define _ROS_moveit_msgs_MoveGroupSequenceResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/MotionSequenceResponse.h"

namespace moveit_msgs
{

  class MoveGroupSequenceResult : public ros::Msg
  {
    public:
      typedef moveit_msgs::MotionSequenceResponse _response_type;
      _response_type response;

    MoveGroupSequenceResult():
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

    const char * getType(){ return "moveit_msgs/MoveGroupSequenceResult"; };
    const char * getMD5(){ return "039cee462ada3f0feb5f4e2e12baefae"; };

  };

}
#endif
