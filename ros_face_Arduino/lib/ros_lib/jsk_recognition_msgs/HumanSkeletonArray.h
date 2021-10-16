#ifndef _ROS_jsk_recognition_msgs_HumanSkeletonArray_h
#define _ROS_jsk_recognition_msgs_HumanSkeletonArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/Int32.h"
#include "jsk_recognition_msgs/HumanSkeleton.h"

namespace jsk_recognition_msgs
{

  class HumanSkeletonArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t human_ids_length;
      typedef std_msgs::Int32 _human_ids_type;
      _human_ids_type st_human_ids;
      _human_ids_type * human_ids;
      uint32_t skeletons_length;
      typedef jsk_recognition_msgs::HumanSkeleton _skeletons_type;
      _skeletons_type st_skeletons;
      _skeletons_type * skeletons;

    HumanSkeletonArray():
      header(),
      human_ids_length(0), human_ids(NULL),
      skeletons_length(0), skeletons(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->human_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->human_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->human_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->human_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->human_ids_length);
      for( uint32_t i = 0; i < human_ids_length; i++){
      offset += this->human_ids[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->skeletons_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->skeletons_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->skeletons_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->skeletons_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->skeletons_length);
      for( uint32_t i = 0; i < skeletons_length; i++){
      offset += this->skeletons[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t human_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      human_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      human_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      human_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->human_ids_length);
      if(human_ids_lengthT > human_ids_length)
        this->human_ids = (std_msgs::Int32*)realloc(this->human_ids, human_ids_lengthT * sizeof(std_msgs::Int32));
      human_ids_length = human_ids_lengthT;
      for( uint32_t i = 0; i < human_ids_length; i++){
      offset += this->st_human_ids.deserialize(inbuffer + offset);
        memcpy( &(this->human_ids[i]), &(this->st_human_ids), sizeof(std_msgs::Int32));
      }
      uint32_t skeletons_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      skeletons_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      skeletons_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      skeletons_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->skeletons_length);
      if(skeletons_lengthT > skeletons_length)
        this->skeletons = (jsk_recognition_msgs::HumanSkeleton*)realloc(this->skeletons, skeletons_lengthT * sizeof(jsk_recognition_msgs::HumanSkeleton));
      skeletons_length = skeletons_lengthT;
      for( uint32_t i = 0; i < skeletons_length; i++){
      offset += this->st_skeletons.deserialize(inbuffer + offset);
        memcpy( &(this->skeletons[i]), &(this->st_skeletons), sizeof(jsk_recognition_msgs::HumanSkeleton));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/HumanSkeletonArray"; };
    const char * getMD5(){ return "4013ce44abe9aafa9055e095797a9d50"; };

  };

}
#endif
