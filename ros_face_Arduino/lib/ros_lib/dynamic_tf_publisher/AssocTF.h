#ifndef _ROS_SERVICE_AssocTF_h
#define _ROS_SERVICE_AssocTF_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace dynamic_tf_publisher
{

static const char ASSOCTF[] = "dynamic_tf_publisher/AssocTF";

  class AssocTFRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _parent_frame_type;
      _parent_frame_type parent_frame;
      typedef const char* _child_frame_type;
      _child_frame_type child_frame;

    AssocTFRequest():
      header(),
      parent_frame(""),
      child_frame("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_parent_frame = strlen(this->parent_frame);
      varToArr(outbuffer + offset, length_parent_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->parent_frame, length_parent_frame);
      offset += length_parent_frame;
      uint32_t length_child_frame = strlen(this->child_frame);
      varToArr(outbuffer + offset, length_child_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->child_frame, length_child_frame);
      offset += length_child_frame;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_parent_frame;
      arrToVar(length_parent_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_parent_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_parent_frame-1]=0;
      this->parent_frame = (char *)(inbuffer + offset-1);
      offset += length_parent_frame;
      uint32_t length_child_frame;
      arrToVar(length_child_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_child_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_child_frame-1]=0;
      this->child_frame = (char *)(inbuffer + offset-1);
      offset += length_child_frame;
     return offset;
    }

    const char * getType(){ return ASSOCTF; };
    const char * getMD5(){ return "984a9f3f6741b2b5568909b82fec6355"; };

  };

  class AssocTFResponse : public ros::Msg
  {
    public:

    AssocTFResponse()
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

    const char * getType(){ return ASSOCTF; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class AssocTF {
    public:
    typedef AssocTFRequest Request;
    typedef AssocTFResponse Response;
  };

}
#endif
