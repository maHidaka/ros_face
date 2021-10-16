#ifndef _ROS_jsk_recognition_msgs_Spectrum_h
#define _ROS_jsk_recognition_msgs_Spectrum_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class Spectrum : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t amplitude_length;
      typedef float _amplitude_type;
      _amplitude_type st_amplitude;
      _amplitude_type * amplitude;
      uint32_t frequency_length;
      typedef float _frequency_type;
      _frequency_type st_frequency;
      _frequency_type * frequency;

    Spectrum():
      header(),
      amplitude_length(0), amplitude(NULL),
      frequency_length(0), frequency(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->amplitude_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->amplitude_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->amplitude_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->amplitude_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->amplitude_length);
      for( uint32_t i = 0; i < amplitude_length; i++){
      union {
        float real;
        uint32_t base;
      } u_amplitudei;
      u_amplitudei.real = this->amplitude[i];
      *(outbuffer + offset + 0) = (u_amplitudei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_amplitudei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_amplitudei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_amplitudei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->amplitude[i]);
      }
      *(outbuffer + offset + 0) = (this->frequency_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->frequency_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->frequency_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->frequency_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frequency_length);
      for( uint32_t i = 0; i < frequency_length; i++){
      union {
        float real;
        uint32_t base;
      } u_frequencyi;
      u_frequencyi.real = this->frequency[i];
      *(outbuffer + offset + 0) = (u_frequencyi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frequencyi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frequencyi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frequencyi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frequency[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t amplitude_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      amplitude_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      amplitude_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      amplitude_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->amplitude_length);
      if(amplitude_lengthT > amplitude_length)
        this->amplitude = (float*)realloc(this->amplitude, amplitude_lengthT * sizeof(float));
      amplitude_length = amplitude_lengthT;
      for( uint32_t i = 0; i < amplitude_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_amplitude;
      u_st_amplitude.base = 0;
      u_st_amplitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_amplitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_amplitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_amplitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_amplitude = u_st_amplitude.real;
      offset += sizeof(this->st_amplitude);
        memcpy( &(this->amplitude[i]), &(this->st_amplitude), sizeof(float));
      }
      uint32_t frequency_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      frequency_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      frequency_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      frequency_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->frequency_length);
      if(frequency_lengthT > frequency_length)
        this->frequency = (float*)realloc(this->frequency, frequency_lengthT * sizeof(float));
      frequency_length = frequency_lengthT;
      for( uint32_t i = 0; i < frequency_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_frequency;
      u_st_frequency.base = 0;
      u_st_frequency.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_frequency.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_frequency.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_frequency.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_frequency = u_st_frequency.real;
      offset += sizeof(this->st_frequency);
        memcpy( &(this->frequency[i]), &(this->st_frequency), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/Spectrum"; };
    const char * getMD5(){ return "df74a130749a91198632eab1192d1cc9"; };

  };

}
#endif
