#ifndef _ROS_geographic_msgs_RoutePath_h
#define _ROS_geographic_msgs_RoutePath_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "uuid_msgs/UniqueID.h"
#include "geographic_msgs/KeyValue.h"

namespace geographic_msgs
{

  class RoutePath : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uuid_msgs::UniqueID _network_type;
      _network_type network;
      uint32_t segments_length;
      typedef uuid_msgs::UniqueID _segments_type;
      _segments_type st_segments;
      _segments_type * segments;
      uint32_t props_length;
      typedef geographic_msgs::KeyValue _props_type;
      _props_type st_props;
      _props_type * props;

    RoutePath():
      header(),
      network(),
      segments_length(0), segments(NULL),
      props_length(0), props(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->network.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->segments_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->segments_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->segments_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->segments_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->segments_length);
      for( uint32_t i = 0; i < segments_length; i++){
      offset += this->segments[i].serialize(outbuffer + offset);
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
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->network.deserialize(inbuffer + offset);
      uint32_t segments_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      segments_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      segments_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      segments_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->segments_length);
      if(segments_lengthT > segments_length)
        this->segments = (uuid_msgs::UniqueID*)realloc(this->segments, segments_lengthT * sizeof(uuid_msgs::UniqueID));
      segments_length = segments_lengthT;
      for( uint32_t i = 0; i < segments_length; i++){
      offset += this->st_segments.deserialize(inbuffer + offset);
        memcpy( &(this->segments[i]), &(this->st_segments), sizeof(uuid_msgs::UniqueID));
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

    const char * getType(){ return "geographic_msgs/RoutePath"; };
    const char * getMD5(){ return "0aa2dd809a8091bdb4466dfefecbb8cf"; };

  };

}
#endif
