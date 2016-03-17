#include <Bridge.h>
#include <HttpClient.h>

String barcode = "arduino1";
String url = "http://192.168.2.7/Tickets/connection.php?barcode=" + barcode;
char result = '-1';

void setup() {

  pinMode(13, OUTPUT);  //Initialize pin 13
  Bridge.begin();
  SerialUSB.begin(9600); 
  while(!SerialUSB);
  
}

void loop() { 
  
  HttpClient client;
  client.get(url);

  while(client.available()){
    
    result = client.read();
    SerialUSB.println(result);
    break;
  }
  SerialUSB.flush();
  delay(5000);

  if(result == '1'){
    digitalWrite(13, HIGH);
    delay(5000);
  }else{
    digitalWrite(13, LOW);
    delay(5000);
  }
}
