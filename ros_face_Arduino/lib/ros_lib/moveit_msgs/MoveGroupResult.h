#ifndef _ROS_moveit_msgs_MoveGroupResult_h
#define _ROS_moveit_msgs_MoveGroupResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/MoveItErrorCodes.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/RobotTrajectory.h"

namespace moveit_msgs
{

  class MoveGroupResult : public ros::Msg
  {
    public:
      typedef moveit_msgs::MoveItErrorCodes _error_code_type;
      _error_code_type error_code;
      typedef moveit_msgs::RobotState _trajectory_start_type;
      _trajectory_start_type trajectory_start;
      typedef moveit_msgs::RobotTrajectory _planned_trajectory_type;
      _planned_trajectory_type planned_trajectory;
      typedef moveit_msgs::RobotTrajectory _executed_trajectory_type;
      _executed_trajectory_type executed_trajectory;
      typedef float _planning_time_type;
      _planning_time_type planning_time;

    MoveGroupResult():
      error_code(),
      trajectory_start(),
      planned_trajectory(),
      executed_trajectory(),
      planning_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->error_code.serialize(outbuffer + offset);
      offset += this->trajectory_start.serialize(outbuffer + offset);
      offset += this->planned_trajectory.serialize(outbuffer + offset);
      offset += this->executed_trajectory.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->planning_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->error_code.deserialize(inbuffer + offset);
      offset += this->trajectory_start.deserialize(inbuffer + offset);
      offset += this->planned_trajectory.deserialize(inbuffer + offset);
      offset += this->executed_trajectory.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->planning_time));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/MoveGroupResult"; };
    const char * getMD5(){ return "34098589d402fee7ae9c3fd413e5a6c6"; };

  };

}
#endif
