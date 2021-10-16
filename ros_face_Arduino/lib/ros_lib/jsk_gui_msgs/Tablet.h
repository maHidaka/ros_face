#ifndef _ROS_jsk_gui_msgs_Tablet_h
#define _ROS_jsk_gui_msgs_Tablet_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_gui_msgs/Action.h"
#include "jsk_gui_msgs/DeviceSensor.h"
#include "jsk_gui_msgs/Touch.h"

namespace jsk_gui_msgs
{

  class Tablet : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _hardware_name_type;
      _hardware_name_type hardware_name;
      typedef const char* _hardware_id_type;
      _hardware_id_type hardware_id;
      typedef jsk_gui_msgs::Action _action_type;
      _action_type action;
      typedef jsk_gui_msgs::DeviceSensor _sensor_type;
      _sensor_type sensor;
      uint32_t touches_length;
      typedef jsk_gui_msgs::Touch _touches_type;
      _touches_type st_touches;
      _touches_type * touches;

    Tablet():
      header(),
      hardware_name(""),
      hardware_id(""),
      action(),
      sensor(),
      touches_length(0), touches(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_hardware_name = strlen(this->hardware_name);
      varToArr(outbuffer + offset, length_hardware_name);
      offset += 4;
      memcpy(outbuffer + offset, this->hardware_name, length_hardware_name);
      offset += length_hardware_name;
      uint32_t length_hardware_id = strlen(this->hardware_id);
      varToArr(outbuffer + offset, length_hardware_id);
      offset += 4;
      memcpy(outbuffer + offset, this->hardware_id, length_hardware_id);
      offset += length_hardware_id;
      offset += this->action.serialize(outbuffer + offset);
      offset += this->sensor.serialize(outbuffer + offset);
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
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_hardware_name;
      arrToVar(length_hardware_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_hardware_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_hardware_name-1]=0;
      this->hardware_name = (char *)(inbuffer + offset-1);
      offset += length_hardware_name;
      uint32_t length_hardware_id;
      arrToVar(length_hardware_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_hardware_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_hardware_id-1]=0;
      this->hardware_id = (char *)(inbuffer + offset-1);
      offset += length_hardware_id;
      offset += this->action.deserialize(inbuffer + offset);
      offset += this->sensor.deserialize(inbuffer + offset);
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

    const char * getType(){ return "jsk_gui_msgs/Tablet"; };
    const char * getMD5(){ return "0bab196c7b214826d8c27d7bd5f924f6"; };

  };

}
#endif
