#ifndef _ROS_moveit_msgs_GripperTranslation_h
#define _ROS_moveit_msgs_GripperTranslation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3Stamped.h"

namespace moveit_msgs
{

  class GripperTranslation : public ros::Msg
  {
    public:
      typedef geometry_msgs::Vector3Stamped _direction_type;
      _direction_type direction;
      typedef float _desired_distance_type;
      _desired_distance_type desired_distance;
      typedef float _min_distance_type;
      _min_distance_type min_distance;

    GripperTranslation():
      direction(),
      desired_distance(0),
      min_distance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->direction.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_desired_distance;
      u_desired_distance.real = this->desired_distance;
      *(outbuffer + offset + 0) = (u_desired_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_desired_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_desired_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_desired_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->desired_distance);
      union {
        float real;
        uint32_t base;
      } u_min_distance;
      u_min_distance.real = this->min_distance;
      *(outbuffer + offset + 0) = (u_min_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_distance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->direction.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_desired_distance;
      u_desired_distance.base = 0;
      u_desired_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_desired_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_desired_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_desired_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->desired_distance = u_desired_distance.real;
      offset += sizeof(this->desired_distance);
      union {
        float real;
        uint32_t base;
      } u_min_distance;
      u_min_distance.base = 0;
      u_min_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_distance = u_min_distance.real;
      offset += sizeof(this->min_distance);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/GripperTranslation"; };
    const char * getMD5(){ return "b53bc0ad0f717cdec3b0e42dec300121"; };

  };

}
#endif
