#ifndef _ROS_SERVICE_SetReferenceGeoPose_h
#define _ROS_SERVICE_SetReferenceGeoPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geographic_msgs/GeoPose.h"

namespace hector_gazebo_plugins
{

static const char SETREFERENCEGEOPOSE[] = "hector_gazebo_plugins/SetReferenceGeoPose";

  class SetReferenceGeoPoseRequest : public ros::Msg
  {
    public:
      typedef geographic_msgs::GeoPose _geo_pose_type;
      _geo_pose_type geo_pose;

    SetReferenceGeoPoseRequest():
      geo_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->geo_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->geo_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETREFERENCEGEOPOSE; };
    const char * getMD5(){ return "fe903ca95d0210defda73a1629604439"; };

  };

  class SetReferenceGeoPoseResponse : public ros::Msg
  {
    public:

    SetReferenceGeoPoseResponse()
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

    const char * getType(){ return SETREFERENCEGEOPOSE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetReferenceGeoPose {
    public:
    typedef SetReferenceGeoPoseRequest Request;
    typedef SetReferenceGeoPoseResponse Response;
  };

}
#endif
