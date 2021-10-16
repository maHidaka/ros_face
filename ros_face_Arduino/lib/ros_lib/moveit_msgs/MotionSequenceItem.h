#ifndef _ROS_moveit_msgs_MotionSequenceItem_h
#define _ROS_moveit_msgs_MotionSequenceItem_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/MotionPlanRequest.h"

namespace moveit_msgs
{

  class MotionSequenceItem : public ros::Msg
  {
    public:
      typedef moveit_msgs::MotionPlanRequest _req_type;
      _req_type req;
      typedef float _blend_radius_type;
      _blend_radius_type blend_radius;

    MotionSequenceItem():
      req(),
      blend_radius(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->req.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->blend_radius);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->req.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->blend_radius));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/MotionSequenceItem"; };
    const char * getMD5(){ return "932aef4280f479e42c693b8b285624bf"; };

  };

}
#endif
