#ifndef _ROS_moveit_msgs_RobotState_h
#define _ROS_moveit_msgs_RobotState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/JointState.h"
#include "sensor_msgs/MultiDOFJointState.h"
#include "moveit_msgs/AttachedCollisionObject.h"

namespace moveit_msgs
{

  class RobotState : public ros::Msg
  {
    public:
      typedef sensor_msgs::JointState _joint_state_type;
      _joint_state_type joint_state;
      typedef sensor_msgs::MultiDOFJointState _multi_dof_joint_state_type;
      _multi_dof_joint_state_type multi_dof_joint_state;
      uint32_t attached_collision_objects_length;
      typedef moveit_msgs::AttachedCollisionObject _attached_collision_objects_type;
      _attached_collision_objects_type st_attached_collision_objects;
      _attached_collision_objects_type * attached_collision_objects;
      typedef bool _is_diff_type;
      _is_diff_type is_diff;

    RobotState():
      joint_state(),
      multi_dof_joint_state(),
      attached_collision_objects_length(0), attached_collision_objects(NULL),
      is_diff(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->joint_state.serialize(outbuffer + offset);
      offset += this->multi_dof_joint_state.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->attached_collision_objects_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->attached_collision_objects_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->attached_collision_objects_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->attached_collision_objects_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->attached_collision_objects_length);
      for( uint32_t i = 0; i < attached_collision_objects_length; i++){
      offset += this->attached_collision_objects[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_is_diff;
      u_is_diff.real = this->is_diff;
      *(outbuffer + offset + 0) = (u_is_diff.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_diff);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->joint_state.deserialize(inbuffer + offset);
      offset += this->multi_dof_joint_state.deserialize(inbuffer + offset);
      uint32_t attached_collision_objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      attached_collision_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      attached_collision_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      attached_collision_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->attached_collision_objects_length);
      if(attached_collision_objects_lengthT > attached_collision_objects_length)
        this->attached_collision_objects = (moveit_msgs::AttachedCollisionObject*)realloc(this->attached_collision_objects, attached_collision_objects_lengthT * sizeof(moveit_msgs::AttachedCollisionObject));
      attached_collision_objects_length = attached_collision_objects_lengthT;
      for( uint32_t i = 0; i < attached_collision_objects_length; i++){
      offset += this->st_attached_collision_objects.deserialize(inbuffer + offset);
        memcpy( &(this->attached_collision_objects[i]), &(this->st_attached_collision_objects), sizeof(moveit_msgs::AttachedCollisionObject));
      }
      union {
        bool real;
        uint8_t base;
      } u_is_diff;
      u_is_diff.base = 0;
      u_is_diff.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_diff = u_is_diff.real;
      offset += sizeof(this->is_diff);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/RobotState"; };
    const char * getMD5(){ return "217a2e8e5547f4162b13a37db9cb4da4"; };

  };

}
#endif
