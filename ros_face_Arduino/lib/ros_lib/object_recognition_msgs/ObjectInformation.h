#ifndef _ROS_object_recognition_msgs_ObjectInformation_h
#define _ROS_object_recognition_msgs_ObjectInformation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "shape_msgs/Mesh.h"
#include "sensor_msgs/PointCloud2.h"

namespace object_recognition_msgs
{

  class ObjectInformation : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef shape_msgs::Mesh _ground_truth_mesh_type;
      _ground_truth_mesh_type ground_truth_mesh;
      typedef sensor_msgs::PointCloud2 _ground_truth_point_cloud_type;
      _ground_truth_point_cloud_type ground_truth_point_cloud;

    ObjectInformation():
      name(""),
      ground_truth_mesh(),
      ground_truth_point_cloud()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += this->ground_truth_mesh.serialize(outbuffer + offset);
      offset += this->ground_truth_point_cloud.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += this->ground_truth_mesh.deserialize(inbuffer + offset);
      offset += this->ground_truth_point_cloud.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "object_recognition_msgs/ObjectInformation"; };
    const char * getMD5(){ return "921ec39f51c7b927902059cf3300ecde"; };

  };

}
#endif
