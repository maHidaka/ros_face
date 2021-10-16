#ifndef _ROS_moveit_msgs_JointLimits_h
#define _ROS_moveit_msgs_JointLimits_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

  class JointLimits : public ros::Msg
  {
    public:
      typedef const char* _joint_name_type;
      _joint_name_type joint_name;
      typedef bool _has_position_limits_type;
      _has_position_limits_type has_position_limits;
      typedef float _min_position_type;
      _min_position_type min_position;
      typedef float _max_position_type;
      _max_position_type max_position;
      typedef bool _has_velocity_limits_type;
      _has_velocity_limits_type has_velocity_limits;
      typedef float _max_velocity_type;
      _max_velocity_type max_velocity;
      typedef bool _has_acceleration_limits_type;
      _has_acceleration_limits_type has_acceleration_limits;
      typedef float _max_acceleration_type;
      _max_acceleration_type max_acceleration;

    JointLimits():
      joint_name(""),
      has_position_limits(0),
      min_position(0),
      max_position(0),
      has_velocity_limits(0),
      max_velocity(0),
      has_acceleration_limits(0),
      max_acceleration(0)
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
      union {
        bool real;
        uint8_t base;
      } u_has_position_limits;
      u_has_position_limits.real = this->has_position_limits;
      *(outbuffer + offset + 0) = (u_has_position_limits.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_position_limits);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_position);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_position);
      union {
        bool real;
        uint8_t base;
      } u_has_velocity_limits;
      u_has_velocity_limits.real = this->has_velocity_limits;
      *(outbuffer + offset + 0) = (u_has_velocity_limits.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_velocity_limits);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_velocity);
      union {
        bool real;
        uint8_t base;
      } u_has_acceleration_limits;
      u_has_acceleration_limits.real = this->has_acceleration_limits;
      *(outbuffer + offset + 0) = (u_has_acceleration_limits.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_acceleration_limits);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_acceleration);
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
      union {
        bool real;
        uint8_t base;
      } u_has_position_limits;
      u_has_position_limits.base = 0;
      u_has_position_limits.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_position_limits = u_has_position_limits.real;
      offset += sizeof(this->has_position_limits);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_position));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_position));
      union {
        bool real;
        uint8_t base;
      } u_has_velocity_limits;
      u_has_velocity_limits.base = 0;
      u_has_velocity_limits.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_velocity_limits = u_has_velocity_limits.real;
      offset += sizeof(this->has_velocity_limits);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_velocity));
      union {
        bool real;
        uint8_t base;
      } u_has_acceleration_limits;
      u_has_acceleration_limits.base = 0;
      u_has_acceleration_limits.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_acceleration_limits = u_has_acceleration_limits.real;
      offset += sizeof(this->has_acceleration_limits);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_acceleration));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/JointLimits"; };
    const char * getMD5(){ return "8ca618c7329ea46142cbc864a2efe856"; };

  };

}
#endif
