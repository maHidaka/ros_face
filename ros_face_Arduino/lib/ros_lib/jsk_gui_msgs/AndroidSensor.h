#ifndef _ROS_jsk_gui_msgs_AndroidSensor_h
#define _ROS_jsk_gui_msgs_AndroidSensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_gui_msgs
{

  class AndroidSensor : public ros::Msg
  {
    public:
      typedef float _accel_x_type;
      _accel_x_type accel_x;
      typedef float _accel_y_type;
      _accel_y_type accel_y;
      typedef float _accel_z_type;
      _accel_z_type accel_z;
      typedef float _orientation_x_type;
      _orientation_x_type orientation_x;
      typedef float _orientation_y_type;
      _orientation_y_type orientation_y;
      typedef float _orientation_z_type;
      _orientation_z_type orientation_z;

    AndroidSensor():
      accel_x(0),
      accel_y(0),
      accel_z(0),
      orientation_x(0),
      orientation_y(0),
      orientation_z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->accel_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->accel_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->accel_z);
      offset += serializeAvrFloat64(outbuffer + offset, this->orientation_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->orientation_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->orientation_z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->accel_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->accel_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->accel_z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->orientation_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->orientation_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->orientation_z));
     return offset;
    }

    const char * getType(){ return "jsk_gui_msgs/AndroidSensor"; };
    const char * getMD5(){ return "d832dbe3be7e7f061d963f2188f1a407"; };

  };

}
#endif
