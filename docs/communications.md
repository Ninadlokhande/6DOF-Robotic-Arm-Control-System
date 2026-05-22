# Communication System

The robotic arm receives control commands through serial communication.

---

# Serial Communication

## Baud Rate

9600 bps

```cpp
Serial.begin(9600);
```

---

# Command Format

## Single Servo Control

Format:
servoNumber angle

Example:
0 90

Moves Servo 0 to 90°.

---

# Multi-Servo Command

Format:
255 angle

Example:
255 45

Moves all servos to 45° simultaneously.

---

# Serial Parsing Workflow

The firmware:

* receives serial data
* extracts integer values
* validates servo numbers
* validates angles
* executes motion commands

---

# Communication Validation

The firmware validates:

* valid servo IDs
* valid angle ranges
* serial formatting

Invalid commands generate warning messages.

Example:

```cpp
Invalid servo number! Use 0-5 or 255 for all.
```

---

# Bluetooth Expansion

The system architecture supports Bluetooth communication using HC-05 modules for wireless robotic arm control.
