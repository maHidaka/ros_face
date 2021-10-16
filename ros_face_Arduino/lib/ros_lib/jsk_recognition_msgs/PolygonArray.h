#ifndef _ROS_jsk_recognition_msgs_PolygonArray_h
#define _ROS_jsk_recognition_msgs_PolygonArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PolygonStamped.h"

namespace jsk_recognition_msgs
{

  class PolygonArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t polygons_length;
      typedef geometry_msgs::PolygonStamped _polygons_type;
      _polygons_type st_polygons;
      _polygons_type * polygons;
      uint32_t labels_length;
      typedef uint32_t _labels_type;
      _labels_type st_labels;
      _labels_type * labels;
      uint32_t likelihood_length;
      typedef float _likelihood_type;
      _likelihood_type st_likelihood;
      _likelihood_type * likelihood;

    PolygonArray():
      header(),
      polygons_length(0), polygons(NULL),
      labels_length(0), labels(NULL),
      likelihood_length(0), likelihood(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->polygons_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->polygons_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->polygons_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->polygons_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->polygons_length);
      for( uint32_t i = 0; i < polygons_length; i++){
      offset += this->polygons[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->labels_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->labels_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->labels_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->labels_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->labels_length);
      for( uint32_t i = 0; i < labels_length; i++){
      *(outbuffer + offset + 0) = (this->labels[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->labels[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->labels[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->labels[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->labels[i]);
      }
      *(outbuffer + offset + 0) = (this->likelihood_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->likelihood_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->likelihood_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->likelihood_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->likelihood_length);
      for( uint32_t i = 0; i < likelihood_length; i++){
      union {
        float real;
        uint32_t base;
      } u_likelihoodi;
      u_likelihoodi.real = this->likelihood[i];
      *(outbuffer + offset + 0) = (u_likelihoodi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_likelihoodi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_likelihoodi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_likelihoodi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->likelihood[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t polygons_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      polygons_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      polygons_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      polygons_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->polygons_length);
      if(polygons_lengthT > polygons_length)
        this->polygons = (geometry_msgs::PolygonStamped*)realloc(this->polygons, polygons_lengthT * sizeof(geometry_msgs::PolygonStamped));
      polygons_length = polygons_lengthT;
      for( uint32_t i = 0; i < polygons_length; i++){
      offset += this->st_polygons.deserialize(inbuffer + offset);
        memcpy( &(this->polygons[i]), &(this->st_polygons), sizeof(geometry_msgs::PolygonStamped));
      }
      uint32_t labels_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      labels_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      labels_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      labels_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->labels_length);
      if(labels_lengthT > labels_length)
        this->labels = (uint32_t*)realloc(this->labels, labels_lengthT * sizeof(uint32_t));
      labels_length = labels_lengthT;
      for( uint32_t i = 0; i < labels_length; i++){
      this->st_labels =  ((uint32_t) (*(inbuffer + offset)));
      this->st_labels |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_labels |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_labels |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_labels);
        memcpy( &(this->labels[i]), &(this->st_labels), sizeof(uint32_t));
      }
      uint32_t likelihood_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      likelihood_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      likelihood_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      likelihood_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->likelihood_length);
      if(likelihood_lengthT > likelihood_length)
        this->likelihood = (float*)realloc(this->likelihood, likelihood_lengthT * sizeof(float));
      likelihood_length = likelihood_lengthT;
      for( uint32_t i = 0; i < likelihood_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_likelihood;
      u_st_likelihood.base = 0;
      u_st_likelihood.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_likelihood.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_likelihood.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_likelihood.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_likelihood = u_st_likelihood.real;
      offset += sizeof(this->st_likelihood);
        memcpy( &(this->likelihood[i]), &(this->st_likelihood), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/PolygonArray"; };
    const char * getMD5(){ return "709b37d39871cfdbbfbd5c41cf9bc2be"; };

  };

}
#endif
