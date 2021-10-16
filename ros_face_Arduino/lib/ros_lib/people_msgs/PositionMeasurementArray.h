#ifndef _ROS_people_msgs_PositionMeasurementArray_h
#define _ROS_people_msgs_PositionMeasurementArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "people_msgs/PositionMeasurement.h"

namespace people_msgs
{

  class PositionMeasurementArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t people_length;
      typedef people_msgs::PositionMeasurement _people_type;
      _people_type st_people;
      _people_type * people;
      uint32_t cooccurrence_length;
      typedef float _cooccurrence_type;
      _cooccurrence_type st_cooccurrence;
      _cooccurrence_type * cooccurrence;

    PositionMeasurementArray():
      header(),
      people_length(0), people(NULL),
      cooccurrence_length(0), cooccurrence(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->people_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->people_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->people_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->people_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->people_length);
      for( uint32_t i = 0; i < people_length; i++){
      offset += this->people[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cooccurrence_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cooccurrence_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cooccurrence_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cooccurrence_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cooccurrence_length);
      for( uint32_t i = 0; i < cooccurrence_length; i++){
      union {
        float real;
        uint32_t base;
      } u_cooccurrencei;
      u_cooccurrencei.real = this->cooccurrence[i];
      *(outbuffer + offset + 0) = (u_cooccurrencei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cooccurrencei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cooccurrencei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cooccurrencei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cooccurrence[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t people_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      people_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      people_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      people_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->people_length);
      if(people_lengthT > people_length)
        this->people = (people_msgs::PositionMeasurement*)realloc(this->people, people_lengthT * sizeof(people_msgs::PositionMeasurement));
      people_length = people_lengthT;
      for( uint32_t i = 0; i < people_length; i++){
      offset += this->st_people.deserialize(inbuffer + offset);
        memcpy( &(this->people[i]), &(this->st_people), sizeof(people_msgs::PositionMeasurement));
      }
      uint32_t cooccurrence_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cooccurrence_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cooccurrence_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cooccurrence_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cooccurrence_length);
      if(cooccurrence_lengthT > cooccurrence_length)
        this->cooccurrence = (float*)realloc(this->cooccurrence, cooccurrence_lengthT * sizeof(float));
      cooccurrence_length = cooccurrence_lengthT;
      for( uint32_t i = 0; i < cooccurrence_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_cooccurrence;
      u_st_cooccurrence.base = 0;
      u_st_cooccurrence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_cooccurrence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_cooccurrence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_cooccurrence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_cooccurrence = u_st_cooccurrence.real;
      offset += sizeof(this->st_cooccurrence);
        memcpy( &(this->cooccurrence[i]), &(this->st_cooccurrence), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "people_msgs/PositionMeasurementArray"; };
    const char * getMD5(){ return "59c860d40aa739ec920eb3ad24ae019e"; };

  };

}
#endif
