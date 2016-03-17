#include <Bridge.h>
#include <HttpClient.h>

String barcode = "x1234567";
String url = "http://192.168.2.7/Tickets/connection.php?barcode=" + barcode;

void setup() {

  pinMode(13, OUTPUT);  //Initialize pin 13
  SerialUSB.begin(9600);  
  while(!SerialUSB);
  
}

void loop() { 
  
  HttpClient client;
  client.get("http://192.168.2.7/Tickets/connection.php?barcode=x1234567");
  
  SerialUSB.println(url);

  while(client.available()){
    
    String result = (String)client.read();
    
    SerialUSB.println("hola!! " + result);
    delay(10000);
  }
  SerialUSB.flush();
  delay(5000);
  
/*
  if(result.length() > 1){
    Serial.println(result);
  }else{
     if(result == "1"){
        digitalWrite(13, HIGH);
        delay(100000);
     }else{
        digitalWrite(13, LOW);
        delay(100000);
     }
  }*/
  

 /*
  
  exit(0);*/
}
