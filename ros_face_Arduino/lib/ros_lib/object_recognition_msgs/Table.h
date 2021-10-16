#ifndef _ROS_object_recognition_msgs_Table_h
#define _ROS_object_recognition_msgs_Table_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"

namespace object_recognition_msgs
{

  class Table : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      uint32_t convex_hull_length;
      typedef geometry_msgs::Point _convex_hull_type;
      _convex_hull_type st_convex_hull;
      _convex_hull_type * convex_hull;

    Table():
      header(),
      pose(),
      convex_hull_length(0), convex_hull(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->convex_hull_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->convex_hull_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->convex_hull_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->convex_hull_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->convex_hull_length);
      for( uint32_t i = 0; i < convex_hull_length; i++){
      offset += this->convex_hull[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      uint32_t convex_hull_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      convex_hull_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      convex_hull_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      convex_hull_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->convex_hull_length);
      if(convex_hull_lengthT > convex_hull_length)
        this->convex_hull = (geometry_msgs::Point*)realloc(this->convex_hull, convex_hull_lengthT * sizeof(geometry_msgs::Point));
      convex_hull_length = convex_hull_lengthT;
      for( uint32_t i = 0; i < convex_hull_length; i++){
      offset += this->st_convex_hull.deserialize(inbuffer + offset);
        memcpy( &(this->convex_hull[i]), &(this->st_convex_hull), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "object_recognition_msgs/Table"; };
    const char * getMD5(){ return "39efebc7d51e44bd2d72f2df6c7823a2"; };

  };

}
#endif
