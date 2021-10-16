#ifndef _ROS_moveit_msgs_DisplayTrajectory_h
#define _ROS_moveit_msgs_DisplayTrajectory_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/RobotTrajectory.h"
#include "moveit_msgs/RobotState.h"

namespace moveit_msgs
{

  class DisplayTrajectory : public ros::Msg
  {
    public:
      typedef const char* _model_id_type;
      _model_id_type model_id;
      uint32_t trajectory_length;
      typedef moveit_msgs::RobotTrajectory _trajectory_type;
      _trajectory_type st_trajectory;
      _trajectory_type * trajectory;
      typedef moveit_msgs::RobotState _trajectory_start_type;
      _trajectory_start_type trajectory_start;

    DisplayTrajectory():
      model_id(""),
      trajectory_length(0), trajectory(NULL),
      trajectory_start()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_model_id = strlen(this->model_id);
      varToArr(outbuffer + offset, length_model_id);
      offset += 4;
      memcpy(outbuffer + offset, this->model_id, length_model_id);
      offset += length_model_id;
      *(outbuffer + offset + 0) = (this->trajectory_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trajectory_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trajectory_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trajectory_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trajectory_length);
      for( uint32_t i = 0; i < trajectory_length; i++){
      offset += this->trajectory[i].serialize(outbuffer + offset);
      }
      offset += this->trajectory_start.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_model_id;
      arrToVar(length_model_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model_id-1]=0;
      this->model_id = (char *)(inbuffer + offset-1);
      offset += length_model_id;
      uint32_t trajectory_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->trajectory_length);
      if(trajectory_lengthT > trajectory_length)
        this->trajectory = (moveit_msgs::RobotTrajectory*)realloc(this->trajectory, trajectory_lengthT * sizeof(moveit_msgs::RobotTrajectory));
      trajectory_length = trajectory_lengthT;
      for( uint32_t i = 0; i < trajectory_length; i++){
      offset += this->st_trajectory.deserialize(inbuffer + offset);
        memcpy( &(this->trajectory[i]), &(this->st_trajectory), sizeof(moveit_msgs::RobotTrajectory));
      }
      offset += this->trajectory_start.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/DisplayTrajectory"; };
    const char * getMD5(){ return "c3c039261ab9e8a11457dac56b6316c8"; };

  };

}
#endif
