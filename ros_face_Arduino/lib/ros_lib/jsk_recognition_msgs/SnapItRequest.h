#ifndef _ROS_jsk_recognition_msgs_SnapItRequest_h
#define _ROS_jsk_recognition_msgs_SnapItRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PolygonStamped.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/Vector3Stamped.h"

namespace jsk_recognition_msgs
{

  class SnapItRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _model_type_type;
      _model_type_type model_type;
      typedef geometry_msgs::PolygonStamped _target_plane_type;
      _target_plane_type target_plane;
      typedef geometry_msgs::PointStamped _center_type;
      _center_type center;
      typedef geometry_msgs::Vector3Stamped _direction_type;
      _direction_type direction;
      typedef float _radius_type;
      _radius_type radius;
      typedef float _height_type;
      _height_type height;
      typedef float _max_distance_type;
      _max_distance_type max_distance;
      typedef float _eps_angle_type;
      _eps_angle_type eps_angle;
      enum { MODEL_PLANE = 0 };
      enum { MODEL_CYLINDER = 1 };

    SnapItRequest():
      header(),
      model_type(0),
      target_plane(),
      center(),
      direction(),
      radius(0),
      height(0),
      max_distance(0),
      eps_angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->model_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->model_type);
      offset += this->target_plane.serialize(outbuffer + offset);
      offset += this->center.serialize(outbuffer + offset);
      offset += this->direction.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->radius);
      offset += serializeAvrFloat64(outbuffer + offset, this->height);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_distance);
      offset += serializeAvrFloat64(outbuffer + offset, this->eps_angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->model_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->model_type);
      offset += this->target_plane.deserialize(inbuffer + offset);
      offset += this->center.deserialize(inbuffer + offset);
      offset += this->direction.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->radius));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->height));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_distance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eps_angle));
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/SnapItRequest"; };
    const char * getMD5(){ return "5733f480694296678d81cff0483b399b"; };

  };

}
#endif
