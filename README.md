# 6DOF Robotic Arm Control System

A 6-degree-of-freedom robotic arm designed for embedded motion control, multi-servo coordination, and robotic manipulation experiments using Arduino and the PCA9685 PWM servo controller.

The project implements:

* 6-axis robotic arm control
* PCA9685-based PWM servo driving
* Real-time serial communication
* Embedded servo coordination
* Home-position initialization
* Scalable robotic motion architecture

This project focuses on practical robotics, embedded systems, and robotic arm control workflows for automation and manipulation applications.

---

# Features

* 6-DOF robotic arm
* Multi-servo coordinated movement
* PCA9685 PWM servo controller
* Serial-command based control
* Home-position initialization
* Angle constraint protection
* Embedded motion control
* Real-time servo actuation
* Expandable control architecture

---

# Hardware Components

## Controller

* Arduino Uno

## Servo Driver

* PCA9685 16-channel PWM driver

## Actuators

* 6 Servo Motors

## Power System

* External servo power supply

## Communication

* USB Serial Communication
* Bluetooth module (HC-05)

---

# Software & Firmware

## Technologies Used

* Arduino C++
* Wire Library
* Adafruit PWM Servo Driver Library

## Functionalities

* Individual servo control
* Simultaneous multi-servo positioning
* Home-angle initialization
* Real-time serial command parsing
* PWM pulse mapping
* Servo angle constraints

---

# System Architecture

The Arduino communicates with the PCA9685 PWM driver using the I2C protocol.

The PCA9685 generates stable PWM signals for controlling all servo motors independently while reducing direct PWM load on the microcontroller.

The robotic arm receives commands through serial communication and translates them into servo angle movements.

---

# Servo Configuration

| Servo   | Function       |
| ------- | -------------- |
| Servo 0 | Base Rotation  |
| Servo 1 | Shoulder Joint |
| Servo 2 | Elbow Joint    |
| Servo 3 | Wrist Pitch    |
| Servo 4 | Wrist Rotation |
| Servo 5 | Gripper        |

---

# Home Position Angles

| Servo   | Home Angle |
| ------- | ---------- |
| Servo 0 | 60°        |
| Servo 1 | 0°         |
| Servo 2 | 140°       |
| Servo 3 | 160°       |
| Servo 4 | 60°        |
| Servo 5 | 45°        |

---

# Serial Command Format

## Single Servo Control

servoNumber angle

Example:
0 90

Moves Servo 0 to 90°.

---

## Control All Servos

255 angle

Example:
255 45

Moves all servos to 45°.

---

# Code Features

## PWM Servo Mapping

The firmware converts servo angles into PWM pulse values for accurate positioning using the PCA9685 driver.

## Angle Constraints

Servo angles are constrained between:
0° to 180°

to prevent invalid movement commands.

## Home Initialization

All servos automatically move to predefined home positions during startup.

---

# Project Images

## Hardware Setup

(Add image here)

## Robotic Arm Assembly

(Add image here)

## Servo Driver Connections

(Add image here)

---

# Future Improvements

* Inverse kinematics implementation
* Bluetooth app control
* ROS integration
* Object detection using OpenCV
* AI-assisted motion planning
* Path interpolation
* Joystick control
* Web dashboard control

---

# Author

Ninad Lokhande

GitHub:
https://github.com/Ninadlokhande/6DOF-Robotic-Arm-Control-System
