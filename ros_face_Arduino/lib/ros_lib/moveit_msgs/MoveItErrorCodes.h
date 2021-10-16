#ifndef _ROS_moveit_msgs_MoveItErrorCodes_h
#define _ROS_moveit_msgs_MoveItErrorCodes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

  class MoveItErrorCodes : public ros::Msg
  {
    public:
      typedef int32_t _val_type;
      _val_type val;
      enum { SUCCESS = 1 };
      enum { FAILURE = 99999 };
      enum { PLANNING_FAILED = -1 };
      enum { INVALID_MOTION_PLAN = -2 };
      enum { MOTION_PLAN_INVALIDATED_BY_ENVIRONMENT_CHANGE = -3 };
      enum { CONTROL_FAILED = -4 };
      enum { UNABLE_TO_AQUIRE_SENSOR_DATA = -5 };
      enum { TIMED_OUT = -6 };
      enum { PREEMPTED = -7 };
      enum { START_STATE_IN_COLLISION = -10 };
      enum { START_STATE_VIOLATES_PATH_CONSTRAINTS = -11 };
      enum { GOAL_IN_COLLISION = -12 };
      enum { GOAL_VIOLATES_PATH_CONSTRAINTS = -13 };
      enum { GOAL_CONSTRAINTS_VIOLATED = -14 };
      enum { INVALID_GROUP_NAME = -15 };
      enum { INVALID_GOAL_CONSTRAINTS = -16 };
      enum { INVALID_ROBOT_STATE = -17 };
      enum { INVALID_LINK_NAME = -18 };
      enum { INVALID_OBJECT_NAME = -19 };
      enum { FRAME_TRANSFORM_FAILURE = -21 };
      enum { COLLISION_CHECKING_UNAVAILABLE = -22 };
      enum { ROBOT_STATE_STALE = -23 };
      enum { SENSOR_INFO_STALE = -24 };
      enum { NO_IK_SOLUTION = -31 };

    MoveItErrorCodes():
      val(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_val;
      u_val.real = this->val;
      *(outbuffer + offset + 0) = (u_val.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_val.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_val.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_val.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->val);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_val;
      u_val.base = 0;
      u_val.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_val.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_val.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_val.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->val = u_val.real;
      offset += sizeof(this->val);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/MoveItErrorCodes"; };
    const char * getMD5(){ return "aa336b18d80531f66439810112c0a43e"; };

  };

}
#endif
