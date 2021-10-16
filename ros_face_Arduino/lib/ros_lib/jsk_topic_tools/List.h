#ifndef _ROS_SERVICE_List_h
#define _ROS_SERVICE_List_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_topic_tools
{

static const char LIST[] = "jsk_topic_tools/List";

  class ListRequest : public ros::Msg
  {
    public:

    ListRequest()
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

    const char * getType(){ return LIST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ListResponse : public ros::Msg
  {
    public:
      uint32_t topic_names_length;
      typedef char* _topic_names_type;
      _topic_names_type st_topic_names;
      _topic_names_type * topic_names;

    ListResponse():
      topic_names_length(0), topic_names(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->topic_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->topic_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->topic_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->topic_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->topic_names_length);
      for( uint32_t i = 0; i < topic_names_length; i++){
      uint32_t length_topic_namesi = strlen(this->topic_names[i]);
      varToArr(outbuffer + offset, length_topic_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->topic_names[i], length_topic_namesi);
      offset += length_topic_namesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t topic_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      topic_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      topic_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      topic_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->topic_names_length);
      if(topic_names_lengthT > topic_names_length)
        this->topic_names = (char**)realloc(this->topic_names, topic_names_lengthT * sizeof(char*));
      topic_names_length = topic_names_lengthT;
      for( uint32_t i = 0; i < topic_names_length; i++){
      uint32_t length_st_topic_names;
      arrToVar(length_st_topic_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_topic_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_topic_names-1]=0;
      this->st_topic_names = (char *)(inbuffer + offset-1);
      offset += length_st_topic_names;
        memcpy( &(this->topic_names[i]), &(this->st_topic_names), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return LIST; };
    const char * getMD5(){ return "f88f7a076bf16dde010b2480af40dcdb"; };

  };

  class List {
    public:
    typedef ListRequest Request;
    typedef ListResponse Response;
  };

}
#endif
