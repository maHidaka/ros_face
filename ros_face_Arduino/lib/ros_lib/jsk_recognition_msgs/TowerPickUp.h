#ifndef _ROS_SERVICE_TowerPickUp_h
#define _ROS_SERVICE_TowerPickUp_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_recognition_msgs
{

static const char TOWERPICKUP[] = "jsk_recognition_msgs/TowerPickUp";

  class TowerPickUpRequest : public ros::Msg
  {
    public:
      typedef int32_t _tower_index_type;
      _tower_index_type tower_index;

    TowerPickUpRequest():
      tower_index(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_tower_index;
      u_tower_index.real = this->tower_index;
      *(outbuffer + offset + 0) = (u_tower_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tower_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tower_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tower_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tower_index);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_tower_index;
      u_tower_index.base = 0;
      u_tower_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tower_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tower_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tower_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tower_index = u_tower_index.real;
      offset += sizeof(this->tower_index);
     return offset;
    }

    const char * getType(){ return TOWERPICKUP; };
    const char * getMD5(){ return "e8bd24109f26b6d833bc4570d67d71c9"; };

  };

  class TowerPickUpResponse : public ros::Msg
  {
    public:

    TowerPickUpResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return TOWERPICKUP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class TowerPickUp {
    public:
    typedef TowerPickUpRequest Request;
    typedef TowerPickUpResponse Response;
  };

}
#endif
