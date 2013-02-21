
/*
  Web client
 
 This sketch connects to a website (http://www.google.com)
 using a WiFi shield.
 
 This example is written for a network using WPA encryption. For 
 WEP or WPA, change the Wifi.begin() call accordingly.
 
 This example is written for a network using WPA encryption. For 
 WEP or WPA, change the Wifi.begin() call accordingly.
 
 Circuit:
 * WiFi shield attached
 
 created 13 July 2010
 by dlf (Metodo2 srl)
 modified 31 May 2012
 by Tom Igoe
 */


#include <SPI.h>
#include <WiFi.h>

char ssid[] = "DG860AA2";      //  your network SSID (name)
char pass[] = "DG860A4B83A2";   // your network password

int keyIndex = 0;            // your network key Index number (needed only for WEP)
int inputValueFromServer;
int c = 0;
int status = WL_IDLE_STATUS;
//IPAddress server(128,122,98,50);//itpsandbox
IPAddress server(192,168,0,20); //android's 
WiFiClient client;
float brightness = 0;

//----------------

void setup() {
  
  Serial.begin(9600); 
  while ( status != WL_CONNECTED) { 
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection:
    delay(200);
  } 

  Serial.println("Connected to wifi");
  printWifiStatus();

  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  if (client.connect(server, 23)) {
    Serial.println("connected to server");
  }
}



void loop() {
  
  while (client.available()) {
    Serial.println("connected!");
    c = client.parseInt();
    if(c>900 && c < 2000){
      c=899;
    }
      if( c < 5000 ){
   brightness = map(c,10,900,0,255);
 


  Serial.println(brightness);
 if(brightness<0){brightness=0;}
  analogWrite(3,brightness);
  }
  
  if(c < 0) {
    Serial.println("I miss You!");
    analogWrite(3,0);
    delay(700);
    analogWrite(3,255);
    delay(700);
     analogWrite(3,0);
    delay(700);
    analogWrite(3,255);
    delay(700);
    analogWrite(3,0);
    delay(700);
    analogWrite(3,255);
    delay(700);
  }
    Serial.print("c's value: ");
    Serial.println(c);
  }
 

  if (!client.connected()) {
    Serial.println("disconnecting from server.");
    client.connect(server,23);
  }


}












