#ifndef _ROS_jsk_recognition_msgs_HistogramWithRangeArray_h
#define _ROS_jsk_recognition_msgs_HistogramWithRangeArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/HistogramWithRange.h"

namespace jsk_recognition_msgs
{

  class HistogramWithRangeArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t histograms_length;
      typedef jsk_recognition_msgs::HistogramWithRange _histograms_type;
      _histograms_type st_histograms;
      _histograms_type * histograms;

    HistogramWithRangeArray():
      header(),
      histograms_length(0), histograms(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->histograms_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->histograms_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->histograms_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->histograms_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->histograms_length);
      for( uint32_t i = 0; i < histograms_length; i++){
      offset += this->histograms[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t histograms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      histograms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      histograms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      histograms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->histograms_length);
      if(histograms_lengthT > histograms_length)
        this->histograms = (jsk_recognition_msgs::HistogramWithRange*)realloc(this->histograms, histograms_lengthT * sizeof(jsk_recognition_msgs::HistogramWithRange));
      histograms_length = histograms_lengthT;
      for( uint32_t i = 0; i < histograms_length; i++){
      offset += this->st_histograms.deserialize(inbuffer + offset);
        memcpy( &(this->histograms[i]), &(this->st_histograms), sizeof(jsk_recognition_msgs::HistogramWithRange));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/HistogramWithRangeArray"; };
    const char * getMD5(){ return "2622b1b7ae84f154677cf4c0d3a398c7"; };

  };

}
#endif
