#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define NUM_SERVOS 6
#define SERVO_MIN 150
#define SERVO_MAX 600

int homeAngles[NUM_SERVOS] = {60, 0, 140, 160, 60, 45};

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);  // 50Hz for servos

  Serial.println("PCA9685 Servo Controller Ready");

  // Move all servos to home at startup
  for (int i = 0; i < NUM_SERVOS; i++) {
    setServoAngle(i, homeAngles[i]);
    Serial.print("Servo #"); Serial.print(i);
    Serial.print(" moved to Home Angle: "); Serial.println(homeAngles[i]);
    delay(200);
  }
}

void loop() {
  if (Serial.available() > 0) {
    int servoNumber = Serial.parseInt(); // read first integer
    int angle = Serial.parseInt();       // read second integer
    // Clear the serial buffer of remaining characters
    while (Serial.available() > 0 && Serial.peek() != '\n') Serial.read();
    Serial.read(); // read newline

    Serial.print("Parsed: Servo "); Serial.print(servoNumber);
    Serial.print(" -> Angle "); Serial.println(angle);

    angle = constrain(angle, 0, 180);

    if (servoNumber == 255) { // all servos
      for (int i = 0; i < NUM_SERVOS; i++) {
        setServoAngle(i, angle);
        Serial.print("Servo #"); Serial.print(i);
        Serial.print(" set to "); Serial.print(angle); Serial.println("°");
      }
    } 
    else if (servoNumber >= 0 && servoNumber < NUM_SERVOS) { // single servo
      setServoAngle(servoNumber, angle);
      Serial.print("Servo #"); Serial.print(servoNumber);
      Serial.print(" set to "); Serial.print(angle); Serial.println("°");
    } 
    else {
      Serial.println("Invalid servo number! Use 0-5 or 255 for all.");
    }
  }
}

void setServoAngle(int servo, int angle) {
  int pulse = map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
  pwm.setPWM(servo, 0, pulse);
}
