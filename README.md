# ROS-Face

## 概要
ROS-Face-driverと通信して簡単な表情筋の操作をテストできるパッケージ

- youtube link

[![](https://i.gyazo.com/028d51303543b1cb5be1388b1f5db8c4.jpg)](https://www.youtube.com/watch?v=7tOlgr7ISOY&feature=youtu.be)

## 動作環境
- OS: Ubuntu 18.04
- ROSディストリビューション: melodic

## 実行方法

パッケージを構築
```
cd ~/catkin_ws/src
git clone https://github.com/maHidaka/ros-face
cd ~/catkin_ws
catkin_make
```
<br>

- ROS-Face-driverをPCに接続する

```
roscore
```
ROS-Face-driverとの接続

```
rosrun rosserial_python serial_node.py /dev/ttyACM0
```
このパッケージの実行
```
rosrun ros-face ros-face.py
```
---
- ch0~7までのコマンドを入力しEnterKeyを押下すると対応するROS-Face-driverのポートから筋電司令パルスが出力される

## ROS-Face-driver
- mbedOS
  - https://os.mbed.com/users/mhdk/code/ROS-Face-driver/

- device 
  - Nucleo f446RE
  
  
- schematic

[![](https://i.gyazo.com/d7a97aa6d9ba32ab8f96a417f3d4521c.png)](/face-driver.pdf)
