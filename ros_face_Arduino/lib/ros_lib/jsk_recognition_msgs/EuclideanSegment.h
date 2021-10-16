#ifndef _ROS_SERVICE_EuclideanSegment_h
#define _ROS_SERVICE_EuclideanSegment_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"

namespace jsk_recognition_msgs
{

static const char EUCLIDEANSEGMENT[] = "jsk_recognition_msgs/EuclideanSegment";

  class EuclideanSegmentRequest : public ros::Msg
  {
    public:
      typedef sensor_msgs::PointCloud2 _input_type;
      _input_type input;
      typedef float _tolerance_type;
      _tolerance_type tolerance;

    EuclideanSegmentRequest():
      input(),
      tolerance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->input.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_tolerance;
      u_tolerance.real = this->tolerance;
      *(outbuffer + offset + 0) = (u_tolerance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tolerance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tolerance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tolerance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tolerance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->input.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_tolerance;
      u_tolerance.base = 0;
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tolerance = u_tolerance.real;
      offset += sizeof(this->tolerance);
     return offset;
    }

    const char * getType(){ return EUCLIDEANSEGMENT; };
    const char * getMD5(){ return "116dd66bdc82f46d7b7414ce880ea794"; };

  };

  class EuclideanSegmentResponse : public ros::Msg
  {
    public:
      uint32_t output_length;
      typedef sensor_msgs::PointCloud2 _output_type;
      _output_type st_output;
      _output_type * output;

    EuclideanSegmentResponse():
      output_length(0), output(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->output_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->output_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->output_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->output_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->output_length);
      for( uint32_t i = 0; i < output_length; i++){
      offset += this->output[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t output_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      output_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      output_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      output_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->output_length);
      if(output_lengthT > output_length)
        this->output = (sensor_msgs::PointCloud2*)realloc(this->output, output_lengthT * sizeof(sensor_msgs::PointCloud2));
      output_length = output_lengthT;
      for( uint32_t i = 0; i < output_length; i++){
      offset += this->st_output.deserialize(inbuffer + offset);
        memcpy( &(this->output[i]), &(this->st_output), sizeof(sensor_msgs::PointCloud2));
      }
     return offset;
    }

    const char * getType(){ return EUCLIDEANSEGMENT; };
    const char * getMD5(){ return "6db5ac8d8316fdb3e0c62197115f87cd"; };

  };

  class EuclideanSegment {
    public:
    typedef EuclideanSegmentRequest Request;
    typedef EuclideanSegmentResponse Response;
  };

}
#endif
