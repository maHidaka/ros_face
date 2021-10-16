#ifndef _ROS_move_base_msgs_RecoveryStatus_h
#define _ROS_move_base_msgs_RecoveryStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace move_base_msgs
{

  class RecoveryStatus : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _pose_stamped_type;
      _pose_stamped_type pose_stamped;
      typedef uint16_t _current_recovery_number_type;
      _current_recovery_number_type current_recovery_number;
      typedef uint16_t _total_number_of_recoveries_type;
      _total_number_of_recoveries_type total_number_of_recoveries;
      typedef const char* _recovery_behavior_name_type;
      _recovery_behavior_name_type recovery_behavior_name;

    RecoveryStatus():
      pose_stamped(),
      current_recovery_number(0),
      total_number_of_recoveries(0),
      recovery_behavior_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose_stamped.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->current_recovery_number >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_recovery_number >> (8 * 1)) & 0xFF;
      offset += sizeof(this->current_recovery_number);
      *(outbuffer + offset + 0) = (this->total_number_of_recoveries >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->total_number_of_recoveries >> (8 * 1)) & 0xFF;
      offset += sizeof(this->total_number_of_recoveries);
      uint32_t length_recovery_behavior_name = strlen(this->recovery_behavior_name);
      varToArr(outbuffer + offset, length_recovery_behavior_name);
      offset += 4;
      memcpy(outbuffer + offset, this->recovery_behavior_name, length_recovery_behavior_name);
      offset += length_recovery_behavior_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose_stamped.deserialize(inbuffer + offset);
      this->current_recovery_number =  ((uint16_t) (*(inbuffer + offset)));
      this->current_recovery_number |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->current_recovery_number);
      this->total_number_of_recoveries =  ((uint16_t) (*(inbuffer + offset)));
      this->total_number_of_recoveries |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->total_number_of_recoveries);
      uint32_t length_recovery_behavior_name;
      arrToVar(length_recovery_behavior_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_recovery_behavior_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_recovery_behavior_name-1]=0;
      this->recovery_behavior_name = (char *)(inbuffer + offset-1);
      offset += length_recovery_behavior_name;
     return offset;
    }

    const char * getType(){ return "move_base_msgs/RecoveryStatus"; };
    const char * getMD5(){ return "a2488e0805e1529a31044786ee1a2623"; };

  };

}
#endif
