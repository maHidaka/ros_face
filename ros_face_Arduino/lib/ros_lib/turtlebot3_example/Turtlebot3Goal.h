#ifndef _ROS_turtlebot3_example_Turtlebot3Goal_h
#define _ROS_turtlebot3_example_Turtlebot3Goal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace turtlebot3_example
{

  class Turtlebot3Goal : public ros::Msg
  {
    public:
      typedef geometry_msgs::Vector3 _goal_type;
      _goal_type goal;

    Turtlebot3Goal():
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "turtlebot3_example/Turtlebot3Goal"; };
    const char * getMD5(){ return "8ad3bd0e46ff6777ce7cd2fdd945cb9e"; };

  };

}
#endif
