
#include <PID_v1.h>

double Setpoint ; // POTENCIA establecida
double Input; // Corriente
double Output ; //PWM
//PID parameters
double Kp=0, Ki=10, Kd=0; 
 

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
 
void setup()
{
  
  Serial.begin(9600);   
  //POTENCIA
  Setpoint = 75;
  //Turn the PID on
  myPID.SetMode(AUTOMATIC);
  //Adjust PID values
  myPID.SetTunings(Kp, Ki, Kd);
}
 
void loop()
{
  Input = map(analogRead(5), 0, 1024, 0, 255);  // photo senor is set on analog pin 5
  //PID calculation
  myPID.Compute();
  analogWrite(3,Output); //LED is set to digital 3 this is a pwm pin. 
  Serial.print(Input);
  Serial.print(" ");
  Serial.println(Output);
  Serial.print(" ");  
  Serial.println(Setpoint);
//  delay(100); 
}
