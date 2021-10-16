#ifndef _ROS_jsk_rviz_plugins_PictogramArray_h
#define _ROS_jsk_rviz_plugins_PictogramArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_rviz_plugins/Pictogram.h"

namespace jsk_rviz_plugins
{

  class PictogramArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t pictograms_length;
      typedef jsk_rviz_plugins::Pictogram _pictograms_type;
      _pictograms_type st_pictograms;
      _pictograms_type * pictograms;

    PictogramArray():
      header(),
      pictograms_length(0), pictograms(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->pictograms_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pictograms_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pictograms_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pictograms_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pictograms_length);
      for( uint32_t i = 0; i < pictograms_length; i++){
      offset += this->pictograms[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t pictograms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pictograms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pictograms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pictograms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pictograms_length);
      if(pictograms_lengthT > pictograms_length)
        this->pictograms = (jsk_rviz_plugins::Pictogram*)realloc(this->pictograms, pictograms_lengthT * sizeof(jsk_rviz_plugins::Pictogram));
      pictograms_length = pictograms_lengthT;
      for( uint32_t i = 0; i < pictograms_length; i++){
      offset += this->st_pictograms.deserialize(inbuffer + offset);
        memcpy( &(this->pictograms[i]), &(this->st_pictograms), sizeof(jsk_rviz_plugins::Pictogram));
      }
     return offset;
    }

    const char * getType(){ return "jsk_rviz_plugins/PictogramArray"; };
    const char * getMD5(){ return "bfdafbfcdf121aed91dae673b47ae3fe"; };

  };

}
#endif
