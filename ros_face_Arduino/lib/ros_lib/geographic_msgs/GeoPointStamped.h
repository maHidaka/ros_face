#ifndef _ROS_geographic_msgs_GeoPointStamped_h
#define _ROS_geographic_msgs_GeoPointStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geographic_msgs/GeoPoint.h"

namespace geographic_msgs
{

  class GeoPointStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geographic_msgs::GeoPoint _position_type;
      _position_type position;

    GeoPointStamped():
      header(),
      position()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "geographic_msgs/GeoPointStamped"; };
    const char * getMD5(){ return "ea50d268b03080563c330351a21edc89"; };

  };

}
#endif
