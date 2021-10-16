#ifndef _ROS_jsk_recognition_msgs_RotatedRectStamped_h
#define _ROS_jsk_recognition_msgs_RotatedRectStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/RotatedRect.h"

namespace jsk_recognition_msgs
{

  class RotatedRectStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef jsk_recognition_msgs::RotatedRect _rect_type;
      _rect_type rect;

    RotatedRectStamped():
      header(),
      rect()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->rect.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->rect.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/RotatedRectStamped"; };
    const char * getMD5(){ return "0260299b5425567e14c7b295b58829e9"; };

  };

}
#endif
