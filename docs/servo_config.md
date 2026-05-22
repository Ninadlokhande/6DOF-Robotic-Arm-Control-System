# Servo Configuration

## Servo Driver

The robotic arm uses the PCA9685 16-channel PWM driver for stable and synchronized servo control.

### PWM Frequency

50 Hz

### Pulse Range

* Minimum Pulse: 150
* Maximum Pulse: 600

These values are mapped to:
0° → 180°

for servo angle positioning.

---

# Servo Allocation

| Servo ID | Joint          | Function              |
| -------- | -------------- | --------------------- |
| Servo 0  | Base           | Horizontal rotation   |
| Servo 1  | Shoulder       | Vertical arm lift     |
| Servo 2  | Elbow          | Arm extension         |
| Servo 3  | Wrist Pitch    | Wrist angle movement  |
| Servo 4  | Wrist Rotation | End-effector rotation |
| Servo 5  | Gripper        | Object gripping       |

---

# Home Position Configuration

The robotic arm initializes to predefined home angles during startup.

```cpp
int homeAngles[NUM_SERVOS] = {60, 0, 140, 160, 60, 45};
```

---

# Servo Motion Workflow

1. Serial command received
2. Servo number parsed
3. Target angle parsed
4. Angle constrained between 0°–180°
5. PWM pulse generated
6. PCA9685 updates servo output

---

# Angle Protection

To prevent invalid motion commands and servo damage:

```cpp
angle = constrain(angle, 0, 180);
```

limits servo motion to safe operating ranges.

---

# PWM Pulse Mapping

Servo angles are converted into PWM pulse widths:

```cpp
int pulse = map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
```

This allows smooth and proportional servo movement.
