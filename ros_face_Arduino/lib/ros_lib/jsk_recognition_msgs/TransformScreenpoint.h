#ifndef _ROS_SERVICE_TransformScreenpoint_h
#define _ROS_SERVICE_TransformScreenpoint_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Vector3.h"

namespace jsk_recognition_msgs
{

static const char TRANSFORMSCREENPOINT[] = "jsk_recognition_msgs/TransformScreenpoint";

  class TransformScreenpointRequest : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef bool _no_update_type;
      _no_update_type no_update;

    TransformScreenpointRequest():
      x(0),
      y(0),
      no_update(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        bool real;
        uint8_t base;
      } u_no_update;
      u_no_update.real = this->no_update;
      *(outbuffer + offset + 0) = (u_no_update.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->no_update);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        bool real;
        uint8_t base;
      } u_no_update;
      u_no_update.base = 0;
      u_no_update.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->no_update = u_no_update.real;
      offset += sizeof(this->no_update);
     return offset;
    }

    const char * getType(){ return TRANSFORMSCREENPOINT; };
    const char * getMD5(){ return "3796b576f471dba594bd202be056132c"; };

  };

  class TransformScreenpointResponse : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Point _point_type;
      _point_type point;
      typedef geometry_msgs::Vector3 _vector_type;
      _vector_type vector;

    TransformScreenpointResponse():
      header(),
      point(),
      vector()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->point.serialize(outbuffer + offset);
      offset += this->vector.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->point.deserialize(inbuffer + offset);
      offset += this->vector.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return TRANSFORMSCREENPOINT; };
    const char * getMD5(){ return "b4d4e89e36c63a48672ef02dabdec610"; };

  };

  class TransformScreenpoint {
    public:
    typedef TransformScreenpointRequest Request;
    typedef TransformScreenpointResponse Response;
  };

}
#endif
