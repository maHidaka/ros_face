#ifndef _ROS_moveit_msgs_AllowedCollisionMatrix_h
#define _ROS_moveit_msgs_AllowedCollisionMatrix_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/AllowedCollisionEntry.h"

namespace moveit_msgs
{

  class AllowedCollisionMatrix : public ros::Msg
  {
    public:
      uint32_t entry_names_length;
      typedef char* _entry_names_type;
      _entry_names_type st_entry_names;
      _entry_names_type * entry_names;
      uint32_t entry_values_length;
      typedef moveit_msgs::AllowedCollisionEntry _entry_values_type;
      _entry_values_type st_entry_values;
      _entry_values_type * entry_values;
      uint32_t default_entry_names_length;
      typedef char* _default_entry_names_type;
      _default_entry_names_type st_default_entry_names;
      _default_entry_names_type * default_entry_names;
      uint32_t default_entry_values_length;
      typedef bool _default_entry_values_type;
      _default_entry_values_type st_default_entry_values;
      _default_entry_values_type * default_entry_values;

    AllowedCollisionMatrix():
      entry_names_length(0), entry_names(NULL),
      entry_values_length(0), entry_values(NULL),
      default_entry_names_length(0), default_entry_names(NULL),
      default_entry_values_length(0), default_entry_values(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->entry_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->entry_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->entry_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->entry_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->entry_names_length);
      for( uint32_t i = 0; i < entry_names_length; i++){
      uint32_t length_entry_namesi = strlen(this->entry_names[i]);
      varToArr(outbuffer + offset, length_entry_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->entry_names[i], length_entry_namesi);
      offset += length_entry_namesi;
      }
      *(outbuffer + offset + 0) = (this->entry_values_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->entry_values_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->entry_values_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->entry_values_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->entry_values_length);
      for( uint32_t i = 0; i < entry_values_length; i++){
      offset += this->entry_values[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->default_entry_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->default_entry_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->default_entry_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->default_entry_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->default_entry_names_length);
      for( uint32_t i = 0; i < default_entry_names_length; i++){
      uint32_t length_default_entry_namesi = strlen(this->default_entry_names[i]);
      varToArr(outbuffer + offset, length_default_entry_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->default_entry_names[i], length_default_entry_namesi);
      offset += length_default_entry_namesi;
      }
      *(outbuffer + offset + 0) = (this->default_entry_values_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->default_entry_values_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->default_entry_values_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->default_entry_values_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->default_entry_values_length);
      for( uint32_t i = 0; i < default_entry_values_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_default_entry_valuesi;
      u_default_entry_valuesi.real = this->default_entry_values[i];
      *(outbuffer + offset + 0) = (u_default_entry_valuesi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->default_entry_values[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t entry_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      entry_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      entry_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      entry_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->entry_names_length);
      if(entry_names_lengthT > entry_names_length)
        this->entry_names = (char**)realloc(this->entry_names, entry_names_lengthT * sizeof(char*));
      entry_names_length = entry_names_lengthT;
      for( uint32_t i = 0; i < entry_names_length; i++){
      uint32_t length_st_entry_names;
      arrToVar(length_st_entry_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_entry_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_entry_names-1]=0;
      this->st_entry_names = (char *)(inbuffer + offset-1);
      offset += length_st_entry_names;
        memcpy( &(this->entry_names[i]), &(this->st_entry_names), sizeof(char*));
      }
      uint32_t entry_values_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      entry_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      entry_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      entry_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->entry_values_length);
      if(entry_values_lengthT > entry_values_length)
        this->entry_values = (moveit_msgs::AllowedCollisionEntry*)realloc(this->entry_values, entry_values_lengthT * sizeof(moveit_msgs::AllowedCollisionEntry));
      entry_values_length = entry_values_lengthT;
      for( uint32_t i = 0; i < entry_values_length; i++){
      offset += this->st_entry_values.deserialize(inbuffer + offset);
        memcpy( &(this->entry_values[i]), &(this->st_entry_values), sizeof(moveit_msgs::AllowedCollisionEntry));
      }
      uint32_t default_entry_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      default_entry_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      default_entry_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      default_entry_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->default_entry_names_length);
      if(default_entry_names_lengthT > default_entry_names_length)
        this->default_entry_names = (char**)realloc(this->default_entry_names, default_entry_names_lengthT * sizeof(char*));
      default_entry_names_length = default_entry_names_lengthT;
      for( uint32_t i = 0; i < default_entry_names_length; i++){
      uint32_t length_st_default_entry_names;
      arrToVar(length_st_default_entry_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_default_entry_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_default_entry_names-1]=0;
      this->st_default_entry_names = (char *)(inbuffer + offset-1);
      offset += length_st_default_entry_names;
        memcpy( &(this->default_entry_names[i]), &(this->st_default_entry_names), sizeof(char*));
      }
      uint32_t default_entry_values_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      default_entry_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      default_entry_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      default_entry_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->default_entry_values_length);
      if(default_entry_values_lengthT > default_entry_values_length)
        this->default_entry_values = (bool*)realloc(this->default_entry_values, default_entry_values_lengthT * sizeof(bool));
      default_entry_values_length = default_entry_values_lengthT;
      for( uint32_t i = 0; i < default_entry_values_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_default_entry_values;
      u_st_default_entry_values.base = 0;
      u_st_default_entry_values.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_default_entry_values = u_st_default_entry_values.real;
      offset += sizeof(this->st_default_entry_values);
        memcpy( &(this->default_entry_values[i]), &(this->st_default_entry_values), sizeof(bool));
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/AllowedCollisionMatrix"; };
    const char * getMD5(){ return "aedce13587eef0d79165a075659c1879"; };

  };

}
#endif
