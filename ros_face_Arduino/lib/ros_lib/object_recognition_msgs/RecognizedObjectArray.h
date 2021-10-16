#ifndef _ROS_object_recognition_msgs_RecognizedObjectArray_h
#define _ROS_object_recognition_msgs_RecognizedObjectArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "object_recognition_msgs/RecognizedObject.h"

namespace object_recognition_msgs
{

  class RecognizedObjectArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t objects_length;
      typedef object_recognition_msgs::RecognizedObject _objects_type;
      _objects_type st_objects;
      _objects_type * objects;
      uint32_t cooccurrence_length;
      typedef float _cooccurrence_type;
      _cooccurrence_type st_cooccurrence;
      _cooccurrence_type * cooccurrence;

    RecognizedObjectArray():
      header(),
      objects_length(0), objects(NULL),
      cooccurrence_length(0), cooccurrence(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->objects_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->objects_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->objects_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->objects_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->objects_length);
      for( uint32_t i = 0; i < objects_length; i++){
      offset += this->objects[i].serialize(outbuffer + offset);
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
      uint32_t objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->objects_length);
      if(objects_lengthT > objects_length)
        this->objects = (object_recognition_msgs::RecognizedObject*)realloc(this->objects, objects_lengthT * sizeof(object_recognition_msgs::RecognizedObject));
      objects_length = objects_lengthT;
      for( uint32_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(object_recognition_msgs::RecognizedObject));
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

    const char * getType(){ return "object_recognition_msgs/RecognizedObjectArray"; };
    const char * getMD5(){ return "bad6b1546b9ebcabb49fb3b858d78964"; };

  };

}
#endif
