#ifndef _ROS_moveit_msgs_PlanningSceneComponents_h
#define _ROS_moveit_msgs_PlanningSceneComponents_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

  class PlanningSceneComponents : public ros::Msg
  {
    public:
      typedef uint32_t _components_type;
      _components_type components;
      enum { SCENE_SETTINGS = 1 };
      enum { ROBOT_STATE = 2 };
      enum { ROBOT_STATE_ATTACHED_OBJECTS = 4 };
      enum { WORLD_OBJECT_NAMES = 8 };
      enum { WORLD_OBJECT_GEOMETRY = 16 };
      enum { OCTOMAP = 32 };
      enum { TRANSFORMS = 64 };
      enum { ALLOWED_COLLISION_MATRIX = 128 };
      enum { LINK_PADDING_AND_SCALING = 256 };
      enum { OBJECT_COLORS = 512 };

    PlanningSceneComponents():
      components(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->components >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->components >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->components >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->components >> (8 * 3)) & 0xFF;
      offset += sizeof(this->components);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->components =  ((uint32_t) (*(inbuffer + offset)));
      this->components |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->components |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->components |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->components);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PlanningSceneComponents"; };
    const char * getMD5(){ return "bc993e784476960b918b6e7ad5bb58ce"; };

  };

}
#endif
