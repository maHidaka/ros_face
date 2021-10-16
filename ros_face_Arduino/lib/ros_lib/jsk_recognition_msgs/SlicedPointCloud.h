#ifndef _ROS_jsk_recognition_msgs_SlicedPointCloud_h
#define _ROS_jsk_recognition_msgs_SlicedPointCloud_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"

namespace jsk_recognition_msgs
{

  class SlicedPointCloud : public ros::Msg
  {
    public:
      typedef sensor_msgs::PointCloud2 _point_cloud_type;
      _point_cloud_type point_cloud;
      typedef uint8_t _slice_index_type;
      _slice_index_type slice_index;
      typedef uint8_t _sequence_id_type;
      _sequence_id_type sequence_id;

    SlicedPointCloud():
      point_cloud(),
      slice_index(0),
      sequence_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->point_cloud.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->slice_index >> (8 * 0)) & 0xFF;
      offset += sizeof(this->slice_index);
      *(outbuffer + offset + 0) = (this->sequence_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sequence_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->point_cloud.deserialize(inbuffer + offset);
      this->slice_index =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->slice_index);
      this->sequence_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sequence_id);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/SlicedPointCloud"; };
    const char * getMD5(){ return "37376a48b034bf543f8cfd86844487c7"; };

  };

}
#endif
