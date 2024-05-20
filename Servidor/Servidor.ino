#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "Dados.h"

const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(80);

const char indexHTML[] PROGMEM = "<!DOCTYPE html><html lang=\"pt-br\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>Trunfo</title><link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap@4.6.2/dist/css/bootstrap.min.css\"><script src=\"https://cdn.jsdelivr.net/npm/jquery@3.5.1/dist/jquery.slim.min.js\"></script><script src=\"https://cdn.jsdelivr.net/npm/bootstrap@4.6.2/dist/js/bootstrap.bundle.min.js\"></script><style>body {background-color: #888888;}img {max-width: 100%;}</style></head><body><div class=\"container my-3\"><div class=\"row\"><div class=\"col-md-6 offset-md-3\"><div class=\"card shadow mb-3\"><div class=\"card-body text-center\"><img src=\"https://apolo1401.github.io/TrunfoPixar/Trunfo%20da%20Pixar.png\" /></div></div><div class=\"card shadow\"><div class=\"card-body\"><div class=\"form-group\"><label for=\"carta1\">Carta 1</label><select class=\"form-control\" id=\"carta1\"><option>1a</option><option>2a</option><option>3a</option><option>4a</option><option>5a</option><option>6a</option><option>7a</option><option>8a</option><option>1b</option><option>2b</option><option>3b</option><option>4b</option><option>5b</option><option>6b</option><option>7b</option><option>8b</option><option>1c</option><option>2c</option><option>3c</option><option>4c</option><option>5c</option><option>6c</option><option>7c</option><option>8c</option><option>1d</option><option>2d</option><option>3d</option><option>4d</option><option>5d</option><option>6d</option><option>7d</option><option>8d</option></select></div><div class=\"form-group\"><label for=\"carta2\">Carta 2</label><select class=\"form-control\" id=\"carta2\"><option>1a</option><option>2a</option><option>3a</option><option>4a</option><option>5a</option><option>6a</option><option>7a</option><option>8a</option><option>1b</option><option>2b</option><option>3b</option><option>4b</option><option>5b</option><option>6b</option><option>7b</option><option>8b</option><option>1c</option><option>2c</option><option>3c</option><option>4c</option><option>5c</option><option>6c</option><option>7c</option><option>8c</option><option>1d</option><option>2d</option><option>3d</option><option>4d</option><option>5d</option><option>6d</option><option>7d</option><option>8d</option></select></div><div class=\"form-group\"><label for=\"atributo\">Atributo</label><select class=\"form-control\" id=\"atributo\"><option value=\"pf\">Primeiro Filme</option><option value=\"he\">he</option><option value=\"hf\">hf</option><option value=\"fo\">fo</option><option value=\"in\">in</option></select></div><button type=\"button\" class=\"btn btn-primary btn-block\" onclick=\"calcular()\">Calcular!</button></div></div></div></div></div><script>\"use strict\"; function calcular() {let c1 = document.getElementById(\"carta1\").value;let c2 = document.getElementById(\"carta2\").value;let atr = document.getElementById(\"atributo\").value;let vencedor = \"empate\";if (c1 == \"1b\") {if (c2 == \"1a\" || c2 == \"2a\" || c2 == \"3a\" || c2 == \"4a\" || c2 == \"5a\" || c2 == \"6a\" || c2 == \"7a\" || c2 == \"8a\") {vencedor = \"carta2\";} else {vencedor = \"carta1\";}} else if (c2 == \"1b\") {if (c1 == \"1a\" || c1 == \"2a\" || c1 == \"3a\" || c1 == \"4a\" || c1 == \"5a\" || c1 == \"6a\" || c1 == \"7a\" || c1 == \"8a\") {vencedor = \"carta1\";} else {vencedor = \"carta2\";}} else {let v1 = 0;let v2 = 0;let pf1 = 0;let he1 = 0;let hf1 = 0;let fo1 = 0;let in1 = 0;let pf2 = 0;let he2 = 0;let hf2 = 0;let fo2 = 0;let in2 = 0;if (c1 == \"1a\") {pf1 = 2004;he1 = 8;hf1 = 2;fo1 = 66;in1 = 69;} else if (c1 == \"2a\") {pf1 = 1995;he1 = 3;hf1 = 2;fo1 = 55;in1 = 30;} else if (c1 == \"3a\") {pf1 = 2004;he1 = 9;hf1 = 3;fo1 = 94;in1 = 46;} else if (c1 == \"4a\") {pf1 = 2003;he1 = 3;hf1 = 2;fo1 = 76;in1 = 31;} else if (c1 == \"5a\") {pf1 = 1995;he1 = 9;hf1 = 5;fo1 = 30;in1 = 58;} else if (c1 == \"6a\") {pf1 = 2001;he1 = 1;hf1 = 2;fo1 = 72;in1 = 70;} else if (c1 == \"7a\") {pf1 = 2006;he1 = 6;hf1 = 3;fo1 = 68;in1 = 71;} else if (c1 == \"8a\") {pf1 = 2003;he1 = 8;hf1 = 2;fo1 = 20;in1 = 56;} else if (c1 == \"2b\") {pf1 = 2003;he1 = 7;hf1 = 3;fo1 = 23;in1 = 26;} else if (c1 == \"3b\") {pf1 = 2006;he1 = 7;hf1 = 2;fo1 = 77;in1 = 73;} else if (c1 == \"4b\") {pf1 = 2003;he1 = 5;hf1 = 5;fo1 = 14;in1 = 50;} else if (c1 == \"5b\") {pf1 = 2006;he1 = 8;hf1 = 5;fo1 = 70;in1 = 60;} else if (c1 == \"6b\") {pf1 = 2001;he1 = 3;hf1 = 2;fo1 = 44;in1 = 20;} else if (c1 == \"7b\") {pf1 = 2006;he1 = 7;hf1 = 5;fo1 = 80;in1 = 43;} else if (c1 == \"8b\") {pf1 = 2001;he1 = 7;hf1 = 4;fo1 = 69;in1 = 65;} else if (c1 == \"1c\") {pf1 = 2008;he1 = 6;hf1 = 3;fo1 = 61;in1 = 70;} else if (c1 == \"2c\") {pf1 = 2001;he1 = 9;hf1 = 5;fo1 = 99;in1 = 48;} else if (c1 == \"3c\") {pf1 = 2008;he1 = 8;hf1 = 4;fo1 = 50;in1 = 64;} else if (c1 == \"4c\") {pf1 = 2004;he1 = 7;hf1 = 3;fo1 = 54;in1 = 59;} else if (c1 == \"5c\") {pf1 = 1995;he1 = 4;hf1 = 2;fo1 = 25;in1 = 40;} else if (c1 == \"6c\") {pf1 = 2004;he1 = 6;hf1 = 3;fo1 = 56;in1 = 63;} else if (c1 == \"7c\") {pf1 = 2012;he1 = 9;hf1 = 4;fo1 = 60;in1 = 55;} else if (c1 == \"8c\") {pf1 = 1999;he1 = 7;hf1 = 4;fo1 = 30;in1 = 55;} else if (c1 == \"1d\") {pf1 = 2009;he1 = 5;hf1 = 2;fo1 = 58;in1 = 50;} else if (c1 == \"2d\") {pf1 = 2009;he1 = 5;hf1 = 2;fo1 = 55;in1 = 40;} else if (c1 == \"3d\") {pf1 = 2012;he1 = 4;hf1 = 2;fo1 = 40;in1 = 20;} else if (c1 == \"4d\") {pf1 = 2016;he1 = 4;hf1 = 3;fo1 = 30;in1 = 60;} else if (c1 == \"5d\") {pf1 = 2015;he1 = 2;hf1 = 3;fo1 = 5;in1 = 45;} else if (c1 == \"6d\") {pf1 = 2015;he1 = 4;hf1 = 3;fo1 = 6;in1 = 55;} else if (c1 == \"7d\") {pf1 = 2015;he1 = 7;hf1 = 4;fo1 = 7;in1 = 45;} else if (c1 == \"8d\") {pf1 = 2019;he1 = 5;hf1 = 4;fo1 = 25;in1 = 33;}if (c2 == \"1a\") {pf2 = 2004;he2 = 8;hf2 = 2;fo2 = 66;in2 = 69;} else if (c2 == \"2a\") {pf2 = 1995;he2 = 3;hf2 = 2;fo2 = 55;in2 = 30;} else if (c2 == \"3a\") {pf2 = 2004;he2 = 9;hf2 = 3;fo2 = 94;in2 = 46;} else if (c2 == \"4a\") {pf2 = 2003;he2 = 3;hf2 = 2;fo2 = 76;in2 = 31;} else if (c2 == \"5a\") {pf2 = 1995;he2 = 9;hf2 = 5;fo2 = 30;in2 = 58;} else if (c2 == \"6a\") {pf2 = 2001;he2 = 1;hf2 = 2;fo2 = 72;in2 = 70;} else if (c2 == \"7a\") {pf2 = 2006;he2 = 6;hf2 = 3;fo2 = 68;in2 = 71;} else if (c2 == \"8a\") {pf2 = 2003;he2 = 8;hf2 = 2;fo2 = 20;in2 = 56;} else if (c2 == \"2b\") {pf2 = 2003;he2 = 7;hf2 = 3;fo2 = 23;in2 = 26;} else if (c2 == \"3b\") {pf2 = 2006;he2 = 7;hf2 = 2;fo2 = 77;in2 = 73;} else if (c2 == \"4b\") {pf2 = 2003;he2 = 5;hf2 = 5;fo2 = 14;in2 = 50;} else if (c2 == \"5b\") {pf2 = 2006;he2 = 8;hf2 = 5;fo2 = 70;in2 = 60;} else if (c2 == \"6b\") {pf2 = 2001;he2 = 3;hf2 = 2;fo2 = 44;in2 = 20;} else if (c2 == \"7b\") {pf2 = 2006;he2 = 7;hf2 = 5;fo2 = 80;in2 = 43;} else if (c2 == \"8b\") {pf2 = 2001;he2 = 7;hf2 = 4;fo2 = 69;in2 = 65;} else if (c2 == \"1c\") {pf2 = 2008;he2 = 6;hf2 = 3;fo2 = 61;in2 = 70;} else if (c2 == \"2c\") {pf2 = 2001;he2 = 9;hf2 = 5;fo2 = 99;in2 = 48;} else if (c2 == \"3c\") {pf2 = 2008;he2 = 8;hf2 = 4;fo2 = 50;in2 = 64;} else if (c2 == \"4c\") {pf2 = 2004;he2 = 7;hf2 = 3;fo2 = 54;in2 = 59;} else if (c2 == \"5c\") {pf2 = 1995;he2 = 4;hf2 = 2;fo2 = 25;in2 = 40;} else if (c2 == \"6c\") {pf2 = 2004;he2 = 6;hf2 = 3;fo2 = 56;in2 = 63;} else if (c2 == \"7c\") {pf2 = 2012;he2 = 9;hf2 = 4;fo2 = 60;in2 = 55;} else if (c2 == \"8c\") {pf2 = 1999;he2 = 7;hf2 = 4;fo2 = 30;in2 = 55;} else if (c2 == \"1d\") {pf2 = 2009;he2 = 5;hf2 = 2;fo2 = 58;in2 = 50;} else if (c2 == \"2d\") {pf2 = 2009;he2 = 5;hf2 = 2;fo2 = 55;in2 = 40;} else if (c2 == \"3d\") {pf2 = 2012;he2 = 4;hf2 = 2;fo2 = 40;in2 = 20;} else if (c2 == \"4d\") {pf2 = 2016;he2 = 4;hf2 = 3;fo2 = 30;in2 = 60;} else if (c2 == \"5d\") {pf2 = 2015;he2 = 2;hf2 = 3;fo2 = 5;in2 = 45;} else if (c2 == \"6d\") {pf2 = 2015;he2 = 4;hf2 = 3;fo2 = 6;in2 = 55;} else if (c2 == \"7d\") {pf2 = 2015;he2 = 7;hf2 = 4;fo2 = 7;in2 = 45;} else if (c2 == \"8d\") {pf2 = 2019;he2 = 5;hf2 = 4;fo2 = 25;in2 = 33;}if (atr == \"pf\") {if (pf1 > pf2) {vencedor = \"carta1\";} else if (pf1 < pf2) {vencedor = \"carta2\";} else {vencedor = \"empate\";}} else if (atr == \"he\") {if (he1 > he2) {vencedor = \"carta1\";} else if (he1 < he2) {vencedor = \"carta2\";} else {vencedor = \"empate\";}} else if (atr == \"hf\") {if (hf1 > hf2) {vencedor = \"carta1\";} else if (hf1 < hf2) {vencedor = \"carta2\";} else {vencedor = \"empate\";}} else if (atr == \"fo\") {if (fo1 > fo2) {vencedor = \"carta1\";} else if (fo1 < fo2) {vencedor = \"carta2\";} else {vencedor = \"empate\";}} else if (atr == \"in\") {if (in1 > in2) {vencedor = \"carta1\";} else if (in1 < in2) {vencedor = \"carta2\";} else {vencedor = \"empate\";}}}location.href = \"/\" + vencedor;}</script></body></html>";

void enviarIndex() {
  server.send(200, "text/html", indexHTML);
}

void enviarEmpate() {
  Serial.println("Empate");
  for (int i = 0; i < 10; i++) {
    digitalWrite(D3, 1);
    digitalWrite(D4, 1);
    delay(100);
    digitalWrite(D3, 0);
    digitalWrite(D4, 0);
    delay(100);
  }
  enviarIndex();
}

void enviarCarta1() {
  Serial.println("Carta 1");
  for (int i = 0; i < 10; i++) {
    digitalWrite(D3, 1);
    delay(100);
    digitalWrite(D3, 0);
    delay(100);
  }
  enviarIndex();
}

void enviarCarta2() {
  Serial.println("Carta 2");
  for (int i = 0; i < 10; i++) {
    digitalWrite(D4, 1);
    delay(100);
    digitalWrite(D4, 0);
    delay(100);
  }
  enviarIndex();
}

void setup() {
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

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
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) { Serial.println("MDNS responder started"); }

  server.on("/", enviarIndex);
  server.on("/empate", enviarEmpate);
  server.on("/carta1", enviarCarta1);
  server.on("/carta2", enviarCarta2);
  server.onNotFound(enviarIndex);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
  MDNS.update();
}
