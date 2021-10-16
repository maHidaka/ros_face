#ifndef _ROS_bond_Constants_h
#define _ROS_bond_Constants_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace bond
{

  class Constants : public ros::Msg
  {
    public:
      enum { DEAD_PUBLISH_PERIOD =  0.05 };
      enum { DEFAULT_CONNECT_TIMEOUT =  10.0 };
      enum { DEFAULT_HEARTBEAT_TIMEOUT =  4.0 };
      enum { DEFAULT_DISCONNECT_TIMEOUT =  2.0 };
      enum { DEFAULT_HEARTBEAT_PERIOD =  1.0 };
      enum { DISABLE_HEARTBEAT_TIMEOUT_PARAM = /bond_disable_heartbeat_timeout };

    Constants()
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

    const char * getType(){ return "bond/Constants"; };
    const char * getMD5(){ return "6fc594dc1d7bd7919077042712f8c8b0"; };

  };

}
#endif
