# Servo API Rework
Don't like how the normal 0-180 servo system works? Want a simpler way to work with servos?
Copy paste `main.cpp` into your arduino code!

## Demo
```cpp
TwoWheelCar car;

void setup()
{
  // leftWheelPin, zero velocity point for left wheel, rightWheelPin, zero velocity point for right wheel
  car.init(9, 93, 11, 93);
}

void loop()
{
  // move forward for one second
  // at speed 1 (forward/clockwise, very slow)
  // -90 is backward/anticlockwise fast
  car.moveFor(1000, 1);
  // stop for one second
  car.stopFor(1000);
}
```
