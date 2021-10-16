#ifndef _ROS_SERVICE_EusCommand_h
#define _ROS_SERVICE_EusCommand_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_rviz_plugins
{

static const char EUSCOMMAND[] = "jsk_rviz_plugins/EusCommand";

  class EusCommandRequest : public ros::Msg
  {
    public:
      typedef const char* _command_type;
      _command_type command;

    EusCommandRequest():
      command("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_command = strlen(this->command);
      varToArr(outbuffer + offset, length_command);
      offset += 4;
      memcpy(outbuffer + offset, this->command, length_command);
      offset += length_command;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_command;
      arrToVar(length_command, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_command; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_command-1]=0;
      this->command = (char *)(inbuffer + offset-1);
      offset += length_command;
     return offset;
    }

    const char * getType(){ return EUSCOMMAND; };
    const char * getMD5(){ return "cba5e21e920a3a2b7b375cb65b64cdea"; };

  };

  class EusCommandResponse : public ros::Msg
  {
    public:

    EusCommandResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return EUSCOMMAND; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class EusCommand {
    public:
    typedef EusCommandRequest Request;
    typedef EusCommandResponse Response;
  };

}
#endif
