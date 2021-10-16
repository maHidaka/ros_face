#ifndef _ROS_SERVICE_ICPAlign_h
#define _ROS_SERVICE_ICPAlign_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"
#include "jsk_recognition_msgs/ICPResult.h"

namespace jsk_recognition_msgs
{

static const char ICPALIGN[] = "jsk_recognition_msgs/ICPAlign";

  class ICPAlignRequest : public ros::Msg
  {
    public:
      typedef sensor_msgs::PointCloud2 _reference_cloud_type;
      _reference_cloud_type reference_cloud;
      typedef sensor_msgs::PointCloud2 _target_cloud_type;
      _target_cloud_type target_cloud;

    ICPAlignRequest():
      reference_cloud(),
      target_cloud()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->reference_cloud.serialize(outbuffer + offset);
      offset += this->target_cloud.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->reference_cloud.deserialize(inbuffer + offset);
      offset += this->target_cloud.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return ICPALIGN; };
    const char * getMD5(){ return "3e0df534693afbbecb9cc87944720695"; };

  };

  class ICPAlignResponse : public ros::Msg
  {
    public:
      typedef jsk_recognition_msgs::ICPResult _result_type;
      _result_type result;

    ICPAlignResponse():
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return ICPALIGN; };
    const char * getMD5(){ return "a511a876c2be142caffd78741c68e4cf"; };

  };

  class ICPAlign {
    public:
    typedef ICPAlignRequest Request;
    typedef ICPAlignResponse Response;
  };

}
#endif
