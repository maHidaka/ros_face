#ifndef _ROS_jsk_recognition_msgs_BoundingBoxArrayWithCameraInfo_h
#define _ROS_jsk_recognition_msgs_BoundingBoxArrayWithCameraInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/BoundingBoxArray.h"
#include "sensor_msgs/CameraInfo.h"

namespace jsk_recognition_msgs
{

  class BoundingBoxArrayWithCameraInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef jsk_recognition_msgs::BoundingBoxArray _boxes_type;
      _boxes_type boxes;
      typedef sensor_msgs::CameraInfo _camera_info_type;
      _camera_info_type camera_info;

    BoundingBoxArrayWithCameraInfo():
      header(),
      boxes(),
      camera_info()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->boxes.serialize(outbuffer + offset);
      offset += this->camera_info.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->boxes.deserialize(inbuffer + offset);
      offset += this->camera_info.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/BoundingBoxArrayWithCameraInfo"; };
    const char * getMD5(){ return "e68d75609bb0b7f4ac5831524b0126e7"; };

  };

}
#endif
