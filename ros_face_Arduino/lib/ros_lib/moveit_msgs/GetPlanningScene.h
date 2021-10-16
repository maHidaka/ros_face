#ifndef _ROS_SERVICE_GetPlanningScene_h
#define _ROS_SERVICE_GetPlanningScene_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/PlanningScene.h"
#include "moveit_msgs/PlanningSceneComponents.h"

namespace moveit_msgs
{

static const char GETPLANNINGSCENE[] = "moveit_msgs/GetPlanningScene";

  class GetPlanningSceneRequest : public ros::Msg
  {
    public:
      typedef moveit_msgs::PlanningSceneComponents _components_type;
      _components_type components;

    GetPlanningSceneRequest():
      components()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->components.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->components.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETPLANNINGSCENE; };
    const char * getMD5(){ return "d81da6c0e5e015646a4efe344f33d7dc"; };

  };

  class GetPlanningSceneResponse : public ros::Msg
  {
    public:
      typedef moveit_msgs::PlanningScene _scene_type;
      _scene_type scene;

    GetPlanningSceneResponse():
      scene()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->scene.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->scene.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETPLANNINGSCENE; };
    const char * getMD5(){ return "7bedc4871b1d0af6ec8b8996db347e7f"; };

  };

  class GetPlanningScene {
    public:
    typedef GetPlanningSceneRequest Request;
    typedef GetPlanningSceneResponse Response;
  };

}
#endif
