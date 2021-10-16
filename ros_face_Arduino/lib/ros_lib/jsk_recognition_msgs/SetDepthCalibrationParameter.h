#ifndef _ROS_SERVICE_SetDepthCalibrationParameter_h
#define _ROS_SERVICE_SetDepthCalibrationParameter_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_recognition_msgs/DepthCalibrationParameter.h"

namespace jsk_recognition_msgs
{

static const char SETDEPTHCALIBRATIONPARAMETER[] = "jsk_recognition_msgs/SetDepthCalibrationParameter";

  class SetDepthCalibrationParameterRequest : public ros::Msg
  {
    public:
      typedef jsk_recognition_msgs::DepthCalibrationParameter _parameter_type;
      _parameter_type parameter;

    SetDepthCalibrationParameterRequest():
      parameter()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->parameter.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->parameter.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETDEPTHCALIBRATIONPARAMETER; };
    const char * getMD5(){ return "46b1552cd9512adcf9bbec97800b0e0d"; };

  };

  class SetDepthCalibrationParameterResponse : public ros::Msg
  {
    public:

    SetDepthCalibrationParameterResponse()
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

    const char * getType(){ return SETDEPTHCALIBRATIONPARAMETER; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetDepthCalibrationParameter {
    public:
    typedef SetDepthCalibrationParameterRequest Request;
    typedef SetDepthCalibrationParameterResponse Response;
  };

}
#endif
