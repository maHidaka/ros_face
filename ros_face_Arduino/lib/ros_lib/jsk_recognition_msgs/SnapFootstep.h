#ifndef _ROS_SERVICE_SnapFootstep_h
#define _ROS_SERVICE_SnapFootstep_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_footstep_msgs/FootstepArray.h"

namespace jsk_recognition_msgs
{

static const char SNAPFOOTSTEP[] = "jsk_recognition_msgs/SnapFootstep";

  class SnapFootstepRequest : public ros::Msg
  {
    public:
      typedef jsk_footstep_msgs::FootstepArray _input_type;
      _input_type input;

    SnapFootstepRequest():
      input()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->input.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->input.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SNAPFOOTSTEP; };
    const char * getMD5(){ return "acbed27d6a2c527657315248d9480de2"; };

  };

  class SnapFootstepResponse : public ros::Msg
  {
    public:
      typedef jsk_footstep_msgs::FootstepArray _output_type;
      _output_type output;

    SnapFootstepResponse():
      output()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->output.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->output.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SNAPFOOTSTEP; };
    const char * getMD5(){ return "626bcd752f55cb0f7d967a8b0b14cc89"; };

  };

  class SnapFootstep {
    public:
    typedef SnapFootstepRequest Request;
    typedef SnapFootstepResponse Response;
  };

}
#endif
