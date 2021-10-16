#ifndef _ROS_SERVICE_BoundingBoxQuery_h
#define _ROS_SERVICE_BoundingBoxQuery_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace octomap_msgs
{

static const char BOUNDINGBOXQUERY[] = "octomap_msgs/BoundingBoxQuery";

  class BoundingBoxQueryRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _min_type;
      _min_type min;
      typedef geometry_msgs::Point _max_type;
      _max_type max;

    BoundingBoxQueryRequest():
      min(),
      max()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->min.serialize(outbuffer + offset);
      offset += this->max.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->min.deserialize(inbuffer + offset);
      offset += this->max.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return BOUNDINGBOXQUERY; };
    const char * getMD5(){ return "93aa3d73b866f04880927745f4aab303"; };

  };

  class BoundingBoxQueryResponse : public ros::Msg
  {
    public:

    BoundingBoxQueryResponse()
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

    const char * getType(){ return BOUNDINGBOXQUERY; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class BoundingBoxQuery {
    public:
    typedef BoundingBoxQueryRequest Request;
    typedef BoundingBoxQueryResponse Response;
  };

}
#endif
