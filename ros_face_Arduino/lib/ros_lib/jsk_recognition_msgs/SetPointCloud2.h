#ifndef _ROS_SERVICE_SetPointCloud2_h
#define _ROS_SERVICE_SetPointCloud2_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"

namespace jsk_recognition_msgs
{

static const char SETPOINTCLOUD2[] = "jsk_recognition_msgs/SetPointCloud2";

  class SetPointCloud2Request : public ros::Msg
  {
    public:
      typedef sensor_msgs::PointCloud2 _cloud_type;
      _cloud_type cloud;
      typedef const char* _name_type;
      _name_type name;

    SetPointCloud2Request():
      cloud(),
      name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->cloud.serialize(outbuffer + offset);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->cloud.deserialize(inbuffer + offset);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
     return offset;
    }

    const char * getType(){ return SETPOINTCLOUD2; };
    const char * getMD5(){ return "f233222fb244758562fcd56961c317c9"; };

  };

  class SetPointCloud2Response : public ros::Msg
  {
    public:
      typedef const char* _output_type;
      _output_type output;

    SetPointCloud2Response():
      output("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_output = strlen(this->output);
      varToArr(outbuffer + offset, length_output);
      offset += 4;
      memcpy(outbuffer + offset, this->output, length_output);
      offset += length_output;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_output;
      arrToVar(length_output, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_output; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_output-1]=0;
      this->output = (char *)(inbuffer + offset-1);
      offset += length_output;
     return offset;
    }

    const char * getType(){ return SETPOINTCLOUD2; };
    const char * getMD5(){ return "0825d95fdfa2c8f4bbb4e9c74bccd3fd"; };

  };

  class SetPointCloud2 {
    public:
    typedef SetPointCloud2Request Request;
    typedef SetPointCloud2Response Response;
  };

}
#endif
