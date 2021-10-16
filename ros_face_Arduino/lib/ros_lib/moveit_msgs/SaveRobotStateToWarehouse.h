#ifndef _ROS_SERVICE_SaveRobotStateToWarehouse_h
#define _ROS_SERVICE_SaveRobotStateToWarehouse_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/RobotState.h"

namespace moveit_msgs
{

static const char SAVEROBOTSTATETOWAREHOUSE[] = "moveit_msgs/SaveRobotStateToWarehouse";

  class SaveRobotStateToWarehouseRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _robot_type;
      _robot_type robot;
      typedef moveit_msgs::RobotState _state_type;
      _state_type state;

    SaveRobotStateToWarehouseRequest():
      name(""),
      robot(""),
      state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_robot = strlen(this->robot);
      varToArr(outbuffer + offset, length_robot);
      offset += 4;
      memcpy(outbuffer + offset, this->robot, length_robot);
      offset += length_robot;
      offset += this->state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_robot;
      arrToVar(length_robot, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot-1]=0;
      this->robot = (char *)(inbuffer + offset-1);
      offset += length_robot;
      offset += this->state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SAVEROBOTSTATETOWAREHOUSE; };
    const char * getMD5(){ return "7937284880c511876f85988912ec5448"; };

  };

  class SaveRobotStateToWarehouseResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SaveRobotStateToWarehouseResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return SAVEROBOTSTATETOWAREHOUSE; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SaveRobotStateToWarehouse {
    public:
    typedef SaveRobotStateToWarehouseRequest Request;
    typedef SaveRobotStateToWarehouseResponse Response;
  };

}
#endif
