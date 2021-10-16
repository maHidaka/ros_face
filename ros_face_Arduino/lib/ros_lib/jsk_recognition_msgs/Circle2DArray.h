#ifndef _ROS_jsk_recognition_msgs_Circle2DArray_h
#define _ROS_jsk_recognition_msgs_Circle2DArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/Circle2D.h"

namespace jsk_recognition_msgs
{

  class Circle2DArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t circles_length;
      typedef jsk_recognition_msgs::Circle2D _circles_type;
      _circles_type st_circles;
      _circles_type * circles;

    Circle2DArray():
      header(),
      circles_length(0), circles(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->circles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->circles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->circles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->circles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->circles_length);
      for( uint32_t i = 0; i < circles_length; i++){
      offset += this->circles[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t circles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      circles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      circles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      circles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->circles_length);
      if(circles_lengthT > circles_length)
        this->circles = (jsk_recognition_msgs::Circle2D*)realloc(this->circles, circles_lengthT * sizeof(jsk_recognition_msgs::Circle2D));
      circles_length = circles_lengthT;
      for( uint32_t i = 0; i < circles_length; i++){
      offset += this->st_circles.deserialize(inbuffer + offset);
        memcpy( &(this->circles[i]), &(this->st_circles), sizeof(jsk_recognition_msgs::Circle2D));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/Circle2DArray"; };
    const char * getMD5(){ return "7c3f0f08758538a1e02ce600cf99132f"; };

  };

}
#endif
