#ifndef _ROS_jsk_gui_msgs_MagneticField_h
#define _ROS_jsk_gui_msgs_MagneticField_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace jsk_gui_msgs
{

  class MagneticField : public ros::Msg
  {
    public:
      typedef geometry_msgs::Vector3 _magneticfield_type;
      _magneticfield_type magneticfield;

    MagneticField():
      magneticfield()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->magneticfield.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->magneticfield.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_gui_msgs/MagneticField"; };
    const char * getMD5(){ return "a924df7c82a527d1b76508ed8354604b"; };

  };

}
#endif
