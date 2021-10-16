#ifndef _ROS_moveit_msgs_PositionConstraint_h
#define _ROS_moveit_msgs_PositionConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"
#include "moveit_msgs/BoundingVolume.h"

namespace moveit_msgs
{

  class PositionConstraint : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _link_name_type;
      _link_name_type link_name;
      typedef geometry_msgs::Vector3 _target_point_offset_type;
      _target_point_offset_type target_point_offset;
      typedef moveit_msgs::BoundingVolume _constraint_region_type;
      _constraint_region_type constraint_region;
      typedef float _weight_type;
      _weight_type weight;

    PositionConstraint():
      header(),
      link_name(""),
      target_point_offset(),
      constraint_region(),
      weight(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_link_name = strlen(this->link_name);
      varToArr(outbuffer + offset, length_link_name);
      offset += 4;
      memcpy(outbuffer + offset, this->link_name, length_link_name);
      offset += length_link_name;
      offset += this->target_point_offset.serialize(outbuffer + offset);
      offset += this->constraint_region.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->weight);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_link_name;
      arrToVar(length_link_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_name-1]=0;
      this->link_name = (char *)(inbuffer + offset-1);
      offset += length_link_name;
      offset += this->target_point_offset.deserialize(inbuffer + offset);
      offset += this->constraint_region.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->weight));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PositionConstraint"; };
    const char * getMD5(){ return "c83edf208d87d3aa3169f47775a58e6a"; };

  };

}
#endif
