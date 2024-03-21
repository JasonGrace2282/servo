#include <Servo.h>

class Wheel {
  public:
  	int turningPoint;
  	Servo servo;
  
  	void init(int pin, int turning = 93)
    {
      turningPoint = turning;
      
      servo.attach(pin);
      
    } 
  
  	void setSpeed(int speed);
  	void stopSpinning();
};

void Wheel::setSpeed(int speed)
{
  Serial.println(speed);
  speed= -1 * speed + turningPoint;
  if (!(speed>=0 && speed<=180))
  {
    Serial.println("Invalid speed");
    exit(1);
  }
  Serial.println(speed);
  servo.write(speed);
}

void Wheel::stopSpinning()
{
  setSpeed(0);
}

class TwoWheelCar {
  public:
  	Wheel leftWheel;
  	Wheel rightWheel;
  
  	void init(int leftWheelPin, int leftWheelZero, int rightWheelPin, int rightWheelZero)
    {
      leftWheel.init(leftWheelPin, leftWheelZero);
      rightWheel.init(rightWheelPin, rightWheelZero);
    }
  
  	void moveFor(int time, int speed);
  	void turnRightFor(int time, int innerSpeed, int outerSpeed);
  	void turnLeftFor(int time, int innerSpeed, int outerSpeed);
  	void stop();
};

void TwoWheelCar::moveFor(int time, int speed = 1)
{
  rightWheel.setSpeed(speed);
  leftWheel.setSpeed(-1*speed);
  delay(seconds);
}

void TwoWheelCar::turnRightFor(int time, int innerSpeed, int outerSpeed)
{
  leftWheel.setSpeed(-1 * outerSpeed);
  rightWheel.setSpeed(-1 * innerSpeed);
  delay(time);
}

void TwoWheelCar::turnLeftFor(int time, int innerSpeed, int outerSpeed)
{
  leftWheel.setSpeed(outerSpeed);
  rightWheel.setSpeed(innerSpeed);
  delay(time);
}

void TwoWheelCar::stopFor()
{
  leftWheel.stopSpinning();
  rightWheel.stopSpinning();
}
