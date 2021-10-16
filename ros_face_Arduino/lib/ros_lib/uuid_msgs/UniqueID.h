#ifndef _ROS_uuid_msgs_UniqueID_h
#define _ROS_uuid_msgs_UniqueID_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace uuid_msgs
{

  class UniqueID : public ros::Msg
  {
    public:
      uint8_t uuid[16];

    UniqueID():
      uuid()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 16; i++){
      *(outbuffer + offset + 0) = (this->uuid[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->uuid[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 16; i++){
      this->uuid[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->uuid[i]);
      }
     return offset;
    }

    const char * getType(){ return "uuid_msgs/UniqueID"; };
    const char * getMD5(){ return "fec2a93b6f5367ee8112c9c0b41ff310"; };

  };

}
#endif
