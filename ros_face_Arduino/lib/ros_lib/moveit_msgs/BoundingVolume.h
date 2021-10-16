#ifndef _ROS_moveit_msgs_BoundingVolume_h
#define _ROS_moveit_msgs_BoundingVolume_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "shape_msgs/SolidPrimitive.h"
#include "geometry_msgs/Pose.h"
#include "shape_msgs/Mesh.h"

namespace moveit_msgs
{

  class BoundingVolume : public ros::Msg
  {
    public:
      uint32_t primitives_length;
      typedef shape_msgs::SolidPrimitive _primitives_type;
      _primitives_type st_primitives;
      _primitives_type * primitives;
      uint32_t primitive_poses_length;
      typedef geometry_msgs::Pose _primitive_poses_type;
      _primitive_poses_type st_primitive_poses;
      _primitive_poses_type * primitive_poses;
      uint32_t meshes_length;
      typedef shape_msgs::Mesh _meshes_type;
      _meshes_type st_meshes;
      _meshes_type * meshes;
      uint32_t mesh_poses_length;
      typedef geometry_msgs::Pose _mesh_poses_type;
      _mesh_poses_type st_mesh_poses;
      _mesh_poses_type * mesh_poses;

    BoundingVolume():
      primitives_length(0), primitives(NULL),
      primitive_poses_length(0), primitive_poses(NULL),
      meshes_length(0), meshes(NULL),
      mesh_poses_length(0), mesh_poses(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->primitives_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->primitives_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->primitives_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->primitives_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->primitives_length);
      for( uint32_t i = 0; i < primitives_length; i++){
      offset += this->primitives[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->primitive_poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->primitive_poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->primitive_poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->primitive_poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->primitive_poses_length);
      for( uint32_t i = 0; i < primitive_poses_length; i++){
      offset += this->primitive_poses[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->meshes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->meshes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->meshes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->meshes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->meshes_length);
      for( uint32_t i = 0; i < meshes_length; i++){
      offset += this->meshes[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->mesh_poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mesh_poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mesh_poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mesh_poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mesh_poses_length);
      for( uint32_t i = 0; i < mesh_poses_length; i++){
      offset += this->mesh_poses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t primitives_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      primitives_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      primitives_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      primitives_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->primitives_length);
      if(primitives_lengthT > primitives_length)
        this->primitives = (shape_msgs::SolidPrimitive*)realloc(this->primitives, primitives_lengthT * sizeof(shape_msgs::SolidPrimitive));
      primitives_length = primitives_lengthT;
      for( uint32_t i = 0; i < primitives_length; i++){
      offset += this->st_primitives.deserialize(inbuffer + offset);
        memcpy( &(this->primitives[i]), &(this->st_primitives), sizeof(shape_msgs::SolidPrimitive));
      }
      uint32_t primitive_poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      primitive_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      primitive_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      primitive_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->primitive_poses_length);
      if(primitive_poses_lengthT > primitive_poses_length)
        this->primitive_poses = (geometry_msgs::Pose*)realloc(this->primitive_poses, primitive_poses_lengthT * sizeof(geometry_msgs::Pose));
      primitive_poses_length = primitive_poses_lengthT;
      for( uint32_t i = 0; i < primitive_poses_length; i++){
      offset += this->st_primitive_poses.deserialize(inbuffer + offset);
        memcpy( &(this->primitive_poses[i]), &(this->st_primitive_poses), sizeof(geometry_msgs::Pose));
      }
      uint32_t meshes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      meshes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      meshes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      meshes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->meshes_length);
      if(meshes_lengthT > meshes_length)
        this->meshes = (shape_msgs::Mesh*)realloc(this->meshes, meshes_lengthT * sizeof(shape_msgs::Mesh));
      meshes_length = meshes_lengthT;
      for( uint32_t i = 0; i < meshes_length; i++){
      offset += this->st_meshes.deserialize(inbuffer + offset);
        memcpy( &(this->meshes[i]), &(this->st_meshes), sizeof(shape_msgs::Mesh));
      }
      uint32_t mesh_poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      mesh_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      mesh_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      mesh_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->mesh_poses_length);
      if(mesh_poses_lengthT > mesh_poses_length)
        this->mesh_poses = (geometry_msgs::Pose*)realloc(this->mesh_poses, mesh_poses_lengthT * sizeof(geometry_msgs::Pose));
      mesh_poses_length = mesh_poses_lengthT;
      for( uint32_t i = 0; i < mesh_poses_length; i++){
      offset += this->st_mesh_poses.deserialize(inbuffer + offset);
        memcpy( &(this->mesh_poses[i]), &(this->st_mesh_poses), sizeof(geometry_msgs::Pose));
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/BoundingVolume"; };
    const char * getMD5(){ return "22db94010f39e9198032cb4a1aeda26e"; };

  };

}
#endif
