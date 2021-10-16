#ifndef _ROS_SERVICE_QueryPlannerInterfaces_h
#define _ROS_SERVICE_QueryPlannerInterfaces_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/PlannerInterfaceDescription.h"

namespace moveit_msgs
{

static const char QUERYPLANNERINTERFACES[] = "moveit_msgs/QueryPlannerInterfaces";

  class QueryPlannerInterfacesRequest : public ros::Msg
  {
    public:

    QueryPlannerInterfacesRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return QUERYPLANNERINTERFACES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class QueryPlannerInterfacesResponse : public ros::Msg
  {
    public:
      uint32_t planner_interfaces_length;
      typedef moveit_msgs::PlannerInterfaceDescription _planner_interfaces_type;
      _planner_interfaces_type st_planner_interfaces;
      _planner_interfaces_type * planner_interfaces;

    QueryPlannerInterfacesResponse():
      planner_interfaces_length(0), planner_interfaces(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->planner_interfaces_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->planner_interfaces_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->planner_interfaces_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->planner_interfaces_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->planner_interfaces_length);
      for( uint32_t i = 0; i < planner_interfaces_length; i++){
      offset += this->planner_interfaces[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t planner_interfaces_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      planner_interfaces_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      planner_interfaces_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      planner_interfaces_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->planner_interfaces_length);
      if(planner_interfaces_lengthT > planner_interfaces_length)
        this->planner_interfaces = (moveit_msgs::PlannerInterfaceDescription*)realloc(this->planner_interfaces, planner_interfaces_lengthT * sizeof(moveit_msgs::PlannerInterfaceDescription));
      planner_interfaces_length = planner_interfaces_lengthT;
      for( uint32_t i = 0; i < planner_interfaces_length; i++){
      offset += this->st_planner_interfaces.deserialize(inbuffer + offset);
        memcpy( &(this->planner_interfaces[i]), &(this->st_planner_interfaces), sizeof(moveit_msgs::PlannerInterfaceDescription));
      }
     return offset;
    }

    const char * getType(){ return QUERYPLANNERINTERFACES; };
    const char * getMD5(){ return "acd3317a4c5631f33127fb428209db05"; };

  };

  class QueryPlannerInterfaces {
    public:
    typedef QueryPlannerInterfacesRequest Request;
    typedef QueryPlannerInterfacesResponse Response;
  };

}
#endif
