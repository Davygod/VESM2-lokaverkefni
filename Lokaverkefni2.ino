#include <IRremote.h>
#include <Wire.h>
#include <Servo.h>
Servo myservo; //Create an object for the servo
int val; //Variable for storing servo angle

#define IR_RX_Pin 12
#define SERVO_PIN 3
#define ULTRA_SONIDO_SIG 13

#define MOTOR_1_EN 5
#define MOTOR_1_IN1 7
#define MOTOR_1_IN2 4

#define MOTOR_2_EN 6
#define MOTOR_2_IN3 9
#define MOTOR_2_IN4 8

#define BACKWARD 0
#define FORWARD 1
#define BREAK 2

// Global Variables
Servo servoMotor;
decode_results results;
int state = 0;

void blink()
{
  state = !state;
}

void setup()
{
  //Wire.begin();         // Wire communication begin
  //Wire.begin(4);        // Join i2c bus with address #4
  //Wire.onReceive(receiveEvent); // Register event
  Serial.begin(9600);       // Start serial for output
  //while (!Serial); // Waiting for Serial Monitor
  //Serial.println("\nI2C Scanner");
  myservo.attach(3); //Set digital pin 3 as he command pin for determining the servo angle
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  
  /* Associate Pins */
  servoMotor.attach(SERVO_PIN);
  
  /* Initialize Output Pins */
  pinMode(MOTOR_1_EN,OUTPUT);
  pinMode(MOTOR_1_IN1,OUTPUT);
  pinMode(MOTOR_1_IN2,OUTPUT);
  pinMode(MOTOR_2_EN,OUTPUT);
  pinMode(MOTOR_2_IN3,OUTPUT);
  pinMode(MOTOR_2_IN4,OUTPUT);
  
}

void loop()
{
  //byte error, address; //variable for error and I2C address
  //int nDevices;
  
  //Serial.println("Scanning...");
  
  //nDevices = 0;
  //for (address = 1; address < 127; address++ )
  //{
    // The i2c_scanner uses the return value of
    // the Write.endTransmission to see if
    // a device did acknowledge to the address.
   // Wire.beginTransmission(address);
   // error = Wire.endTransmission();
    
    //if (error == 0)
    //{
     // Serial.print("I2C device found at address 0x");
     // if (address < 16)
      //  Serial.print("0");
    //Serial.print(address, HEX);
      //Serial.println("  !");
     // nDevices++;
   // }
   // else if (error == 2)
    //{
     // Serial.print("Unknown error at address 0x");
     // if (address < 16)
     //   Serial.print("0");
     // Serial.println(address, HEX);
    //}
  digitalWrite(5, HIGH);
  digitalWrite(8, HIGH); 
  val = 0;
  myservo.write(val); //Move the servo (0 degree)
  delay(1500);
  val = 90;
  myservo.write(val); //Move the servo (90 degrees)
  delay(1500);
  }
  //if (nDevices == 0)
   // Serial.println("No I2C devices found\n");
  //else
   // Serial.println("done\n");
  
  //delay(5000); // wait 5 seconds for the next I2C scan
