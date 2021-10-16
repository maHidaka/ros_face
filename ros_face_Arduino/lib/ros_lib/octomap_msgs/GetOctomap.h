#ifndef _ROS_SERVICE_GetOctomap_h
#define _ROS_SERVICE_GetOctomap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "octomap_msgs/Octomap.h"

namespace octomap_msgs
{

static const char GETOCTOMAP[] = "octomap_msgs/GetOctomap";

  class GetOctomapRequest : public ros::Msg
  {
    public:

    GetOctomapRequest()
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

    const char * getType(){ return GETOCTOMAP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetOctomapResponse : public ros::Msg
  {
    public:
      typedef octomap_msgs::Octomap _map_type;
      _map_type map;

    GetOctomapResponse():
      map()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->map.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->map.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETOCTOMAP; };
    const char * getMD5(){ return "be9d2869d24fe40d6bc21ac21f6bb2c5"; };

  };

  class GetOctomap {
    public:
    typedef GetOctomapRequest Request;
    typedef GetOctomapResponse Response;
  };

}
#endif
