#ifndef _ROS_moveit_msgs_PlanningOptions_h
#define _ROS_moveit_msgs_PlanningOptions_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/PlanningScene.h"

namespace moveit_msgs
{

  class PlanningOptions : public ros::Msg
  {
    public:
      typedef moveit_msgs::PlanningScene _planning_scene_diff_type;
      _planning_scene_diff_type planning_scene_diff;
      typedef bool _plan_only_type;
      _plan_only_type plan_only;
      typedef bool _look_around_type;
      _look_around_type look_around;
      typedef int32_t _look_around_attempts_type;
      _look_around_attempts_type look_around_attempts;
      typedef float _max_safe_execution_cost_type;
      _max_safe_execution_cost_type max_safe_execution_cost;
      typedef bool _replan_type;
      _replan_type replan;
      typedef int32_t _replan_attempts_type;
      _replan_attempts_type replan_attempts;
      typedef float _replan_delay_type;
      _replan_delay_type replan_delay;

    PlanningOptions():
      planning_scene_diff(),
      plan_only(0),
      look_around(0),
      look_around_attempts(0),
      max_safe_execution_cost(0),
      replan(0),
      replan_attempts(0),
      replan_delay(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->planning_scene_diff.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_plan_only;
      u_plan_only.real = this->plan_only;
      *(outbuffer + offset + 0) = (u_plan_only.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->plan_only);
      union {
        bool real;
        uint8_t base;
      } u_look_around;
      u_look_around.real = this->look_around;
      *(outbuffer + offset + 0) = (u_look_around.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->look_around);
      union {
        int32_t real;
        uint32_t base;
      } u_look_around_attempts;
      u_look_around_attempts.real = this->look_around_attempts;
      *(outbuffer + offset + 0) = (u_look_around_attempts.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_look_around_attempts.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_look_around_attempts.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_look_around_attempts.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->look_around_attempts);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_safe_execution_cost);
      union {
        bool real;
        uint8_t base;
      } u_replan;
      u_replan.real = this->replan;
      *(outbuffer + offset + 0) = (u_replan.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->replan);
      union {
        int32_t real;
        uint32_t base;
      } u_replan_attempts;
      u_replan_attempts.real = this->replan_attempts;
      *(outbuffer + offset + 0) = (u_replan_attempts.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_replan_attempts.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_replan_attempts.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_replan_attempts.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->replan_attempts);
      offset += serializeAvrFloat64(outbuffer + offset, this->replan_delay);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->planning_scene_diff.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_plan_only;
      u_plan_only.base = 0;
      u_plan_only.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->plan_only = u_plan_only.real;
      offset += sizeof(this->plan_only);
      union {
        bool real;
        uint8_t base;
      } u_look_around;
      u_look_around.base = 0;
      u_look_around.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->look_around = u_look_around.real;
      offset += sizeof(this->look_around);
      union {
        int32_t real;
        uint32_t base;
      } u_look_around_attempts;
      u_look_around_attempts.base = 0;
      u_look_around_attempts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_look_around_attempts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_look_around_attempts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_look_around_attempts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->look_around_attempts = u_look_around_attempts.real;
      offset += sizeof(this->look_around_attempts);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_safe_execution_cost));
      union {
        bool real;
        uint8_t base;
      } u_replan;
      u_replan.base = 0;
      u_replan.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->replan = u_replan.real;
      offset += sizeof(this->replan);
      union {
        int32_t real;
        uint32_t base;
      } u_replan_attempts;
      u_replan_attempts.base = 0;
      u_replan_attempts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_replan_attempts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_replan_attempts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_replan_attempts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->replan_attempts = u_replan_attempts.real;
      offset += sizeof(this->replan_attempts);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->replan_delay));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PlanningOptions"; };
    const char * getMD5(){ return "3934e50ede2ecea03e532aade900ab50"; };

  };

}
#endif
