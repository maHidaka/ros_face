#ifndef _ROS_jsk_recognition_msgs_PointsArray_h
#define _ROS_jsk_recognition_msgs_PointsArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/PointCloud2.h"

namespace jsk_recognition_msgs
{

  class PointsArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t cloud_list_length;
      typedef sensor_msgs::PointCloud2 _cloud_list_type;
      _cloud_list_type st_cloud_list;
      _cloud_list_type * cloud_list;

    PointsArray():
      header(),
      cloud_list_length(0), cloud_list(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->cloud_list_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cloud_list_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cloud_list_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cloud_list_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cloud_list_length);
      for( uint32_t i = 0; i < cloud_list_length; i++){
      offset += this->cloud_list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t cloud_list_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cloud_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cloud_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cloud_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cloud_list_length);
      if(cloud_list_lengthT > cloud_list_length)
        this->cloud_list = (sensor_msgs::PointCloud2*)realloc(this->cloud_list, cloud_list_lengthT * sizeof(sensor_msgs::PointCloud2));
      cloud_list_length = cloud_list_lengthT;
      for( uint32_t i = 0; i < cloud_list_length; i++){
      offset += this->st_cloud_list.deserialize(inbuffer + offset);
        memcpy( &(this->cloud_list[i]), &(this->st_cloud_list), sizeof(sensor_msgs::PointCloud2));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/PointsArray"; };
    const char * getMD5(){ return "0aa7e57c9da77fc1a0d8277bba5672b1"; };

  };

}
#endif
