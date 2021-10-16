#ifndef _ROS_audio_common_msgs_AudioInfo_h
#define _ROS_audio_common_msgs_AudioInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace audio_common_msgs
{

  class AudioInfo : public ros::Msg
  {
    public:
      typedef uint8_t _channels_type;
      _channels_type channels;
      typedef uint32_t _sample_rate_type;
      _sample_rate_type sample_rate;
      typedef const char* _sample_format_type;
      _sample_format_type sample_format;
      typedef uint32_t _bitrate_type;
      _bitrate_type bitrate;
      typedef const char* _coding_format_type;
      _coding_format_type coding_format;

    AudioInfo():
      channels(0),
      sample_rate(0),
      sample_format(""),
      bitrate(0),
      coding_format("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->channels >> (8 * 0)) & 0xFF;
      offset += sizeof(this->channels);
      *(outbuffer + offset + 0) = (this->sample_rate >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sample_rate >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sample_rate >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sample_rate >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sample_rate);
      uint32_t length_sample_format = strlen(this->sample_format);
      varToArr(outbuffer + offset, length_sample_format);
      offset += 4;
      memcpy(outbuffer + offset, this->sample_format, length_sample_format);
      offset += length_sample_format;
      *(outbuffer + offset + 0) = (this->bitrate >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bitrate >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bitrate >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bitrate >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bitrate);
      uint32_t length_coding_format = strlen(this->coding_format);
      varToArr(outbuffer + offset, length_coding_format);
      offset += 4;
      memcpy(outbuffer + offset, this->coding_format, length_coding_format);
      offset += length_coding_format;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->channels =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->channels);
      this->sample_rate =  ((uint32_t) (*(inbuffer + offset)));
      this->sample_rate |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sample_rate |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sample_rate |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sample_rate);
      uint32_t length_sample_format;
      arrToVar(length_sample_format, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sample_format; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sample_format-1]=0;
      this->sample_format = (char *)(inbuffer + offset-1);
      offset += length_sample_format;
      this->bitrate =  ((uint32_t) (*(inbuffer + offset)));
      this->bitrate |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->bitrate |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->bitrate |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->bitrate);
      uint32_t length_coding_format;
      arrToVar(length_coding_format, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_coding_format; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_coding_format-1]=0;
      this->coding_format = (char *)(inbuffer + offset-1);
      offset += length_coding_format;
     return offset;
    }

    const char * getType(){ return "audio_common_msgs/AudioInfo"; };
    const char * getMD5(){ return "9413d9b7029680d3b1db6ed0ae535f88"; };

  };

}
#endif
