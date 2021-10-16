#ifndef _ROS_SERVICE_DeleteTF_h
#define _ROS_SERVICE_DeleteTF_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace dynamic_tf_publisher
{

static const char DELETETF[] = "dynamic_tf_publisher/DeleteTF";

  class DeleteTFRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;

    DeleteTFRequest():
      header()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return DELETETF; };
    const char * getMD5(){ return "d7be0bb39af8fb9129d5a76e6b63a290"; };

  };

  class DeleteTFResponse : public ros::Msg
  {
    public:

    DeleteTFResponse()
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

    const char * getType(){ return DELETETF; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class DeleteTF {
    public:
    typedef DeleteTFRequest Request;
    typedef DeleteTFResponse Response;
  };

}
#endif
