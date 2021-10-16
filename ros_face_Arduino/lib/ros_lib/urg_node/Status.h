#ifndef _ROS_urg_node_Status_h
#define _ROS_urg_node_Status_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace urg_node
{

  class Status : public ros::Msg
  {
    public:
      typedef uint16_t _operating_mode_type;
      _operating_mode_type operating_mode;
      typedef uint16_t _area_number_type;
      _area_number_type area_number;
      typedef bool _error_status_type;
      _error_status_type error_status;
      typedef uint16_t _error_code_type;
      _error_code_type error_code;
      typedef bool _lockout_status_type;
      _lockout_status_type lockout_status;
      typedef uint16_t _distance_type;
      _distance_type distance;
      typedef float _angle_type;
      _angle_type angle;
      enum { NORMAL = 0 };
      enum { SETTING = 1 };

    Status():
      operating_mode(0),
      area_number(0),
      error_status(0),
      error_code(0),
      lockout_status(0),
      distance(0),
      angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->operating_mode >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->operating_mode >> (8 * 1)) & 0xFF;
      offset += sizeof(this->operating_mode);
      *(outbuffer + offset + 0) = (this->area_number >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->area_number >> (8 * 1)) & 0xFF;
      offset += sizeof(this->area_number);
      union {
        bool real;
        uint8_t base;
      } u_error_status;
      u_error_status.real = this->error_status;
      *(outbuffer + offset + 0) = (u_error_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->error_status);
      *(outbuffer + offset + 0) = (this->error_code >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->error_code >> (8 * 1)) & 0xFF;
      offset += sizeof(this->error_code);
      union {
        bool real;
        uint8_t base;
      } u_lockout_status;
      u_lockout_status.real = this->lockout_status;
      *(outbuffer + offset + 0) = (u_lockout_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lockout_status);
      *(outbuffer + offset + 0) = (this->distance >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->distance >> (8 * 1)) & 0xFF;
      offset += sizeof(this->distance);
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.real = this->angle;
      *(outbuffer + offset + 0) = (u_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->operating_mode =  ((uint16_t) (*(inbuffer + offset)));
      this->operating_mode |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->operating_mode);
      this->area_number =  ((uint16_t) (*(inbuffer + offset)));
      this->area_number |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->area_number);
      union {
        bool real;
        uint8_t base;
      } u_error_status;
      u_error_status.base = 0;
      u_error_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->error_status = u_error_status.real;
      offset += sizeof(this->error_status);
      this->error_code =  ((uint16_t) (*(inbuffer + offset)));
      this->error_code |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->error_code);
      union {
        bool real;
        uint8_t base;
      } u_lockout_status;
      u_lockout_status.base = 0;
      u_lockout_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->lockout_status = u_lockout_status.real;
      offset += sizeof(this->lockout_status);
      this->distance =  ((uint16_t) (*(inbuffer + offset)));
      this->distance |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->distance);
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.base = 0;
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle = u_angle.real;
      offset += sizeof(this->angle);
     return offset;
    }

    const char * getType(){ return "urg_node/Status"; };
    const char * getMD5(){ return "b393072b65230b373302bfe803e80784"; };

  };

}
#endif
