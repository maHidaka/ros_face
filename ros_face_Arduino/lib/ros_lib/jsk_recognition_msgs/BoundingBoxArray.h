#ifndef _ROS_jsk_recognition_msgs_BoundingBoxArray_h
#define _ROS_jsk_recognition_msgs_BoundingBoxArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/BoundingBox.h"

namespace jsk_recognition_msgs
{

  class BoundingBoxArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t boxes_length;
      typedef jsk_recognition_msgs::BoundingBox _boxes_type;
      _boxes_type st_boxes;
      _boxes_type * boxes;

    BoundingBoxArray():
      header(),
      boxes_length(0), boxes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->boxes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->boxes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->boxes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->boxes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->boxes_length);
      for( uint32_t i = 0; i < boxes_length; i++){
      offset += this->boxes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t boxes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      boxes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      boxes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      boxes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->boxes_length);
      if(boxes_lengthT > boxes_length)
        this->boxes = (jsk_recognition_msgs::BoundingBox*)realloc(this->boxes, boxes_lengthT * sizeof(jsk_recognition_msgs::BoundingBox));
      boxes_length = boxes_lengthT;
      for( uint32_t i = 0; i < boxes_length; i++){
      offset += this->st_boxes.deserialize(inbuffer + offset);
        memcpy( &(this->boxes[i]), &(this->st_boxes), sizeof(jsk_recognition_msgs::BoundingBox));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/BoundingBoxArray"; };
    const char * getMD5(){ return "c8f4a8bb1acd18ce778d183912bb472d"; };

  };

}
#endif
