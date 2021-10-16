#ifndef _ROS_moveit_msgs_AttachedCollisionObject_h
#define _ROS_moveit_msgs_AttachedCollisionObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/CollisionObject.h"
#include "trajectory_msgs/JointTrajectory.h"

namespace moveit_msgs
{

  class AttachedCollisionObject : public ros::Msg
  {
    public:
      typedef const char* _link_name_type;
      _link_name_type link_name;
      typedef moveit_msgs::CollisionObject _object_type;
      _object_type object;
      uint32_t touch_links_length;
      typedef char* _touch_links_type;
      _touch_links_type st_touch_links;
      _touch_links_type * touch_links;
      typedef trajectory_msgs::JointTrajectory _detach_posture_type;
      _detach_posture_type detach_posture;
      typedef float _weight_type;
      _weight_type weight;

    AttachedCollisionObject():
      link_name(""),
      object(),
      touch_links_length(0), touch_links(NULL),
      detach_posture(),
      weight(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_link_name = strlen(this->link_name);
      varToArr(outbuffer + offset, length_link_name);
      offset += 4;
      memcpy(outbuffer + offset, this->link_name, length_link_name);
      offset += length_link_name;
      offset += this->object.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->touch_links_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->touch_links_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->touch_links_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->touch_links_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->touch_links_length);
      for( uint32_t i = 0; i < touch_links_length; i++){
      uint32_t length_touch_linksi = strlen(this->touch_links[i]);
      varToArr(outbuffer + offset, length_touch_linksi);
      offset += 4;
      memcpy(outbuffer + offset, this->touch_links[i], length_touch_linksi);
      offset += length_touch_linksi;
      }
      offset += this->detach_posture.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->weight);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_link_name;
      arrToVar(length_link_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_name-1]=0;
      this->link_name = (char *)(inbuffer + offset-1);
      offset += length_link_name;
      offset += this->object.deserialize(inbuffer + offset);
      uint32_t touch_links_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      touch_links_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      touch_links_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      touch_links_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->touch_links_length);
      if(touch_links_lengthT > touch_links_length)
        this->touch_links = (char**)realloc(this->touch_links, touch_links_lengthT * sizeof(char*));
      touch_links_length = touch_links_lengthT;
      for( uint32_t i = 0; i < touch_links_length; i++){
      uint32_t length_st_touch_links;
      arrToVar(length_st_touch_links, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_touch_links; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_touch_links-1]=0;
      this->st_touch_links = (char *)(inbuffer + offset-1);
      offset += length_st_touch_links;
        memcpy( &(this->touch_links[i]), &(this->st_touch_links), sizeof(char*));
      }
      offset += this->detach_posture.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->weight));
     return offset;
    }

    const char * getType(){ return "moveit_msgs/AttachedCollisionObject"; };
    const char * getMD5(){ return "3ceac60b21e85bbd6c5b0ab9d476b752"; };

  };

}
#endif
