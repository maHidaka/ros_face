#ifndef _ROS_jsk_recognition_msgs_HistogramWithRange_h
#define _ROS_jsk_recognition_msgs_HistogramWithRange_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/HistogramWithRangeBin.h"

namespace jsk_recognition_msgs
{

  class HistogramWithRange : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t bins_length;
      typedef jsk_recognition_msgs::HistogramWithRangeBin _bins_type;
      _bins_type st_bins;
      _bins_type * bins;

    HistogramWithRange():
      header(),
      bins_length(0), bins(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->bins_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bins_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bins_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bins_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bins_length);
      for( uint32_t i = 0; i < bins_length; i++){
      offset += this->bins[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t bins_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      bins_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      bins_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      bins_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->bins_length);
      if(bins_lengthT > bins_length)
        this->bins = (jsk_recognition_msgs::HistogramWithRangeBin*)realloc(this->bins, bins_lengthT * sizeof(jsk_recognition_msgs::HistogramWithRangeBin));
      bins_length = bins_lengthT;
      for( uint32_t i = 0; i < bins_length; i++){
      offset += this->st_bins.deserialize(inbuffer + offset);
        memcpy( &(this->bins[i]), &(this->st_bins), sizeof(jsk_recognition_msgs::HistogramWithRangeBin));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/HistogramWithRange"; };
    const char * getMD5(){ return "aa922a22cbdcbdcc1146f30df5b605b8"; };

  };

}
#endif
