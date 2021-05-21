#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "XE1KmPqMA7vcH0oTELBedEE2S_fc3KS6";
char ssid[] = "mecha";
char pass[] = "mechatronic";

int IR_sensor = D1;
int LED = D7;

WidgetLED led1(V2);// Virtual Pin V2
BlynkTimer timer;

void sensor1(){
  int value = digitalRead(IR_sensor);
  if(value == HIGH){
    led1.on();
    digitalWrite(LED,HIGH);
  }
  else{
    led1.off();
    digitalWrite(LED,LOW);
  }  
}
void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(IR_sensor,INPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  timer.setInterval(300L,sensor1);
}

void loop()
{
  Blynk.run();
  timer.run();
}
