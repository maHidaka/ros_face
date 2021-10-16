#ifndef _ROS_moveit_msgs_PositionIKRequest_h
#define _ROS_moveit_msgs_PositionIKRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/Constraints.h"
#include "geometry_msgs/PoseStamped.h"
#include "ros/duration.h"

namespace moveit_msgs
{

  class PositionIKRequest : public ros::Msg
  {
    public:
      typedef const char* _group_name_type;
      _group_name_type group_name;
      typedef moveit_msgs::RobotState _robot_state_type;
      _robot_state_type robot_state;
      typedef moveit_msgs::Constraints _constraints_type;
      _constraints_type constraints;
      typedef bool _avoid_collisions_type;
      _avoid_collisions_type avoid_collisions;
      typedef const char* _ik_link_name_type;
      _ik_link_name_type ik_link_name;
      typedef geometry_msgs::PoseStamped _pose_stamped_type;
      _pose_stamped_type pose_stamped;
      uint32_t ik_link_names_length;
      typedef char* _ik_link_names_type;
      _ik_link_names_type st_ik_link_names;
      _ik_link_names_type * ik_link_names;
      uint32_t pose_stamped_vector_length;
      typedef geometry_msgs::PoseStamped _pose_stamped_vector_type;
      _pose_stamped_vector_type st_pose_stamped_vector;
      _pose_stamped_vector_type * pose_stamped_vector;
      typedef ros::Duration _timeout_type;
      _timeout_type timeout;
      typedef int32_t _attempts_type;
      _attempts_type attempts;

    PositionIKRequest():
      group_name(""),
      robot_state(),
      constraints(),
      avoid_collisions(0),
      ik_link_name(""),
      pose_stamped(),
      ik_link_names_length(0), ik_link_names(NULL),
      pose_stamped_vector_length(0), pose_stamped_vector(NULL),
      timeout(),
      attempts(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_group_name = strlen(this->group_name);
      varToArr(outbuffer + offset, length_group_name);
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      offset += this->robot_state.serialize(outbuffer + offset);
      offset += this->constraints.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_avoid_collisions;
      u_avoid_collisions.real = this->avoid_collisions;
      *(outbuffer + offset + 0) = (u_avoid_collisions.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->avoid_collisions);
      uint32_t length_ik_link_name = strlen(this->ik_link_name);
      varToArr(outbuffer + offset, length_ik_link_name);
      offset += 4;
      memcpy(outbuffer + offset, this->ik_link_name, length_ik_link_name);
      offset += length_ik_link_name;
      offset += this->pose_stamped.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->ik_link_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ik_link_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ik_link_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ik_link_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ik_link_names_length);
      for( uint32_t i = 0; i < ik_link_names_length; i++){
      uint32_t length_ik_link_namesi = strlen(this->ik_link_names[i]);
      varToArr(outbuffer + offset, length_ik_link_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->ik_link_names[i], length_ik_link_namesi);
      offset += length_ik_link_namesi;
      }
      *(outbuffer + offset + 0) = (this->pose_stamped_vector_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pose_stamped_vector_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pose_stamped_vector_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pose_stamped_vector_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pose_stamped_vector_length);
      for( uint32_t i = 0; i < pose_stamped_vector_length; i++){
      offset += this->pose_stamped_vector[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->timeout.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeout.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeout.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeout.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout.sec);
      *(outbuffer + offset + 0) = (this->timeout.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeout.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeout.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeout.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout.nsec);
      union {
        int32_t real;
        uint32_t base;
      } u_attempts;
      u_attempts.real = this->attempts;
      *(outbuffer + offset + 0) = (u_attempts.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_attempts.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_attempts.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_attempts.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->attempts);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_group_name;
      arrToVar(length_group_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
      offset += this->robot_state.deserialize(inbuffer + offset);
      offset += this->constraints.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_avoid_collisions;
      u_avoid_collisions.base = 0;
      u_avoid_collisions.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->avoid_collisions = u_avoid_collisions.real;
      offset += sizeof(this->avoid_collisions);
      uint32_t length_ik_link_name;
      arrToVar(length_ik_link_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ik_link_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ik_link_name-1]=0;
      this->ik_link_name = (char *)(inbuffer + offset-1);
      offset += length_ik_link_name;
      offset += this->pose_stamped.deserialize(inbuffer + offset);
      uint32_t ik_link_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ik_link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ik_link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ik_link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ik_link_names_length);
      if(ik_link_names_lengthT > ik_link_names_length)
        this->ik_link_names = (char**)realloc(this->ik_link_names, ik_link_names_lengthT * sizeof(char*));
      ik_link_names_length = ik_link_names_lengthT;
      for( uint32_t i = 0; i < ik_link_names_length; i++){
      uint32_t length_st_ik_link_names;
      arrToVar(length_st_ik_link_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_ik_link_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_ik_link_names-1]=0;
      this->st_ik_link_names = (char *)(inbuffer + offset-1);
      offset += length_st_ik_link_names;
        memcpy( &(this->ik_link_names[i]), &(this->st_ik_link_names), sizeof(char*));
      }
      uint32_t pose_stamped_vector_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pose_stamped_vector_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pose_stamped_vector_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pose_stamped_vector_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pose_stamped_vector_length);
      if(pose_stamped_vector_lengthT > pose_stamped_vector_length)
        this->pose_stamped_vector = (geometry_msgs::PoseStamped*)realloc(this->pose_stamped_vector, pose_stamped_vector_lengthT * sizeof(geometry_msgs::PoseStamped));
      pose_stamped_vector_length = pose_stamped_vector_lengthT;
      for( uint32_t i = 0; i < pose_stamped_vector_length; i++){
      offset += this->st_pose_stamped_vector.deserialize(inbuffer + offset);
        memcpy( &(this->pose_stamped_vector[i]), &(this->st_pose_stamped_vector), sizeof(geometry_msgs::PoseStamped));
      }
      this->timeout.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeout.sec);
      this->timeout.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeout.nsec);
      union {
        int32_t real;
        uint32_t base;
      } u_attempts;
      u_attempts.base = 0;
      u_attempts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_attempts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_attempts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_attempts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->attempts = u_attempts.real;
      offset += sizeof(this->attempts);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PositionIKRequest"; };
    const char * getMD5(){ return "9936dc239c90af180ec94a51596c96f2"; };

  };

}
#endif
