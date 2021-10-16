#ifndef _ROS_SERVICE_TowerRobotMoveCommand_h
#define _ROS_SERVICE_TowerRobotMoveCommand_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_recognition_msgs
{

static const char TOWERROBOTMOVECOMMAND[] = "jsk_recognition_msgs/TowerRobotMoveCommand";

  class TowerRobotMoveCommandRequest : public ros::Msg
  {
    public:
      typedef int32_t _robot_index_type;
      _robot_index_type robot_index;
      typedef int32_t _plate_index_type;
      _plate_index_type plate_index;
      typedef int32_t _from_tower_type;
      _from_tower_type from_tower;
      typedef int32_t _to_tower_type;
      _to_tower_type to_tower;
      typedef int32_t _option_command_type;
      _option_command_type option_command;
      enum { ROBOT1 = 1 };
      enum { ROBOT2 = 2 };
      enum { ROBOT3 = 3 };
      enum { PLATE_SMALL = 1 };
      enum { PLATE_MIDDLE = 2 };
      enum { PLATE_LARGE = 3 };
      enum { TOWER_LOWEST = 1 };
      enum { TOWER_MIDDLE = 2 };
      enum { TOWER_HIGHEST = 3 };
      enum { TOWER_LOWEST2 = 1 };
      enum { OPTION_NONE = 0 };
      enum { OPTION_MOVE_INITIAL = 1 };

    TowerRobotMoveCommandRequest():
      robot_index(0),
      plate_index(0),
      from_tower(0),
      to_tower(0),
      option_command(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_robot_index;
      u_robot_index.real = this->robot_index;
      *(outbuffer + offset + 0) = (u_robot_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_robot_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_robot_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_robot_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->robot_index);
      union {
        int32_t real;
        uint32_t base;
      } u_plate_index;
      u_plate_index.real = this->plate_index;
      *(outbuffer + offset + 0) = (u_plate_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_plate_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_plate_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_plate_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->plate_index);
      union {
        int32_t real;
        uint32_t base;
      } u_from_tower;
      u_from_tower.real = this->from_tower;
      *(outbuffer + offset + 0) = (u_from_tower.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_from_tower.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_from_tower.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_from_tower.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->from_tower);
      union {
        int32_t real;
        uint32_t base;
      } u_to_tower;
      u_to_tower.real = this->to_tower;
      *(outbuffer + offset + 0) = (u_to_tower.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_to_tower.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_to_tower.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_to_tower.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->to_tower);
      union {
        int32_t real;
        uint32_t base;
      } u_option_command;
      u_option_command.real = this->option_command;
      *(outbuffer + offset + 0) = (u_option_command.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_option_command.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_option_command.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_option_command.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->option_command);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_robot_index;
      u_robot_index.base = 0;
      u_robot_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_robot_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_robot_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_robot_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->robot_index = u_robot_index.real;
      offset += sizeof(this->robot_index);
      union {
        int32_t real;
        uint32_t base;
      } u_plate_index;
      u_plate_index.base = 0;
      u_plate_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_plate_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_plate_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_plate_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->plate_index = u_plate_index.real;
      offset += sizeof(this->plate_index);
      union {
        int32_t real;
        uint32_t base;
      } u_from_tower;
      u_from_tower.base = 0;
      u_from_tower.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_from_tower.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_from_tower.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_from_tower.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->from_tower = u_from_tower.real;
      offset += sizeof(this->from_tower);
      union {
        int32_t real;
        uint32_t base;
      } u_to_tower;
      u_to_tower.base = 0;
      u_to_tower.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_to_tower.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_to_tower.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_to_tower.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->to_tower = u_to_tower.real;
      offset += sizeof(this->to_tower);
      union {
        int32_t real;
        uint32_t base;
      } u_option_command;
      u_option_command.base = 0;
      u_option_command.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_option_command.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_option_command.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_option_command.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->option_command = u_option_command.real;
      offset += sizeof(this->option_command);
     return offset;
    }

    const char * getType(){ return TOWERROBOTMOVECOMMAND; };
    const char * getMD5(){ return "aadba056bdce0494569ab50ecd2ec90c"; };

  };

  class TowerRobotMoveCommandResponse : public ros::Msg
  {
    public:

    TowerRobotMoveCommandResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return TOWERROBOTMOVECOMMAND; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class TowerRobotMoveCommand {
    public:
    typedef TowerRobotMoveCommandRequest Request;
    typedef TowerRobotMoveCommandResponse Response;
  };

}
#endif
