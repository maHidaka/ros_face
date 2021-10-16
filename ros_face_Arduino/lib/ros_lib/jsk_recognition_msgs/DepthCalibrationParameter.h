#ifndef _ROS_jsk_recognition_msgs_DepthCalibrationParameter_h
#define _ROS_jsk_recognition_msgs_DepthCalibrationParameter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_recognition_msgs
{

  class DepthCalibrationParameter : public ros::Msg
  {
    public:
      uint32_t coefficients2_length;
      typedef float _coefficients2_type;
      _coefficients2_type st_coefficients2;
      _coefficients2_type * coefficients2;
      uint32_t coefficients1_length;
      typedef float _coefficients1_type;
      _coefficients1_type st_coefficients1;
      _coefficients1_type * coefficients1;
      uint32_t coefficients0_length;
      typedef float _coefficients0_type;
      _coefficients0_type st_coefficients0;
      _coefficients0_type * coefficients0;
      typedef bool _use_abs_type;
      _use_abs_type use_abs;

    DepthCalibrationParameter():
      coefficients2_length(0), coefficients2(NULL),
      coefficients1_length(0), coefficients1(NULL),
      coefficients0_length(0), coefficients0(NULL),
      use_abs(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->coefficients2_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->coefficients2_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->coefficients2_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->coefficients2_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coefficients2_length);
      for( uint32_t i = 0; i < coefficients2_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->coefficients2[i]);
      }
      *(outbuffer + offset + 0) = (this->coefficients1_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->coefficients1_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->coefficients1_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->coefficients1_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coefficients1_length);
      for( uint32_t i = 0; i < coefficients1_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->coefficients1[i]);
      }
      *(outbuffer + offset + 0) = (this->coefficients0_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->coefficients0_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->coefficients0_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->coefficients0_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coefficients0_length);
      for( uint32_t i = 0; i < coefficients0_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->coefficients0[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_use_abs;
      u_use_abs.real = this->use_abs;
      *(outbuffer + offset + 0) = (u_use_abs.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_abs);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t coefficients2_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      coefficients2_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      coefficients2_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      coefficients2_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->coefficients2_length);
      if(coefficients2_lengthT > coefficients2_length)
        this->coefficients2 = (float*)realloc(this->coefficients2, coefficients2_lengthT * sizeof(float));
      coefficients2_length = coefficients2_lengthT;
      for( uint32_t i = 0; i < coefficients2_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_coefficients2));
        memcpy( &(this->coefficients2[i]), &(this->st_coefficients2), sizeof(float));
      }
      uint32_t coefficients1_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      coefficients1_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      coefficients1_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      coefficients1_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->coefficients1_length);
      if(coefficients1_lengthT > coefficients1_length)
        this->coefficients1 = (float*)realloc(this->coefficients1, coefficients1_lengthT * sizeof(float));
      coefficients1_length = coefficients1_lengthT;
      for( uint32_t i = 0; i < coefficients1_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_coefficients1));
        memcpy( &(this->coefficients1[i]), &(this->st_coefficients1), sizeof(float));
      }
      uint32_t coefficients0_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      coefficients0_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      coefficients0_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      coefficients0_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->coefficients0_length);
      if(coefficients0_lengthT > coefficients0_length)
        this->coefficients0 = (float*)realloc(this->coefficients0, coefficients0_lengthT * sizeof(float));
      coefficients0_length = coefficients0_lengthT;
      for( uint32_t i = 0; i < coefficients0_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_coefficients0));
        memcpy( &(this->coefficients0[i]), &(this->st_coefficients0), sizeof(float));
      }
      union {
        bool real;
        uint8_t base;
      } u_use_abs;
      u_use_abs.base = 0;
      u_use_abs.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_abs = u_use_abs.real;
      offset += sizeof(this->use_abs);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/DepthCalibrationParameter"; };
    const char * getMD5(){ return "d8318983ee0a76ad66ecf4b504350888"; };

  };

}
#endif
