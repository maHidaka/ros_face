#ifndef _ROS_json_msgs_Json_h
#define _ROS_json_msgs_Json_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace json_msgs
{

  class Json : public ros::Msg
  {
    public:
      uint32_t bytes_length;
      typedef uint8_t _bytes_type;
      _bytes_type st_bytes;
      _bytes_type * bytes;

    Json():
      bytes_length(0), bytes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->bytes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bytes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bytes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bytes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bytes_length);
      for( uint32_t i = 0; i < bytes_length; i++){
      *(outbuffer + offset + 0) = (this->bytes[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bytes[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t bytes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      bytes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      bytes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      bytes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->bytes_length);
      if(bytes_lengthT > bytes_length)
        this->bytes = (uint8_t*)realloc(this->bytes, bytes_lengthT * sizeof(uint8_t));
      bytes_length = bytes_lengthT;
      for( uint32_t i = 0; i < bytes_length; i++){
      this->st_bytes =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_bytes);
        memcpy( &(this->bytes[i]), &(this->st_bytes), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "json_msgs/Json"; };
    const char * getMD5(){ return "d159f2bd8169d3b3339e6f1fce045c6d"; };

  };

}
#endif
