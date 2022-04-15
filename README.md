# ROS-Face

ROS-Faceは、rosのシステムを使って人間の表情筋を操作することを目的としたプロジェクトです。
あなたはロボットを操作するときのように、人間の表情をコントロールできます。

# ATTENTION
このプロジェクトに起因するいかなる事故や不利益もmaHidakaは受け付けません。すべて自己責任であることを了承した人のみこのコードの利用をBSD 2-Clause License
の範疇で許可します。

## setup

### install rosserial

事前にrosの環境構築ができている必要があります。
melodicでの動作を確認済みです。他のバージョンでも動くかもしれません。

```
sudo apt install ros-melodic-rosserial-arduino
sudo apt install ros-melodic-rosserial
```


### Upload sketch to Arduino Uno

Main sketch is here "ROS_FACE/ros_face_Arduino/src/main.cpp".

platformioで書き込みます
platformioについてや、ArduinoIDEを使った書き込みについては別サイトの説明をご覧ください。


## Example usage

1. ``` cd catkin_ws/src```
1. ```git clone https://github.com/maHidaka/ros_face.git```
1. ```catkin build```
2. ```roslaunch ros_face_apps face_control_joy.launch```
