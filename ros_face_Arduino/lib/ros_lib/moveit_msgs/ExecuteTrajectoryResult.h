#ifndef _ROS_moveit_msgs_ExecuteTrajectoryResult_h
#define _ROS_moveit_msgs_ExecuteTrajectoryResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/MoveItErrorCodes.h"

namespace moveit_msgs
{

  class ExecuteTrajectoryResult : public ros::Msg
  {
    public:
      typedef moveit_msgs::MoveItErrorCodes _error_code_type;
      _error_code_type error_code;

    ExecuteTrajectoryResult():
      error_code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/ExecuteTrajectoryResult"; };
    const char * getMD5(){ return "1f7ab918f5d0c5312f25263d3d688122"; };

  };

}
#endif
