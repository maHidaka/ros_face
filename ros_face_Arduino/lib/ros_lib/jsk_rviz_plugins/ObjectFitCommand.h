#ifndef _ROS_jsk_rviz_plugins_ObjectFitCommand_h
#define _ROS_jsk_rviz_plugins_ObjectFitCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_rviz_plugins
{

  class ObjectFitCommand : public ros::Msg
  {
    public:
      typedef int8_t _command_type;
      _command_type command;
      enum { FIT = 0 };
      enum { NEAR = 1 };
      enum { OTHER = 2 };
      enum { REVERSE_FIT = 3 };
      enum { REVERSE_NEAR = 4 };
      enum { REVERSE_OTHER = 5 };

    ObjectFitCommand():
      command(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_command;
      u_command.real = this->command;
      *(outbuffer + offset + 0) = (u_command.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_command;
      u_command.base = 0;
      u_command.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->command = u_command.real;
      offset += sizeof(this->command);
     return offset;
    }

    const char * getType(){ return "jsk_rviz_plugins/ObjectFitCommand"; };
    const char * getMD5(){ return "aaf37eac6a6717d09d438978a4117776"; };

  };

}
#endif
