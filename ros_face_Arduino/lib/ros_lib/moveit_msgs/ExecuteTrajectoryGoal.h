#ifndef _ROS_moveit_msgs_ExecuteTrajectoryGoal_h
#define _ROS_moveit_msgs_ExecuteTrajectoryGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/RobotTrajectory.h"

namespace moveit_msgs
{

  class ExecuteTrajectoryGoal : public ros::Msg
  {
    public:
      typedef moveit_msgs::RobotTrajectory _trajectory_type;
      _trajectory_type trajectory;

    ExecuteTrajectoryGoal():
      trajectory()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/ExecuteTrajectoryGoal"; };
    const char * getMD5(){ return "054c09e62210d7faad2f9fffdad07b57"; };

  };

}
#endif
