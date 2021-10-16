#ifndef _ROS_SERVICE_GetObjectInformation_h
#define _ROS_SERVICE_GetObjectInformation_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "object_recognition_msgs/ObjectType.h"
#include "object_recognition_msgs/ObjectInformation.h"

namespace object_recognition_msgs
{

static const char GETOBJECTINFORMATION[] = "object_recognition_msgs/GetObjectInformation";

  class GetObjectInformationRequest : public ros::Msg
  {
    public:
      typedef object_recognition_msgs::ObjectType _type_type;
      _type_type type;

    GetObjectInformationRequest():
      type()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->type.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->type.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETOBJECTINFORMATION; };
    const char * getMD5(){ return "0d72b69e80da0fe473b0bdcdd7a28d4d"; };

  };

  class GetObjectInformationResponse : public ros::Msg
  {
    public:
      typedef object_recognition_msgs::ObjectInformation _information_type;
      _information_type information;

    GetObjectInformationResponse():
      information()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->information.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->information.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETOBJECTINFORMATION; };
    const char * getMD5(){ return "a62c5d1c41e250373b3e8e912a13a9cb"; };

  };

  class GetObjectInformation {
    public:
    typedef GetObjectInformationRequest Request;
    typedef GetObjectInformationResponse Response;
  };

}
#endif
