#ifndef _ROS_SERVICE_GetStateValidity_h
#define _ROS_SERVICE_GetStateValidity_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/ConstraintEvalResult.h"
#include "moveit_msgs/CostSource.h"
#include "moveit_msgs/ContactInformation.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/Constraints.h"

namespace moveit_msgs
{

static const char GETSTATEVALIDITY[] = "moveit_msgs/GetStateValidity";

  class GetStateValidityRequest : public ros::Msg
  {
    public:
      typedef moveit_msgs::RobotState _robot_state_type;
      _robot_state_type robot_state;
      typedef const char* _group_name_type;
      _group_name_type group_name;
      typedef moveit_msgs::Constraints _constraints_type;
      _constraints_type constraints;

    GetStateValidityRequest():
      robot_state(),
      group_name(""),
      constraints()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->robot_state.serialize(outbuffer + offset);
      uint32_t length_group_name = strlen(this->group_name);
      varToArr(outbuffer + offset, length_group_name);
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      offset += this->constraints.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->robot_state.deserialize(inbuffer + offset);
      uint32_t length_group_name;
      arrToVar(length_group_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
      offset += this->constraints.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETSTATEVALIDITY; };
    const char * getMD5(){ return "b569c609cafad20ba7d0e46e70e7cab1"; };

  };

  class GetStateValidityResponse : public ros::Msg
  {
    public:
      typedef bool _valid_type;
      _valid_type valid;
      uint32_t contacts_length;
      typedef moveit_msgs::ContactInformation _contacts_type;
      _contacts_type st_contacts;
      _contacts_type * contacts;
      uint32_t cost_sources_length;
      typedef moveit_msgs::CostSource _cost_sources_type;
      _cost_sources_type st_cost_sources;
      _cost_sources_type * cost_sources;
      uint32_t constraint_result_length;
      typedef moveit_msgs::ConstraintEvalResult _constraint_result_type;
      _constraint_result_type st_constraint_result;
      _constraint_result_type * constraint_result;

    GetStateValidityResponse():
      valid(0),
      contacts_length(0), contacts(NULL),
      cost_sources_length(0), cost_sources(NULL),
      constraint_result_length(0), constraint_result(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_valid;
      u_valid.real = this->valid;
      *(outbuffer + offset + 0) = (u_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->valid);
      *(outbuffer + offset + 0) = (this->contacts_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->contacts_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->contacts_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->contacts_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->contacts_length);
      for( uint32_t i = 0; i < contacts_length; i++){
      offset += this->contacts[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cost_sources_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cost_sources_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cost_sources_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cost_sources_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cost_sources_length);
      for( uint32_t i = 0; i < cost_sources_length; i++){
      offset += this->cost_sources[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->constraint_result_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->constraint_result_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->constraint_result_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->constraint_result_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->constraint_result_length);
      for( uint32_t i = 0; i < constraint_result_length; i++){
      offset += this->constraint_result[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_valid;
      u_valid.base = 0;
      u_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->valid = u_valid.real;
      offset += sizeof(this->valid);
      uint32_t contacts_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      contacts_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      contacts_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      contacts_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->contacts_length);
      if(contacts_lengthT > contacts_length)
        this->contacts = (moveit_msgs::ContactInformation*)realloc(this->contacts, contacts_lengthT * sizeof(moveit_msgs::ContactInformation));
      contacts_length = contacts_lengthT;
      for( uint32_t i = 0; i < contacts_length; i++){
      offset += this->st_contacts.deserialize(inbuffer + offset);
        memcpy( &(this->contacts[i]), &(this->st_contacts), sizeof(moveit_msgs::ContactInformation));
      }
      uint32_t cost_sources_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cost_sources_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cost_sources_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cost_sources_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cost_sources_length);
      if(cost_sources_lengthT > cost_sources_length)
        this->cost_sources = (moveit_msgs::CostSource*)realloc(this->cost_sources, cost_sources_lengthT * sizeof(moveit_msgs::CostSource));
      cost_sources_length = cost_sources_lengthT;
      for( uint32_t i = 0; i < cost_sources_length; i++){
      offset += this->st_cost_sources.deserialize(inbuffer + offset);
        memcpy( &(this->cost_sources[i]), &(this->st_cost_sources), sizeof(moveit_msgs::CostSource));
      }
      uint32_t constraint_result_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      constraint_result_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      constraint_result_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      constraint_result_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->constraint_result_length);
      if(constraint_result_lengthT > constraint_result_length)
        this->constraint_result = (moveit_msgs::ConstraintEvalResult*)realloc(this->constraint_result, constraint_result_lengthT * sizeof(moveit_msgs::ConstraintEvalResult));
      constraint_result_length = constraint_result_lengthT;
      for( uint32_t i = 0; i < constraint_result_length; i++){
      offset += this->st_constraint_result.deserialize(inbuffer + offset);
        memcpy( &(this->constraint_result[i]), &(this->st_constraint_result), sizeof(moveit_msgs::ConstraintEvalResult));
      }
     return offset;
    }

    const char * getType(){ return GETSTATEVALIDITY; };
    const char * getMD5(){ return "e326fb22b7448f29c0e726d9270d9929"; };

  };

  class GetStateValidity {
    public:
    typedef GetStateValidityRequest Request;
    typedef GetStateValidityResponse Response;
  };

}
#endif
