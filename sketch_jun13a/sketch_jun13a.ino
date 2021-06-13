//6Jw595YzlCe2DxJ6jAnp6VlCxAUuxT4Hqm04dN8C85Y
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
//#include <DHT.h>
#include <TridentTD_LineNotify.h>

const int buttonPin = D2;

//#define DHTTYPE DHT11
//#define DHTPIN  2

// 修改成上述寄到登入郵箱的 Token號碼
#define LINE_TOKEN "6Jw595YzlCe2DxJ6jAnp6VlCxAUuxT4Hqm04dN8C85Y"

// 設定無線基地台SSID跟密碼
const char* ssid     = "WIFI151_SmartHome";
const char* password = "062145983";
int buttonState = 0;
//DHT dht(DHTPIN, DHTTYPE, 11);    // 11 works fine for ESP8266
 
//float humidity, temp_f;   // 從 DHT-11 讀取的值

//unsigned long previousMillis = 0;        // will store last temp was read
//const long interval = 2000;              // interval at which to read sensor

// 用不到以下兩個變數
// const char* host = "notify-api.line.me";
// const int httpsPort = 443;
 
void setup(void)
{
  //Serial.begin(9600);  // 設定速率 感測器
  //dht.begin();           // 初始化
  pinMode(buttonPin, INPUT);
  
  WiFi.mode(WIFI_STA);
  // 連接無線基地台
  WiFi.begin(ssid, password);
  Serial.print("\n\r \n\rWorking to connect");

  // 等待連線，並從 Console顯示 IP
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  //Serial.println("DHT Weather Reading Server");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
 
void loop(void)
{
  // 顯示 Line版本
  Serial.println(LINE.getVersion());
 
  LINE.setToken(LINE_TOKEN);

  // 先換行再顯示
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    // turn LED on:
    Serial.print("Good");
  } else {
    // turn LED off:
    LINE.notify("\n 緊急按鈕按下" );
  }    
  // 每1秒發送一次
  delay(5000);
}
