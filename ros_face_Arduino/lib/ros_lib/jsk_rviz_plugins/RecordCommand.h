#ifndef _ROS_jsk_rviz_plugins_RecordCommand_h
#define _ROS_jsk_rviz_plugins_RecordCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_rviz_plugins
{

  class RecordCommand : public ros::Msg
  {
    public:
      typedef int8_t _command_type;
      _command_type command;
      typedef const char* _target_type;
      _target_type target;
      enum { RECORD = 0 };
      enum { RECORD_STOP = 1 };
      enum { PLAY = 2 };

    RecordCommand():
      command(0),
      target("")
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
      uint32_t length_target = strlen(this->target);
      varToArr(outbuffer + offset, length_target);
      offset += 4;
      memcpy(outbuffer + offset, this->target, length_target);
      offset += length_target;
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
      uint32_t length_target;
      arrToVar(length_target, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target-1]=0;
      this->target = (char *)(inbuffer + offset-1);
      offset += length_target;
     return offset;
    }

    const char * getType(){ return "jsk_rviz_plugins/RecordCommand"; };
    const char * getMD5(){ return "31931c62eab5500089183eef0161c139"; };

  };

}
#endif
