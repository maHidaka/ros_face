#ifndef _ROS_jsk_recognition_msgs_HeightmapConfig_h
#define _ROS_jsk_recognition_msgs_HeightmapConfig_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_recognition_msgs
{

  class HeightmapConfig : public ros::Msg
  {
    public:
      typedef float _min_x_type;
      _min_x_type min_x;
      typedef float _max_x_type;
      _max_x_type max_x;
      typedef float _min_y_type;
      _min_y_type min_y;
      typedef float _max_y_type;
      _max_y_type max_y;

    HeightmapConfig():
      min_x(0),
      max_x(0),
      min_y(0),
      max_y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_min_x;
      u_min_x.real = this->min_x;
      *(outbuffer + offset + 0) = (u_min_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_x);
      union {
        float real;
        uint32_t base;
      } u_max_x;
      u_max_x.real = this->max_x;
      *(outbuffer + offset + 0) = (u_max_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_x);
      union {
        float real;
        uint32_t base;
      } u_min_y;
      u_min_y.real = this->min_y;
      *(outbuffer + offset + 0) = (u_min_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_y);
      union {
        float real;
        uint32_t base;
      } u_max_y;
      u_max_y.real = this->max_y;
      *(outbuffer + offset + 0) = (u_max_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_min_x;
      u_min_x.base = 0;
      u_min_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_x = u_min_x.real;
      offset += sizeof(this->min_x);
      union {
        float real;
        uint32_t base;
      } u_max_x;
      u_max_x.base = 0;
      u_max_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_x = u_max_x.real;
      offset += sizeof(this->max_x);
      union {
        float real;
        uint32_t base;
      } u_min_y;
      u_min_y.base = 0;
      u_min_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_y = u_min_y.real;
      offset += sizeof(this->min_y);
      union {
        float real;
        uint32_t base;
      } u_max_y;
      u_max_y.base = 0;
      u_max_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_y = u_max_y.real;
      offset += sizeof(this->max_y);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/HeightmapConfig"; };
    const char * getMD5(){ return "f2f90f6dd5aeedef48b062e1a4aabb89"; };

  };

}
#endif
