#include <IRremote.h>

IRrecv ir_recv(10);
decode_results results;

// C++ code
//
void setup()
{
  pinMode(2, OUTPUT);
  ir_recv.enableIRIn();
  Serial.begin(9600);
}

void loop()
{
  
  int cds_sensor_value = 0;
  
  cds_sensor_value = analogRead(A0);
  //Serial.println(cds_sensor_value);
  
  if(ir_recv.decode(&results))
  {
    Serial.println(results.value);
    delay(30)
    ir_recv.resume();
    
    if(results.value==16593103)
    {
      digitalWrite(2, HIGH);
      delay(2000);
    }
    if(results.value==16593103)
    {
      digitalWrite(2, LOW);
    }
    
  }
      
  
 /* if(cds_sensor_value<200)
  {
    digitalWrite(2, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(2, LOW);
  }
  else
  {
    digitalWrite(2, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  }
*/
}