#ifndef _ROS_view_controller_msgs_CameraMovement_h
#define _ROS_view_controller_msgs_CameraMovement_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/Vector3Stamped.h"
#include "ros/duration.h"

namespace view_controller_msgs
{

  class CameraMovement : public ros::Msg
  {
    public:
      typedef geometry_msgs::PointStamped _eye_type;
      _eye_type eye;
      typedef geometry_msgs::PointStamped _focus_type;
      _focus_type focus;
      typedef geometry_msgs::Vector3Stamped _up_type;
      _up_type up;
      typedef ros::Duration _transition_duration_type;
      _transition_duration_type transition_duration;
      typedef uint8_t _interpolation_speed_type;
      _interpolation_speed_type interpolation_speed;
      enum { RISING =  0  };
      enum { DECLINING =  1  };
      enum { FULL =  2  };
      enum { WAVE =  3  };

    CameraMovement():
      eye(),
      focus(),
      up(),
      transition_duration(),
      interpolation_speed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->eye.serialize(outbuffer + offset);
      offset += this->focus.serialize(outbuffer + offset);
      offset += this->up.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->transition_duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->transition_duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->transition_duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->transition_duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transition_duration.sec);
      *(outbuffer + offset + 0) = (this->transition_duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->transition_duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->transition_duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->transition_duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transition_duration.nsec);
      *(outbuffer + offset + 0) = (this->interpolation_speed >> (8 * 0)) & 0xFF;
      offset += sizeof(this->interpolation_speed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->eye.deserialize(inbuffer + offset);
      offset += this->focus.deserialize(inbuffer + offset);
      offset += this->up.deserialize(inbuffer + offset);
      this->transition_duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->transition_duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->transition_duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->transition_duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->transition_duration.sec);
      this->transition_duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->transition_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->transition_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->transition_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->transition_duration.nsec);
      this->interpolation_speed =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->interpolation_speed);
     return offset;
    }

    const char * getType(){ return "view_controller_msgs/CameraMovement"; };
    const char * getMD5(){ return "fc7aac4a39426fb5e8b2dbb6e85bfc66"; };

  };

}
#endif
