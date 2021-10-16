#ifndef _ROS_moveit_msgs_AllowedCollisionEntry_h
#define _ROS_moveit_msgs_AllowedCollisionEntry_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

  class AllowedCollisionEntry : public ros::Msg
  {
    public:
      uint32_t enabled_length;
      typedef bool _enabled_type;
      _enabled_type st_enabled;
      _enabled_type * enabled;

    AllowedCollisionEntry():
      enabled_length(0), enabled(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->enabled_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->enabled_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->enabled_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->enabled_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->enabled_length);
      for( uint32_t i = 0; i < enabled_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_enabledi;
      u_enabledi.real = this->enabled[i];
      *(outbuffer + offset + 0) = (u_enabledi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enabled[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t enabled_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      enabled_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      enabled_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      enabled_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->enabled_length);
      if(enabled_lengthT > enabled_length)
        this->enabled = (bool*)realloc(this->enabled, enabled_lengthT * sizeof(bool));
      enabled_length = enabled_lengthT;
      for( uint32_t i = 0; i < enabled_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_enabled;
      u_st_enabled.base = 0;
      u_st_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_enabled = u_st_enabled.real;
      offset += sizeof(this->st_enabled);
        memcpy( &(this->enabled[i]), &(this->st_enabled), sizeof(bool));
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/AllowedCollisionEntry"; };
    const char * getMD5(){ return "90d1ae1850840724bb043562fe3285fc"; };

  };

}
#endif
