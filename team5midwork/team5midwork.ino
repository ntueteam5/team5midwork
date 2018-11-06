#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`

SSD1306Wire  display(0x3c, 21, 22);
int freq = 5000;
int ledchannel = 0;
int resolution = 8;
const char* ssid = "dark killer";
const char* password = "0971093999";
char webSite[3000];

WebServer server(80);

const int led[] ={14,15};

void handleRoot() {
  snprintf(webSite,3000,"<!DOCTYPE html><html> <head> <meta charset=\"UTF-8\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>One Click of Fate</title> <style>html{background-color:rgb(255, 255, 255);}body{margin: 50px auto; width: 360px; background-color: rgb(255, 248, 235); border: 2px solid rgb(75, 35, 12);}.title{text-align:center; font-family:微軟正黑體; color:rgb(75, 35, 12); margin-top: 20px; margin-bottom: 20px;}h3{text-align:center; font-family:微軟正黑體; text-decoration: underline; font-size: 24px; color:rgb(75, 35, 12);}a{display:block; text-decoration:none; background-color:#FFFFFF;radius:3px; width:150px; text-align:center; margin:0 auto; margin-bottom:30px; font-size:2em; box-shadow: 0px 3px 6px #000;}.btn1{color:rgb(75, 35, 12); font-family:微軟正黑體;}.btn2{color:rgb(75, 35, 12); font-family:微軟正黑體;}</style> </head> <body> <h1 class=\"title\"><strong>命運的一指<br>One Click of Fate</strong></h1> <h3 class=\"content\">遊戲規則:只能按一下</h3> <hr/> <a class=\"btn1\" href=\"./easy.html\"><strong>Easy</strong></a> <a class=\"btn2\" href=\"./hard.html\"><strong>Hard</strong></a> </body> </html>");
  server.send(200,"text/html",webSite);
  digitalWrite(led[0], 0);
  digitalWrite(led[1], 0);
}

void easy() {
  snprintf(webSite,3000,"<!DOCTYPE html><html> <head> <meta charset=\"UTF-8\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>One Click of Fate</title> <style>html{background-color:#FFFFFF;}body{margin: 50px auto; width: 360px; background-color: rgb(255, 248, 235); border: 2px solid rgb(75, 35, 12);}.title{text-align:center; font-family:微軟正黑體; color:rgb(75, 35, 12); margin-top: 20px; margin-bottom: 20px;}a{display:block; text-decoration:none; background-color:rgb(255, 255, 255); radius:3px; width:50px; text-align:center; margin:10px 10px; margin-bottom:10px; font-size:2em; box-shadow: 0px 3px 6px #000;}.btn1{padding: 0.3em 0.5em; font-size: 1.5em; color:rgb(75, 35, 12);}ul{list-style-type: none; justify-content: center;}.nav-column{display: flex;}.nav-column-item-link{background-color:rgb(255, 240, 224);}</style> </head> <body> <h1 class=\"title\">命運的一指<br>One Click of Fate</h1> <nav class=\"nav\"> <ul class=\"nav-column\"> <li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li><li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li><li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li></ul> </nav> <nav class=\"nav\"> <ul class=\"nav-column\"> <li class=\"nav-column-item\"><a href=\"./lose.html\" class=\"nav-column-item-link\">?</a></li><li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li><li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li></ul> </nav> <nav class=\"nav\"> <ul class=\"nav-column\"> <li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li><li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li><li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li></ul> </nav> </body> </html>");
  server.send(200,"text/html",webSite);
  digitalWrite(led[0], 0);
  digitalWrite(led[1], 0);
}

void hard() {
  snprintf(webSite,3000,"<!DOCTYPE html><html> <head> <meta charset=\"UTF-8\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>One Click of Fate</title> <style>html{background-color:#FFFFFF;}body{margin: 50px auto; width: 360px; background-color: rgb(255, 248, 235); border: 2px solid rgb(75, 35, 12);}.title{text-align:center; font-family:微軟正黑體; color:rgb(75, 35, 12); margin-top: 20px; margin-bottom: 20px;}a{display:block; text-decoration:none; background-color:rgb(255, 255, 255); radius:3px; width:50px; text-align:center; margin:10px 10px; margin-bottom:10px; font-size:2em; box-shadow: 0px 3px 6px #000;}.btn1{padding: 0.3em 0.5em; font-size: 1.5em; color:rgb(75, 35, 12);}ul{list-style-type: none;}.nav-column{justify-content: center; display: flex;}.nav-column-item-link{background-color:rgb(255, 240, 224);}</style> </head> <body> <h1 class=\"title\">命運的一指<br>One Click of Fate</h1> <nav class=\"nav\"> <ul class=\"nav-column\"> <li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li><li class=\"nav-column-item\"><a href=\"./lose.html\" class=\"nav-column-item-link\">?</a></li></nav> <nav class=\"nav\"> <ul class=\"nav-column\"> <li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li><li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li></ul> </nav> </body> </html>");
  server.send(200,"text/html",webSite);
  digitalWrite(led[0], 0);
  digitalWrite(led[1], 0);
}


