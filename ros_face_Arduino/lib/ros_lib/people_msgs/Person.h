#ifndef _ROS_people_msgs_Person_h
#define _ROS_people_msgs_Person_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace people_msgs
{

  class Person : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef geometry_msgs::Point _position_type;
      _position_type position;
      typedef geometry_msgs::Point _velocity_type;
      _velocity_type velocity;
      typedef float _reliability_type;
      _reliability_type reliability;
      uint32_t tagnames_length;
      typedef char* _tagnames_type;
      _tagnames_type st_tagnames;
      _tagnames_type * tagnames;
      uint32_t tags_length;
      typedef char* _tags_type;
      _tags_type st_tags;
      _tags_type * tags;

    Person():
      name(""),
      position(),
      velocity(),
      reliability(0),
      tagnames_length(0), tagnames(NULL),
      tags_length(0), tags(NULL)
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
      offset += this->position.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->reliability);
      *(outbuffer + offset + 0) = (this->tagnames_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tagnames_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tagnames_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tagnames_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tagnames_length);
      for( uint32_t i = 0; i < tagnames_length; i++){
      uint32_t length_tagnamesi = strlen(this->tagnames[i]);
      varToArr(outbuffer + offset, length_tagnamesi);
      offset += 4;
      memcpy(outbuffer + offset, this->tagnames[i], length_tagnamesi);
      offset += length_tagnamesi;
      }
      *(outbuffer + offset + 0) = (this->tags_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_length);
      for( uint32_t i = 0; i < tags_length; i++){
      uint32_t length_tagsi = strlen(this->tags[i]);
      varToArr(outbuffer + offset, length_tagsi);
      offset += 4;
      memcpy(outbuffer + offset, this->tags[i], length_tagsi);
      offset += length_tagsi;
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
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->reliability));
      uint32_t tagnames_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tagnames_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tagnames_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tagnames_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tagnames_length);
      if(tagnames_lengthT > tagnames_length)
        this->tagnames = (char**)realloc(this->tagnames, tagnames_lengthT * sizeof(char*));
      tagnames_length = tagnames_lengthT;
      for( uint32_t i = 0; i < tagnames_length; i++){
      uint32_t length_st_tagnames;
      arrToVar(length_st_tagnames, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_tagnames; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_tagnames-1]=0;
      this->st_tagnames = (char *)(inbuffer + offset-1);
      offset += length_st_tagnames;
        memcpy( &(this->tagnames[i]), &(this->st_tagnames), sizeof(char*));
      }
      uint32_t tags_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tags_length);
      if(tags_lengthT > tags_length)
        this->tags = (char**)realloc(this->tags, tags_lengthT * sizeof(char*));
      tags_length = tags_lengthT;
      for( uint32_t i = 0; i < tags_length; i++){
      uint32_t length_st_tags;
      arrToVar(length_st_tags, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_tags; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_tags-1]=0;
      this->st_tags = (char *)(inbuffer + offset-1);
      offset += length_st_tags;
        memcpy( &(this->tags[i]), &(this->st_tags), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "people_msgs/Person"; };
    const char * getMD5(){ return "0b7c0818b76476f3863bd13f4d59f8df"; };

  };

}
#endif
