#ifndef _ROS_SERVICE_Detect_h
#define _ROS_SERVICE_Detect_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/CameraInfo.h"
#include "posedetection_msgs/ObjectDetection.h"

namespace posedetection_msgs
{

static const char DETECT[] = "posedetection_msgs/Detect";

  class DetectRequest : public ros::Msg
  {
    public:
      typedef sensor_msgs::Image _image_type;
      _image_type image;
      typedef sensor_msgs::CameraInfo _camera_info_type;
      _camera_info_type camera_info;

    DetectRequest():
      image(),
      camera_info()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->image.serialize(outbuffer + offset);
      offset += this->camera_info.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->image.deserialize(inbuffer + offset);
      offset += this->camera_info.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return DETECT; };
    const char * getMD5(){ return "bfee1901edaf2aa4d9f0844a03ff634f"; };

  };

  class DetectResponse : public ros::Msg
  {
    public:
      typedef posedetection_msgs::ObjectDetection _object_detection_type;
      _object_detection_type object_detection;

    DetectResponse():
      object_detection()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->object_detection.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->object_detection.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return DETECT; };
    const char * getMD5(){ return "7b25cb2a35e9a4692af3117eeddab11b"; };

  };

  class Detect {
    public:
    typedef DetectRequest Request;
    typedef DetectResponse Response;
  };

}
#endif
