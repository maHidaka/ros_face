#ifndef _ROS_geographic_msgs_RouteNetwork_h
#define _ROS_geographic_msgs_RouteNetwork_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "uuid_msgs/UniqueID.h"
#include "geographic_msgs/BoundingBox.h"
#include "geographic_msgs/WayPoint.h"
#include "geographic_msgs/RouteSegment.h"
#include "geographic_msgs/KeyValue.h"

namespace geographic_msgs
{

  class RouteNetwork : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uuid_msgs::UniqueID _id_type;
      _id_type id;
      typedef geographic_msgs::BoundingBox _bounds_type;
      _bounds_type bounds;
      uint32_t points_length;
      typedef geographic_msgs::WayPoint _points_type;
      _points_type st_points;
      _points_type * points;
      uint32_t segments_length;
      typedef geographic_msgs::RouteSegment _segments_type;
      _segments_type st_segments;
      _segments_type * segments;
      uint32_t props_length;
      typedef geographic_msgs::KeyValue _props_type;
      _props_type st_props;
      _props_type * props;

    RouteNetwork():
      header(),
      id(),
      bounds(),
      points_length(0), points(NULL),
      segments_length(0), segments(NULL),
      props_length(0), props(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->id.serialize(outbuffer + offset);
      offset += this->bounds.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
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
      offset += this->id.deserialize(inbuffer + offset);
      offset += this->bounds.deserialize(inbuffer + offset);
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_length);
      if(points_lengthT > points_length)
        this->points = (geographic_msgs::WayPoint*)realloc(this->points, points_lengthT * sizeof(geographic_msgs::WayPoint));
      points_length = points_lengthT;
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(geographic_msgs::WayPoint));
      }
      uint32_t segments_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      segments_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      segments_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      segments_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->segments_length);
      if(segments_lengthT > segments_length)
        this->segments = (geographic_msgs::RouteSegment*)realloc(this->segments, segments_lengthT * sizeof(geographic_msgs::RouteSegment));
      segments_length = segments_lengthT;
      for( uint32_t i = 0; i < segments_length; i++){
      offset += this->st_segments.deserialize(inbuffer + offset);
        memcpy( &(this->segments[i]), &(this->st_segments), sizeof(geographic_msgs::RouteSegment));
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

    const char * getType(){ return "geographic_msgs/RouteNetwork"; };
    const char * getMD5(){ return "fd717c0a34a7c954deed32c6847f30a8"; };

  };

}
#endif
