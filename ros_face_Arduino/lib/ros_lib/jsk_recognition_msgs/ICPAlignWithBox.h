#ifndef _ROS_SERVICE_ICPAlignWithBox_h
#define _ROS_SERVICE_ICPAlignWithBox_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_recognition_msgs/BoundingBox.h"
#include "sensor_msgs/PointCloud2.h"
#include "jsk_recognition_msgs/ICPResult.h"

namespace jsk_recognition_msgs
{

static const char ICPALIGNWITHBOX[] = "jsk_recognition_msgs/ICPAlignWithBox";

  class ICPAlignWithBoxRequest : public ros::Msg
  {
    public:
      typedef sensor_msgs::PointCloud2 _target_cloud_type;
      _target_cloud_type target_cloud;
      typedef jsk_recognition_msgs::BoundingBox _target_box_type;
      _target_box_type target_box;

    ICPAlignWithBoxRequest():
      target_cloud(),
      target_box()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->target_cloud.serialize(outbuffer + offset);
      offset += this->target_box.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->target_cloud.deserialize(inbuffer + offset);
      offset += this->target_box.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return ICPALIGNWITHBOX; };
    const char * getMD5(){ return "9431a0df63f5a2625b973e92c6229cf3"; };

  };

  class ICPAlignWithBoxResponse : public ros::Msg
  {
    public:
      typedef jsk_recognition_msgs::ICPResult _result_type;
      _result_type result;

    ICPAlignWithBoxResponse():
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

    const char * getType(){ return ICPALIGNWITHBOX; };
    const char * getMD5(){ return "a511a876c2be142caffd78741c68e4cf"; };

  };

  class ICPAlignWithBox {
    public:
    typedef ICPAlignWithBoxRequest Request;
    typedef ICPAlignWithBoxResponse Response;
  };

}
#endif
