#ifndef _ROS_SERVICE_GetPlannerParams_h
#define _ROS_SERVICE_GetPlannerParams_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/PlannerParams.h"

namespace moveit_msgs
{

static const char GETPLANNERPARAMS[] = "moveit_msgs/GetPlannerParams";

  class GetPlannerParamsRequest : public ros::Msg
  {
    public:
      typedef const char* _planner_config_type;
      _planner_config_type planner_config;
      typedef const char* _group_type;
      _group_type group;

    GetPlannerParamsRequest():
      planner_config(""),
      group("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_planner_config = strlen(this->planner_config);
      varToArr(outbuffer + offset, length_planner_config);
      offset += 4;
      memcpy(outbuffer + offset, this->planner_config, length_planner_config);
      offset += length_planner_config;
      uint32_t length_group = strlen(this->group);
      varToArr(outbuffer + offset, length_group);
      offset += 4;
      memcpy(outbuffer + offset, this->group, length_group);
      offset += length_group;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_planner_config;
      arrToVar(length_planner_config, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_planner_config; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_planner_config-1]=0;
      this->planner_config = (char *)(inbuffer + offset-1);
      offset += length_planner_config;
      uint32_t length_group;
      arrToVar(length_group, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group-1]=0;
      this->group = (char *)(inbuffer + offset-1);
      offset += length_group;
     return offset;
    }

    const char * getType(){ return GETPLANNERPARAMS; };
    const char * getMD5(){ return "f548a13784550d510d791867af53ef40"; };

  };

  class GetPlannerParamsResponse : public ros::Msg
  {
    public:
      typedef moveit_msgs::PlannerParams _params_type;
      _params_type params;

    GetPlannerParamsResponse():
      params()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->params.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->params.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETPLANNERPARAMS; };
    const char * getMD5(){ return "462b1bd59976ece800f6a48f2b0bf1a2"; };

  };

  class GetPlannerParams {
    public:
    typedef GetPlannerParamsRequest Request;
    typedef GetPlannerParamsResponse Response;
  };

}
#endif
