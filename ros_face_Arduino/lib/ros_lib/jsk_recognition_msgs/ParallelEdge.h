#ifndef _ROS_jsk_recognition_msgs_ParallelEdge_h
#define _ROS_jsk_recognition_msgs_ParallelEdge_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pcl_msgs/PointIndices.h"
#include "pcl_msgs/ModelCoefficients.h"

namespace jsk_recognition_msgs
{

  class ParallelEdge : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t cluster_indices_length;
      typedef pcl_msgs::PointIndices _cluster_indices_type;
      _cluster_indices_type st_cluster_indices;
      _cluster_indices_type * cluster_indices;
      uint32_t coefficients_length;
      typedef pcl_msgs::ModelCoefficients _coefficients_type;
      _coefficients_type st_coefficients;
      _coefficients_type * coefficients;

    ParallelEdge():
      header(),
      cluster_indices_length(0), cluster_indices(NULL),
      coefficients_length(0), coefficients(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->cluster_indices_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cluster_indices_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cluster_indices_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cluster_indices_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cluster_indices_length);
      for( uint32_t i = 0; i < cluster_indices_length; i++){
      offset += this->cluster_indices[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->coefficients_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->coefficients_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->coefficients_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->coefficients_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coefficients_length);
      for( uint32_t i = 0; i < coefficients_length; i++){
      offset += this->coefficients[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t cluster_indices_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cluster_indices_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cluster_indices_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cluster_indices_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cluster_indices_length);
      if(cluster_indices_lengthT > cluster_indices_length)
        this->cluster_indices = (pcl_msgs::PointIndices*)realloc(this->cluster_indices, cluster_indices_lengthT * sizeof(pcl_msgs::PointIndices));
      cluster_indices_length = cluster_indices_lengthT;
      for( uint32_t i = 0; i < cluster_indices_length; i++){
      offset += this->st_cluster_indices.deserialize(inbuffer + offset);
        memcpy( &(this->cluster_indices[i]), &(this->st_cluster_indices), sizeof(pcl_msgs::PointIndices));
      }
      uint32_t coefficients_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      coefficients_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      coefficients_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      coefficients_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->coefficients_length);
      if(coefficients_lengthT > coefficients_length)
        this->coefficients = (pcl_msgs::ModelCoefficients*)realloc(this->coefficients, coefficients_lengthT * sizeof(pcl_msgs::ModelCoefficients));
      coefficients_length = coefficients_lengthT;
      for( uint32_t i = 0; i < coefficients_length; i++){
      offset += this->st_coefficients.deserialize(inbuffer + offset);
        memcpy( &(this->coefficients[i]), &(this->st_coefficients), sizeof(pcl_msgs::ModelCoefficients));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/ParallelEdge"; };
    const char * getMD5(){ return "3a550d5b6275fe0a1580ebf8a62dd336"; };

  };

}
#endif
