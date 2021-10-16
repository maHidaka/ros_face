#ifndef _ROS_jsk_recognition_msgs_ParallelEdgeArray_h
#define _ROS_jsk_recognition_msgs_ParallelEdgeArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/ParallelEdge.h"

namespace jsk_recognition_msgs
{

  class ParallelEdgeArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t edge_groups_length;
      typedef jsk_recognition_msgs::ParallelEdge _edge_groups_type;
      _edge_groups_type st_edge_groups;
      _edge_groups_type * edge_groups;

    ParallelEdgeArray():
      header(),
      edge_groups_length(0), edge_groups(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->edge_groups_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->edge_groups_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->edge_groups_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->edge_groups_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->edge_groups_length);
      for( uint32_t i = 0; i < edge_groups_length; i++){
      offset += this->edge_groups[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t edge_groups_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      edge_groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      edge_groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      edge_groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->edge_groups_length);
      if(edge_groups_lengthT > edge_groups_length)
        this->edge_groups = (jsk_recognition_msgs::ParallelEdge*)realloc(this->edge_groups, edge_groups_lengthT * sizeof(jsk_recognition_msgs::ParallelEdge));
      edge_groups_length = edge_groups_lengthT;
      for( uint32_t i = 0; i < edge_groups_length; i++){
      offset += this->st_edge_groups.deserialize(inbuffer + offset);
        memcpy( &(this->edge_groups[i]), &(this->st_edge_groups), sizeof(jsk_recognition_msgs::ParallelEdge));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/ParallelEdgeArray"; };
    const char * getMD5(){ return "7c8ef4f5976c55fb32293ceaa19a1189"; };

  };

}
#endif
