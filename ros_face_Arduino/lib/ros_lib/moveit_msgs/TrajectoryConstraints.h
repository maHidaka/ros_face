#ifndef _ROS_moveit_msgs_TrajectoryConstraints_h
#define _ROS_moveit_msgs_TrajectoryConstraints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/Constraints.h"

namespace moveit_msgs
{

  class TrajectoryConstraints : public ros::Msg
  {
    public:
      uint32_t constraints_length;
      typedef moveit_msgs::Constraints _constraints_type;
      _constraints_type st_constraints;
      _constraints_type * constraints;

    TrajectoryConstraints():
      constraints_length(0), constraints(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->constraints_length);
      for( uint32_t i = 0; i < constraints_length; i++){
      offset += this->constraints[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->constraints_length);
      if(constraints_lengthT > constraints_length)
        this->constraints = (moveit_msgs::Constraints*)realloc(this->constraints, constraints_lengthT * sizeof(moveit_msgs::Constraints));
      constraints_length = constraints_lengthT;
      for( uint32_t i = 0; i < constraints_length; i++){
      offset += this->st_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->constraints[i]), &(this->st_constraints), sizeof(moveit_msgs::Constraints));
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/TrajectoryConstraints"; };
    const char * getMD5(){ return "461e1a732dfebb01e7d6c75d51a51eac"; };

  };

}
#endif
