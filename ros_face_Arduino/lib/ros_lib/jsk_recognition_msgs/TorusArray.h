#ifndef _ROS_jsk_recognition_msgs_TorusArray_h
#define _ROS_jsk_recognition_msgs_TorusArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/Torus.h"

namespace jsk_recognition_msgs
{

  class TorusArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t toruses_length;
      typedef jsk_recognition_msgs::Torus _toruses_type;
      _toruses_type st_toruses;
      _toruses_type * toruses;

    TorusArray():
      header(),
      toruses_length(0), toruses(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->toruses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->toruses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->toruses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->toruses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->toruses_length);
      for( uint32_t i = 0; i < toruses_length; i++){
      offset += this->toruses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t toruses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      toruses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      toruses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      toruses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->toruses_length);
      if(toruses_lengthT > toruses_length)
        this->toruses = (jsk_recognition_msgs::Torus*)realloc(this->toruses, toruses_lengthT * sizeof(jsk_recognition_msgs::Torus));
      toruses_length = toruses_lengthT;
      for( uint32_t i = 0; i < toruses_length; i++){
      offset += this->st_toruses.deserialize(inbuffer + offset);
        memcpy( &(this->toruses[i]), &(this->st_toruses), sizeof(jsk_recognition_msgs::Torus));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/TorusArray"; };
    const char * getMD5(){ return "81d0dbf46016b5714fa4ea9eca5485e0"; };

  };

}
#endif
