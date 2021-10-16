#ifndef _ROS_SERVICE_CheckCircle_h
#define _ROS_SERVICE_CheckCircle_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace jsk_recognition_msgs
{

static const char CHECKCIRCLE[] = "jsk_recognition_msgs/CheckCircle";

  class CheckCircleRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _point_type;
      _point_type point;

    CheckCircleRequest():
      point()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->point.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->point.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return CHECKCIRCLE; };
    const char * getMD5(){ return "a7c84ff13976aa04656e56e300124444"; };

  };

  class CheckCircleResponse : public ros::Msg
  {
    public:
      typedef bool _clicked_type;
      _clicked_type clicked;
      typedef int32_t _index_type;
      _index_type index;
      typedef const char* _msg_type;
      _msg_type msg;

    CheckCircleResponse():
      clicked(0),
      index(0),
      msg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_clicked;
      u_clicked.real = this->clicked;
      *(outbuffer + offset + 0) = (u_clicked.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clicked);
      union {
        int32_t real;
        uint32_t base;
      } u_index;
      u_index.real = this->index;
      *(outbuffer + offset + 0) = (u_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->index);
      uint32_t length_msg = strlen(this->msg);
      varToArr(outbuffer + offset, length_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->msg, length_msg);
      offset += length_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_clicked;
      u_clicked.base = 0;
      u_clicked.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clicked = u_clicked.real;
      offset += sizeof(this->clicked);
      union {
        int32_t real;
        uint32_t base;
      } u_index;
      u_index.base = 0;
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->index = u_index.real;
      offset += sizeof(this->index);
      uint32_t length_msg;
      arrToVar(length_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg-1]=0;
      this->msg = (char *)(inbuffer + offset-1);
      offset += length_msg;
     return offset;
    }

    const char * getType(){ return CHECKCIRCLE; };
    const char * getMD5(){ return "94ed41c732187b6ea58431df72ab10b2"; };

  };

  class CheckCircle {
    public:
    typedef CheckCircleRequest Request;
    typedef CheckCircleResponse Response;
  };

}
#endif
