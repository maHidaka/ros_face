#ifndef _ROS_view_controller_msgs_CameraTrajectory_h
#define _ROS_view_controller_msgs_CameraTrajectory_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "view_controller_msgs/CameraMovement.h"

namespace view_controller_msgs
{

  class CameraTrajectory : public ros::Msg
  {
    public:
      uint32_t trajectory_length;
      typedef view_controller_msgs::CameraMovement _trajectory_type;
      _trajectory_type st_trajectory;
      _trajectory_type * trajectory;
      typedef const char* _target_frame_type;
      _target_frame_type target_frame;
      typedef bool _allow_free_yaw_axis_type;
      _allow_free_yaw_axis_type allow_free_yaw_axis;
      typedef uint8_t _mouse_interaction_mode_type;
      _mouse_interaction_mode_type mouse_interaction_mode;
      typedef bool _interaction_disabled_type;
      _interaction_disabled_type interaction_disabled;
      typedef bool _render_frame_by_frame_type;
      _render_frame_by_frame_type render_frame_by_frame;
      typedef int8_t _frames_per_second_type;
      _frames_per_second_type frames_per_second;
      enum { NO_CHANGE =  0  };
      enum { ORBIT =  1  };
      enum { FPS =  2  };

    CameraTrajectory():
      trajectory_length(0), trajectory(NULL),
      target_frame(""),
      allow_free_yaw_axis(0),
      mouse_interaction_mode(0),
      interaction_disabled(0),
      render_frame_by_frame(0),
      frames_per_second(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->trajectory_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trajectory_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trajectory_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trajectory_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trajectory_length);
      for( uint32_t i = 0; i < trajectory_length; i++){
      offset += this->trajectory[i].serialize(outbuffer + offset);
      }
      uint32_t length_target_frame = strlen(this->target_frame);
      varToArr(outbuffer + offset, length_target_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->target_frame, length_target_frame);
      offset += length_target_frame;
      union {
        bool real;
        uint8_t base;
      } u_allow_free_yaw_axis;
      u_allow_free_yaw_axis.real = this->allow_free_yaw_axis;
      *(outbuffer + offset + 0) = (u_allow_free_yaw_axis.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->allow_free_yaw_axis);
      *(outbuffer + offset + 0) = (this->mouse_interaction_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mouse_interaction_mode);
      union {
        bool real;
        uint8_t base;
      } u_interaction_disabled;
      u_interaction_disabled.real = this->interaction_disabled;
      *(outbuffer + offset + 0) = (u_interaction_disabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->interaction_disabled);
      union {
        bool real;
        uint8_t base;
      } u_render_frame_by_frame;
      u_render_frame_by_frame.real = this->render_frame_by_frame;
      *(outbuffer + offset + 0) = (u_render_frame_by_frame.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->render_frame_by_frame);
      union {
        int8_t real;
        uint8_t base;
      } u_frames_per_second;
      u_frames_per_second.real = this->frames_per_second;
      *(outbuffer + offset + 0) = (u_frames_per_second.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->frames_per_second);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t trajectory_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->trajectory_length);
      if(trajectory_lengthT > trajectory_length)
        this->trajectory = (view_controller_msgs::CameraMovement*)realloc(this->trajectory, trajectory_lengthT * sizeof(view_controller_msgs::CameraMovement));
      trajectory_length = trajectory_lengthT;
      for( uint32_t i = 0; i < trajectory_length; i++){
      offset += this->st_trajectory.deserialize(inbuffer + offset);
        memcpy( &(this->trajectory[i]), &(this->st_trajectory), sizeof(view_controller_msgs::CameraMovement));
      }
      uint32_t length_target_frame;
      arrToVar(length_target_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_frame-1]=0;
      this->target_frame = (char *)(inbuffer + offset-1);
      offset += length_target_frame;
      union {
        bool real;
        uint8_t base;
      } u_allow_free_yaw_axis;
      u_allow_free_yaw_axis.base = 0;
      u_allow_free_yaw_axis.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->allow_free_yaw_axis = u_allow_free_yaw_axis.real;
      offset += sizeof(this->allow_free_yaw_axis);
      this->mouse_interaction_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mouse_interaction_mode);
      union {
        bool real;
        uint8_t base;
      } u_interaction_disabled;
      u_interaction_disabled.base = 0;
      u_interaction_disabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->interaction_disabled = u_interaction_disabled.real;
      offset += sizeof(this->interaction_disabled);
      union {
        bool real;
        uint8_t base;
      } u_render_frame_by_frame;
      u_render_frame_by_frame.base = 0;
      u_render_frame_by_frame.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->render_frame_by_frame = u_render_frame_by_frame.real;
      offset += sizeof(this->render_frame_by_frame);
      union {
        int8_t real;
        uint8_t base;
      } u_frames_per_second;
      u_frames_per_second.base = 0;
      u_frames_per_second.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->frames_per_second = u_frames_per_second.real;
      offset += sizeof(this->frames_per_second);
     return offset;
    }

    const char * getType(){ return "view_controller_msgs/CameraTrajectory"; };
    const char * getMD5(){ return "c56d6e838f60da69466a74c60cf627d7"; };

  };

}
#endif
