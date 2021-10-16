#ifndef _ROS_posedetection_msgs_Object6DPose_h
#define _ROS_posedetection_msgs_Object6DPose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace posedetection_msgs
{

  class Object6DPose : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef float _reliability_type;
      _reliability_type reliability;
      typedef const char* _type_type;
      _type_type type;

    Object6DPose():
      pose(),
      reliability(0),
      type("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_reliability;
      u_reliability.real = this->reliability;
      *(outbuffer + offset + 0) = (u_reliability.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reliability.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reliability.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reliability.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reliability);
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_reliability;
      u_reliability.base = 0;
      u_reliability.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reliability.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reliability.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reliability.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reliability = u_reliability.real;
      offset += sizeof(this->reliability);
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
     return offset;
    }

    const char * getType(){ return "posedetection_msgs/Object6DPose"; };
    const char * getMD5(){ return "68aad97d55c4f9555772eee1814bb3c7"; };

  };

}
#endif
