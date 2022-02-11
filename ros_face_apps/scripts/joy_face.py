#!/usr/bin/env python
# -*- coding: utf-8 -*- 

import rospy
import time
from std_msgs.msg import String
from sensor_msgs.msg import Joy
from ros_face_msgs.msg import FaceCmd

class JoyFace:
    def __init__(self):
        self.cmd = FaceCmd()
        self.joy_sub = rospy.Subscriber("/joy", Joy, self.joy_callback)
        self.face_pub = rospy.Publisher("/face_cmd", FaceCmd, queue_size=1)

    def joy_callback(self, msg):
        if msg.buttons[4] == 1:
            self.cmd.ch1.state = True
        else:
            self.cmd.ch1.state = False
        
        if msg.buttons[5] == 1:
            self.cmd.ch2.state = True
        else:
            self.cmd.ch2.state = False

        print("soiya")
        self.publish_cmd(self.cmd)


    def publish_cmd(self, cmd):
        self.face_pub.publish(cmd)

if __name__ == "__main__":
    rospy.init_node("joy_face")
    time.sleep(2.0)
    joy_face = JoyFace()

    while not rospy.is_shutdown():
        rospy.sleep(0.01)