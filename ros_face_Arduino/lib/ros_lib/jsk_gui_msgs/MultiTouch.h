#ifndef _ROS_jsk_gui_msgs_MultiTouch_h
#define _ROS_jsk_gui_msgs_MultiTouch_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_gui_msgs/Touch.h"

namespace jsk_gui_msgs
{

  class MultiTouch : public ros::Msg
  {
    public:
      uint32_t touches_length;
      typedef jsk_gui_msgs::Touch _touches_type;
      _touches_type st_touches;
      _touches_type * touches;

    MultiTouch():
      touches_length(0), touches(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->touches_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->touches_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->touches_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->touches_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->touches_length);
      for( uint32_t i = 0; i < touches_length; i++){
      offset += this->touches[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t touches_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      touches_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      touches_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      touches_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->touches_length);
      if(touches_lengthT > touches_length)
        this->touches = (jsk_gui_msgs::Touch*)realloc(this->touches, touches_lengthT * sizeof(jsk_gui_msgs::Touch));
      touches_length = touches_lengthT;
      for( uint32_t i = 0; i < touches_length; i++){
      offset += this->st_touches.deserialize(inbuffer + offset);
        memcpy( &(this->touches[i]), &(this->st_touches), sizeof(jsk_gui_msgs::Touch));
      }
     return offset;
    }

    const char * getType(){ return "jsk_gui_msgs/MultiTouch"; };
    const char * getMD5(){ return "9f4a309588ef669e69a71aa5601ea65e"; };

  };

}
#endif
