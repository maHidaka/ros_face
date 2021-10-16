#ifndef _ROS_moveit_msgs_MotionPlanResponse_h
#define _ROS_moveit_msgs_MotionPlanResponse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/RobotTrajectory.h"
#include "moveit_msgs/MoveItErrorCodes.h"

namespace moveit_msgs
{

  class MotionPlanResponse : public ros::Msg
  {
    public:
      typedef moveit_msgs::RobotState _trajectory_start_type;
      _trajectory_start_type trajectory_start;
      typedef const char* _group_name_type;
      _group_name_type group_name;
      typedef moveit_msgs::RobotTrajectory _trajectory_type;
      _trajectory_type trajectory;
      typedef float _planning_time_type;
      _planning_time_type planning_time;
      typedef moveit_msgs::MoveItErrorCodes _error_code_type;
      _error_code_type error_code;

    MotionPlanResponse():
      trajectory_start(),
      group_name(""),
      trajectory(),
      planning_time(0),
      error_code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory_start.serialize(outbuffer + offset);
      uint32_t length_group_name = strlen(this->group_name);
      varToArr(outbuffer + offset, length_group_name);
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      offset += this->trajectory.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->planning_time);
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory_start.deserialize(inbuffer + offset);
      uint32_t length_group_name;
      arrToVar(length_group_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
      offset += this->trajectory.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->planning_time));
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/MotionPlanResponse"; };
    const char * getMD5(){ return "e493d20ab41424c48f671e152c70fc74"; };

  };

}
#endif
