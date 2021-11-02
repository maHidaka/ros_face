#!/usr/bin/env/ python
# -*- coding: utf-8 -*- 

import rospy
from std_msgs.msg import String
from sensor_msgs.msg import Joy
from ros_face_msgs import FaceCmd

class JoyFace:
    def __init__(self):
        self.joy_sub = rospy.Subscriber("/joy", Joy, self.joy_callback)
        self.face_pub = rospy.Publisher("/face_cmd", FaceCmd, queue_size=1)

    def joy_callback(self, msg):
        if  msg.buttons[0] == 1:
            face_cmd = FaceCmd()
            face_cmd.cmd = "blink_L"
            self.publish_face_cmd(face_cmd)
        if msg.buttons[1] == 1:
            face

        if msg.buttons[2] == 1:

        if msg.buttons[3] == 1:

        if msg.buttons[4] == 1:



    def publish_face_cmd(self, face_cmd):
        self.face_pub.publish(face_cmd)

if __name__ == "__main__":
    rospy.init_node("joy_face")
    joy_face = JoyFace()
    rospy.spin()