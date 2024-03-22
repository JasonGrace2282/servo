#include <Servo.h>

class Wheel {
  public:
  	double turningPoint;
  	Servo servo;
  
  	void init(int pin, double turning = 93.0)
    {
      turningPoint = turning;
      
      servo.attach(pin);
      
    } 
  
  	void setSpeed(double speed);
  	void stopSpinning();
};

void Wheel::setSpeed(double speed)
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
  
  	void moveFor(long time, int speed);
  	void turnRightFor(long time, int innerSpeed, int outerSpeed);
  	void turnLeftFor(long time, int innerSpeed, int outerSpeed);
  	void stopFor(int time);
};

void TwoWheelCar::moveFor(long time, int speed = 1)
{
  rightWheel.setSpeed(speed);
  leftWheel.setSpeed(-1*speed);
  delay(time);
}

void TwoWheelCar::turnRightFor(long time, int innerSpeed, int outerSpeed)
{
  leftWheel.setSpeed(-1 * outerSpeed);
  rightWheel.setSpeed(-1 * innerSpeed);
  delay(time);
}

void TwoWheelCar::turnLeftFor(long time, int innerSpeed, int outerSpeed)
{
  leftWheel.setSpeed(outerSpeed);
  rightWheel.setSpeed(innerSpeed);
  delay(time);
}

void TwoWheelCar::stopFor(int time)
{
  leftWheel.stopSpinning();
  rightWheel.stopSpinning();
  delay(time);
}
