#ifndef _ROS_moveit_msgs_LinkScale_h
#define _ROS_moveit_msgs_LinkScale_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

  class LinkScale : public ros::Msg
  {
    public:
      typedef const char* _link_name_type;
      _link_name_type link_name;
      typedef float _scale_type;
      _scale_type scale;

    LinkScale():
      link_name(""),
      scale(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_link_name = strlen(this->link_name);
      varToArr(outbuffer + offset, length_link_name);
      offset += 4;
      memcpy(outbuffer + offset, this->link_name, length_link_name);
      offset += length_link_name;
      offset += serializeAvrFloat64(outbuffer + offset, this->scale);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_link_name;
      arrToVar(length_link_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_name-1]=0;
      this->link_name = (char *)(inbuffer + offset-1);
      offset += length_link_name;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->scale));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/LinkScale"; };
    const char * getMD5(){ return "19faf226446bfb2f645a4da6f2a56166"; };

  };

}
#endif
