#ifndef _ROS_jsk_recognition_msgs_SegmentArray_h
#define _ROS_jsk_recognition_msgs_SegmentArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/Segment.h"

namespace jsk_recognition_msgs
{

  class SegmentArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t segments_length;
      typedef jsk_recognition_msgs::Segment _segments_type;
      _segments_type st_segments;
      _segments_type * segments;

    SegmentArray():
      header(),
      segments_length(0), segments(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->segments_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->segments_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->segments_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->segments_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->segments_length);
      for( uint32_t i = 0; i < segments_length; i++){
      offset += this->segments[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t segments_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      segments_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      segments_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      segments_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->segments_length);
      if(segments_lengthT > segments_length)
        this->segments = (jsk_recognition_msgs::Segment*)realloc(this->segments, segments_lengthT * sizeof(jsk_recognition_msgs::Segment));
      segments_length = segments_lengthT;
      for( uint32_t i = 0; i < segments_length; i++){
      offset += this->st_segments.deserialize(inbuffer + offset);
        memcpy( &(this->segments[i]), &(this->st_segments), sizeof(jsk_recognition_msgs::Segment));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/SegmentArray"; };
    const char * getMD5(){ return "672a84c8545e1a65663c5497ab1a917c"; };

  };

}
#endif
