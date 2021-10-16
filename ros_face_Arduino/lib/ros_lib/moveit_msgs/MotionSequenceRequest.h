#ifndef _ROS_moveit_msgs_MotionSequenceRequest_h
#define _ROS_moveit_msgs_MotionSequenceRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/MotionSequenceItem.h"

namespace moveit_msgs
{

  class MotionSequenceRequest : public ros::Msg
  {
    public:
      uint32_t items_length;
      typedef moveit_msgs::MotionSequenceItem _items_type;
      _items_type st_items;
      _items_type * items;

    MotionSequenceRequest():
      items_length(0), items(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->items_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->items_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->items_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->items_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->items_length);
      for( uint32_t i = 0; i < items_length; i++){
      offset += this->items[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t items_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      items_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      items_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      items_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->items_length);
      if(items_lengthT > items_length)
        this->items = (moveit_msgs::MotionSequenceItem*)realloc(this->items, items_lengthT * sizeof(moveit_msgs::MotionSequenceItem));
      items_length = items_lengthT;
      for( uint32_t i = 0; i < items_length; i++){
      offset += this->st_items.deserialize(inbuffer + offset);
        memcpy( &(this->items[i]), &(this->st_items), sizeof(moveit_msgs::MotionSequenceItem));
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/MotionSequenceRequest"; };
    const char * getMD5(){ return "c89266756409bea218f39a7f05ef21a1"; };

  };

}
#endif
