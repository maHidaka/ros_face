#ifndef _ROS_moveit_msgs_JointConstraint_h
#define _ROS_moveit_msgs_JointConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

  class JointConstraint : public ros::Msg
  {
    public:
      typedef const char* _joint_name_type;
      _joint_name_type joint_name;
      typedef float _position_type;
      _position_type position;
      typedef float _tolerance_above_type;
      _tolerance_above_type tolerance_above;
      typedef float _tolerance_below_type;
      _tolerance_below_type tolerance_below;
      typedef float _weight_type;
      _weight_type weight;

    JointConstraint():
      joint_name(""),
      position(0),
      tolerance_above(0),
      tolerance_below(0),
      weight(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_joint_name = strlen(this->joint_name);
      varToArr(outbuffer + offset, length_joint_name);
      offset += 4;
      memcpy(outbuffer + offset, this->joint_name, length_joint_name);
      offset += length_joint_name;
      offset += serializeAvrFloat64(outbuffer + offset, this->position);
      offset += serializeAvrFloat64(outbuffer + offset, this->tolerance_above);
      offset += serializeAvrFloat64(outbuffer + offset, this->tolerance_below);
      offset += serializeAvrFloat64(outbuffer + offset, this->weight);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_joint_name;
      arrToVar(length_joint_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_joint_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_joint_name-1]=0;
      this->joint_name = (char *)(inbuffer + offset-1);
      offset += length_joint_name;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tolerance_above));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tolerance_below));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->weight));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/JointConstraint"; };
    const char * getMD5(){ return "c02a15146bec0ce13564807805b008f0"; };

  };

}
#endif
