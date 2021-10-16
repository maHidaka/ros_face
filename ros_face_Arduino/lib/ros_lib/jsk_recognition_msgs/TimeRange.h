#ifndef _ROS_jsk_recognition_msgs_TimeRange_h
#define _ROS_jsk_recognition_msgs_TimeRange_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/time.h"

namespace jsk_recognition_msgs
{

  class TimeRange : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef ros::Time _start_type;
      _start_type start;
      typedef ros::Time _end_type;
      _end_type end;

    TimeRange():
      header(),
      start(),
      end()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->start.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start.sec);
      *(outbuffer + offset + 0) = (this->start.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start.nsec);
      *(outbuffer + offset + 0) = (this->end.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->end.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->end.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->end.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end.sec);
      *(outbuffer + offset + 0) = (this->end.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->end.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->end.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->end.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->start.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->start.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start.sec);
      this->start.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->start.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start.nsec);
      this->end.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->end.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->end.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->end.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->end.sec);
      this->end.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->end.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->end.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->end.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->end.nsec);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/TimeRange"; };
    const char * getMD5(){ return "a8a69e1e51e3731790c8e4120a725398"; };

  };

}
#endif
