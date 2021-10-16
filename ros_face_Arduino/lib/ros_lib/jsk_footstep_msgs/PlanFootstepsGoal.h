#ifndef _ROS_jsk_footstep_msgs_PlanFootstepsGoal_h
#define _ROS_jsk_footstep_msgs_PlanFootstepsGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_footstep_msgs/FootstepArray.h"
#include "ros/duration.h"

namespace jsk_footstep_msgs
{

  class PlanFootstepsGoal : public ros::Msg
  {
    public:
      typedef jsk_footstep_msgs::FootstepArray _goal_footstep_type;
      _goal_footstep_type goal_footstep;
      typedef jsk_footstep_msgs::FootstepArray _initial_footstep_type;
      _initial_footstep_type initial_footstep;
      typedef ros::Duration _timeout_type;
      _timeout_type timeout;

    PlanFootstepsGoal():
      goal_footstep(),
      initial_footstep(),
      timeout()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->goal_footstep.serialize(outbuffer + offset);
      offset += this->initial_footstep.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->timeout.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeout.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeout.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeout.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout.sec);
      *(outbuffer + offset + 0) = (this->timeout.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeout.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeout.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeout.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->goal_footstep.deserialize(inbuffer + offset);
      offset += this->initial_footstep.deserialize(inbuffer + offset);
      this->timeout.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeout.sec);
      this->timeout.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeout.nsec);
     return offset;
    }

    const char * getType(){ return "jsk_footstep_msgs/PlanFootstepsGoal"; };
    const char * getMD5(){ return "68011023a311776030c53b8ca437fae1"; };

  };

}
#endif
