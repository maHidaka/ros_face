#ifndef _ROS_jsk_gui_msgs_Action_h
#define _ROS_jsk_gui_msgs_Action_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_gui_msgs
{

  class Action : public ros::Msg
  {
    public:
      typedef const char* _task_name_type;
      _task_name_type task_name;
      typedef int64_t _arm_id_type;
      _arm_id_type arm_id;
      typedef const char* _state_type;
      _state_type state;
      typedef float _state_value_type;
      _state_value_type state_value;
      typedef const char* _direction_type;
      _direction_type direction;
      typedef float _direction_value_type;
      _direction_value_type direction_value;
      typedef int64_t _touch_x_type;
      _touch_x_type touch_x;
      typedef int64_t _touch_y_type;
      _touch_y_type touch_y;
      enum { RARMID = 0 };
      enum { LARMID = 1 };

    Action():
      task_name(""),
      arm_id(0),
      state(""),
      state_value(0),
      direction(""),
      direction_value(0),
      touch_x(0),
      touch_y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_task_name = strlen(this->task_name);
      varToArr(outbuffer + offset, length_task_name);
      offset += 4;
      memcpy(outbuffer + offset, this->task_name, length_task_name);
      offset += length_task_name;
      union {
        int64_t real;
        uint64_t base;
      } u_arm_id;
      u_arm_id.real = this->arm_id;
      *(outbuffer + offset + 0) = (u_arm_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_arm_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_arm_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_arm_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_arm_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_arm_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_arm_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_arm_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->arm_id);
      uint32_t length_state = strlen(this->state);
      varToArr(outbuffer + offset, length_state);
      offset += 4;
      memcpy(outbuffer + offset, this->state, length_state);
      offset += length_state;
      offset += serializeAvrFloat64(outbuffer + offset, this->state_value);
      uint32_t length_direction = strlen(this->direction);
      varToArr(outbuffer + offset, length_direction);
      offset += 4;
      memcpy(outbuffer + offset, this->direction, length_direction);
      offset += length_direction;
      offset += serializeAvrFloat64(outbuffer + offset, this->direction_value);
      union {
        int64_t real;
        uint64_t base;
      } u_touch_x;
      u_touch_x.real = this->touch_x;
      *(outbuffer + offset + 0) = (u_touch_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_touch_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_touch_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_touch_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_touch_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_touch_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_touch_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_touch_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->touch_x);
      union {
        int64_t real;
        uint64_t base;
      } u_touch_y;
      u_touch_y.real = this->touch_y;
      *(outbuffer + offset + 0) = (u_touch_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_touch_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_touch_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_touch_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_touch_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_touch_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_touch_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_touch_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->touch_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_task_name;
      arrToVar(length_task_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_task_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_task_name-1]=0;
      this->task_name = (char *)(inbuffer + offset-1);
      offset += length_task_name;
      union {
        int64_t real;
        uint64_t base;
      } u_arm_id;
      u_arm_id.base = 0;
      u_arm_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_arm_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_arm_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_arm_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_arm_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_arm_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_arm_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_arm_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->arm_id = u_arm_id.real;
      offset += sizeof(this->arm_id);
      uint32_t length_state;
      arrToVar(length_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state-1]=0;
      this->state = (char *)(inbuffer + offset-1);
      offset += length_state;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->state_value));
      uint32_t length_direction;
      arrToVar(length_direction, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_direction; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_direction-1]=0;
      this->direction = (char *)(inbuffer + offset-1);
      offset += length_direction;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->direction_value));
      union {
        int64_t real;
        uint64_t base;
      } u_touch_x;
      u_touch_x.base = 0;
      u_touch_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_touch_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_touch_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_touch_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_touch_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_touch_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_touch_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_touch_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->touch_x = u_touch_x.real;
      offset += sizeof(this->touch_x);
      union {
        int64_t real;
        uint64_t base;
      } u_touch_y;
      u_touch_y.base = 0;
      u_touch_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_touch_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_touch_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_touch_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_touch_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_touch_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_touch_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_touch_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->touch_y = u_touch_y.real;
      offset += sizeof(this->touch_y);
     return offset;
    }

    const char * getType(){ return "jsk_gui_msgs/Action"; };
    const char * getMD5(){ return "d81dc8475ff89ce7097d2e73ebfc2591"; };

  };

}
#endif
