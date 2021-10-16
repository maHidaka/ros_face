#ifndef _ROS_SERVICE_Feature0DDetect_h
#define _ROS_SERVICE_Feature0DDetect_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"
#include "posedetection_msgs/Feature0D.h"

namespace posedetection_msgs
{

static const char FEATURE0DDETECT[] = "posedetection_msgs/Feature0DDetect";

  class Feature0DDetectRequest : public ros::Msg
  {
    public:
      typedef sensor_msgs::Image _image_type;
      _image_type image;

    Feature0DDetectRequest():
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

    const char * getType(){ return FEATURE0DDETECT; };
    const char * getMD5(){ return "b13d2865c5af2a64e6e30ab1b56e1dd5"; };

  };

  class Feature0DDetectResponse : public ros::Msg
  {
    public:
      typedef posedetection_msgs::Feature0D _features_type;
      _features_type features;

    Feature0DDetectResponse():
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

    const char * getType(){ return FEATURE0DDETECT; };
    const char * getMD5(){ return "fa5677bbe36e6cfb2be31b9bbea8bcae"; };

  };

  class Feature0DDetect {
    public:
    typedef Feature0DDetectRequest Request;
    typedef Feature0DDetectResponse Response;
  };

}
#endif
