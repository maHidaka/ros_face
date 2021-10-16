#ifndef _ROS_moveit_msgs_PlanningScene_h
#define _ROS_moveit_msgs_PlanningScene_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/RobotState.h"
#include "geometry_msgs/TransformStamped.h"
#include "moveit_msgs/AllowedCollisionMatrix.h"
#include "moveit_msgs/LinkPadding.h"
#include "moveit_msgs/LinkScale.h"
#include "moveit_msgs/ObjectColor.h"
#include "moveit_msgs/PlanningSceneWorld.h"

namespace moveit_msgs
{

  class PlanningScene : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef moveit_msgs::RobotState _robot_state_type;
      _robot_state_type robot_state;
      typedef const char* _robot_model_name_type;
      _robot_model_name_type robot_model_name;
      uint32_t fixed_frame_transforms_length;
      typedef geometry_msgs::TransformStamped _fixed_frame_transforms_type;
      _fixed_frame_transforms_type st_fixed_frame_transforms;
      _fixed_frame_transforms_type * fixed_frame_transforms;
      typedef moveit_msgs::AllowedCollisionMatrix _allowed_collision_matrix_type;
      _allowed_collision_matrix_type allowed_collision_matrix;
      uint32_t link_padding_length;
      typedef moveit_msgs::LinkPadding _link_padding_type;
      _link_padding_type st_link_padding;
      _link_padding_type * link_padding;
      uint32_t link_scale_length;
      typedef moveit_msgs::LinkScale _link_scale_type;
      _link_scale_type st_link_scale;
      _link_scale_type * link_scale;
      uint32_t object_colors_length;
      typedef moveit_msgs::ObjectColor _object_colors_type;
      _object_colors_type st_object_colors;
      _object_colors_type * object_colors;
      typedef moveit_msgs::PlanningSceneWorld _world_type;
      _world_type world;
      typedef bool _is_diff_type;
      _is_diff_type is_diff;

    PlanningScene():
      name(""),
      robot_state(),
      robot_model_name(""),
      fixed_frame_transforms_length(0), fixed_frame_transforms(NULL),
      allowed_collision_matrix(),
      link_padding_length(0), link_padding(NULL),
      link_scale_length(0), link_scale(NULL),
      object_colors_length(0), object_colors(NULL),
      world(),
      is_diff(0)
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
      offset += this->robot_state.serialize(outbuffer + offset);
      uint32_t length_robot_model_name = strlen(this->robot_model_name);
      varToArr(outbuffer + offset, length_robot_model_name);
      offset += 4;
      memcpy(outbuffer + offset, this->robot_model_name, length_robot_model_name);
      offset += length_robot_model_name;
      *(outbuffer + offset + 0) = (this->fixed_frame_transforms_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fixed_frame_transforms_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fixed_frame_transforms_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fixed_frame_transforms_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fixed_frame_transforms_length);
      for( uint32_t i = 0; i < fixed_frame_transforms_length; i++){
      offset += this->fixed_frame_transforms[i].serialize(outbuffer + offset);
      }
      offset += this->allowed_collision_matrix.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->link_padding_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->link_padding_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->link_padding_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->link_padding_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->link_padding_length);
      for( uint32_t i = 0; i < link_padding_length; i++){
      offset += this->link_padding[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->link_scale_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->link_scale_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->link_scale_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->link_scale_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->link_scale_length);
      for( uint32_t i = 0; i < link_scale_length; i++){
      offset += this->link_scale[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->object_colors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->object_colors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->object_colors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->object_colors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->object_colors_length);
      for( uint32_t i = 0; i < object_colors_length; i++){
      offset += this->object_colors[i].serialize(outbuffer + offset);
      }
      offset += this->world.serialize(outbuffer + offset);
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
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += this->robot_state.deserialize(inbuffer + offset);
      uint32_t length_robot_model_name;
      arrToVar(length_robot_model_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot_model_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot_model_name-1]=0;
      this->robot_model_name = (char *)(inbuffer + offset-1);
      offset += length_robot_model_name;
      uint32_t fixed_frame_transforms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fixed_frame_transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fixed_frame_transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fixed_frame_transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fixed_frame_transforms_length);
      if(fixed_frame_transforms_lengthT > fixed_frame_transforms_length)
        this->fixed_frame_transforms = (geometry_msgs::TransformStamped*)realloc(this->fixed_frame_transforms, fixed_frame_transforms_lengthT * sizeof(geometry_msgs::TransformStamped));
      fixed_frame_transforms_length = fixed_frame_transforms_lengthT;
      for( uint32_t i = 0; i < fixed_frame_transforms_length; i++){
      offset += this->st_fixed_frame_transforms.deserialize(inbuffer + offset);
        memcpy( &(this->fixed_frame_transforms[i]), &(this->st_fixed_frame_transforms), sizeof(geometry_msgs::TransformStamped));
      }
      offset += this->allowed_collision_matrix.deserialize(inbuffer + offset);
      uint32_t link_padding_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      link_padding_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      link_padding_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      link_padding_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->link_padding_length);
      if(link_padding_lengthT > link_padding_length)
        this->link_padding = (moveit_msgs::LinkPadding*)realloc(this->link_padding, link_padding_lengthT * sizeof(moveit_msgs::LinkPadding));
      link_padding_length = link_padding_lengthT;
      for( uint32_t i = 0; i < link_padding_length; i++){
      offset += this->st_link_padding.deserialize(inbuffer + offset);
        memcpy( &(this->link_padding[i]), &(this->st_link_padding), sizeof(moveit_msgs::LinkPadding));
      }
      uint32_t link_scale_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      link_scale_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      link_scale_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      link_scale_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->link_scale_length);
      if(link_scale_lengthT > link_scale_length)
        this->link_scale = (moveit_msgs::LinkScale*)realloc(this->link_scale, link_scale_lengthT * sizeof(moveit_msgs::LinkScale));
      link_scale_length = link_scale_lengthT;
      for( uint32_t i = 0; i < link_scale_length; i++){
      offset += this->st_link_scale.deserialize(inbuffer + offset);
        memcpy( &(this->link_scale[i]), &(this->st_link_scale), sizeof(moveit_msgs::LinkScale));
      }
      uint32_t object_colors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      object_colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      object_colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      object_colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->object_colors_length);
      if(object_colors_lengthT > object_colors_length)
        this->object_colors = (moveit_msgs::ObjectColor*)realloc(this->object_colors, object_colors_lengthT * sizeof(moveit_msgs::ObjectColor));
      object_colors_length = object_colors_lengthT;
      for( uint32_t i = 0; i < object_colors_length; i++){
      offset += this->st_object_colors.deserialize(inbuffer + offset);
        memcpy( &(this->object_colors[i]), &(this->st_object_colors), sizeof(moveit_msgs::ObjectColor));
      }
      offset += this->world.deserialize(inbuffer + offset);
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

    const char * getType(){ return "moveit_msgs/PlanningScene"; };
    const char * getMD5(){ return "89aac6d20db967ba716cba5a86b1b9d5"; };

  };

}
#endif
