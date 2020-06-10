#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();
#include "ThingSpeak.h"
#include <WiFi.h>

//----------------  Fill in your credentails   ---------------------
char ssid[] = "Galaxy M30s7B81";             // your network SSID (name) 
char pass[] = "1qaz2Wsx";         // your network password
unsigned long myChannelNumber = 1064324;  // Replace the 0 with your channel number
const char * myWriteAPIKey = "2VDR8S4G5BXCD4IO";    // Paste your ThingSpeak Write API Key between the quotes 
//------------------------------------------------------------------

WiFiClient  client;



void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  delay(10);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client); 
}

void loop() {

  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }
  
  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
  // pieces of information in a channel.  Here, we write to field 1.
  int h = 0;


h = hallRead();

  int x = ThingSpeak.writeField(myChannelNumber, 1, h, myWriteAPIKey);
  
  // Check the return code
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
 Serial.print("Hall: ");
    Serial.println(h);
 
 /* h++;
  if(h > 99){
    h = 0;
  }*/
  
  delay(15000); // Wait 15 seconds before sending a new value
}
