#ifndef _ROS_SERVICE_GetGeographicMap_h
#define _ROS_SERVICE_GetGeographicMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geographic_msgs/GeographicMap.h"
#include "geographic_msgs/BoundingBox.h"

namespace geographic_msgs
{

static const char GETGEOGRAPHICMAP[] = "geographic_msgs/GetGeographicMap";

  class GetGeographicMapRequest : public ros::Msg
  {
    public:
      typedef const char* _url_type;
      _url_type url;
      typedef geographic_msgs::BoundingBox _bounds_type;
      _bounds_type bounds;

    GetGeographicMapRequest():
      url(""),
      bounds()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_url = strlen(this->url);
      varToArr(outbuffer + offset, length_url);
      offset += 4;
      memcpy(outbuffer + offset, this->url, length_url);
      offset += length_url;
      offset += this->bounds.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_url;
      arrToVar(length_url, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_url; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_url-1]=0;
      this->url = (char *)(inbuffer + offset-1);
      offset += length_url;
      offset += this->bounds.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETGEOGRAPHICMAP; };
    const char * getMD5(){ return "505cc89008cb1745810d2ee4ea646d6e"; };

  };

  class GetGeographicMapResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _status_type;
      _status_type status;
      typedef geographic_msgs::GeographicMap _map_type;
      _map_type map;

    GetGeographicMapResponse():
      success(0),
      status(""),
      map()
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
      offset += this->map.serialize(outbuffer + offset);
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
      offset += this->map.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETGEOGRAPHICMAP; };
    const char * getMD5(){ return "0910332806c65953a4f4252eb780811a"; };

  };

  class GetGeographicMap {
    public:
    typedef GetGeographicMapRequest Request;
    typedef GetGeographicMapResponse Response;
  };

}
#endif
