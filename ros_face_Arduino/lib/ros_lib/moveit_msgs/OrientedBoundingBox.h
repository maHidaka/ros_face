#ifndef _ROS_moveit_msgs_OrientedBoundingBox_h
#define _ROS_moveit_msgs_OrientedBoundingBox_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point32.h"

namespace moveit_msgs
{

  class OrientedBoundingBox : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef geometry_msgs::Point32 _extents_type;
      _extents_type extents;

    OrientedBoundingBox():
      pose(),
      extents()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->extents.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->extents.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/OrientedBoundingBox"; };
    const char * getMD5(){ return "da3bd98e7cb14efa4141367a9d886ee7"; };

  };

}
#endif
