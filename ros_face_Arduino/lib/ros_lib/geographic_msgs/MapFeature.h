#ifndef _ROS_geographic_msgs_MapFeature_h
#define _ROS_geographic_msgs_MapFeature_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"
#include "geographic_msgs/KeyValue.h"

namespace geographic_msgs
{

  class MapFeature : public ros::Msg
  {
    public:
      typedef uuid_msgs::UniqueID _id_type;
      _id_type id;
      uint32_t components_length;
      typedef uuid_msgs::UniqueID _components_type;
      _components_type st_components;
      _components_type * components;
      uint32_t props_length;
      typedef geographic_msgs::KeyValue _props_type;
      _props_type st_props;
      _props_type * props;

    MapFeature():
      id(),
      components_length(0), components(NULL),
      props_length(0), props(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->id.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->components_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->components_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->components_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->components_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->components_length);
      for( uint32_t i = 0; i < components_length; i++){
      offset += this->components[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->props_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->props_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->props_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->props_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->props_length);
      for( uint32_t i = 0; i < props_length; i++){
      offset += this->props[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->id.deserialize(inbuffer + offset);
      uint32_t components_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      components_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      components_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      components_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->components_length);
      if(components_lengthT > components_length)
        this->components = (uuid_msgs::UniqueID*)realloc(this->components, components_lengthT * sizeof(uuid_msgs::UniqueID));
      components_length = components_lengthT;
      for( uint32_t i = 0; i < components_length; i++){
      offset += this->st_components.deserialize(inbuffer + offset);
        memcpy( &(this->components[i]), &(this->st_components), sizeof(uuid_msgs::UniqueID));
      }
      uint32_t props_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      props_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      props_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      props_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->props_length);
      if(props_lengthT > props_length)
        this->props = (geographic_msgs::KeyValue*)realloc(this->props, props_lengthT * sizeof(geographic_msgs::KeyValue));
      props_length = props_lengthT;
      for( uint32_t i = 0; i < props_length; i++){
      offset += this->st_props.deserialize(inbuffer + offset);
        memcpy( &(this->props[i]), &(this->st_props), sizeof(geographic_msgs::KeyValue));
      }
     return offset;
    }

    const char * getType(){ return "geographic_msgs/MapFeature"; };
    const char * getMD5(){ return "e2505ace5e8da8a15b610eaf62bdefae"; };

  };

}
#endif
