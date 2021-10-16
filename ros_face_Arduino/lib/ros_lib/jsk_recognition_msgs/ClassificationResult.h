#ifndef _ROS_jsk_recognition_msgs_ClassificationResult_h
#define _ROS_jsk_recognition_msgs_ClassificationResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class ClassificationResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t labels_length;
      typedef uint32_t _labels_type;
      _labels_type st_labels;
      _labels_type * labels;
      uint32_t label_names_length;
      typedef char* _label_names_type;
      _label_names_type st_label_names;
      _label_names_type * label_names;
      uint32_t label_proba_length;
      typedef float _label_proba_type;
      _label_proba_type st_label_proba;
      _label_proba_type * label_proba;
      uint32_t probabilities_length;
      typedef float _probabilities_type;
      _probabilities_type st_probabilities;
      _probabilities_type * probabilities;
      typedef const char* _classifier_type;
      _classifier_type classifier;
      uint32_t target_names_length;
      typedef char* _target_names_type;
      _target_names_type st_target_names;
      _target_names_type * target_names;

    ClassificationResult():
      header(),
      labels_length(0), labels(NULL),
      label_names_length(0), label_names(NULL),
      label_proba_length(0), label_proba(NULL),
      probabilities_length(0), probabilities(NULL),
      classifier(""),
      target_names_length(0), target_names(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      *(outbuffer + offset + 0) = (this->label_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->label_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->label_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->label_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->label_names_length);
      for( uint32_t i = 0; i < label_names_length; i++){
      uint32_t length_label_namesi = strlen(this->label_names[i]);
      varToArr(outbuffer + offset, length_label_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->label_names[i], length_label_namesi);
      offset += length_label_namesi;
      }
      *(outbuffer + offset + 0) = (this->label_proba_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->label_proba_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->label_proba_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->label_proba_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->label_proba_length);
      for( uint32_t i = 0; i < label_proba_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->label_proba[i]);
      }
      *(outbuffer + offset + 0) = (this->probabilities_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->probabilities_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->probabilities_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->probabilities_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->probabilities_length);
      for( uint32_t i = 0; i < probabilities_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->probabilities[i]);
      }
      uint32_t length_classifier = strlen(this->classifier);
      varToArr(outbuffer + offset, length_classifier);
      offset += 4;
      memcpy(outbuffer + offset, this->classifier, length_classifier);
      offset += length_classifier;
      *(outbuffer + offset + 0) = (this->target_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->target_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->target_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->target_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_names_length);
      for( uint32_t i = 0; i < target_names_length; i++){
      uint32_t length_target_namesi = strlen(this->target_names[i]);
      varToArr(outbuffer + offset, length_target_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->target_names[i], length_target_namesi);
      offset += length_target_namesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
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
      uint32_t label_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      label_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      label_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      label_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->label_names_length);
      if(label_names_lengthT > label_names_length)
        this->label_names = (char**)realloc(this->label_names, label_names_lengthT * sizeof(char*));
      label_names_length = label_names_lengthT;
      for( uint32_t i = 0; i < label_names_length; i++){
      uint32_t length_st_label_names;
      arrToVar(length_st_label_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_label_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_label_names-1]=0;
      this->st_label_names = (char *)(inbuffer + offset-1);
      offset += length_st_label_names;
        memcpy( &(this->label_names[i]), &(this->st_label_names), sizeof(char*));
      }
      uint32_t label_proba_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      label_proba_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      label_proba_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      label_proba_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->label_proba_length);
      if(label_proba_lengthT > label_proba_length)
        this->label_proba = (float*)realloc(this->label_proba, label_proba_lengthT * sizeof(float));
      label_proba_length = label_proba_lengthT;
      for( uint32_t i = 0; i < label_proba_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_label_proba));
        memcpy( &(this->label_proba[i]), &(this->st_label_proba), sizeof(float));
      }
      uint32_t probabilities_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      probabilities_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      probabilities_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      probabilities_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->probabilities_length);
      if(probabilities_lengthT > probabilities_length)
        this->probabilities = (float*)realloc(this->probabilities, probabilities_lengthT * sizeof(float));
      probabilities_length = probabilities_lengthT;
      for( uint32_t i = 0; i < probabilities_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_probabilities));
        memcpy( &(this->probabilities[i]), &(this->st_probabilities), sizeof(float));
      }
      uint32_t length_classifier;
      arrToVar(length_classifier, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_classifier; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_classifier-1]=0;
      this->classifier = (char *)(inbuffer + offset-1);
      offset += length_classifier;
      uint32_t target_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      target_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      target_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      target_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->target_names_length);
      if(target_names_lengthT > target_names_length)
        this->target_names = (char**)realloc(this->target_names, target_names_lengthT * sizeof(char*));
      target_names_length = target_names_lengthT;
      for( uint32_t i = 0; i < target_names_length; i++){
      uint32_t length_st_target_names;
      arrToVar(length_st_target_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_target_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_target_names-1]=0;
      this->st_target_names = (char *)(inbuffer + offset-1);
      offset += length_st_target_names;
        memcpy( &(this->target_names[i]), &(this->st_target_names), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/ClassificationResult"; };
    const char * getMD5(){ return "cce1f8edabff85a20e9cc013e319497c"; };

  };

}
#endif
