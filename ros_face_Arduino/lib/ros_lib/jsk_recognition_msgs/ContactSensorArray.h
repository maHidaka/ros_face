#ifndef _ROS_jsk_recognition_msgs_ContactSensorArray_h
#define _ROS_jsk_recognition_msgs_ContactSensorArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/ContactSensor.h"

namespace jsk_recognition_msgs
{

  class ContactSensorArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t datas_length;
      typedef jsk_recognition_msgs::ContactSensor _datas_type;
      _datas_type st_datas;
      _datas_type * datas;

    ContactSensorArray():
      header(),
      datas_length(0), datas(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->datas_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->datas_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->datas_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->datas_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->datas_length);
      for( uint32_t i = 0; i < datas_length; i++){
      offset += this->datas[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t datas_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      datas_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      datas_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      datas_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->datas_length);
      if(datas_lengthT > datas_length)
        this->datas = (jsk_recognition_msgs::ContactSensor*)realloc(this->datas, datas_lengthT * sizeof(jsk_recognition_msgs::ContactSensor));
      datas_length = datas_lengthT;
      for( uint32_t i = 0; i < datas_length; i++){
      offset += this->st_datas.deserialize(inbuffer + offset);
        memcpy( &(this->datas[i]), &(this->st_datas), sizeof(jsk_recognition_msgs::ContactSensor));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/ContactSensorArray"; };
    const char * getMD5(){ return "c65f16fb3a523c0b77d7e31330b214da"; };

  };

}
#endif
