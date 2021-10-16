#ifndef _ROS_moveit_msgs_PlannerInterfaceDescription_h
#define _ROS_moveit_msgs_PlannerInterfaceDescription_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

  class PlannerInterfaceDescription : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      uint32_t planner_ids_length;
      typedef char* _planner_ids_type;
      _planner_ids_type st_planner_ids;
      _planner_ids_type * planner_ids;

    PlannerInterfaceDescription():
      name(""),
      planner_ids_length(0), planner_ids(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->planner_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->planner_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->planner_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->planner_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->planner_ids_length);
      for( uint32_t i = 0; i < planner_ids_length; i++){
      uint32_t length_planner_idsi = strlen(this->planner_ids[i]);
      varToArr(outbuffer + offset, length_planner_idsi);
      offset += 4;
      memcpy(outbuffer + offset, this->planner_ids[i], length_planner_idsi);
      offset += length_planner_idsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t planner_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      planner_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      planner_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      planner_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->planner_ids_length);
      if(planner_ids_lengthT > planner_ids_length)
        this->planner_ids = (char**)realloc(this->planner_ids, planner_ids_lengthT * sizeof(char*));
      planner_ids_length = planner_ids_lengthT;
      for( uint32_t i = 0; i < planner_ids_length; i++){
      uint32_t length_st_planner_ids;
      arrToVar(length_st_planner_ids, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_planner_ids; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_planner_ids-1]=0;
      this->st_planner_ids = (char *)(inbuffer + offset-1);
      offset += length_st_planner_ids;
        memcpy( &(this->planner_ids[i]), &(this->st_planner_ids), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PlannerInterfaceDescription"; };
    const char * getMD5(){ return "ea5f6e6129aa1b110ccda9900d2bf25e"; };

  };

}
#endif
