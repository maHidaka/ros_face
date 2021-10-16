#ifndef _ROS_sound_play_SoundRequest_h
#define _ROS_sound_play_SoundRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sound_play
{

  class SoundRequest : public ros::Msg
  {
    public:
      typedef int8_t _sound_type;
      _sound_type sound;
      typedef int8_t _command_type;
      _command_type command;
      typedef float _volume_type;
      _volume_type volume;
      typedef const char* _arg_type;
      _arg_type arg;
      typedef const char* _arg2_type;
      _arg2_type arg2;
      enum { BACKINGUP =  1 };
      enum { NEEDS_UNPLUGGING =  2 };
      enum { NEEDS_PLUGGING =  3 };
      enum { NEEDS_UNPLUGGING_BADLY =  4 };
      enum { NEEDS_PLUGGING_BADLY =  5 };
      enum { ALL =  -1  };
      enum { PLAY_FILE =  -2 };
      enum { SAY =  -3 };
      enum { PLAY_STOP =  0  };
      enum { PLAY_ONCE =  1  };
      enum { PLAY_START =  2  };

    SoundRequest():
      sound(0),
      command(0),
      volume(0),
      arg(""),
      arg2("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_sound;
      u_sound.real = this->sound;
      *(outbuffer + offset + 0) = (u_sound.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sound);
      union {
        int8_t real;
        uint8_t base;
      } u_command;
      u_command.real = this->command;
      *(outbuffer + offset + 0) = (u_command.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      union {
        float real;
        uint32_t base;
      } u_volume;
      u_volume.real = this->volume;
      *(outbuffer + offset + 0) = (u_volume.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_volume.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_volume.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_volume.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->volume);
      uint32_t length_arg = strlen(this->arg);
      varToArr(outbuffer + offset, length_arg);
      offset += 4;
      memcpy(outbuffer + offset, this->arg, length_arg);
      offset += length_arg;
      uint32_t length_arg2 = strlen(this->arg2);
      varToArr(outbuffer + offset, length_arg2);
      offset += 4;
      memcpy(outbuffer + offset, this->arg2, length_arg2);
      offset += length_arg2;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_sound;
      u_sound.base = 0;
      u_sound.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sound = u_sound.real;
      offset += sizeof(this->sound);
      union {
        int8_t real;
        uint8_t base;
      } u_command;
      u_command.base = 0;
      u_command.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->command = u_command.real;
      offset += sizeof(this->command);
      union {
        float real;
        uint32_t base;
      } u_volume;
      u_volume.base = 0;
      u_volume.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_volume.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_volume.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_volume.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->volume = u_volume.real;
      offset += sizeof(this->volume);
      uint32_t length_arg;
      arrToVar(length_arg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_arg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_arg-1]=0;
      this->arg = (char *)(inbuffer + offset-1);
      offset += length_arg;
      uint32_t length_arg2;
      arrToVar(length_arg2, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_arg2; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_arg2-1]=0;
      this->arg2 = (char *)(inbuffer + offset-1);
      offset += length_arg2;
     return offset;
    }

    const char * getType(){ return "sound_play/SoundRequest"; };
    const char * getMD5(){ return "d098ce4a040686259137ece23a625167"; };

  };

}
#endif
