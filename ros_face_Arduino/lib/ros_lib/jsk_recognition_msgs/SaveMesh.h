#ifndef _ROS_SERVICE_SaveMesh_h
#define _ROS_SERVICE_SaveMesh_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_recognition_msgs/BoundingBox.h"

namespace jsk_recognition_msgs
{

static const char SAVEMESH[] = "jsk_recognition_msgs/SaveMesh";

  class SaveMeshRequest : public ros::Msg
  {
    public:
      typedef const char* _ground_frame_id_type;
      _ground_frame_id_type ground_frame_id;
      typedef jsk_recognition_msgs::BoundingBox _box_type;
      _box_type box;

    SaveMeshRequest():
      ground_frame_id(""),
      box()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_ground_frame_id = strlen(this->ground_frame_id);
      varToArr(outbuffer + offset, length_ground_frame_id);
      offset += 4;
      memcpy(outbuffer + offset, this->ground_frame_id, length_ground_frame_id);
      offset += length_ground_frame_id;
      offset += this->box.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_ground_frame_id;
      arrToVar(length_ground_frame_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ground_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ground_frame_id-1]=0;
      this->ground_frame_id = (char *)(inbuffer + offset-1);
      offset += length_ground_frame_id;
      offset += this->box.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SAVEMESH; };
    const char * getMD5(){ return "aedbb75b25dc1f22d6170286e35b1132"; };

  };

  class SaveMeshResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SaveMeshResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return SAVEMESH; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SaveMesh {
    public:
    typedef SaveMeshRequest Request;
    typedef SaveMeshResponse Response;
  };

}
#endif
