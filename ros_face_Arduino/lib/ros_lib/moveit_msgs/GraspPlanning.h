#ifndef _ROS_SERVICE_GraspPlanning_h
#define _ROS_SERVICE_GraspPlanning_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/Grasp.h"
#include "moveit_msgs/MoveItErrorCodes.h"
#include "moveit_msgs/CollisionObject.h"

namespace moveit_msgs
{

static const char GRASPPLANNING[] = "moveit_msgs/GraspPlanning";

  class GraspPlanningRequest : public ros::Msg
  {
    public:
      typedef const char* _group_name_type;
      _group_name_type group_name;
      typedef moveit_msgs::CollisionObject _target_type;
      _target_type target;
      uint32_t support_surfaces_length;
      typedef char* _support_surfaces_type;
      _support_surfaces_type st_support_surfaces;
      _support_surfaces_type * support_surfaces;
      uint32_t candidate_grasps_length;
      typedef moveit_msgs::Grasp _candidate_grasps_type;
      _candidate_grasps_type st_candidate_grasps;
      _candidate_grasps_type * candidate_grasps;
      uint32_t movable_obstacles_length;
      typedef moveit_msgs::CollisionObject _movable_obstacles_type;
      _movable_obstacles_type st_movable_obstacles;
      _movable_obstacles_type * movable_obstacles;

    GraspPlanningRequest():
      group_name(""),
      target(),
      support_surfaces_length(0), support_surfaces(NULL),
      candidate_grasps_length(0), candidate_grasps(NULL),
      movable_obstacles_length(0), movable_obstacles(NULL)
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
      offset += this->target.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->support_surfaces_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->support_surfaces_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->support_surfaces_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->support_surfaces_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->support_surfaces_length);
      for( uint32_t i = 0; i < support_surfaces_length; i++){
      uint32_t length_support_surfacesi = strlen(this->support_surfaces[i]);
      varToArr(outbuffer + offset, length_support_surfacesi);
      offset += 4;
      memcpy(outbuffer + offset, this->support_surfaces[i], length_support_surfacesi);
      offset += length_support_surfacesi;
      }
      *(outbuffer + offset + 0) = (this->candidate_grasps_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->candidate_grasps_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->candidate_grasps_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->candidate_grasps_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->candidate_grasps_length);
      for( uint32_t i = 0; i < candidate_grasps_length; i++){
      offset += this->candidate_grasps[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->movable_obstacles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->movable_obstacles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->movable_obstacles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->movable_obstacles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->movable_obstacles_length);
      for( uint32_t i = 0; i < movable_obstacles_length; i++){
      offset += this->movable_obstacles[i].serialize(outbuffer + offset);
      }
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
      offset += this->target.deserialize(inbuffer + offset);
      uint32_t support_surfaces_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      support_surfaces_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      support_surfaces_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      support_surfaces_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->support_surfaces_length);
      if(support_surfaces_lengthT > support_surfaces_length)
        this->support_surfaces = (char**)realloc(this->support_surfaces, support_surfaces_lengthT * sizeof(char*));
      support_surfaces_length = support_surfaces_lengthT;
      for( uint32_t i = 0; i < support_surfaces_length; i++){
      uint32_t length_st_support_surfaces;
      arrToVar(length_st_support_surfaces, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_support_surfaces; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_support_surfaces-1]=0;
      this->st_support_surfaces = (char *)(inbuffer + offset-1);
      offset += length_st_support_surfaces;
        memcpy( &(this->support_surfaces[i]), &(this->st_support_surfaces), sizeof(char*));
      }
      uint32_t candidate_grasps_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      candidate_grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      candidate_grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      candidate_grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->candidate_grasps_length);
      if(candidate_grasps_lengthT > candidate_grasps_length)
        this->candidate_grasps = (moveit_msgs::Grasp*)realloc(this->candidate_grasps, candidate_grasps_lengthT * sizeof(moveit_msgs::Grasp));
      candidate_grasps_length = candidate_grasps_lengthT;
      for( uint32_t i = 0; i < candidate_grasps_length; i++){
      offset += this->st_candidate_grasps.deserialize(inbuffer + offset);
        memcpy( &(this->candidate_grasps[i]), &(this->st_candidate_grasps), sizeof(moveit_msgs::Grasp));
      }
      uint32_t movable_obstacles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      movable_obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      movable_obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      movable_obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->movable_obstacles_length);
      if(movable_obstacles_lengthT > movable_obstacles_length)
        this->movable_obstacles = (moveit_msgs::CollisionObject*)realloc(this->movable_obstacles, movable_obstacles_lengthT * sizeof(moveit_msgs::CollisionObject));
      movable_obstacles_length = movable_obstacles_lengthT;
      for( uint32_t i = 0; i < movable_obstacles_length; i++){
      offset += this->st_movable_obstacles.deserialize(inbuffer + offset);
        memcpy( &(this->movable_obstacles[i]), &(this->st_movable_obstacles), sizeof(moveit_msgs::CollisionObject));
      }
     return offset;
    }

    const char * getType(){ return GRASPPLANNING; };
    const char * getMD5(){ return "c234e9a645708cc86b57a43999746ae6"; };

  };

  class GraspPlanningResponse : public ros::Msg
  {
    public:
      uint32_t grasps_length;
      typedef moveit_msgs::Grasp _grasps_type;
      _grasps_type st_grasps;
      _grasps_type * grasps;
      typedef moveit_msgs::MoveItErrorCodes _error_code_type;
      _error_code_type error_code;

    GraspPlanningResponse():
      grasps_length(0), grasps(NULL),
      error_code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->grasps_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->grasps_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->grasps_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->grasps_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->grasps_length);
      for( uint32_t i = 0; i < grasps_length; i++){
      offset += this->grasps[i].serialize(outbuffer + offset);
      }
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t grasps_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->grasps_length);
      if(grasps_lengthT > grasps_length)
        this->grasps = (moveit_msgs::Grasp*)realloc(this->grasps, grasps_lengthT * sizeof(moveit_msgs::Grasp));
      grasps_length = grasps_lengthT;
      for( uint32_t i = 0; i < grasps_length; i++){
      offset += this->st_grasps.deserialize(inbuffer + offset);
        memcpy( &(this->grasps[i]), &(this->st_grasps), sizeof(moveit_msgs::Grasp));
      }
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GRASPPLANNING; };
    const char * getMD5(){ return "bb8169d403b6e9f96bf61e22a50d13ae"; };

  };

  class GraspPlanning {
    public:
    typedef GraspPlanningRequest Request;
    typedef GraspPlanningResponse Response;
  };

}
#endif
