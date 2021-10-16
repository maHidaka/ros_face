#ifndef _ROS_jsk_rviz_plugins_OverlayMenu_h
#define _ROS_jsk_rviz_plugins_OverlayMenu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"

namespace jsk_rviz_plugins
{

  class OverlayMenu : public ros::Msg
  {
    public:
      typedef int32_t _action_type;
      _action_type action;
      typedef uint32_t _current_index_type;
      _current_index_type current_index;
      uint32_t menus_length;
      typedef char* _menus_type;
      _menus_type st_menus;
      _menus_type * menus;
      typedef const char* _title_type;
      _title_type title;
      typedef std_msgs::ColorRGBA _bg_color_type;
      _bg_color_type bg_color;
      typedef std_msgs::ColorRGBA _fg_color_type;
      _fg_color_type fg_color;
      enum { ACTION_SELECT = 0 };
      enum { ACTION_CLOSE = 1 };

    OverlayMenu():
      action(0),
      current_index(0),
      menus_length(0), menus(NULL),
      title(""),
      bg_color(),
      fg_color()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_action;
      u_action.real = this->action;
      *(outbuffer + offset + 0) = (u_action.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_action.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_action.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_action.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->action);
      *(outbuffer + offset + 0) = (this->current_index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_index >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->current_index >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->current_index >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_index);
      *(outbuffer + offset + 0) = (this->menus_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->menus_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->menus_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->menus_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->menus_length);
      for( uint32_t i = 0; i < menus_length; i++){
      uint32_t length_menusi = strlen(this->menus[i]);
      varToArr(outbuffer + offset, length_menusi);
      offset += 4;
      memcpy(outbuffer + offset, this->menus[i], length_menusi);
      offset += length_menusi;
      }
      uint32_t length_title = strlen(this->title);
      varToArr(outbuffer + offset, length_title);
      offset += 4;
      memcpy(outbuffer + offset, this->title, length_title);
      offset += length_title;
      offset += this->bg_color.serialize(outbuffer + offset);
      offset += this->fg_color.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_action;
      u_action.base = 0;
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->action = u_action.real;
      offset += sizeof(this->action);
      this->current_index =  ((uint32_t) (*(inbuffer + offset)));
      this->current_index |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->current_index |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->current_index |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->current_index);
      uint32_t menus_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      menus_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      menus_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      menus_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->menus_length);
      if(menus_lengthT > menus_length)
        this->menus = (char**)realloc(this->menus, menus_lengthT * sizeof(char*));
      menus_length = menus_lengthT;
      for( uint32_t i = 0; i < menus_length; i++){
      uint32_t length_st_menus;
      arrToVar(length_st_menus, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_menus; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_menus-1]=0;
      this->st_menus = (char *)(inbuffer + offset-1);
      offset += length_st_menus;
        memcpy( &(this->menus[i]), &(this->st_menus), sizeof(char*));
      }
      uint32_t length_title;
      arrToVar(length_title, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_title; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_title-1]=0;
      this->title = (char *)(inbuffer + offset-1);
      offset += length_title;
      offset += this->bg_color.deserialize(inbuffer + offset);
      offset += this->fg_color.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_rviz_plugins/OverlayMenu"; };
    const char * getMD5(){ return "517426ba068ca022d86cf2c56c98889f"; };

  };

}
#endif
