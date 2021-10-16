#ifndef _ROS_SERVICE_RobotPickupReleasePoint_h
#define _ROS_SERVICE_RobotPickupReleasePoint_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace jsk_recognition_msgs
{

static const char ROBOTPICKUPRELEASEPOINT[] = "jsk_recognition_msgs/RobotPickupReleasePoint";

  class RobotPickupReleasePointRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Point _target_point_type;
      _target_point_type target_point;
      typedef int8_t _pick_or_release_type;
      _pick_or_release_type pick_or_release;

    RobotPickupReleasePointRequest():
      header(),
      target_point(),
      pick_or_release(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->target_point.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_pick_or_release;
      u_pick_or_release.real = this->pick_or_release;
      *(outbuffer + offset + 0) = (u_pick_or_release.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pick_or_release);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->target_point.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_pick_or_release;
      u_pick_or_release.base = 0;
      u_pick_or_release.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pick_or_release = u_pick_or_release.real;
      offset += sizeof(this->pick_or_release);
     return offset;
    }

    const char * getType(){ return ROBOTPICKUPRELEASEPOINT; };
    const char * getMD5(){ return "deed053f0da0bc3c530cdf92dcf06642"; };

  };

  class RobotPickupReleasePointResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    RobotPickupReleasePointResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return ROBOTPICKUPRELEASEPOINT; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class RobotPickupReleasePoint {
    public:
    typedef RobotPickupReleasePointRequest Request;
    typedef RobotPickupReleasePointResponse Response;
  };

}
#endif
