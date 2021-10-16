#ifndef _ROS_SERVICE_SetLabels_h
#define _ROS_SERVICE_SetLabels_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_recognition_msgs
{

static const char SETLABELS[] = "jsk_recognition_msgs/SetLabels";

  class SetLabelsRequest : public ros::Msg
  {
    public:
      uint32_t labels_length;
      typedef int64_t _labels_type;
      _labels_type st_labels;
      _labels_type * labels;

    SetLabelsRequest():
      labels_length(0), labels(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->labels_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->labels_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->labels_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->labels_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->labels_length);
      for( uint32_t i = 0; i < labels_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_labelsi;
      u_labelsi.real = this->labels[i];
      *(outbuffer + offset + 0) = (u_labelsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_labelsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_labelsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_labelsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_labelsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_labelsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_labelsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_labelsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->labels[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t labels_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      labels_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      labels_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      labels_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->labels_length);
      if(labels_lengthT > labels_length)
        this->labels = (int64_t*)realloc(this->labels, labels_lengthT * sizeof(int64_t));
      labels_length = labels_lengthT;
      for( uint32_t i = 0; i < labels_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_labels;
      u_st_labels.base = 0;
      u_st_labels.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_labels.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_labels.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_labels.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_labels.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_labels.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_labels.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_labels.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_labels = u_st_labels.real;
      offset += sizeof(this->st_labels);
        memcpy( &(this->labels[i]), &(this->st_labels), sizeof(int64_t));
      }
     return offset;
    }

    const char * getType(){ return SETLABELS; };
    const char * getMD5(){ return "59c228f541cab5b727a29411b8f17b33"; };

  };

  class SetLabelsResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SetLabelsResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return SETLABELS; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetLabels {
    public:
    typedef SetLabelsRequest Request;
    typedef SetLabelsResponse Response;
  };

}
#endif
