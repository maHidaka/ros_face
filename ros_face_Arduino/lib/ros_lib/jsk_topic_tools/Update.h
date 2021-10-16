#ifndef _ROS_SERVICE_Update_h
#define _ROS_SERVICE_Update_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace jsk_topic_tools
{

static const char UPDATE[] = "jsk_topic_tools/Update";

  class UpdateRequest : public ros::Msg
  {
    public:
      typedef const char* _topic_name_type;
      _topic_name_type topic_name;
      typedef bool _periodic_type;
      _periodic_type periodic;
      typedef ros::Duration _periodic_rate_type;
      _periodic_rate_type periodic_rate;

    UpdateRequest():
      topic_name(""),
      periodic(0),
      periodic_rate()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_topic_name = strlen(this->topic_name);
      varToArr(outbuffer + offset, length_topic_name);
      offset += 4;
      memcpy(outbuffer + offset, this->topic_name, length_topic_name);
      offset += length_topic_name;
      union {
        bool real;
        uint8_t base;
      } u_periodic;
      u_periodic.real = this->periodic;
      *(outbuffer + offset + 0) = (u_periodic.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->periodic);
      *(outbuffer + offset + 0) = (this->periodic_rate.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->periodic_rate.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->periodic_rate.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->periodic_rate.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->periodic_rate.sec);
      *(outbuffer + offset + 0) = (this->periodic_rate.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->periodic_rate.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->periodic_rate.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->periodic_rate.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->periodic_rate.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_topic_name;
      arrToVar(length_topic_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic_name-1]=0;
      this->topic_name = (char *)(inbuffer + offset-1);
      offset += length_topic_name;
      union {
        bool real;
        uint8_t base;
      } u_periodic;
      u_periodic.base = 0;
      u_periodic.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->periodic = u_periodic.real;
      offset += sizeof(this->periodic);
      this->periodic_rate.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->periodic_rate.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->periodic_rate.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->periodic_rate.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->periodic_rate.sec);
      this->periodic_rate.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->periodic_rate.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->periodic_rate.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->periodic_rate.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->periodic_rate.nsec);
     return offset;
    }

    const char * getType(){ return UPDATE; };
    const char * getMD5(){ return "0050acd5c94510531ac3023287e6b559"; };

  };

  class UpdateResponse : public ros::Msg
  {
    public:
      typedef float _rate_type;
      _rate_type rate;

    UpdateResponse():
      rate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->rate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rate));
     return offset;
    }

    const char * getType(){ return UPDATE; };
    const char * getMD5(){ return "4910f3d55cbb29566b6c8f8f16528adf"; };

  };

  class Update {
    public:
    typedef UpdateRequest Request;
    typedef UpdateResponse Response;
  };

}
#endif
