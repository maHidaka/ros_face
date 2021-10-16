#ifndef _ROS_actionlib_msgs_GoalStatusArray_h
#define _ROS_actionlib_msgs_GoalStatusArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"

namespace actionlib_msgs
{

  class GoalStatusArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t status_list_length;
      typedef actionlib_msgs::GoalStatus _status_list_type;
      _status_list_type st_status_list;
      _status_list_type * status_list;

    GoalStatusArray():
      header(),
      status_list_length(0), status_list(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->status_list_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->status_list_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->status_list_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->status_list_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->status_list_length);
      for( uint32_t i = 0; i < status_list_length; i++){
      offset += this->status_list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t status_list_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      status_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      status_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      status_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->status_list_length);
      if(status_list_lengthT > status_list_length)
        this->status_list = (actionlib_msgs::GoalStatus*)realloc(this->status_list, status_list_lengthT * sizeof(actionlib_msgs::GoalStatus));
      status_list_length = status_list_lengthT;
      for( uint32_t i = 0; i < status_list_length; i++){
      offset += this->st_status_list.deserialize(inbuffer + offset);
        memcpy( &(this->status_list[i]), &(this->st_status_list), sizeof(actionlib_msgs::GoalStatus));
      }
     return offset;
    }

    const char * getType(){ return "actionlib_msgs/GoalStatusArray"; };
    const char * getMD5(){ return "8b2b82f13216d0a8ea88bd3af735e619"; };

  };

}
#endif
