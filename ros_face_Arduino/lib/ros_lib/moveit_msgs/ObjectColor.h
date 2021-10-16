#ifndef _ROS_moveit_msgs_ObjectColor_h
#define _ROS_moveit_msgs_ObjectColor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"

namespace moveit_msgs
{

  class ObjectColor : public ros::Msg
  {
    public:
      typedef const char* _id_type;
      _id_type id;
      typedef std_msgs::ColorRGBA _color_type;
      _color_type color;

    ObjectColor():
      id(""),
      color()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      offset += this->color.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      offset += this->color.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/ObjectColor"; };
    const char * getMD5(){ return "ec3bd6f103430e64b2ae706a67d8488e"; };

  };

}
#endif
