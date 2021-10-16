#ifndef _ROS_jsk_gui_msgs_VoiceMessage_h
#define _ROS_jsk_gui_msgs_VoiceMessage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_gui_msgs
{

  class VoiceMessage : public ros::Msg
  {
    public:
      uint32_t texts_length;
      typedef char* _texts_type;
      _texts_type st_texts;
      _texts_type * texts;

    VoiceMessage():
      texts_length(0), texts(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->texts_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->texts_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->texts_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->texts_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->texts_length);
      for( uint32_t i = 0; i < texts_length; i++){
      uint32_t length_textsi = strlen(this->texts[i]);
      varToArr(outbuffer + offset, length_textsi);
      offset += 4;
      memcpy(outbuffer + offset, this->texts[i], length_textsi);
      offset += length_textsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t texts_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      texts_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      texts_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      texts_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->texts_length);
      if(texts_lengthT > texts_length)
        this->texts = (char**)realloc(this->texts, texts_lengthT * sizeof(char*));
      texts_length = texts_lengthT;
      for( uint32_t i = 0; i < texts_length; i++){
      uint32_t length_st_texts;
      arrToVar(length_st_texts, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_texts; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_texts-1]=0;
      this->st_texts = (char *)(inbuffer + offset-1);
      offset += length_st_texts;
        memcpy( &(this->texts[i]), &(this->st_texts), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "jsk_gui_msgs/VoiceMessage"; };
    const char * getMD5(){ return "8d7dcfb3b46640ccf02177a3f0cf9530"; };

  };

}
#endif
