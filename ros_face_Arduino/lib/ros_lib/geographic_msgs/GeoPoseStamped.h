#ifndef _ROS_geographic_msgs_GeoPoseStamped_h
#define _ROS_geographic_msgs_GeoPoseStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geographic_msgs/GeoPose.h"

namespace geographic_msgs
{

  class GeoPoseStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geographic_msgs::GeoPose _pose_type;
      _pose_type pose;

    GeoPoseStamped():
      header(),
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "geographic_msgs/GeoPoseStamped"; };
    const char * getMD5(){ return "cc409c8ed6064d8a846fa207bf3fba6b"; };

  };

}
#endif
