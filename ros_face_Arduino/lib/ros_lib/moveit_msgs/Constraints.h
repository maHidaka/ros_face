#ifndef _ROS_moveit_msgs_Constraints_h
#define _ROS_moveit_msgs_Constraints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/JointConstraint.h"
#include "moveit_msgs/PositionConstraint.h"
#include "moveit_msgs/OrientationConstraint.h"
#include "moveit_msgs/VisibilityConstraint.h"

namespace moveit_msgs
{

  class Constraints : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      uint32_t joint_constraints_length;
      typedef moveit_msgs::JointConstraint _joint_constraints_type;
      _joint_constraints_type st_joint_constraints;
      _joint_constraints_type * joint_constraints;
      uint32_t position_constraints_length;
      typedef moveit_msgs::PositionConstraint _position_constraints_type;
      _position_constraints_type st_position_constraints;
      _position_constraints_type * position_constraints;
      uint32_t orientation_constraints_length;
      typedef moveit_msgs::OrientationConstraint _orientation_constraints_type;
      _orientation_constraints_type st_orientation_constraints;
      _orientation_constraints_type * orientation_constraints;
      uint32_t visibility_constraints_length;
      typedef moveit_msgs::VisibilityConstraint _visibility_constraints_type;
      _visibility_constraints_type st_visibility_constraints;
      _visibility_constraints_type * visibility_constraints;

    Constraints():
      name(""),
      joint_constraints_length(0), joint_constraints(NULL),
      position_constraints_length(0), position_constraints(NULL),
      orientation_constraints_length(0), orientation_constraints(NULL),
      visibility_constraints_length(0), visibility_constraints(NULL)
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
      *(outbuffer + offset + 0) = (this->joint_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joint_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joint_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joint_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->joint_constraints_length);
      for( uint32_t i = 0; i < joint_constraints_length; i++){
      offset += this->joint_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->position_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->position_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->position_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->position_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_constraints_length);
      for( uint32_t i = 0; i < position_constraints_length; i++){
      offset += this->position_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->orientation_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->orientation_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->orientation_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->orientation_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->orientation_constraints_length);
      for( uint32_t i = 0; i < orientation_constraints_length; i++){
      offset += this->orientation_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->visibility_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->visibility_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->visibility_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->visibility_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->visibility_constraints_length);
      for( uint32_t i = 0; i < visibility_constraints_length; i++){
      offset += this->visibility_constraints[i].serialize(outbuffer + offset);
      }
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
      uint32_t joint_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joint_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->joint_constraints_length);
      if(joint_constraints_lengthT > joint_constraints_length)
        this->joint_constraints = (moveit_msgs::JointConstraint*)realloc(this->joint_constraints, joint_constraints_lengthT * sizeof(moveit_msgs::JointConstraint));
      joint_constraints_length = joint_constraints_lengthT;
      for( uint32_t i = 0; i < joint_constraints_length; i++){
      offset += this->st_joint_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->joint_constraints[i]), &(this->st_joint_constraints), sizeof(moveit_msgs::JointConstraint));
      }
      uint32_t position_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      position_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      position_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      position_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->position_constraints_length);
      if(position_constraints_lengthT > position_constraints_length)
        this->position_constraints = (moveit_msgs::PositionConstraint*)realloc(this->position_constraints, position_constraints_lengthT * sizeof(moveit_msgs::PositionConstraint));
      position_constraints_length = position_constraints_lengthT;
      for( uint32_t i = 0; i < position_constraints_length; i++){
      offset += this->st_position_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->position_constraints[i]), &(this->st_position_constraints), sizeof(moveit_msgs::PositionConstraint));
      }
      uint32_t orientation_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      orientation_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      orientation_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      orientation_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->orientation_constraints_length);
      if(orientation_constraints_lengthT > orientation_constraints_length)
        this->orientation_constraints = (moveit_msgs::OrientationConstraint*)realloc(this->orientation_constraints, orientation_constraints_lengthT * sizeof(moveit_msgs::OrientationConstraint));
      orientation_constraints_length = orientation_constraints_lengthT;
      for( uint32_t i = 0; i < orientation_constraints_length; i++){
      offset += this->st_orientation_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->orientation_constraints[i]), &(this->st_orientation_constraints), sizeof(moveit_msgs::OrientationConstraint));
      }
      uint32_t visibility_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      visibility_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      visibility_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      visibility_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->visibility_constraints_length);
      if(visibility_constraints_lengthT > visibility_constraints_length)
        this->visibility_constraints = (moveit_msgs::VisibilityConstraint*)realloc(this->visibility_constraints, visibility_constraints_lengthT * sizeof(moveit_msgs::VisibilityConstraint));
      visibility_constraints_length = visibility_constraints_lengthT;
      for( uint32_t i = 0; i < visibility_constraints_length; i++){
      offset += this->st_visibility_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->visibility_constraints[i]), &(this->st_visibility_constraints), sizeof(moveit_msgs::VisibilityConstraint));
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/Constraints"; };
    const char * getMD5(){ return "8d5ce8d34ef26c65fb5d43c9e99bf6e0"; };

  };

}
#endif
