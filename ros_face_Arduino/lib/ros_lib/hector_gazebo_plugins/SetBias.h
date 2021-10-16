#ifndef _ROS_SERVICE_SetBias_h
#define _ROS_SERVICE_SetBias_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace hector_gazebo_plugins
{

static const char SETBIAS[] = "hector_gazebo_plugins/SetBias";

  class SetBiasRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Vector3 _bias_type;
      _bias_type bias;

    SetBiasRequest():
      bias()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->bias.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->bias.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETBIAS; };
    const char * getMD5(){ return "af1f260075d9ba9bd73ca10c6a45df07"; };

  };

  class SetBiasResponse : public ros::Msg
  {
    public:

    SetBiasResponse()
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

    const char * getType(){ return SETBIAS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetBias {
    public:
    typedef SetBiasRequest Request;
    typedef SetBiasResponse Response;
  };

}
#endif
