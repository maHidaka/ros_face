#ifndef _ROS_moveit_msgs_KinematicSolverInfo_h
#define _ROS_moveit_msgs_KinematicSolverInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/JointLimits.h"

namespace moveit_msgs
{

  class KinematicSolverInfo : public ros::Msg
  {
    public:
      uint32_t joint_names_length;
      typedef char* _joint_names_type;
      _joint_names_type st_joint_names;
      _joint_names_type * joint_names;
      uint32_t limits_length;
      typedef moveit_msgs::JointLimits _limits_type;
      _limits_type st_limits;
      _limits_type * limits;
      uint32_t link_names_length;
      typedef char* _link_names_type;
      _link_names_type st_link_names;
      _link_names_type * link_names;

    KinematicSolverInfo():
      joint_names_length(0), joint_names(NULL),
      limits_length(0), limits(NULL),
      link_names_length(0), link_names(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->joint_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joint_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joint_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joint_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++){
      uint32_t length_joint_namesi = strlen(this->joint_names[i]);
      varToArr(outbuffer + offset, length_joint_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->joint_names[i], length_joint_namesi);
      offset += length_joint_namesi;
      }
      *(outbuffer + offset + 0) = (this->limits_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->limits_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->limits_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->limits_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->limits_length);
      for( uint32_t i = 0; i < limits_length; i++){
      offset += this->limits[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->link_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->link_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->link_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->link_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->link_names_length);
      for( uint32_t i = 0; i < link_names_length; i++){
      uint32_t length_link_namesi = strlen(this->link_names[i]);
      varToArr(outbuffer + offset, length_link_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->link_names[i], length_link_namesi);
      offset += length_link_namesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t joint_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->joint_names_length);
      if(joint_names_lengthT > joint_names_length)
        this->joint_names = (char**)realloc(this->joint_names, joint_names_lengthT * sizeof(char*));
      joint_names_length = joint_names_lengthT;
      for( uint32_t i = 0; i < joint_names_length; i++){
      uint32_t length_st_joint_names;
      arrToVar(length_st_joint_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_joint_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_joint_names-1]=0;
      this->st_joint_names = (char *)(inbuffer + offset-1);
      offset += length_st_joint_names;
        memcpy( &(this->joint_names[i]), &(this->st_joint_names), sizeof(char*));
      }
      uint32_t limits_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->limits_length);
      if(limits_lengthT > limits_length)
        this->limits = (moveit_msgs::JointLimits*)realloc(this->limits, limits_lengthT * sizeof(moveit_msgs::JointLimits));
      limits_length = limits_lengthT;
      for( uint32_t i = 0; i < limits_length; i++){
      offset += this->st_limits.deserialize(inbuffer + offset);
        memcpy( &(this->limits[i]), &(this->st_limits), sizeof(moveit_msgs::JointLimits));
      }
      uint32_t link_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->link_names_length);
      if(link_names_lengthT > link_names_length)
        this->link_names = (char**)realloc(this->link_names, link_names_lengthT * sizeof(char*));
      link_names_length = link_names_lengthT;
      for( uint32_t i = 0; i < link_names_length; i++){
      uint32_t length_st_link_names;
      arrToVar(length_st_link_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_link_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_link_names-1]=0;
      this->st_link_names = (char *)(inbuffer + offset-1);
      offset += length_st_link_names;
        memcpy( &(this->link_names[i]), &(this->st_link_names), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/KinematicSolverInfo"; };
    const char * getMD5(){ return "cc048557c0f9795c392dd80f8bb00489"; };

  };

}
#endif
