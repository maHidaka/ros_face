#ifndef _ROS_moveit_msgs_MotionSequenceResponse_h
#define _ROS_moveit_msgs_MotionSequenceResponse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/MoveItErrorCodes.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/RobotTrajectory.h"

namespace moveit_msgs
{

  class MotionSequenceResponse : public ros::Msg
  {
    public:
      typedef moveit_msgs::MoveItErrorCodes _error_code_type;
      _error_code_type error_code;
      typedef moveit_msgs::RobotState _sequence_start_type;
      _sequence_start_type sequence_start;
      uint32_t planned_trajectories_length;
      typedef moveit_msgs::RobotTrajectory _planned_trajectories_type;
      _planned_trajectories_type st_planned_trajectories;
      _planned_trajectories_type * planned_trajectories;
      typedef float _planning_time_type;
      _planning_time_type planning_time;

    MotionSequenceResponse():
      error_code(),
      sequence_start(),
      planned_trajectories_length(0), planned_trajectories(NULL),
      planning_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->error_code.serialize(outbuffer + offset);
      offset += this->sequence_start.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->planned_trajectories_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->planned_trajectories_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->planned_trajectories_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->planned_trajectories_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->planned_trajectories_length);
      for( uint32_t i = 0; i < planned_trajectories_length; i++){
      offset += this->planned_trajectories[i].serialize(outbuffer + offset);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->planning_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->error_code.deserialize(inbuffer + offset);
      offset += this->sequence_start.deserialize(inbuffer + offset);
      uint32_t planned_trajectories_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      planned_trajectories_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      planned_trajectories_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      planned_trajectories_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->planned_trajectories_length);
      if(planned_trajectories_lengthT > planned_trajectories_length)
        this->planned_trajectories = (moveit_msgs::RobotTrajectory*)realloc(this->planned_trajectories, planned_trajectories_lengthT * sizeof(moveit_msgs::RobotTrajectory));
      planned_trajectories_length = planned_trajectories_lengthT;
      for( uint32_t i = 0; i < planned_trajectories_length; i++){
      offset += this->st_planned_trajectories.deserialize(inbuffer + offset);
        memcpy( &(this->planned_trajectories[i]), &(this->st_planned_trajectories), sizeof(moveit_msgs::RobotTrajectory));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->planning_time));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/MotionSequenceResponse"; };
    const char * getMD5(){ return "3b9d4e8079db4576e4829d30617a3d1d"; };

  };

}
#endif
