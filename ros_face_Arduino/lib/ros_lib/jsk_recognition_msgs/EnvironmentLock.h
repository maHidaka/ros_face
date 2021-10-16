#ifndef _ROS_SERVICE_EnvironmentLock_h
#define _ROS_SERVICE_EnvironmentLock_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_recognition_msgs
{

static const char ENVIRONMENTLOCK[] = "jsk_recognition_msgs/EnvironmentLock";

  class EnvironmentLockRequest : public ros::Msg
  {
    public:

    EnvironmentLockRequest()
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

    const char * getType(){ return ENVIRONMENTLOCK; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class EnvironmentLockResponse : public ros::Msg
  {
    public:
      typedef uint32_t _environment_id_type;
      _environment_id_type environment_id;

    EnvironmentLockResponse():
      environment_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->environment_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->environment_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->environment_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->environment_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->environment_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->environment_id =  ((uint32_t) (*(inbuffer + offset)));
      this->environment_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->environment_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->environment_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->environment_id);
     return offset;
    }

    const char * getType(){ return ENVIRONMENTLOCK; };
    const char * getMD5(){ return "109afc0d3bd22aa461d45c8ef5ab6d75"; };

  };

  class EnvironmentLock {
    public:
    typedef EnvironmentLockRequest Request;
    typedef EnvironmentLockResponse Response;
  };

}
#endif
