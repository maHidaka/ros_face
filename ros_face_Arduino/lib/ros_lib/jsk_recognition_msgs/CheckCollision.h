#ifndef _ROS_SERVICE_CheckCollision_h
#define _ROS_SERVICE_CheckCollision_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "sensor_msgs/JointState.h"

namespace jsk_recognition_msgs
{

static const char CHECKCOLLISION[] = "jsk_recognition_msgs/CheckCollision";

  class CheckCollisionRequest : public ros::Msg
  {
    public:
      typedef sensor_msgs::JointState _joint_type;
      _joint_type joint;
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;

    CheckCollisionRequest():
      joint(),
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->joint.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->joint.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return CHECKCOLLISION; };
    const char * getMD5(){ return "2bfa8f4c4d92353b38f908fbabfac432"; };

  };

  class CheckCollisionResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    CheckCollisionResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return CHECKCOLLISION; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class CheckCollision {
    public:
    typedef CheckCollisionRequest Request;
    typedef CheckCollisionResponse Response;
  };

}
#endif
