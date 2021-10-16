#ifndef _ROS_SERVICE_SetDynamicTF_h
#define _ROS_SERVICE_SetDynamicTF_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/TransformStamped.h"

namespace dynamic_tf_publisher
{

static const char SETDYNAMICTF[] = "dynamic_tf_publisher/SetDynamicTF";

  class SetDynamicTFRequest : public ros::Msg
  {
    public:
      typedef float _freq_type;
      _freq_type freq;
      typedef geometry_msgs::TransformStamped _cur_tf_type;
      _cur_tf_type cur_tf;

    SetDynamicTFRequest():
      freq(0),
      cur_tf()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_freq;
      u_freq.real = this->freq;
      *(outbuffer + offset + 0) = (u_freq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_freq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_freq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_freq.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->freq);
      offset += this->cur_tf.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_freq;
      u_freq.base = 0;
      u_freq.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_freq.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_freq.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_freq.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->freq = u_freq.real;
      offset += sizeof(this->freq);
      offset += this->cur_tf.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETDYNAMICTF; };
    const char * getMD5(){ return "257be6eb2c49e846d6c3c12c85bb0fb1"; };

  };

  class SetDynamicTFResponse : public ros::Msg
  {
    public:

    SetDynamicTFResponse()
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

    const char * getType(){ return SETDYNAMICTF; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetDynamicTF {
    public:
    typedef SetDynamicTFRequest Request;
    typedef SetDynamicTFResponse Response;
  };

}
#endif
