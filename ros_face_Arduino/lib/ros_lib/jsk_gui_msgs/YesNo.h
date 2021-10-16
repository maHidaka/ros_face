#ifndef _ROS_SERVICE_YesNo_h
#define _ROS_SERVICE_YesNo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_gui_msgs
{

static const char YESNO[] = "jsk_gui_msgs/YesNo";

  class YesNoRequest : public ros::Msg
  {
    public:
      typedef const char* _message_type;
      _message_type message;

    YesNoRequest():
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    const char * getType(){ return YESNO; };
    const char * getMD5(){ return "5f003d6bcc824cbd51361d66d8e4f76c"; };

  };

  class YesNoResponse : public ros::Msg
  {
    public:
      typedef bool _yes_type;
      _yes_type yes;

    YesNoResponse():
      yes(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_yes;
      u_yes.real = this->yes;
      *(outbuffer + offset + 0) = (u_yes.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->yes);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_yes;
      u_yes.base = 0;
      u_yes.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->yes = u_yes.real;
      offset += sizeof(this->yes);
     return offset;
    }

    const char * getType(){ return YESNO; };
    const char * getMD5(){ return "aa7d186fb6268a501cd4c0c274f480ff"; };

  };

  class YesNo {
    public:
    typedef YesNoRequest Request;
    typedef YesNoResponse Response;
  };

}
#endif
