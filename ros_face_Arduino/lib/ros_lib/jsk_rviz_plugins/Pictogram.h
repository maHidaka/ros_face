#ifndef _ROS_jsk_rviz_plugins_Pictogram_h
#define _ROS_jsk_rviz_plugins_Pictogram_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "std_msgs/ColorRGBA.h"

namespace jsk_rviz_plugins
{

  class Pictogram : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef uint8_t _action_type;
      _action_type action;
      typedef uint8_t _mode_type;
      _mode_type mode;
      typedef const char* _character_type;
      _character_type character;
      typedef float _size_type;
      _size_type size;
      typedef float _ttl_type;
      _ttl_type ttl;
      typedef float _speed_type;
      _speed_type speed;
      typedef std_msgs::ColorRGBA _color_type;
      _color_type color;
      enum { ADD = 0 };
      enum { DELETE = 1 };
      enum { ROTATE_Z = 2 };
      enum { ROTATE_Y = 3 };
      enum { ROTATE_X = 4 };
      enum { JUMP = 5 };
      enum { JUMP_ONCE = 6 };
      enum { PICTOGRAM_MODE = 0 };
      enum { STRING_MODE = 1 };

    Pictogram():
      header(),
      pose(),
      action(0),
      mode(0),
      character(""),
      size(0),
      ttl(0),
      speed(0),
      color()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->action >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action);
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      uint32_t length_character = strlen(this->character);
      varToArr(outbuffer + offset, length_character);
      offset += 4;
      memcpy(outbuffer + offset, this->character, length_character);
      offset += length_character;
      offset += serializeAvrFloat64(outbuffer + offset, this->size);
      offset += serializeAvrFloat64(outbuffer + offset, this->ttl);
      offset += serializeAvrFloat64(outbuffer + offset, this->speed);
      offset += this->color.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      this->action =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->action);
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
      uint32_t length_character;
      arrToVar(length_character, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_character; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_character-1]=0;
      this->character = (char *)(inbuffer + offset-1);
      offset += length_character;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->size));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ttl));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speed));
      offset += this->color.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_rviz_plugins/Pictogram"; };
    const char * getMD5(){ return "29667e5652a8cfdc9c87d2ed97aa7bbc"; };

  };

}
#endif
