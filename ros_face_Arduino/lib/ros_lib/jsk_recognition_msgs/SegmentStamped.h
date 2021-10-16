#ifndef _ROS_jsk_recognition_msgs_SegmentStamped_h
#define _ROS_jsk_recognition_msgs_SegmentStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/Segment.h"

namespace jsk_recognition_msgs
{

  class SegmentStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef jsk_recognition_msgs::Segment _segment_type;
      _segment_type segment;

    SegmentStamped():
      header(),
      segment()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->segment.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->segment.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/SegmentStamped"; };
    const char * getMD5(){ return "1f2fbdf9b9a242110bee5312e7718d1f"; };

  };

}
#endif
