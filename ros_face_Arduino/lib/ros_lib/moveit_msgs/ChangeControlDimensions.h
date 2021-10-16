#ifndef _ROS_SERVICE_ChangeControlDimensions_h
#define _ROS_SERVICE_ChangeControlDimensions_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

static const char CHANGECONTROLDIMENSIONS[] = "moveit_msgs/ChangeControlDimensions";

  class ChangeControlDimensionsRequest : public ros::Msg
  {
    public:
      typedef bool _control_x_translation_type;
      _control_x_translation_type control_x_translation;
      typedef bool _control_y_translation_type;
      _control_y_translation_type control_y_translation;
      typedef bool _control_z_translation_type;
      _control_z_translation_type control_z_translation;
      typedef bool _control_x_rotation_type;
      _control_x_rotation_type control_x_rotation;
      typedef bool _control_y_rotation_type;
      _control_y_rotation_type control_y_rotation;
      typedef bool _control_z_rotation_type;
      _control_z_rotation_type control_z_rotation;

    ChangeControlDimensionsRequest():
      control_x_translation(0),
      control_y_translation(0),
      control_z_translation(0),
      control_x_rotation(0),
      control_y_rotation(0),
      control_z_rotation(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_control_x_translation;
      u_control_x_translation.real = this->control_x_translation;
      *(outbuffer + offset + 0) = (u_control_x_translation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_x_translation);
      union {
        bool real;
        uint8_t base;
      } u_control_y_translation;
      u_control_y_translation.real = this->control_y_translation;
      *(outbuffer + offset + 0) = (u_control_y_translation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_y_translation);
      union {
        bool real;
        uint8_t base;
      } u_control_z_translation;
      u_control_z_translation.real = this->control_z_translation;
      *(outbuffer + offset + 0) = (u_control_z_translation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_z_translation);
      union {
        bool real;
        uint8_t base;
      } u_control_x_rotation;
      u_control_x_rotation.real = this->control_x_rotation;
      *(outbuffer + offset + 0) = (u_control_x_rotation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_x_rotation);
      union {
        bool real;
        uint8_t base;
      } u_control_y_rotation;
      u_control_y_rotation.real = this->control_y_rotation;
      *(outbuffer + offset + 0) = (u_control_y_rotation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_y_rotation);
      union {
        bool real;
        uint8_t base;
      } u_control_z_rotation;
      u_control_z_rotation.real = this->control_z_rotation;
      *(outbuffer + offset + 0) = (u_control_z_rotation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_z_rotation);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_control_x_translation;
      u_control_x_translation.base = 0;
      u_control_x_translation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->control_x_translation = u_control_x_translation.real;
      offset += sizeof(this->control_x_translation);
      union {
        bool real;
        uint8_t base;
      } u_control_y_translation;
      u_control_y_translation.base = 0;
      u_control_y_translation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->control_y_translation = u_control_y_translation.real;
      offset += sizeof(this->control_y_translation);
      union {
        bool real;
        uint8_t base;
      } u_control_z_translation;
      u_control_z_translation.base = 0;
      u_control_z_translation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->control_z_translation = u_control_z_translation.real;
      offset += sizeof(this->control_z_translation);
      union {
        bool real;
        uint8_t base;
      } u_control_x_rotation;
      u_control_x_rotation.base = 0;
      u_control_x_rotation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->control_x_rotation = u_control_x_rotation.real;
      offset += sizeof(this->control_x_rotation);
      union {
        bool real;
        uint8_t base;
      } u_control_y_rotation;
      u_control_y_rotation.base = 0;
      u_control_y_rotation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->control_y_rotation = u_control_y_rotation.real;
      offset += sizeof(this->control_y_rotation);
      union {
        bool real;
        uint8_t base;
      } u_control_z_rotation;
      u_control_z_rotation.base = 0;
      u_control_z_rotation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->control_z_rotation = u_control_z_rotation.real;
      offset += sizeof(this->control_z_rotation);
     return offset;
    }

    const char * getType(){ return CHANGECONTROLDIMENSIONS; };
    const char * getMD5(){ return "64c0dd6d519e78f5ce2626b06dab34c1"; };

  };

  class ChangeControlDimensionsResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    ChangeControlDimensionsResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return CHANGECONTROLDIMENSIONS; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class ChangeControlDimensions {
    public:
    typedef ChangeControlDimensionsRequest Request;
    typedef ChangeControlDimensionsResponse Response;
  };

}
#endif
