#ifndef _ROS_SERVICE_MakeNavPlan_h
#define _ROS_SERVICE_MakeNavPlan_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace navfn
{

static const char MAKENAVPLAN[] = "navfn/MakeNavPlan";

  class MakeNavPlanRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _start_type;
      _start_type start;
      typedef geometry_msgs::PoseStamped _goal_type;
      _goal_type goal;

    MakeNavPlanRequest():
      start(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->start.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->start.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return MAKENAVPLAN; };
    const char * getMD5(){ return "2fe3126bd5b2d56edd5005220333d4fd"; };

  };

  class MakeNavPlanResponse : public ros::Msg
  {
    public:
      typedef uint8_t _plan_found_type;
      _plan_found_type plan_found;
      typedef const char* _error_message_type;
      _error_message_type error_message;
      uint32_t path_length;
      typedef geometry_msgs::PoseStamped _path_type;
      _path_type st_path;
      _path_type * path;

    MakeNavPlanResponse():
      plan_found(0),
      error_message(""),
      path_length(0), path(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->plan_found >> (8 * 0)) & 0xFF;
      offset += sizeof(this->plan_found);
      uint32_t length_error_message = strlen(this->error_message);
      varToArr(outbuffer + offset, length_error_message);
      offset += 4;
      memcpy(outbuffer + offset, this->error_message, length_error_message);
      offset += length_error_message;
      *(outbuffer + offset + 0) = (this->path_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->path_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->path_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->path_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->path_length);
      for( uint32_t i = 0; i < path_length; i++){
      offset += this->path[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->plan_found =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->plan_found);
      uint32_t length_error_message;
      arrToVar(length_error_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error_message-1]=0;
      this->error_message = (char *)(inbuffer + offset-1);
      offset += length_error_message;
      uint32_t path_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      path_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      path_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      path_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->path_length);
      if(path_lengthT > path_length)
        this->path = (geometry_msgs::PoseStamped*)realloc(this->path, path_lengthT * sizeof(geometry_msgs::PoseStamped));
      path_length = path_lengthT;
      for( uint32_t i = 0; i < path_length; i++){
      offset += this->st_path.deserialize(inbuffer + offset);
        memcpy( &(this->path[i]), &(this->st_path), sizeof(geometry_msgs::PoseStamped));
      }
     return offset;
    }

    const char * getType(){ return MAKENAVPLAN; };
    const char * getMD5(){ return "8b8ed7edf1b237dc9ddda8c8ffed5d3a"; };

  };

  class MakeNavPlan {
    public:
    typedef MakeNavPlanRequest Request;
    typedef MakeNavPlanResponse Response;
  };

}
#endif