void ledred(){
   digitalWrite(14,HIGH);
   server.send(200, "text/html", "<!DOCTYPE html><html lang=\"en\"><head> <meta charset=\"UTF-8\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>One Click of Fate</title> <script src=\"https://code.jquery.com/jquery-3.3.1.js\"></script> <script>$(document).ready(function(){$(\"[type=range]\").change(function(){var ledvalue=$(\"#led\").val(); $(\".ledvalue\").text(ledvalue);});}); </script> <style>body{background-color: lightgoldenrodyellow; margin: 50px auto; width: 360px;}h2{text-align:center; font-family:微軟正黑體; font-size: 36px; color:rgb(75, 35, 12); margin-bottom: 12px;}h3{font-size: 28px;}.container{display: flex; flex-direction: column; align-items: center;}a{display:block; text-decoration:none; background-color:#FFFFFF;radius:3px; width:150px;text-align:center; margin:0 auto; margin-bottom:30px; font-size:2em; box-shadow: 0px 3px 6px #000;}.btn1{color:rgb(75, 35, 12); padding: 0.3em 0.5em; font-size: 1.5em; font-family:微軟正黑體;}</style></head><body> <div class=\"container\"> <h2>命運的一指<br>One Click of Fate</h2> <h3>砰!命運之神眷顧你!!!</h3> <br><a class=\"btn1\" href=\"./index.html\"><strong>Back</strong></a> </div></body></html>");
   display.clear();
   int rd;
   rd=analogRead(36);
   Serial.println(rd);
   //rd=map(rd,0,3615,0,255);
   delay(7);
   // Font Demo1
   // create more fonts at http://oleddisplay.squix.ch/
   display.setTextAlignment(TEXT_ALIGN_LEFT);
   display.setFont(ArialMT_Plain_16);
   display.drawString(0, 40, "HAHA!! You lose!!");
  }

  void ledgreen(){
  digitalWrite(15,HIGH);
    server.send(200, "text/html", "<!DOCTYPE html><html lang=\"en\"><head> <meta charset=\"UTF-8\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>One Click of Fate</title> <script src=\"https://code.jquery.com/jquery-3.3.1.js\"></script> <script>$(document).ready(function(){$(\"[type=range]\").change(function(){var ledvalue=$(\"#led\").val(); $(\".ledvalue\").text(ledvalue);});}); </script> <style>body{background-color: lightgoldenrodyellow; margin: 50px auto; width: 360px;}h2{text-align:center; font-family:微軟正黑體; font-size: 36px; color:rgb(75, 35, 12); margin-bottom: 12px;}h3{font-size: 28px;}.container{display: flex; flex-direction: column; align-items: center;}a{display:block; text-decoration:none; background-color:#FFFFFF;radius:3px; width:150px;text-align:center; margin:0 auto; margin-bottom:30px; font-size:2em; box-shadow: 0px 3px 6px #000;}.btn1{color:rgb(75, 35, 12); padding: 0.3em 0.5em; font-size: 1.5em; font-family:微軟正黑體;}</style></head><body> <div class=\"container\"> <h2>命運的一指<br>One Click of Fate</h2> <h3>切!可惡!運氣不錯...</h3> <br><a class=\"btn1\" href=\"./index.html\"><strong>Back</strong></a> </div></body></html>");
    display.clear();
    int rd;
    rd=analogRead(36);
    Serial.println(rd);
    //rd=map(rd,0,3615,0,255);
    delay(7);
    
    // Font Demo1
    // create more fonts at http://oleddisplay.squix.ch/
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 40, "Oh. You win.");
  }

  void ledoff(){
  digitalWrite(15,LOW);
  digitalWrite(14,LOW);
    server.send(200, "text/html", "<!DOCTYPE html><html> <head> <meta charset=\"UTF-8\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>One Click of Fate</title> <style>html{background-color:rgb(255, 255, 255);}body{margin: 50px auto; width: 360px; background-color: rgb(255, 248, 235); border: 2px solid rgb(75, 35, 12);}.title{text-align:center; font-family:微軟正黑體; color:rgb(75, 35, 12); margin-top: 20px; margin-bottom: 20px;}h3{text-align:center; font-family:微軟正黑體; text-decoration: underline; font-size: 24px; color:rgb(75, 35, 12);}a{display:block; text-decoration:none; background-color:#FFFFFF;radius:3px; width:150px; text-align:center; margin:0 auto; margin-bottom:30px; font-size:2em; box-shadow: 0px 3px 6px #000;}.btn1{color:rgb(75, 35, 12); font-family:微軟正黑體;}.btn2{color:rgb(75, 35, 12); font-family:微軟正黑體;}</style> </head> <body> <h1 class=\"title\"><strong>命運的一指<br>One Click of Fate</strong></h1> <h3 class=\"content\">遊戲規則:只能按一下</h3> <hr/> <a class=\"btn1\" href=\"./easy.html\"><strong>Easy</strong></a> <a class=\"btn2\" href=\"./hard.html\"><strong>Hard</strong></a> </body> </html>");
    display.clear();
  }

  void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/html", "File Not Found...");
  digitalWrite(led[0], 0);
  digitalWrite(led[1], 0);
}

