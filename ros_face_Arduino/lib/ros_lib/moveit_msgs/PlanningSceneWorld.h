#ifndef _ROS_moveit_msgs_PlanningSceneWorld_h
#define _ROS_moveit_msgs_PlanningSceneWorld_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/CollisionObject.h"
#include "octomap_msgs/OctomapWithPose.h"

namespace moveit_msgs
{

  class PlanningSceneWorld : public ros::Msg
  {
    public:
      uint32_t collision_objects_length;
      typedef moveit_msgs::CollisionObject _collision_objects_type;
      _collision_objects_type st_collision_objects;
      _collision_objects_type * collision_objects;
      typedef octomap_msgs::OctomapWithPose _octomap_type;
      _octomap_type octomap;

    PlanningSceneWorld():
      collision_objects_length(0), collision_objects(NULL),
      octomap()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->collision_objects_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->collision_objects_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->collision_objects_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->collision_objects_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->collision_objects_length);
      for( uint32_t i = 0; i < collision_objects_length; i++){
      offset += this->collision_objects[i].serialize(outbuffer + offset);
      }
      offset += this->octomap.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t collision_objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      collision_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      collision_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      collision_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->collision_objects_length);
      if(collision_objects_lengthT > collision_objects_length)
        this->collision_objects = (moveit_msgs::CollisionObject*)realloc(this->collision_objects, collision_objects_lengthT * sizeof(moveit_msgs::CollisionObject));
      collision_objects_length = collision_objects_lengthT;
      for( uint32_t i = 0; i < collision_objects_length; i++){
      offset += this->st_collision_objects.deserialize(inbuffer + offset);
        memcpy( &(this->collision_objects[i]), &(this->st_collision_objects), sizeof(moveit_msgs::CollisionObject));
      }
      offset += this->octomap.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PlanningSceneWorld"; };
    const char * getMD5(){ return "373d88390d1db385335639f687723ee6"; };

  };

}
#endif
