#ifndef _ROS_jsk_recognition_msgs_HistogramWithRangeBin_h
#define _ROS_jsk_recognition_msgs_HistogramWithRangeBin_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_recognition_msgs
{

  class HistogramWithRangeBin : public ros::Msg
  {
    public:
      typedef float _min_value_type;
      _min_value_type min_value;
      typedef float _max_value_type;
      _max_value_type max_value;
      typedef uint32_t _count_type;
      _count_type count;

    HistogramWithRangeBin():
      min_value(0),
      max_value(0),
      count(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->min_value);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_value);
      *(outbuffer + offset + 0) = (this->count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->count >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->count >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->count >> (8 * 3)) & 0xFF;
      offset += sizeof(this->count);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_value));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_value));
      this->count =  ((uint32_t) (*(inbuffer + offset)));
      this->count |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->count |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->count |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->count);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/HistogramWithRangeBin"; };
    const char * getMD5(){ return "a7fe6c3021fcba2c6357f3db21601551"; };

  };

}
#endif