void setup() {

  Serial.begin(115200);
  ledcSetup(ledchannel,freq,resolution);
  ledcAttachPin(LED_BUILTIN,ledchannel);

  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  
  /*void drawLoseDemo() {
     display.clear();
     int rd;
     rd=analogRead(36);
     Serial.println(rd);
     //rd=map(rd,0,3615,0,255);
     delay(7);
     // Font Demo1
      // create more fonts at http://oleddisplay.squix.ch/
     display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_30);
      display.drawString(0, 0, "HAHA!! You lose!!");
  }*/

  
  /*void drawWinDemo() {
     display.clear();
     int rd;
     rd=analogRead(36);
     Serial.println(rd);
     //rd=map(rd,0,3615,0,255);
     delay(7);
     // Font Demo1
      // create more fonts at http://oleddisplay.squix.ch/
     display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_30);
      display.drawString(0, 0, "Oh. You win.");
  }*/

  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);

  digitalWrite(led[0], 0);
  digitalWrite(led[1], 0);

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address:");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
    server.on("/easy.html", []() {
  server.send(200, "text/html", "<!DOCTYPE html><html> <head> <meta charset=\"UTF-8\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>One Click of Fate</title> <style>html{background-color:#FFFFFF;}body{margin: 50px auto; width: 360px; background-color: rgb(255, 248, 235); border: 2px solid rgb(75, 35, 12);}.title{text-align:center; font-family:微軟正黑體; color:rgb(75, 35, 12); margin-top: 20px; margin-bottom: 20px;}a{display:block; text-decoration:none; background-color:rgb(255, 255, 255); radius:3px; width:50px; text-align:center; margin:10px 10px; margin-bottom:10px; font-size:2em; box-shadow: 0px 3px 6px #000;}.btn1{padding: 0.3em 0.5em; font-size: 1.5em; color:rgb(75, 35, 12);}ul{list-style-type: none; justify-content: center;}.nav-column{display: flex;}.nav-column-item-link{background-color:rgb(255, 240, 224);}</style> </head> <body> <h1 class=\"title\">命運的一指<br>One Click of Fate</h1> <nav class=\"nav\"> <ul class=\"nav-column\"> <li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li><li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li><li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li></ul> </nav> <nav class=\"nav\"> <ul class=\"nav-column\"> <li class=\"nav-column-item\"><a href=\"./lose.html\" class=\"nav-column-item-link\">?</a></li><li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li><li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li></ul> </nav> <nav class=\"nav\"> <ul class=\"nav-column\"> <li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li><li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li><li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li></ul> </nav> </body> </html>");
  });
    server.on("/hard.html", []() {
  server.send(200, "text/html", "<!DOCTYPE html><html> <head> <meta charset=\"UTF-8\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>One Click of Fate</title> <style>html{background-color:#FFFFFF;}body{margin: 50px auto; width: 360px; background-color: rgb(255, 248, 235); border: 2px solid rgb(75, 35, 12);}.title{text-align:center; font-family:微軟正黑體; color:rgb(75, 35, 12); margin-top: 20px; margin-bottom: 20px;}a{display:block; text-decoration:none; background-color:rgb(255, 255, 255); radius:3px; width:50px; text-align:center; margin:10px 10px; margin-bottom:10px; font-size:2em; box-shadow: 0px 3px 6px #000;}.btn1{padding: 0.3em 0.5em; font-size: 1.5em; color:rgb(75, 35, 12);}ul{list-style-type: none;}.nav-column{justify-content: center; display: flex;}.nav-column-item-link{background-color:rgb(255, 240, 224);}</style> </head> <body> <h1 class=\"title\">命運的一指<br>One Click of Fate</h1> <nav class=\"nav\"> <ul class=\"nav-column\"> <li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li><li class=\"nav-column-item\"><a href=\"./lose.html\" class=\"nav-column-item-link\">?</a></li></nav> <nav class=\"nav\"> <ul class=\"nav-column\"> <li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li><li class=\"nav-column-item\"><a href=\"./win.html\" class=\"nav-column-item-link\">?</a></li></ul> </nav> </body> </html>");
  });
  server.on("/lose.html",ledred);
  server.on("/win.html",ledgreen);
  server.on("/index.html",ledoff);
  server.on("/inline", []() {
  server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.clear();
}

void loop() {
     int rd;
    rd=analogRead(36);
    Serial.println(rd);
    //rd=map(rd,0,3615,0,255);
    delay(7);
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 10, "One Click of Fate  Be Careful");
    display.display();
  server.handleClient();
  
}
