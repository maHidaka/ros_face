#ifndef _ROS_SERVICE_WhiteBalance_h
#define _ROS_SERVICE_WhiteBalance_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"

namespace jsk_recognition_msgs
{

static const char WHITEBALANCE[] = "jsk_recognition_msgs/WhiteBalance";

  class WhiteBalanceRequest : public ros::Msg
  {
    public:
      float reference_color[3];
      typedef sensor_msgs::Image _input_type;
      _input_type input;

    WhiteBalanceRequest():
      reference_color(),
      input()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_reference_colori;
      u_reference_colori.real = this->reference_color[i];
      *(outbuffer + offset + 0) = (u_reference_colori.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_colori.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_colori.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_colori.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_color[i]);
      }
      offset += this->input.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_reference_colori;
      u_reference_colori.base = 0;
      u_reference_colori.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference_colori.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference_colori.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference_colori.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reference_color[i] = u_reference_colori.real;
      offset += sizeof(this->reference_color[i]);
      }
      offset += this->input.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return WHITEBALANCE; };
    const char * getMD5(){ return "d7702dac51626a53e0806ebd0ad35ca3"; };

  };

  class WhiteBalanceResponse : public ros::Msg
  {
    public:
      typedef sensor_msgs::Image _output_type;
      _output_type output;

    WhiteBalanceResponse():
      output()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->output.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->output.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return WHITEBALANCE; };
    const char * getMD5(){ return "8eeb6eb8777baa5a80bbc676c219bfef"; };

  };

  class WhiteBalance {
    public:
    typedef WhiteBalanceRequest Request;
    typedef WhiteBalanceResponse Response;
  };

}
#endif
