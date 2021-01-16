#!/usr/bin/env python2

# SPDX-License-Identifier: BSD-2-Clause
#
#    Copyright (C) 2021 Masato Hidaka All right reserved.

import rospy
from std_msgs.msg import String

def face_cmd():
  rospy.init_node('face_cmd')
  pub = rospy.Publisher('face_cmd', String, queue_size=1)
  rate = rospy.Rate(10)
  print('face-control')
  print('control consol') 
  print('--------------')

  while not rospy.is_shutdown():
    key = raw_input()
    
    if key == 'ch0':
      cmd = 'ch0'
    elif key == 'ch1':
      cmd = 'ch1'
    elif key == 'ch2':
      cmd = 'ch2'
    elif key == 'ch3':
      cmd = 'ch3'
    elif key == 'ch4':
      cmd = 'ch4'
    elif key == 'ch5':
      cmd = 'ch5'
    elif key == 'ch6':  
      cmd = 'ch6'
    elif key == 'ch7':  
      cmd = 'ch7'
    elif key == 'a':
      cmd = 'debag_on'
    elif key == 'b':
      cmd = 'debag_off'  
    else:
      cmd = 'stay'
      print('Unknown comand')

    pub.publish(cmd)
    rate.sleep()

if __name__ == '__main__':
  try:
    face_cmd()
  except rospy.ROSInterruptException:
    pass
