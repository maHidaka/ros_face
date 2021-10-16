#ifndef _ROS_moveit_msgs_MoveGroupSequenceGoal_h
#define _ROS_moveit_msgs_MoveGroupSequenceGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/MotionSequenceRequest.h"
#include "moveit_msgs/PlanningOptions.h"

namespace moveit_msgs
{

  class MoveGroupSequenceGoal : public ros::Msg
  {
    public:
      typedef moveit_msgs::MotionSequenceRequest _request_type;
      _request_type request;
      typedef moveit_msgs::PlanningOptions _planning_options_type;
      _planning_options_type planning_options;

    MoveGroupSequenceGoal():
      request(),
      planning_options()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->request.serialize(outbuffer + offset);
      offset += this->planning_options.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->request.deserialize(inbuffer + offset);
      offset += this->planning_options.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/MoveGroupSequenceGoal"; };
    const char * getMD5(){ return "12fc6281edcaf031de4783a58087ebf1"; };

  };

}
#endif
