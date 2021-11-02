#ifndef _ROS_wiimote_State_h
#define _ROS_wiimote_State_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"
#include "wiimote/IrSourceInfo.h"
#include "ros/time.h"

namespace wiimote
{

  class State : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Vector3 _angular_velocity_zeroed_type;
      _angular_velocity_zeroed_type angular_velocity_zeroed;
      typedef geometry_msgs::Vector3 _angular_velocity_raw_type;
      _angular_velocity_raw_type angular_velocity_raw;
      float angular_velocity_covariance[9];
      typedef geometry_msgs::Vector3 _linear_acceleration_zeroed_type;
      _linear_acceleration_zeroed_type linear_acceleration_zeroed;
      typedef geometry_msgs::Vector3 _linear_acceleration_raw_type;
      _linear_acceleration_raw_type linear_acceleration_raw;
      float linear_acceleration_covariance[9];
      typedef geometry_msgs::Vector3 _nunchuk_acceleration_zeroed_type;
      _nunchuk_acceleration_zeroed_type nunchuk_acceleration_zeroed;
      typedef geometry_msgs::Vector3 _nunchuk_acceleration_raw_type;
      _nunchuk_acceleration_raw_type nunchuk_acceleration_raw;
      float nunchuk_joystick_zeroed[2];
      float nunchuk_joystick_raw[2];
      bool buttons[11];
      bool nunchuk_buttons[2];
      bool LEDs[4];
      typedef bool _rumble_type;
      _rumble_type rumble;
      uint32_t ir_tracking_length;
      typedef wiimote::IrSourceInfo _ir_tracking_type;
      _ir_tracking_type st_ir_tracking;
      _ir_tracking_type * ir_tracking;
      typedef float _raw_battery_type;
      _raw_battery_type raw_battery;
      typedef float _percent_battery_type;
      _percent_battery_type percent_battery;
      typedef ros::Time _zeroing_time_type;
      _zeroing_time_type zeroing_time;
      typedef uint64_t _errors_type;
      _errors_type errors;
      enum { INVALID =  -1 };
      enum { INVALID_FLOAT =  -1.0 };
      enum { MSG_BTN_1 =  0 };
      enum { MSG_BTN_2 =  1 };
      enum { MSG_BTN_A =  2 };
      enum { MSG_BTN_B =  3 };
      enum { MSG_BTN_PLUS =  4 };
      enum { MSG_BTN_MINUS =  5 };
      enum { MSG_BTN_LEFT =  6 };
      enum { MSG_BTN_RIGHT =  7 };
      enum { MSG_BTN_UP =  8 };
      enum { MSG_BTN_DOWN =  9 };
      enum { MSG_BTN_HOME =  10 };
      enum { MSG_BTN_Z =  0 };
      enum { MSG_BTN_C =  1 };
      enum { MSG_CLASSIC_BTN_X =  0 };
      enum { MSG_CLASSIC_BTN_Y =  1 };
      enum { MSG_CLASSIC_BTN_A =  2 };
      enum { MSG_CLASSIC_BTN_B =  3 };
      enum { MSG_CLASSIC_BTN_PLUS =  4 };
      enum { MSG_CLASSIC_BTN_MINUS =  5 };
      enum { MSG_CLASSIC_BTN_LEFT =  6 };
      enum { MSG_CLASSIC_BTN_RIGHT =  7 };
      enum { MSG_CLASSIC_BTN_UP =  8 };
      enum { MSG_CLASSIC_BTN_DOWN =  9 };
      enum { MSG_CLASSIC_BTN_HOME =  10 };
      enum { MSG_CLASSIC_BTN_L =  11 };
      enum { MSG_CLASSIC_BTN_R =  12 };
      enum { MSG_CLASSIC_BTN_ZL =  13 };
      enum { MSG_CLASSIC_BTN_ZR =  14 };

