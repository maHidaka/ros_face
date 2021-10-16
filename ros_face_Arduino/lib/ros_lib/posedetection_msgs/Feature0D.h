#ifndef _ROS_posedetection_msgs_Feature0D_h
#define _ROS_posedetection_msgs_Feature0D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace posedetection_msgs
{

  class Feature0D : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t positions_length;
      typedef float _positions_type;
      _positions_type st_positions;
      _positions_type * positions;
      uint32_t scales_length;
      typedef float _scales_type;
      _scales_type st_scales;
      _scales_type * scales;
      uint32_t orientations_length;
      typedef float _orientations_type;
      _orientations_type st_orientations;
      _orientations_type * orientations;
      uint32_t confidences_length;
      typedef float _confidences_type;
      _confidences_type st_confidences;
      _confidences_type * confidences;
      uint32_t descriptors_length;
      typedef float _descriptors_type;
      _descriptors_type st_descriptors;
      _descriptors_type * descriptors;
      typedef int32_t _descriptor_dim_type;
      _descriptor_dim_type descriptor_dim;
      typedef const char* _type_type;
      _type_type type;

    Feature0D():
      header(),
      positions_length(0), positions(NULL),
      scales_length(0), scales(NULL),
      orientations_length(0), orientations(NULL),
      confidences_length(0), confidences(NULL),
      descriptors_length(0), descriptors(NULL),
      descriptor_dim(0),
      type("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->positions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->positions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->positions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->positions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->positions_length);
      for( uint32_t i = 0; i < positions_length; i++){
      union {
        float real;
        uint32_t base;
      } u_positionsi;
      u_positionsi.real = this->positions[i];
      *(outbuffer + offset + 0) = (u_positionsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_positionsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_positionsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_positionsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->positions[i]);
      }
      *(outbuffer + offset + 0) = (this->scales_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scales_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->scales_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->scales_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scales_length);
      for( uint32_t i = 0; i < scales_length; i++){
      union {
        float real;
        uint32_t base;
      } u_scalesi;
      u_scalesi.real = this->scales[i];
      *(outbuffer + offset + 0) = (u_scalesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scalesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scalesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scalesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scales[i]);
      }
      *(outbuffer + offset + 0) = (this->orientations_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->orientations_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->orientations_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->orientations_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->orientations_length);
      for( uint32_t i = 0; i < orientations_length; i++){
      union {
        float real;
        uint32_t base;
      } u_orientationsi;
      u_orientationsi.real = this->orientations[i];
      *(outbuffer + offset + 0) = (u_orientationsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_orientationsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_orientationsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_orientationsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->orientations[i]);
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
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t positions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->positions_length);
      if(positions_lengthT > positions_length)
        this->positions = (float*)realloc(this->positions, positions_lengthT * sizeof(float));
      positions_length = positions_lengthT;
      for( uint32_t i = 0; i < positions_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_positions;
      u_st_positions.base = 0;
      u_st_positions.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_positions.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_positions.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_positions.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_positions = u_st_positions.real;
      offset += sizeof(this->st_positions);
        memcpy( &(this->positions[i]), &(this->st_positions), sizeof(float));
      }
      uint32_t scales_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      scales_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      scales_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      scales_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->scales_length);
      if(scales_lengthT > scales_length)
        this->scales = (float*)realloc(this->scales, scales_lengthT * sizeof(float));
      scales_length = scales_lengthT;
      for( uint32_t i = 0; i < scales_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_scales;
      u_st_scales.base = 0;
      u_st_scales.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_scales.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_scales.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_scales.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_scales = u_st_scales.real;
      offset += sizeof(this->st_scales);
        memcpy( &(this->scales[i]), &(this->st_scales), sizeof(float));
      }
      uint32_t orientations_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      orientations_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      orientations_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      orientations_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->orientations_length);
      if(orientations_lengthT > orientations_length)
        this->orientations = (float*)realloc(this->orientations, orientations_lengthT * sizeof(float));
      orientations_length = orientations_lengthT;
      for( uint32_t i = 0; i < orientations_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_orientations;
      u_st_orientations.base = 0;
      u_st_orientations.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_orientations.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_orientations.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_orientations.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_orientations = u_st_orientations.real;
      offset += sizeof(this->st_orientations);
        memcpy( &(this->orientations[i]), &(this->st_orientations), sizeof(float));
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
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
     return offset;
    }

    const char * getType(){ return "posedetection_msgs/Feature0D"; };
    const char * getMD5(){ return "fcb3ba42a42cf972f3838cdb171f5e04"; };

  };

}
#endif
