#ifndef _ROS_jsk_footstep_msgs_FootstepArray_h
#define _ROS_jsk_footstep_msgs_FootstepArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_footstep_msgs/Footstep.h"

namespace jsk_footstep_msgs
{

  class FootstepArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t footsteps_length;
      typedef jsk_footstep_msgs::Footstep _footsteps_type;
      _footsteps_type st_footsteps;
      _footsteps_type * footsteps;

    FootstepArray():
      header(),
      footsteps_length(0), footsteps(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->footsteps_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->footsteps_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->footsteps_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->footsteps_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->footsteps_length);
      for( uint32_t i = 0; i < footsteps_length; i++){
      offset += this->footsteps[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t footsteps_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      footsteps_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      footsteps_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      footsteps_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->footsteps_length);
      if(footsteps_lengthT > footsteps_length)
        this->footsteps = (jsk_footstep_msgs::Footstep*)realloc(this->footsteps, footsteps_lengthT * sizeof(jsk_footstep_msgs::Footstep));
      footsteps_length = footsteps_lengthT;
      for( uint32_t i = 0; i < footsteps_length; i++){
      offset += this->st_footsteps.deserialize(inbuffer + offset);
        memcpy( &(this->footsteps[i]), &(this->st_footsteps), sizeof(jsk_footstep_msgs::Footstep));
      }
     return offset;
    }

    const char * getType(){ return "jsk_footstep_msgs/FootstepArray"; };
    const char * getMD5(){ return "385bc396845a4680214262a4679d83b3"; };

  };

}
#endif
