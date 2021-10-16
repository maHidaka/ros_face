#ifndef _ROS_moveit_msgs_PlannerParams_h
#define _ROS_moveit_msgs_PlannerParams_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

  class PlannerParams : public ros::Msg
  {
    public:
      uint32_t keys_length;
      typedef char* _keys_type;
      _keys_type st_keys;
      _keys_type * keys;
      uint32_t values_length;
      typedef char* _values_type;
      _values_type st_values;
      _values_type * values;
      uint32_t descriptions_length;
      typedef char* _descriptions_type;
      _descriptions_type st_descriptions;
      _descriptions_type * descriptions;

    PlannerParams():
      keys_length(0), keys(NULL),
      values_length(0), values(NULL),
      descriptions_length(0), descriptions(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->keys_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->keys_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->keys_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->keys_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->keys_length);
      for( uint32_t i = 0; i < keys_length; i++){
      uint32_t length_keysi = strlen(this->keys[i]);
      varToArr(outbuffer + offset, length_keysi);
      offset += 4;
      memcpy(outbuffer + offset, this->keys[i], length_keysi);
      offset += length_keysi;
      }
      *(outbuffer + offset + 0) = (this->values_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->values_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->values_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->values_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->values_length);
      for( uint32_t i = 0; i < values_length; i++){
      uint32_t length_valuesi = strlen(this->values[i]);
      varToArr(outbuffer + offset, length_valuesi);
      offset += 4;
      memcpy(outbuffer + offset, this->values[i], length_valuesi);
      offset += length_valuesi;
      }
      *(outbuffer + offset + 0) = (this->descriptions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->descriptions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->descriptions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->descriptions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->descriptions_length);
      for( uint32_t i = 0; i < descriptions_length; i++){
      uint32_t length_descriptionsi = strlen(this->descriptions[i]);
      varToArr(outbuffer + offset, length_descriptionsi);
      offset += 4;
      memcpy(outbuffer + offset, this->descriptions[i], length_descriptionsi);
      offset += length_descriptionsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t keys_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      keys_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      keys_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      keys_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->keys_length);
      if(keys_lengthT > keys_length)
        this->keys = (char**)realloc(this->keys, keys_lengthT * sizeof(char*));
      keys_length = keys_lengthT;
      for( uint32_t i = 0; i < keys_length; i++){
      uint32_t length_st_keys;
      arrToVar(length_st_keys, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_keys; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_keys-1]=0;
      this->st_keys = (char *)(inbuffer + offset-1);
      offset += length_st_keys;
        memcpy( &(this->keys[i]), &(this->st_keys), sizeof(char*));
      }
      uint32_t values_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      values_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      values_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      values_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->values_length);
      if(values_lengthT > values_length)
        this->values = (char**)realloc(this->values, values_lengthT * sizeof(char*));
      values_length = values_lengthT;
      for( uint32_t i = 0; i < values_length; i++){
      uint32_t length_st_values;
      arrToVar(length_st_values, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_values; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_values-1]=0;
      this->st_values = (char *)(inbuffer + offset-1);
      offset += length_st_values;
        memcpy( &(this->values[i]), &(this->st_values), sizeof(char*));
      }
      uint32_t descriptions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      descriptions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      descriptions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      descriptions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->descriptions_length);
      if(descriptions_lengthT > descriptions_length)
        this->descriptions = (char**)realloc(this->descriptions, descriptions_lengthT * sizeof(char*));
      descriptions_length = descriptions_lengthT;
      for( uint32_t i = 0; i < descriptions_length; i++){
      uint32_t length_st_descriptions;
      arrToVar(length_st_descriptions, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_descriptions; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_descriptions-1]=0;
      this->st_descriptions = (char *)(inbuffer + offset-1);
      offset += length_st_descriptions;
        memcpy( &(this->descriptions[i]), &(this->st_descriptions), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PlannerParams"; };
    const char * getMD5(){ return "cebdf4927996b9026bcf59a160d64145"; };

  };

}
#endif
