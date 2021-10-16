#ifndef _ROS_posedetection_msgs_Feature1D_h
#define _ROS_posedetection_msgs_Feature1D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "posedetection_msgs/Curve1D.h"

namespace posedetection_msgs
{

  class Feature1D : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t lines_length;
      typedef posedetection_msgs::Curve1D _lines_type;
      _lines_type st_lines;
      _lines_type * lines;
      uint32_t descriptors_length;
      typedef float _descriptors_type;
      _descriptors_type st_descriptors;
      _descriptors_type * descriptors;
      uint32_t confidences_length;
      typedef float _confidences_type;
      _confidences_type st_confidences;
      _confidences_type * confidences;
      typedef int32_t _descriptor_dim_type;
      _descriptor_dim_type descriptor_dim;

    Feature1D():
      header(),
      lines_length(0), lines(NULL),
      descriptors_length(0), descriptors(NULL),
      confidences_length(0), confidences(NULL),
      descriptor_dim(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->lines_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lines_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lines_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lines_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lines_length);
      for( uint32_t i = 0; i < lines_length; i++){
      offset += this->lines[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->descriptors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->descriptors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->descriptors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->descriptors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->descriptors_length);
      for( uint32_t i = 0; i < descriptors_length; i++){
      union {
        float real;
        uint32_t base;
      } u_descriptorsi;
      u_descriptorsi.real = this->descriptors[i];
      *(outbuffer + offset + 0) = (u_descriptorsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_descriptorsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_descriptorsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_descriptorsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->descriptors[i]);
      }
      *(outbuffer + offset + 0) = (this->confidences_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->confidences_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->confidences_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->confidences_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidences_length);
      for( uint32_t i = 0; i < confidences_length; i++){
      union {
        float real;
        uint32_t base;
      } u_confidencesi;
      u_confidencesi.real = this->confidences[i];
      *(outbuffer + offset + 0) = (u_confidencesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidencesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidencesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidencesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidences[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_descriptor_dim;
      u_descriptor_dim.real = this->descriptor_dim;
      *(outbuffer + offset + 0) = (u_descriptor_dim.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_descriptor_dim.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_descriptor_dim.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_descriptor_dim.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->descriptor_dim);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t lines_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lines_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lines_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lines_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lines_length);
      if(lines_lengthT > lines_length)
        this->lines = (posedetection_msgs::Curve1D*)realloc(this->lines, lines_lengthT * sizeof(posedetection_msgs::Curve1D));
      lines_length = lines_lengthT;
      for( uint32_t i = 0; i < lines_length; i++){
      offset += this->st_lines.deserialize(inbuffer + offset);
        memcpy( &(this->lines[i]), &(this->st_lines), sizeof(posedetection_msgs::Curve1D));
      }
      uint32_t descriptors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      descriptors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      descriptors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      descriptors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->descriptors_length);
      if(descriptors_lengthT > descriptors_length)
        this->descriptors = (float*)realloc(this->descriptors, descriptors_lengthT * sizeof(float));
      descriptors_length = descriptors_lengthT;
      for( uint32_t i = 0; i < descriptors_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_descriptors;
      u_st_descriptors.base = 0;
      u_st_descriptors.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_descriptors.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_descriptors.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_descriptors.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_descriptors = u_st_descriptors.real;
      offset += sizeof(this->st_descriptors);
        memcpy( &(this->descriptors[i]), &(this->st_descriptors), sizeof(float));
      }
      uint32_t confidences_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      confidences_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      confidences_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      confidences_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->confidences_length);
      if(confidences_lengthT > confidences_length)
        this->confidences = (float*)realloc(this->confidences, confidences_lengthT * sizeof(float));
      confidences_length = confidences_lengthT;
      for( uint32_t i = 0; i < confidences_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_confidences;
      u_st_confidences.base = 0;
      u_st_confidences.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_confidences.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_confidences.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_confidences.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_confidences = u_st_confidences.real;
      offset += sizeof(this->st_confidences);
        memcpy( &(this->confidences[i]), &(this->st_confidences), sizeof(float));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_descriptor_dim;
      u_descriptor_dim.base = 0;
      u_descriptor_dim.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_descriptor_dim.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_descriptor_dim.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_descriptor_dim.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->descriptor_dim = u_descriptor_dim.real;
      offset += sizeof(this->descriptor_dim);
     return offset;
    }

    const char * getType(){ return "posedetection_msgs/Feature1D"; };
    const char * getMD5(){ return "4568f21f2dd0840ca2d658d4d1710f33"; };

  };

}
#endif
