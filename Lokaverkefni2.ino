
#define motor1_1 3
#define motor1_2 4
#define motor2_1 5
#define motor2_2 6

#define trig 13
#define echo 12

long duration;
long cm=10000;

void setup() {
  // put your setup code here, to run once:
    pinMode ( motor1_1, OUTPUT );
    pinMode ( motor1_2, OUTPUT );
    pinMode ( motor2_1, OUTPUT );
    pinMode ( motor2_2, OUTPUT );
    
    pinMode ( trig, OUTPUT );
    pinMode ( echo, INPUT );

    delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  forward();
  delay(200);
  ultra();
  if ( cm < 20 )
  {
    backward();
    delay(1000);
    right();
    delay(3000);
    left();
    delay(3000);
    stoprun();
    delay(50000);
  }
    
      
  
  
}

void forward()
{
    digitalWrite ( motor1_1, HIGH   );
    digitalWrite ( motor1_2, LOW );
    digitalWrite ( motor2_1, HIGH );
    digitalWrite ( motor2_2, LOW );
}

void backward()
{
    digitalWrite ( motor1_1, LOW   );
    digitalWrite ( motor1_2, HIGH );
    digitalWrite ( motor2_1, LOW );
    digitalWrite ( motor2_2, HIGH );
}


void right()
{
    digitalWrite ( motor1_1, LOW   );
    digitalWrite ( motor1_2, HIGH );
    digitalWrite ( motor2_1, HIGH );
    digitalWrite ( motor2_2, LOW );
}


void left()
{
    digitalWrite ( motor1_1, HIGH   );
    digitalWrite ( motor1_2, LOW );
    digitalWrite ( motor2_1, LOW );
    digitalWrite ( motor2_2, HIGH );
}


void stoprun()
{
    digitalWrite ( motor1_1, LOW   );
    digitalWrite ( motor1_2, LOW );
    digitalWrite ( motor2_1, LOW );
    digitalWrite ( motor2_2, LOW );
}

void ultra()
{
   digitalWrite ( trig , LOW );
   delayMicroseconds(2);
  
   digitalWrite ( trig , HIGH );
   delayMicroseconds(10);
  
   digitalWrite ( trig , LOW );
  
   duration = pulseIn ( echo , HIGH );
  
   cm = duration /29 /2 ;
}
