// Make sure you install the ESP8266 Board Package via the Arduino IDE Board Manager and select the correct ESP8266 board before compiling. 

//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>

// WiFi network info.
char ssid[] = "L......rt";            //Add your home wifi network ssid 
char wifiPassword[] = "Au.......11";   //Add wifi password

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "38.....-7c...11e7-9d..b-f.......de";        //Add your username
char password[] = "f2......44d....................9c8";    //Add your password
char clientID[] = "53....ee0-af12-1...e7-b177-......599";        //Add your clientID

//GPIO pins used to drive relay
const int output1 = 14;           //NodeMCU GPIO14 pin 
const int output2 = 12;           //NodeMCU GPIO12 pin 
const int output3 = 13;           //NodeMCU GPIO13 pin 
const int output4 = 15;           //NodeMCU GPIO15 pin 

//GPIO pin to Test cloud connectivity(Blue Led)
const int cloudTestLed = 5;


void setup() {
  //configure GPIO pins as output
  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(output3, OUTPUT);
  pinMode(output4, OUTPUT);

  //cloud connectivity test Blue LED 
  pinMode(cloudTestLed, OUTPUT);
  
  //Active low pins so 
  digitalWrite(output1, HIGH); 
  digitalWrite(output2, HIGH);
  digitalWrite(output3, HIGH);
  digitalWrite(output4, HIGH);
  Serial.begin(9600);
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
  digitalWrite(cloudTestLed, HIGH);
  delay(500);
  digitalWrite(cloudTestLed, LOW);
  delay(500);
  digitalWrite(cloudTestLed, HIGH);
  delay(500);
  digitalWrite(cloudTestLed, LOW);
  delay(500);
}

void loop() {
  int num;
  Cayenne.loop();
}


CAYENNE_IN(0)
{
  CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());
  //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
  digitalWrite(cloudTestLed, HIGH);
  delay(1000);
  digitalWrite(cloudTestLed, LOW);
  delay(1000);
  digitalWrite(cloudTestLed, HIGH);
  delay(1000);
  digitalWrite(cloudTestLed, LOW);
  delay(1000);
  
}

CAYENNE_IN(1)
{
  CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());
  //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
  if(getValue.asInt()){
      Serial.println("SwitchON 1");
      digitalWrite(output1,0); //Device will be SwitchON since Active low switch
    }
  else {
      Serial.println("SwicthOff 1");
      digitalWrite(output1,1); //Device will be SwicthOff since Active low switch
    }
}

CAYENNE_IN(2)
{
  CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());
  //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
  if(getValue.asInt()){
      Serial.println("SwitchON 2");
      digitalWrite(output2,0); //Device will be SwitchON since Active low switch
    }
  else {
      Serial.println("SwicthOff 2");
      digitalWrite(output2,1); //Device will be SwicthOff since Active low switch
    }
}

CAYENNE_IN(3)
{
  CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());
  //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
  if(getValue.asInt()){
      Serial.println("SwitchON 3");
      digitalWrite(output3,0); //Device will be SwitchON since Active low switch
    }
  else {
      Serial.println("SwicthOff 3");
      digitalWrite(output3,1); //Device will be SwicthOff since Active low switch
    }
}

CAYENNE_IN(4)
{
  CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());
  //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message"); 
  if(getValue.asInt()){
      Serial.println("SwitchON 4");
      digitalWrite(output4,0); //Device will be SwitchON since Active low switch
    }
  else {
      Serial.println("SwicthOff 4");
      digitalWrite(output4,1); //Device will be SwicthOff since Active low switch
    }
}

