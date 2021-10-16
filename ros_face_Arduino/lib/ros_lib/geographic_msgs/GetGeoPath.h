#ifndef _ROS_SERVICE_GetGeoPath_h
#define _ROS_SERVICE_GetGeoPath_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"
#include "geographic_msgs/GeoPoint.h"
#include "geographic_msgs/GeoPath.h"

namespace geographic_msgs
{

static const char GETGEOPATH[] = "geographic_msgs/GetGeoPath";

  class GetGeoPathRequest : public ros::Msg
  {
    public:
      typedef geographic_msgs::GeoPoint _start_type;
      _start_type start;
      typedef geographic_msgs::GeoPoint _goal_type;
      _goal_type goal;

    GetGeoPathRequest():
      start(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->start.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->start.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETGEOPATH; };
    const char * getMD5(){ return "cad6de11e4ae4ca568785186e1f99f89"; };

  };

  class GetGeoPathResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _status_type;
      _status_type status;
      typedef geographic_msgs::GeoPath _plan_type;
      _plan_type plan;
      typedef uuid_msgs::UniqueID _network_type;
      _network_type network;
      typedef uuid_msgs::UniqueID _start_seg_type;
      _start_seg_type start_seg;
      typedef uuid_msgs::UniqueID _goal_seg_type;
      _goal_seg_type goal_seg;
      typedef float _distance_type;
      _distance_type distance;

    GetGeoPathResponse():
      success(0),
      status(""),
      plan(),
      network(),
      start_seg(),
      goal_seg(),
      distance(0)
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
      offset += this->plan.serialize(outbuffer + offset);
      offset += this->network.serialize(outbuffer + offset);
      offset += this->start_seg.serialize(outbuffer + offset);
      offset += this->goal_seg.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->distance);
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
      offset += this->plan.deserialize(inbuffer + offset);
      offset += this->network.deserialize(inbuffer + offset);
      offset += this->start_seg.deserialize(inbuffer + offset);
      offset += this->goal_seg.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance));
     return offset;
    }

    const char * getType(){ return GETGEOPATH; };
    const char * getMD5(){ return "0562f4b72e4d5b8e5fa142bd7363638c"; };

  };

  class GetGeoPath {
    public:
    typedef GetGeoPathRequest Request;
    typedef GetGeoPathResponse Response;
  };

}
#endif
