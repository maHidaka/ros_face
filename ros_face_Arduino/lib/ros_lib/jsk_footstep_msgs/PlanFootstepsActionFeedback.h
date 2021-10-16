#ifndef _ROS_jsk_footstep_msgs_PlanFootstepsActionFeedback_h
#define _ROS_jsk_footstep_msgs_PlanFootstepsActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "jsk_footstep_msgs/PlanFootstepsFeedback.h"

namespace jsk_footstep_msgs
{

  class PlanFootstepsActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef jsk_footstep_msgs::PlanFootstepsFeedback _feedback_type;
      _feedback_type feedback;

    PlanFootstepsActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_footstep_msgs/PlanFootstepsActionFeedback"; };
    const char * getMD5(){ return "c827ac0ba59dca5c1bf7b9bb97d2a1ae"; };

  };

}
#endif
