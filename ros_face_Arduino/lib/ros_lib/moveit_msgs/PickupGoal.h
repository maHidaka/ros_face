#ifndef _ROS_moveit_msgs_PickupGoal_h
#define _ROS_moveit_msgs_PickupGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/Grasp.h"
#include "moveit_msgs/Constraints.h"
#include "moveit_msgs/PlanningOptions.h"

namespace moveit_msgs
{

  class PickupGoal : public ros::Msg
  {
    public:
      typedef const char* _target_name_type;
      _target_name_type target_name;
      typedef const char* _group_name_type;
      _group_name_type group_name;
      typedef const char* _end_effector_type;
      _end_effector_type end_effector;
      uint32_t possible_grasps_length;
      typedef moveit_msgs::Grasp _possible_grasps_type;
      _possible_grasps_type st_possible_grasps;
      _possible_grasps_type * possible_grasps;
      typedef const char* _support_surface_name_type;
      _support_surface_name_type support_surface_name;
      typedef bool _allow_gripper_support_collision_type;
      _allow_gripper_support_collision_type allow_gripper_support_collision;
      uint32_t attached_object_touch_links_length;
      typedef char* _attached_object_touch_links_type;
      _attached_object_touch_links_type st_attached_object_touch_links;
      _attached_object_touch_links_type * attached_object_touch_links;
      typedef bool _minimize_object_distance_type;
      _minimize_object_distance_type minimize_object_distance;
      typedef moveit_msgs::Constraints _path_constraints_type;
      _path_constraints_type path_constraints;
      typedef const char* _planner_id_type;
      _planner_id_type planner_id;
      uint32_t allowed_touch_objects_length;
      typedef char* _allowed_touch_objects_type;
      _allowed_touch_objects_type st_allowed_touch_objects;
      _allowed_touch_objects_type * allowed_touch_objects;
      typedef float _allowed_planning_time_type;
      _allowed_planning_time_type allowed_planning_time;
      typedef moveit_msgs::PlanningOptions _planning_options_type;
      _planning_options_type planning_options;

