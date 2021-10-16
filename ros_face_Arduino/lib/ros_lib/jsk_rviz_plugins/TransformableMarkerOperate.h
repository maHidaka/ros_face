#ifndef _ROS_jsk_rviz_plugins_TransformableMarkerOperate_h
#define _ROS_jsk_rviz_plugins_TransformableMarkerOperate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_rviz_plugins
{

  class TransformableMarkerOperate : public ros::Msg
  {
    public:
      typedef int32_t _type_type;
      _type_type type;
      typedef int32_t _action_type;
      _action_type action;
      typedef const char* _frame_id_type;
      _frame_id_type frame_id;
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _description_type;
      _description_type description;
      typedef const char* _mesh_resource_type;
      _mesh_resource_type mesh_resource;
      typedef bool _mesh_use_embedded_materials_type;
      _mesh_use_embedded_materials_type mesh_use_embedded_materials;
      enum { BOX = 0 };
      enum { CYLINDER = 1 };
      enum { TORUS = 2 };
      enum { MESH_RESOURCE = 3 };
      enum { INSERT = 0 };
      enum { ERASE = 1 };
      enum { ERASEALL = 2 };
      enum { ERASEFOCUS = 3 };
      enum { COPY = 4 };

    TransformableMarkerOperate():
      type(0),
      action(0),
      frame_id(""),
      name(""),
      description(""),
      mesh_resource(""),
      mesh_use_embedded_materials(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_action;
      u_action.real = this->action;
      *(outbuffer + offset + 0) = (u_action.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_action.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_action.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_action.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->action);
      uint32_t length_frame_id = strlen(this->frame_id);
      varToArr(outbuffer + offset, length_frame_id);
      offset += 4;
      memcpy(outbuffer + offset, this->frame_id, length_frame_id);
      offset += length_frame_id;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_description = strlen(this->description);
      varToArr(outbuffer + offset, length_description);
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      uint32_t length_mesh_resource = strlen(this->mesh_resource);
      varToArr(outbuffer + offset, length_mesh_resource);
      offset += 4;
      memcpy(outbuffer + offset, this->mesh_resource, length_mesh_resource);
      offset += length_mesh_resource;
      union {
        bool real;
        uint8_t base;
      } u_mesh_use_embedded_materials;
      u_mesh_use_embedded_materials.real = this->mesh_use_embedded_materials;
      *(outbuffer + offset + 0) = (u_mesh_use_embedded_materials.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mesh_use_embedded_materials);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->type = u_type.real;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_action;
      u_action.base = 0;
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->action = u_action.real;
      offset += sizeof(this->action);
      uint32_t length_frame_id;
      arrToVar(length_frame_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame_id-1]=0;
      this->frame_id = (char *)(inbuffer + offset-1);
      offset += length_frame_id;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_description;
      arrToVar(length_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      uint32_t length_mesh_resource;
      arrToVar(length_mesh_resource, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mesh_resource; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mesh_resource-1]=0;
      this->mesh_resource = (char *)(inbuffer + offset-1);
      offset += length_mesh_resource;
      union {
        bool real;
        uint8_t base;
      } u_mesh_use_embedded_materials;
      u_mesh_use_embedded_materials.base = 0;
      u_mesh_use_embedded_materials.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mesh_use_embedded_materials = u_mesh_use_embedded_materials.real;
      offset += sizeof(this->mesh_use_embedded_materials);
     return offset;
    }

    const char * getType(){ return "jsk_rviz_plugins/TransformableMarkerOperate"; };
    const char * getMD5(){ return "3f5042567d7e11634fa94e4b5452169c"; };

  };

}
#endif
