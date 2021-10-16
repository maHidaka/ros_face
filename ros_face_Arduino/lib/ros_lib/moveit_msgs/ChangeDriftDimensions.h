#ifndef _ROS_SERVICE_ChangeDriftDimensions_h
#define _ROS_SERVICE_ChangeDriftDimensions_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Transform.h"

namespace moveit_msgs
{

static const char CHANGEDRIFTDIMENSIONS[] = "moveit_msgs/ChangeDriftDimensions";

  class ChangeDriftDimensionsRequest : public ros::Msg
  {
    public:
      typedef bool _drift_x_translation_type;
      _drift_x_translation_type drift_x_translation;
      typedef bool _drift_y_translation_type;
      _drift_y_translation_type drift_y_translation;
      typedef bool _drift_z_translation_type;
      _drift_z_translation_type drift_z_translation;
      typedef bool _drift_x_rotation_type;
      _drift_x_rotation_type drift_x_rotation;
      typedef bool _drift_y_rotation_type;
      _drift_y_rotation_type drift_y_rotation;
      typedef bool _drift_z_rotation_type;
      _drift_z_rotation_type drift_z_rotation;
      typedef geometry_msgs::Transform _transform_jog_frame_to_drift_frame_type;
      _transform_jog_frame_to_drift_frame_type transform_jog_frame_to_drift_frame;

    ChangeDriftDimensionsRequest():
      drift_x_translation(0),
      drift_y_translation(0),
      drift_z_translation(0),
      drift_x_rotation(0),
      drift_y_rotation(0),
      drift_z_rotation(0),
      transform_jog_frame_to_drift_frame()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_drift_x_translation;
      u_drift_x_translation.real = this->drift_x_translation;
      *(outbuffer + offset + 0) = (u_drift_x_translation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->drift_x_translation);
      union {
        bool real;
        uint8_t base;
      } u_drift_y_translation;
      u_drift_y_translation.real = this->drift_y_translation;
      *(outbuffer + offset + 0) = (u_drift_y_translation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->drift_y_translation);
      union {
        bool real;
        uint8_t base;
      } u_drift_z_translation;
      u_drift_z_translation.real = this->drift_z_translation;
      *(outbuffer + offset + 0) = (u_drift_z_translation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->drift_z_translation);
      union {
        bool real;
        uint8_t base;
      } u_drift_x_rotation;
      u_drift_x_rotation.real = this->drift_x_rotation;
      *(outbuffer + offset + 0) = (u_drift_x_rotation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->drift_x_rotation);
      union {
        bool real;
        uint8_t base;
      } u_drift_y_rotation;
      u_drift_y_rotation.real = this->drift_y_rotation;
      *(outbuffer + offset + 0) = (u_drift_y_rotation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->drift_y_rotation);
      union {
        bool real;
        uint8_t base;
      } u_drift_z_rotation;
      u_drift_z_rotation.real = this->drift_z_rotation;
      *(outbuffer + offset + 0) = (u_drift_z_rotation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->drift_z_rotation);
      offset += this->transform_jog_frame_to_drift_frame.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_drift_x_translation;
      u_drift_x_translation.base = 0;
      u_drift_x_translation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->drift_x_translation = u_drift_x_translation.real;
      offset += sizeof(this->drift_x_translation);
      union {
        bool real;
        uint8_t base;
      } u_drift_y_translation;
      u_drift_y_translation.base = 0;
      u_drift_y_translation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->drift_y_translation = u_drift_y_translation.real;
      offset += sizeof(this->drift_y_translation);
      union {
        bool real;
        uint8_t base;
      } u_drift_z_translation;
      u_drift_z_translation.base = 0;
      u_drift_z_translation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->drift_z_translation = u_drift_z_translation.real;
      offset += sizeof(this->drift_z_translation);
      union {
        bool real;
        uint8_t base;
      } u_drift_x_rotation;
      u_drift_x_rotation.base = 0;
      u_drift_x_rotation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->drift_x_rotation = u_drift_x_rotation.real;
      offset += sizeof(this->drift_x_rotation);
      union {
        bool real;
        uint8_t base;
      } u_drift_y_rotation;
      u_drift_y_rotation.base = 0;
      u_drift_y_rotation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->drift_y_rotation = u_drift_y_rotation.real;
      offset += sizeof(this->drift_y_rotation);
      union {
        bool real;
        uint8_t base;
      } u_drift_z_rotation;
      u_drift_z_rotation.base = 0;
      u_drift_z_rotation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->drift_z_rotation = u_drift_z_rotation.real;
      offset += sizeof(this->drift_z_rotation);
      offset += this->transform_jog_frame_to_drift_frame.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return CHANGEDRIFTDIMENSIONS; };
    const char * getMD5(){ return "4a5ce44f94cdee672e699df89b1ebaf1"; };

  };

  class ChangeDriftDimensionsResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    ChangeDriftDimensionsResponse():
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

    const char * getType(){ return CHANGEDRIFTDIMENSIONS; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class ChangeDriftDimensions {
    public:
    typedef ChangeDriftDimensionsRequest Request;
    typedef ChangeDriftDimensionsResponse Response;
  };

}
#endif
