#ifndef _ROS_SERVICE_Feature1DDetect_h
#define _ROS_SERVICE_Feature1DDetect_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"
#include "posedetection_msgs/Feature1D.h"

namespace posedetection_msgs
{

static const char FEATURE1DDETECT[] = "posedetection_msgs/Feature1DDetect";

  class Feature1DDetectRequest : public ros::Msg
  {
    public:
      typedef sensor_msgs::Image _image_type;
      _image_type image;

    Feature1DDetectRequest():
      image()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->image.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->image.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return FEATURE1DDETECT; };
    const char * getMD5(){ return "b13d2865c5af2a64e6e30ab1b56e1dd5"; };

  };

  class Feature1DDetectResponse : public ros::Msg
  {
    public:
      typedef posedetection_msgs::Feature1D _features_type;
      _features_type features;

    Feature1DDetectResponse():
      features()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->features.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->features.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return FEATURE1DDETECT; };
    const char * getMD5(){ return "37f67775de1cbab99b78b350a3d63479"; };

  };

  class Feature1DDetect {
    public:
    typedef Feature1DDetectRequest Request;
    typedef Feature1DDetectResponse Response;
  };

}
#endif
