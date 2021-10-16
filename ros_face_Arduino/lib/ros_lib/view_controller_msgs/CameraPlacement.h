#ifndef _ROS_view_controller_msgs_CameraPlacement_h
#define _ROS_view_controller_msgs_CameraPlacement_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/Vector3Stamped.h"

namespace view_controller_msgs
{

  class CameraPlacement : public ros::Msg
  {
    public:
      typedef uint8_t _interpolation_mode_type;
      _interpolation_mode_type interpolation_mode;
      typedef const char* _target_frame_type;
      _target_frame_type target_frame;
      typedef ros::Duration _time_from_start_type;
      _time_from_start_type time_from_start;
      typedef geometry_msgs::PointStamped _eye_type;
      _eye_type eye;
      typedef geometry_msgs::PointStamped _focus_type;
      _focus_type focus;
      typedef geometry_msgs::Vector3Stamped _up_type;
      _up_type up;
      typedef uint8_t _mouse_interaction_mode_type;
      _mouse_interaction_mode_type mouse_interaction_mode;
      typedef bool _interaction_disabled_type;
      _interaction_disabled_type interaction_disabled;
      typedef bool _allow_free_yaw_axis_type;
      _allow_free_yaw_axis_type allow_free_yaw_axis;
      enum { LINEAR =  0  };
      enum { SPHERICAL =  1  };
      enum { NO_CHANGE =  0  };
      enum { ORBIT =  1  };
      enum { FPS =  2  };

    CameraPlacement():
      interpolation_mode(0),
      target_frame(""),
      time_from_start(),
      eye(),
      focus(),
      up(),
      mouse_interaction_mode(0),
      interaction_disabled(0),
      allow_free_yaw_axis(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->interpolation_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->interpolation_mode);
      uint32_t length_target_frame = strlen(this->target_frame);
      varToArr(outbuffer + offset, length_target_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->target_frame, length_target_frame);
      offset += length_target_frame;
      *(outbuffer + offset + 0) = (this->time_from_start.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.sec);
      *(outbuffer + offset + 0) = (this->time_from_start.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.nsec);
      offset += this->eye.serialize(outbuffer + offset);
      offset += this->focus.serialize(outbuffer + offset);
      offset += this->up.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->mouse_interaction_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mouse_interaction_mode);
      union {
        bool real;
        uint8_t base;
      } u_interaction_disabled;
      u_interaction_disabled.real = this->interaction_disabled;
      *(outbuffer + offset + 0) = (u_interaction_disabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->interaction_disabled);
      union {
        bool real;
        uint8_t base;
      } u_allow_free_yaw_axis;
      u_allow_free_yaw_axis.real = this->allow_free_yaw_axis;
      *(outbuffer + offset + 0) = (u_allow_free_yaw_axis.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->allow_free_yaw_axis);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->interpolation_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->interpolation_mode);
      uint32_t length_target_frame;
      arrToVar(length_target_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_frame-1]=0;
      this->target_frame = (char *)(inbuffer + offset-1);
      offset += length_target_frame;
      this->time_from_start.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.sec);
      this->time_from_start.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.nsec);
      offset += this->eye.deserialize(inbuffer + offset);
      offset += this->focus.deserialize(inbuffer + offset);
      offset += this->up.deserialize(inbuffer + offset);
      this->mouse_interaction_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mouse_interaction_mode);
      union {
        bool real;
        uint8_t base;
      } u_interaction_disabled;
      u_interaction_disabled.base = 0;
      u_interaction_disabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->interaction_disabled = u_interaction_disabled.real;
      offset += sizeof(this->interaction_disabled);
      union {
        bool real;
        uint8_t base;
      } u_allow_free_yaw_axis;
      u_allow_free_yaw_axis.base = 0;
      u_allow_free_yaw_axis.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->allow_free_yaw_axis = u_allow_free_yaw_axis.real;
      offset += sizeof(this->allow_free_yaw_axis);
     return offset;
    }

    const char * getType(){ return "view_controller_msgs/CameraPlacement"; };
    const char * getMD5(){ return "38be6efe15caa86e2c835dd05ab88393"; };

  };

}
#endif
