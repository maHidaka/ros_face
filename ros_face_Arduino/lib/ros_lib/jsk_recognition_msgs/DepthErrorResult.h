#ifndef _ROS_jsk_recognition_msgs_DepthErrorResult_h
#define _ROS_jsk_recognition_msgs_DepthErrorResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class DepthErrorResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _u_type;
      _u_type u;
      typedef uint32_t _v_type;
      _v_type v;
      typedef float _center_u_type;
      _center_u_type center_u;
      typedef float _center_v_type;
      _center_v_type center_v;
      typedef float _true_depth_type;
      _true_depth_type true_depth;
      typedef float _observed_depth_type;
      _observed_depth_type observed_depth;

    DepthErrorResult():
      header(),
      u(0),
      v(0),
      center_u(0),
      center_v(0),
      true_depth(0),
      observed_depth(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->u >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->u >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->u >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->u >> (8 * 3)) & 0xFF;
      offset += sizeof(this->u);
      *(outbuffer + offset + 0) = (this->v >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->v >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->v >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->v >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v);
      union {
        float real;
        uint32_t base;
      } u_center_u;
      u_center_u.real = this->center_u;
      *(outbuffer + offset + 0) = (u_center_u.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_center_u.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_center_u.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_center_u.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->center_u);
      union {
        float real;
        uint32_t base;
      } u_center_v;
      u_center_v.real = this->center_v;
      *(outbuffer + offset + 0) = (u_center_v.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_center_v.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_center_v.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_center_v.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->center_v);
      union {
        float real;
        uint32_t base;
      } u_true_depth;
      u_true_depth.real = this->true_depth;
      *(outbuffer + offset + 0) = (u_true_depth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_true_depth.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_true_depth.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_true_depth.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->true_depth);
      union {
        float real;
        uint32_t base;
      } u_observed_depth;
      u_observed_depth.real = this->observed_depth;
      *(outbuffer + offset + 0) = (u_observed_depth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_observed_depth.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_observed_depth.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_observed_depth.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->observed_depth);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->u =  ((uint32_t) (*(inbuffer + offset)));
      this->u |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->u |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->u |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->u);
      this->v =  ((uint32_t) (*(inbuffer + offset)));
      this->v |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->v |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->v |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->v);
      union {
        float real;
        uint32_t base;
      } u_center_u;
      u_center_u.base = 0;
      u_center_u.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_center_u.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_center_u.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_center_u.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->center_u = u_center_u.real;
      offset += sizeof(this->center_u);
      union {
        float real;
        uint32_t base;
      } u_center_v;
      u_center_v.base = 0;
      u_center_v.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_center_v.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_center_v.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_center_v.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->center_v = u_center_v.real;
      offset += sizeof(this->center_v);
      union {
        float real;
        uint32_t base;
      } u_true_depth;
      u_true_depth.base = 0;
      u_true_depth.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_true_depth.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_true_depth.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_true_depth.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->true_depth = u_true_depth.real;
      offset += sizeof(this->true_depth);
      union {
        float real;
        uint32_t base;
      } u_observed_depth;
      u_observed_depth.base = 0;
      u_observed_depth.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_observed_depth.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_observed_depth.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_observed_depth.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->observed_depth = u_observed_depth.real;
      offset += sizeof(this->observed_depth);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/DepthErrorResult"; };
    const char * getMD5(){ return "cebbb2d000457fe5d971a29ee02ffb16"; };

  };

}
#endif
