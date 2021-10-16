#ifndef _ROS_jsk_recognition_msgs_HumanSkeleton_h
#define _ROS_jsk_recognition_msgs_HumanSkeleton_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/Segment.h"

namespace jsk_recognition_msgs
{

  class HumanSkeleton : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t bone_names_length;
      typedef char* _bone_names_type;
      _bone_names_type st_bone_names;
      _bone_names_type * bone_names;
      uint32_t bones_length;
      typedef jsk_recognition_msgs::Segment _bones_type;
      _bones_type st_bones;
      _bones_type * bones;

    HumanSkeleton():
      header(),
      bone_names_length(0), bone_names(NULL),
      bones_length(0), bones(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->bone_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bone_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bone_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bone_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bone_names_length);
      for( uint32_t i = 0; i < bone_names_length; i++){
      uint32_t length_bone_namesi = strlen(this->bone_names[i]);
      varToArr(outbuffer + offset, length_bone_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->bone_names[i], length_bone_namesi);
      offset += length_bone_namesi;
      }
      *(outbuffer + offset + 0) = (this->bones_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bones_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bones_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bones_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bones_length);
      for( uint32_t i = 0; i < bones_length; i++){
      offset += this->bones[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t bone_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      bone_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      bone_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      bone_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->bone_names_length);
      if(bone_names_lengthT > bone_names_length)
        this->bone_names = (char**)realloc(this->bone_names, bone_names_lengthT * sizeof(char*));
      bone_names_length = bone_names_lengthT;
      for( uint32_t i = 0; i < bone_names_length; i++){
      uint32_t length_st_bone_names;
      arrToVar(length_st_bone_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_bone_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_bone_names-1]=0;
      this->st_bone_names = (char *)(inbuffer + offset-1);
      offset += length_st_bone_names;
        memcpy( &(this->bone_names[i]), &(this->st_bone_names), sizeof(char*));
      }
      uint32_t bones_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      bones_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      bones_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      bones_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->bones_length);
      if(bones_lengthT > bones_length)
        this->bones = (jsk_recognition_msgs::Segment*)realloc(this->bones, bones_lengthT * sizeof(jsk_recognition_msgs::Segment));
      bones_length = bones_lengthT;
      for( uint32_t i = 0; i < bones_length; i++){
      offset += this->st_bones.deserialize(inbuffer + offset);
        memcpy( &(this->bones[i]), &(this->st_bones), sizeof(jsk_recognition_msgs::Segment));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/HumanSkeleton"; };
    const char * getMD5(){ return "b8098e195ee1734e91bc2e38c969a23f"; };

  };

}
#endif
