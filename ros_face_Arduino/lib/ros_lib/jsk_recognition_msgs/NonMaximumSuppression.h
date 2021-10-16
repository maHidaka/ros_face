#ifndef _ROS_SERVICE_NonMaximumSuppression_h
#define _ROS_SERVICE_NonMaximumSuppression_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_recognition_msgs/Rect.h"

namespace jsk_recognition_msgs
{

static const char NONMAXIMUMSUPPRESSION[] = "jsk_recognition_msgs/NonMaximumSuppression";

  class NonMaximumSuppressionRequest : public ros::Msg
  {
    public:
      uint32_t rect_length;
      typedef jsk_recognition_msgs::Rect _rect_type;
      _rect_type st_rect;
      _rect_type * rect;
      typedef float _threshold_type;
      _threshold_type threshold;

    NonMaximumSuppressionRequest():
      rect_length(0), rect(NULL),
      threshold(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->rect_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rect_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rect_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rect_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rect_length);
      for( uint32_t i = 0; i < rect_length; i++){
      offset += this->rect[i].serialize(outbuffer + offset);
      }
      union {
        float real;
        uint32_t base;
      } u_threshold;
      u_threshold.real = this->threshold;
      *(outbuffer + offset + 0) = (u_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_threshold.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->threshold);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t rect_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      rect_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      rect_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      rect_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->rect_length);
      if(rect_lengthT > rect_length)
        this->rect = (jsk_recognition_msgs::Rect*)realloc(this->rect, rect_lengthT * sizeof(jsk_recognition_msgs::Rect));
      rect_length = rect_lengthT;
      for( uint32_t i = 0; i < rect_length; i++){
      offset += this->st_rect.deserialize(inbuffer + offset);
        memcpy( &(this->rect[i]), &(this->st_rect), sizeof(jsk_recognition_msgs::Rect));
      }
      union {
        float real;
        uint32_t base;
      } u_threshold;
      u_threshold.base = 0;
      u_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->threshold = u_threshold.real;
      offset += sizeof(this->threshold);
     return offset;
    }

    const char * getType(){ return NONMAXIMUMSUPPRESSION; };
    const char * getMD5(){ return "54b7e6632715e9e6592b503a3c881dfc"; };

  };

  class NonMaximumSuppressionResponse : public ros::Msg
  {
    public:
      uint32_t bbox_length;
      typedef jsk_recognition_msgs::Rect _bbox_type;
      _bbox_type st_bbox;
      _bbox_type * bbox;
      typedef int64_t _bbox_count_type;
      _bbox_count_type bbox_count;

    NonMaximumSuppressionResponse():
      bbox_length(0), bbox(NULL),
      bbox_count(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->bbox_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bbox_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bbox_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bbox_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bbox_length);
      for( uint32_t i = 0; i < bbox_length; i++){
      offset += this->bbox[i].serialize(outbuffer + offset);
      }
      union {
        int64_t real;
        uint64_t base;
      } u_bbox_count;
      u_bbox_count.real = this->bbox_count;
      *(outbuffer + offset + 0) = (u_bbox_count.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bbox_count.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bbox_count.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bbox_count.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_bbox_count.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_bbox_count.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_bbox_count.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_bbox_count.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->bbox_count);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t bbox_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      bbox_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      bbox_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      bbox_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->bbox_length);
      if(bbox_lengthT > bbox_length)
        this->bbox = (jsk_recognition_msgs::Rect*)realloc(this->bbox, bbox_lengthT * sizeof(jsk_recognition_msgs::Rect));
      bbox_length = bbox_lengthT;
      for( uint32_t i = 0; i < bbox_length; i++){
      offset += this->st_bbox.deserialize(inbuffer + offset);
        memcpy( &(this->bbox[i]), &(this->st_bbox), sizeof(jsk_recognition_msgs::Rect));
      }
      union {
        int64_t real;
        uint64_t base;
      } u_bbox_count;
      u_bbox_count.base = 0;
      u_bbox_count.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bbox_count.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bbox_count.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bbox_count.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_bbox_count.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_bbox_count.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_bbox_count.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_bbox_count.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->bbox_count = u_bbox_count.real;
      offset += sizeof(this->bbox_count);
     return offset;
    }

    const char * getType(){ return NONMAXIMUMSUPPRESSION; };
    const char * getMD5(){ return "8db21435e67f6d13fc94ccbd355f30f1"; };

  };

  class NonMaximumSuppression {
    public:
    typedef NonMaximumSuppressionRequest Request;
    typedef NonMaximumSuppressionResponse Response;
  };

}
#endif
