#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiClientSecure.h>

ESP8266WiFiMulti wifiMulti;

const int led = 2;
const int button = 5;
const char* host = "script.google.com";
const int httpsPort = 443;

WiFiClientSecure client;
String script_id = "AKfycbwa4Dw_mqnf3iouEuGyizwLEIur2i9wLa3HhTeePLB_r1Vhbmxm";



void setup(void) {
  Serial.begin(115200);
  Serial.println('\n');

  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(led, HIGH);
  digitalWrite(button, LOW);

  //Serial.println(digitalRead(2));

  int flag1=0;
  flag1=netConnect(); 

  if (flag1 == 1)
  {
    digitalWrite(led, LOW);
    delay(10000);
    digitalWrite(led, HIGH);
  } else
  {
    digitalWrite(led, HIGH);
  }
  //sendData(14, 1);
}
void loop()
{
  int reading = digitalRead(button);
  //Serial.print(reading);
  int a1=0;
  if (reading == HIGH)
  {
    connectivity_check();
    delay(100);
    sendData(113, reading,a1);
  }
  //delay(1000);
  
}

void sendData(int val1, int val2, int val3)
{
  int a1=val3;
  Serial.print("\nConnecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {                               //Connect to the IP address/URL and port specified in the constructor
    Serial.println("\nConnection Failed");
    a1=1;
  } 
  int a = val1;
  int b = val2;
  String url = "/macros/s/" + script_id + "/exec?output1=" + a + "&output2=" + b;
  Serial.print("Requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");                            //Print data to the server that a client is connected to

  if(a1==0){
    Serial.println("Request Sent");
  } else {
     Serial.println("Request Failed");
  }
  while (client.connected()) {
  String line = client.readStringUntil('\n');                         //stream to string untill described character comes
    if (line == "\r") {
      Serial.println("Headers Received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  //Serial.println(line);
  if (line.startsWith("{\"state\":\"success\"")) {
    Serial.println("\nESP8266/Arduino CI successfull!");
  } else {
    Serial.println("\nESP8266/Arduino CI has failed");
  }

  Serial.println("\nClosing Connection");
}

int netConnect()
{
  wifiMulti.addAP("Karan", "karan1234");
  wifiMulti.addAP("Liberin-Technologies", "l!ber!ntech");
  wifiMulti.addAP("liberin", "1122334455");
  
  int flag = 0;
  Serial.println("Connecting...");
  while (wifiMulti.run() != WL_CONNECTED) {
    delay(250);
    Serial.print('.');
  }
  flag = 1;
  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
  return flag;
}

void connectivity_check()
{
  if(wifiMulti.run() == WL_CONNECTED)
  {
    delay(20);
    Serial.print("\nConnected with Server..\n");
    Serial.print("Ready to Upload\n");
  }else{
    Serial.print("\nServer Not Found..");
  }
  
}