    State():
      header(),
      angular_velocity_zeroed(),
      angular_velocity_raw(),
      angular_velocity_covariance(),
      linear_acceleration_zeroed(),
      linear_acceleration_raw(),
      linear_acceleration_covariance(),
      nunchuk_acceleration_zeroed(),
      nunchuk_acceleration_raw(),
      nunchuk_joystick_zeroed(),
      nunchuk_joystick_raw(),
      buttons(),
      nunchuk_buttons(),
      LEDs(),
      rumble(0),
      ir_tracking_length(0), ir_tracking(NULL),
      raw_battery(0),
      percent_battery(0),
      zeroing_time(),
      errors(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->angular_velocity_zeroed.serialize(outbuffer + offset);
      offset += this->angular_velocity_raw.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 9; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->angular_velocity_covariance[i]);
      }
      offset += this->linear_acceleration_zeroed.serialize(outbuffer + offset);
      offset += this->linear_acceleration_raw.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 9; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->linear_acceleration_covariance[i]);
      }
      offset += this->nunchuk_acceleration_zeroed.serialize(outbuffer + offset);
      offset += this->nunchuk_acceleration_raw.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      union {
        float real;
        uint32_t base;
      } u_nunchuk_joystick_zeroedi;
      u_nunchuk_joystick_zeroedi.real = this->nunchuk_joystick_zeroed[i];
      *(outbuffer + offset + 0) = (u_nunchuk_joystick_zeroedi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nunchuk_joystick_zeroedi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nunchuk_joystick_zeroedi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nunchuk_joystick_zeroedi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nunchuk_joystick_zeroed[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      union {
        float real;
        uint32_t base;
      } u_nunchuk_joystick_rawi;
      u_nunchuk_joystick_rawi.real = this->nunchuk_joystick_raw[i];
      *(outbuffer + offset + 0) = (u_nunchuk_joystick_rawi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nunchuk_joystick_rawi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nunchuk_joystick_rawi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nunchuk_joystick_rawi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nunchuk_joystick_raw[i]);
      }
      for( uint32_t i = 0; i < 11; i++){
      union {
        bool real;
        uint8_t base;
      } u_buttonsi;
      u_buttonsi.real = this->buttons[i];
      *(outbuffer + offset + 0) = (u_buttonsi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->buttons[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      union {
        bool real;
        uint8_t base;
      } u_nunchuk_buttonsi;
      u_nunchuk_buttonsi.real = this->nunchuk_buttons[i];
      *(outbuffer + offset + 0) = (u_nunchuk_buttonsi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->nunchuk_buttons[i]);
      }
      for( uint32_t i = 0; i < 4; i++){
      union {
        bool real;
        uint8_t base;
      } u_LEDsi;
      u_LEDsi.real = this->LEDs[i];
      *(outbuffer + offset + 0) = (u_LEDsi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->LEDs[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_rumble;
      u_rumble.real = this->rumble;
      *(outbuffer + offset + 0) = (u_rumble.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rumble);
      *(outbuffer + offset + 0) = (this->ir_tracking_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ir_tracking_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ir_tracking_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ir_tracking_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ir_tracking_length);
      for( uint32_t i = 0; i < ir_tracking_length; i++){
      offset += this->ir_tracking[i].serialize(outbuffer + offset);
      }
      union {
        float real;
        uint32_t base;
      } u_raw_battery;
      u_raw_battery.real = this->raw_battery;
      *(outbuffer + offset + 0) = (u_raw_battery.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_raw_battery.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_raw_battery.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_raw_battery.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->raw_battery);
      union {
        float real;
        uint32_t base;
      } u_percent_battery;
      u_percent_battery.real = this->percent_battery;
      *(outbuffer + offset + 0) = (u_percent_battery.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_percent_battery.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_percent_battery.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_percent_battery.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->percent_battery);
      *(outbuffer + offset + 0) = (this->zeroing_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->zeroing_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->zeroing_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->zeroing_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->zeroing_time.sec);
      *(outbuffer + offset + 0) = (this->zeroing_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->zeroing_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->zeroing_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->zeroing_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->zeroing_time.nsec);
      *(outbuffer + offset + 0) = (this->errors >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->errors >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->errors >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->errors >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->errors >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->errors >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->errors >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->errors >> (8 * 7)) & 0xFF;
      offset += sizeof(this->errors);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->angular_velocity_zeroed.deserialize(inbuffer + offset);
      offset += this->angular_velocity_raw.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 9; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angular_velocity_covariance[i]));
      }
      offset += this->linear_acceleration_zeroed.deserialize(inbuffer + offset);
      offset += this->linear_acceleration_raw.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 9; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->linear_acceleration_covariance[i]));
      }
      offset += this->nunchuk_acceleration_zeroed.deserialize(inbuffer + offset);
      offset += this->nunchuk_acceleration_raw.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      union {
        float real;
        uint32_t base;
      } u_nunchuk_joystick_zeroedi;
      u_nunchuk_joystick_zeroedi.base = 0;
      u_nunchuk_joystick_zeroedi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nunchuk_joystick_zeroedi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nunchuk_joystick_zeroedi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nunchuk_joystick_zeroedi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nunchuk_joystick_zeroed[i] = u_nunchuk_joystick_zeroedi.real;
      offset += sizeof(this->nunchuk_joystick_zeroed[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      union {
        float real;
        uint32_t base;
      } u_nunchuk_joystick_rawi;
      u_nunchuk_joystick_rawi.base = 0;
      u_nunchuk_joystick_rawi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nunchuk_joystick_rawi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nunchuk_joystick_rawi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nunchuk_joystick_rawi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nunchuk_joystick_raw[i] = u_nunchuk_joystick_rawi.real;
      offset += sizeof(this->nunchuk_joystick_raw[i]);
      }
      for( uint32_t i = 0; i < 11; i++){
      union {
        bool real;
        uint8_t base;
      } u_buttonsi;
      u_buttonsi.base = 0;
      u_buttonsi.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->buttons[i] = u_buttonsi.real;
      offset += sizeof(this->buttons[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      union {
        bool real;
        uint8_t base;
      } u_nunchuk_buttonsi;
      u_nunchuk_buttonsi.base = 0;
      u_nunchuk_buttonsi.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->nunchuk_buttons[i] = u_nunchuk_buttonsi.real;
      offset += sizeof(this->nunchuk_buttons[i]);
      }
      for( uint32_t i = 0; i < 4; i++){
      union {
        bool real;
        uint8_t base;
      } u_LEDsi;
      u_LEDsi.base = 0;
      u_LEDsi.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->LEDs[i] = u_LEDsi.real;
      offset += sizeof(this->LEDs[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_rumble;
      u_rumble.base = 0;
      u_rumble.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rumble = u_rumble.real;
      offset += sizeof(this->rumble);
      uint32_t ir_tracking_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ir_tracking_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ir_tracking_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ir_tracking_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ir_tracking_length);
      if(ir_tracking_lengthT > ir_tracking_length)
        this->ir_tracking = (wiimote::IrSourceInfo*)realloc(this->ir_tracking, ir_tracking_lengthT * sizeof(wiimote::IrSourceInfo));
      ir_tracking_length = ir_tracking_lengthT;
      for( uint32_t i = 0; i < ir_tracking_length; i++){
      offset += this->st_ir_tracking.deserialize(inbuffer + offset);
        memcpy( &(this->ir_tracking[i]), &(this->st_ir_tracking), sizeof(wiimote::IrSourceInfo));
      }
      union {
        float real;
        uint32_t base;
      } u_raw_battery;
      u_raw_battery.base = 0;
      u_raw_battery.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_raw_battery.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_raw_battery.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_raw_battery.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->raw_battery = u_raw_battery.real;
      offset += sizeof(this->raw_battery);
      union {
        float real;
        uint32_t base;
      } u_percent_battery;
      u_percent_battery.base = 0;
      u_percent_battery.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_percent_battery.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_percent_battery.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_percent_battery.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->percent_battery = u_percent_battery.real;
      offset += sizeof(this->percent_battery);
      this->zeroing_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->zeroing_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->zeroing_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->zeroing_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->zeroing_time.sec);
      this->zeroing_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->zeroing_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->zeroing_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->zeroing_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->zeroing_time.nsec);
      this->errors =  ((uint64_t) (*(inbuffer + offset)));
      this->errors |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->errors |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->errors |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->errors |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->errors |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->errors |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->errors |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->errors);
     return offset;
    }

    const char * getType(){ return "wiimote/State"; };
    const char * getMD5(){ return "a69651e8129655c6ed3c5039e468362c"; };

  };

}
#endif
