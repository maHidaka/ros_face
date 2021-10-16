#ifndef _ROS_posedetection_msgs_ImageFeature1D_h
#define _ROS_posedetection_msgs_ImageFeature1D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/CameraInfo.h"
#include "posedetection_msgs/Feature1D.h"

namespace posedetection_msgs
{

  class ImageFeature1D : public ros::Msg
  {
    public:
      typedef sensor_msgs::Image _image_type;
      _image_type image;
      typedef sensor_msgs::CameraInfo _info_type;
      _info_type info;
      typedef posedetection_msgs::Feature1D _features_type;
      _features_type features;

    ImageFeature1D():
      image(),
      info(),
      features()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->image.serialize(outbuffer + offset);
      offset += this->info.serialize(outbuffer + offset);
      offset += this->features.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->image.deserialize(inbuffer + offset);
      offset += this->info.deserialize(inbuffer + offset);
      offset += this->features.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "posedetection_msgs/ImageFeature1D"; };
    const char * getMD5(){ return "bfd3a262e6342c55b7e11fccf00d8b2c"; };

  };

}
#endif
