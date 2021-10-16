#ifndef _ROS_moveit_msgs_WorkspaceParameters_h
#define _ROS_moveit_msgs_WorkspaceParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"

namespace moveit_msgs
{

  class WorkspaceParameters : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Vector3 _min_corner_type;
      _min_corner_type min_corner;
      typedef geometry_msgs::Vector3 _max_corner_type;
      _max_corner_type max_corner;

    WorkspaceParameters():
      header(),
      min_corner(),
      max_corner()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->min_corner.serialize(outbuffer + offset);
      offset += this->max_corner.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->min_corner.deserialize(inbuffer + offset);
      offset += this->max_corner.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/WorkspaceParameters"; };
    const char * getMD5(){ return "d639a834e7b1f927e9f1d6c30e920016"; };

  };

}
#endif
