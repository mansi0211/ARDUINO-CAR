//C code for OBSTACLE AVOIDING ARDUINO CAR
#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>
#define TRIG_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 200 //sets distance
#define MAX_SPEED 500 // sets speed of DC motors

NewPing sonar (TRIG_PIN, ECHO_PIN, MAX_DISTANCE); //Method for Ultrasonic sensor
AF_DCMotor motor1(1, MOTOR12_1KHZ); //Motor1 declaration
AF_DCMotor motor2(2, MOTOR12_1KHZ); //Motot2 declaration
int distance=100; //initial distance int
speedSet = 200; //initial speedSet

void setup() 
{
	distance = readPing(); //reading distance delay(100);
}
void loop() 
{ 
	delay(100);
	if(distance<=25)
	{
		turnRight(); delay(100);
	}
	{
		moveBackward();
	}
	distance = readPing();
}
readPing() //method for reading distance int
{ 
	delay(70); 
	int cm =sonar.ping_cm(); 
	if(cm==0)
	{ 
		cm = 50;
	} 
	return cm; 
}
moveStop() //method to stop the car void
{ 
	int speedSet = 0;
	motor1.run(RELEASE);
	motor2.run(RELEASE);
	motor1.setSpeed(speedSet);
	motor2.setSpeed(speedSet);
}
moveForward() //method to move car forward void
{
	motor1.run(FORWARD);
	motor2.run(FORWARD);
	motor1.setSpeed(speedSet);
	motor2.setSpeed(speedSet);
}
moveBackward() //method to move car backward void
{
	motor1.run(BACKWARD);
	motor2.run(BACKWARD);
	motor1.setSpeed(speedSet);
	motor2.setSpeed(speedSet);
}
turnRight() //method to move car right void
{ 
	int speedSet = 200;
	motor1.run(RELEASE);
	motor2.run(BACKWARD);
	motor2.setSpeed(speedSet);
}
turnLeft() //method to move car left void
{
	int speedSet = 200;
	motor1.run(BACKWARD); 
	motor2.run(RELEASE);
}
