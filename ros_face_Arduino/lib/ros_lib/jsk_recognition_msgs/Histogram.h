#ifndef _ROS_jsk_recognition_msgs_Histogram_h
#define _ROS_jsk_recognition_msgs_Histogram_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class Histogram : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t histogram_length;
      typedef float _histogram_type;
      _histogram_type st_histogram;
      _histogram_type * histogram;

    Histogram():
      header(),
      histogram_length(0), histogram(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->histogram_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->histogram_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->histogram_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->histogram_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->histogram_length);
      for( uint32_t i = 0; i < histogram_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->histogram[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t histogram_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      histogram_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      histogram_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      histogram_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->histogram_length);
      if(histogram_lengthT > histogram_length)
        this->histogram = (float*)realloc(this->histogram, histogram_lengthT * sizeof(float));
      histogram_length = histogram_lengthT;
      for( uint32_t i = 0; i < histogram_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_histogram));
        memcpy( &(this->histogram[i]), &(this->st_histogram), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/Histogram"; };
    const char * getMD5(){ return "376372f016c22c39ab7ee6b6bdd0f10a"; };

  };

}
#endif