    PickupGoal():
      target_name(""),
      group_name(""),
      end_effector(""),
      possible_grasps_length(0), possible_grasps(NULL),
      support_surface_name(""),
      allow_gripper_support_collision(0),
      attached_object_touch_links_length(0), attached_object_touch_links(NULL),
      minimize_object_distance(0),
      path_constraints(),
      planner_id(""),
      allowed_touch_objects_length(0), allowed_touch_objects(NULL),
      allowed_planning_time(0),
      planning_options()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_target_name = strlen(this->target_name);
      varToArr(outbuffer + offset, length_target_name);
      offset += 4;
      memcpy(outbuffer + offset, this->target_name, length_target_name);
      offset += length_target_name;
      uint32_t length_group_name = strlen(this->group_name);
      varToArr(outbuffer + offset, length_group_name);
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      uint32_t length_end_effector = strlen(this->end_effector);
      varToArr(outbuffer + offset, length_end_effector);
      offset += 4;
      memcpy(outbuffer + offset, this->end_effector, length_end_effector);
      offset += length_end_effector;
      *(outbuffer + offset + 0) = (this->possible_grasps_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->possible_grasps_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->possible_grasps_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->possible_grasps_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->possible_grasps_length);
      for( uint32_t i = 0; i < possible_grasps_length; i++){
      offset += this->possible_grasps[i].serialize(outbuffer + offset);
      }
      uint32_t length_support_surface_name = strlen(this->support_surface_name);
      varToArr(outbuffer + offset, length_support_surface_name);
      offset += 4;
      memcpy(outbuffer + offset, this->support_surface_name, length_support_surface_name);
      offset += length_support_surface_name;
      union {
        bool real;
        uint8_t base;
      } u_allow_gripper_support_collision;
      u_allow_gripper_support_collision.real = this->allow_gripper_support_collision;
      *(outbuffer + offset + 0) = (u_allow_gripper_support_collision.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->allow_gripper_support_collision);
      *(outbuffer + offset + 0) = (this->attached_object_touch_links_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->attached_object_touch_links_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->attached_object_touch_links_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->attached_object_touch_links_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->attached_object_touch_links_length);
      for( uint32_t i = 0; i < attached_object_touch_links_length; i++){
      uint32_t length_attached_object_touch_linksi = strlen(this->attached_object_touch_links[i]);
      varToArr(outbuffer + offset, length_attached_object_touch_linksi);
      offset += 4;
      memcpy(outbuffer + offset, this->attached_object_touch_links[i], length_attached_object_touch_linksi);
      offset += length_attached_object_touch_linksi;
      }
      union {
        bool real;
        uint8_t base;
      } u_minimize_object_distance;
      u_minimize_object_distance.real = this->minimize_object_distance;
      *(outbuffer + offset + 0) = (u_minimize_object_distance.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->minimize_object_distance);
      offset += this->path_constraints.serialize(outbuffer + offset);
      uint32_t length_planner_id = strlen(this->planner_id);
      varToArr(outbuffer + offset, length_planner_id);
      offset += 4;
      memcpy(outbuffer + offset, this->planner_id, length_planner_id);
      offset += length_planner_id;
      *(outbuffer + offset + 0) = (this->allowed_touch_objects_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->allowed_touch_objects_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->allowed_touch_objects_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->allowed_touch_objects_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->allowed_touch_objects_length);
      for( uint32_t i = 0; i < allowed_touch_objects_length; i++){
      uint32_t length_allowed_touch_objectsi = strlen(this->allowed_touch_objects[i]);
      varToArr(outbuffer + offset, length_allowed_touch_objectsi);
      offset += 4;
      memcpy(outbuffer + offset, this->allowed_touch_objects[i], length_allowed_touch_objectsi);
      offset += length_allowed_touch_objectsi;
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->allowed_planning_time);
      offset += this->planning_options.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_target_name;
      arrToVar(length_target_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_name-1]=0;
      this->target_name = (char *)(inbuffer + offset-1);
      offset += length_target_name;
      uint32_t length_group_name;
      arrToVar(length_group_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
      uint32_t length_end_effector;
      arrToVar(length_end_effector, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_end_effector; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_end_effector-1]=0;
      this->end_effector = (char *)(inbuffer + offset-1);
      offset += length_end_effector;
      uint32_t possible_grasps_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      possible_grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      possible_grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      possible_grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->possible_grasps_length);
      if(possible_grasps_lengthT > possible_grasps_length)
        this->possible_grasps = (moveit_msgs::Grasp*)realloc(this->possible_grasps, possible_grasps_lengthT * sizeof(moveit_msgs::Grasp));
      possible_grasps_length = possible_grasps_lengthT;
      for( uint32_t i = 0; i < possible_grasps_length; i++){
      offset += this->st_possible_grasps.deserialize(inbuffer + offset);
        memcpy( &(this->possible_grasps[i]), &(this->st_possible_grasps), sizeof(moveit_msgs::Grasp));
      }
      uint32_t length_support_surface_name;
      arrToVar(length_support_surface_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_support_surface_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_support_surface_name-1]=0;
      this->support_surface_name = (char *)(inbuffer + offset-1);
      offset += length_support_surface_name;
      union {
        bool real;
        uint8_t base;
      } u_allow_gripper_support_collision;
      u_allow_gripper_support_collision.base = 0;
      u_allow_gripper_support_collision.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->allow_gripper_support_collision = u_allow_gripper_support_collision.real;
      offset += sizeof(this->allow_gripper_support_collision);
      uint32_t attached_object_touch_links_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      attached_object_touch_links_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      attached_object_touch_links_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      attached_object_touch_links_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->attached_object_touch_links_length);
      if(attached_object_touch_links_lengthT > attached_object_touch_links_length)
        this->attached_object_touch_links = (char**)realloc(this->attached_object_touch_links, attached_object_touch_links_lengthT * sizeof(char*));
      attached_object_touch_links_length = attached_object_touch_links_lengthT;
      for( uint32_t i = 0; i < attached_object_touch_links_length; i++){
      uint32_t length_st_attached_object_touch_links;
      arrToVar(length_st_attached_object_touch_links, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_attached_object_touch_links; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_attached_object_touch_links-1]=0;
      this->st_attached_object_touch_links = (char *)(inbuffer + offset-1);
      offset += length_st_attached_object_touch_links;
        memcpy( &(this->attached_object_touch_links[i]), &(this->st_attached_object_touch_links), sizeof(char*));
      }
      union {
        bool real;
        uint8_t base;
      } u_minimize_object_distance;
      u_minimize_object_distance.base = 0;
      u_minimize_object_distance.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->minimize_object_distance = u_minimize_object_distance.real;
      offset += sizeof(this->minimize_object_distance);
      offset += this->path_constraints.deserialize(inbuffer + offset);
      uint32_t length_planner_id;
      arrToVar(length_planner_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_planner_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_planner_id-1]=0;
      this->planner_id = (char *)(inbuffer + offset-1);
      offset += length_planner_id;
      uint32_t allowed_touch_objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      allowed_touch_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      allowed_touch_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      allowed_touch_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->allowed_touch_objects_length);
      if(allowed_touch_objects_lengthT > allowed_touch_objects_length)
        this->allowed_touch_objects = (char**)realloc(this->allowed_touch_objects, allowed_touch_objects_lengthT * sizeof(char*));
      allowed_touch_objects_length = allowed_touch_objects_lengthT;
      for( uint32_t i = 0; i < allowed_touch_objects_length; i++){
      uint32_t length_st_allowed_touch_objects;
      arrToVar(length_st_allowed_touch_objects, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_allowed_touch_objects; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_allowed_touch_objects-1]=0;
      this->st_allowed_touch_objects = (char *)(inbuffer + offset-1);
      offset += length_st_allowed_touch_objects;
        memcpy( &(this->allowed_touch_objects[i]), &(this->st_allowed_touch_objects), sizeof(char*));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->allowed_planning_time));
      offset += this->planning_options.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PickupGoal"; };
    const char * getMD5(){ return "458c6ab3761d73e99b070063f7b74c2a"; };

  };

}
#endif
