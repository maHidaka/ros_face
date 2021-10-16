#ifndef _ROS_SERVICE_UpdateGeographicMap_h
#define _ROS_SERVICE_UpdateGeographicMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geographic_msgs/GeographicMapChanges.h"

namespace geographic_msgs
{

static const char UPDATEGEOGRAPHICMAP[] = "geographic_msgs/UpdateGeographicMap";

  class UpdateGeographicMapRequest : public ros::Msg
  {
    public:
      typedef geographic_msgs::GeographicMapChanges _updates_type;
      _updates_type updates;

    UpdateGeographicMapRequest():
      updates()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->updates.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->updates.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return UPDATEGEOGRAPHICMAP; };
    const char * getMD5(){ return "8d8da723a1fadc5f7621a18b4e72fc3b"; };

  };

  class UpdateGeographicMapResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _status_type;
      _status_type status;

    UpdateGeographicMapResponse():
      success(0),
      status("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_status = strlen(this->status);
      varToArr(outbuffer + offset, length_status);
      offset += 4;
      memcpy(outbuffer + offset, this->status, length_status);
      offset += length_status;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_status;
      arrToVar(length_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status-1]=0;
      this->status = (char *)(inbuffer + offset-1);
      offset += length_status;
     return offset;
    }

    const char * getType(){ return UPDATEGEOGRAPHICMAP; };
    const char * getMD5(){ return "38b8954d32a849f31d78416b12bff5d1"; };

  };

  class UpdateGeographicMap {
    public:
    typedef UpdateGeographicMapRequest Request;
    typedef UpdateGeographicMapResponse Response;
  };

}
#endif
