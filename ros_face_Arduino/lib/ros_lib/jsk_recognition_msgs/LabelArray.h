#ifndef _ROS_jsk_recognition_msgs_LabelArray_h
#define _ROS_jsk_recognition_msgs_LabelArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/Label.h"

namespace jsk_recognition_msgs
{

  class LabelArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t labels_length;
      typedef jsk_recognition_msgs::Label _labels_type;
      _labels_type st_labels;
      _labels_type * labels;

    LabelArray():
      header(),
      labels_length(0), labels(NULL)
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
      offset += this->labels[i].serialize(outbuffer + offset);
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
        this->labels = (jsk_recognition_msgs::Label*)realloc(this->labels, labels_lengthT * sizeof(jsk_recognition_msgs::Label));
      labels_length = labels_lengthT;
      for( uint32_t i = 0; i < labels_length; i++){
      offset += this->st_labels.deserialize(inbuffer + offset);
        memcpy( &(this->labels[i]), &(this->st_labels), sizeof(jsk_recognition_msgs::Label));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/LabelArray"; };
    const char * getMD5(){ return "8cdb9aed89bee725ff5ad76b2986927d"; };

  };

}
#endif
