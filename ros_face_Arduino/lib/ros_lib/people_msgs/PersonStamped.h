#ifndef _ROS_people_msgs_PersonStamped_h
#define _ROS_people_msgs_PersonStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "people_msgs/Person.h"

namespace people_msgs
{

  class PersonStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef people_msgs::Person _person_type;
      _person_type person;

    PersonStamped():
      header(),
      person()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->person.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->person.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "people_msgs/PersonStamped"; };
    const char * getMD5(){ return "4a352a8b709eb9fec941a4f0f42651e7"; };

  };

}
#endif
