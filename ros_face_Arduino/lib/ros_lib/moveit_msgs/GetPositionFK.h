#ifndef _ROS_SERVICE_GetPositionFK_h
#define _ROS_SERVICE_GetPositionFK_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/MoveItErrorCodes.h"
#include "geometry_msgs/PoseStamped.h"
#include "std_msgs/Header.h"
#include "moveit_msgs/RobotState.h"

namespace moveit_msgs
{

static const char GETPOSITIONFK[] = "moveit_msgs/GetPositionFK";

  class GetPositionFKRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t fk_link_names_length;
      typedef char* _fk_link_names_type;
      _fk_link_names_type st_fk_link_names;
      _fk_link_names_type * fk_link_names;
      typedef moveit_msgs::RobotState _robot_state_type;
      _robot_state_type robot_state;

    GetPositionFKRequest():
      header(),
      fk_link_names_length(0), fk_link_names(NULL),
      robot_state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->fk_link_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fk_link_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fk_link_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fk_link_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fk_link_names_length);
      for( uint32_t i = 0; i < fk_link_names_length; i++){
      uint32_t length_fk_link_namesi = strlen(this->fk_link_names[i]);
      varToArr(outbuffer + offset, length_fk_link_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->fk_link_names[i], length_fk_link_namesi);
      offset += length_fk_link_namesi;
      }
      offset += this->robot_state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t fk_link_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fk_link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fk_link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fk_link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fk_link_names_length);
      if(fk_link_names_lengthT > fk_link_names_length)
        this->fk_link_names = (char**)realloc(this->fk_link_names, fk_link_names_lengthT * sizeof(char*));
      fk_link_names_length = fk_link_names_lengthT;
      for( uint32_t i = 0; i < fk_link_names_length; i++){
      uint32_t length_st_fk_link_names;
      arrToVar(length_st_fk_link_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_fk_link_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_fk_link_names-1]=0;
      this->st_fk_link_names = (char *)(inbuffer + offset-1);
      offset += length_st_fk_link_names;
        memcpy( &(this->fk_link_names[i]), &(this->st_fk_link_names), sizeof(char*));
      }
      offset += this->robot_state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETPOSITIONFK; };
    const char * getMD5(){ return "1d1ed72044ed56f6246c31b522781797"; };

  };

  class GetPositionFKResponse : public ros::Msg
  {
    public:
      uint32_t pose_stamped_length;
      typedef geometry_msgs::PoseStamped _pose_stamped_type;
      _pose_stamped_type st_pose_stamped;
      _pose_stamped_type * pose_stamped;
      uint32_t fk_link_names_length;
      typedef char* _fk_link_names_type;
      _fk_link_names_type st_fk_link_names;
      _fk_link_names_type * fk_link_names;
      typedef moveit_msgs::MoveItErrorCodes _error_code_type;
      _error_code_type error_code;

    GetPositionFKResponse():
      pose_stamped_length(0), pose_stamped(NULL),
      fk_link_names_length(0), fk_link_names(NULL),
      error_code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pose_stamped_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pose_stamped_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pose_stamped_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pose_stamped_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pose_stamped_length);
      for( uint32_t i = 0; i < pose_stamped_length; i++){
      offset += this->pose_stamped[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->fk_link_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fk_link_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fk_link_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fk_link_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fk_link_names_length);
      for( uint32_t i = 0; i < fk_link_names_length; i++){
      uint32_t length_fk_link_namesi = strlen(this->fk_link_names[i]);
      varToArr(outbuffer + offset, length_fk_link_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->fk_link_names[i], length_fk_link_namesi);
      offset += length_fk_link_namesi;
      }
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t pose_stamped_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pose_stamped_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pose_stamped_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pose_stamped_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pose_stamped_length);
      if(pose_stamped_lengthT > pose_stamped_length)
        this->pose_stamped = (geometry_msgs::PoseStamped*)realloc(this->pose_stamped, pose_stamped_lengthT * sizeof(geometry_msgs::PoseStamped));
      pose_stamped_length = pose_stamped_lengthT;
      for( uint32_t i = 0; i < pose_stamped_length; i++){
      offset += this->st_pose_stamped.deserialize(inbuffer + offset);
        memcpy( &(this->pose_stamped[i]), &(this->st_pose_stamped), sizeof(geometry_msgs::PoseStamped));
      }
      uint32_t fk_link_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fk_link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fk_link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fk_link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fk_link_names_length);
      if(fk_link_names_lengthT > fk_link_names_length)
        this->fk_link_names = (char**)realloc(this->fk_link_names, fk_link_names_lengthT * sizeof(char*));
      fk_link_names_length = fk_link_names_lengthT;
      for( uint32_t i = 0; i < fk_link_names_length; i++){
      uint32_t length_st_fk_link_names;
      arrToVar(length_st_fk_link_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_fk_link_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_fk_link_names-1]=0;
      this->st_fk_link_names = (char *)(inbuffer + offset-1);
      offset += length_st_fk_link_names;
        memcpy( &(this->fk_link_names[i]), &(this->st_fk_link_names), sizeof(char*));
      }
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETPOSITIONFK; };
    const char * getMD5(){ return "297215cf4fdfe0008356995ae621dae6"; };

  };

  class GetPositionFK {
    public:
    typedef GetPositionFKRequest Request;
    typedef GetPositionFKResponse Response;
  };

}
#endif
