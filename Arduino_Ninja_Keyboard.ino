#include <NinjaBlockEthernet.h>
#include <SPI.h>
#include <Ethernet.h>
#include <NinjaBlock.h>
#include <aJSON.h>
#include <PS2Keyboard.h>

#define PS2_DATA 4
#define PS2_IRQ 3
PS2Keyboard keyboard;

void setup(){
  Serial.begin(9600);
  Serial.println("Arduino-Ninja-Keyboard: Starting");

  keyboard.begin(PS2_DATA, PS2_IRQ);

  NinjaBlock.host = "api.ninja.is";
  NinjaBlock.port = 80;
  NinjaBlock.nodeID = "MS111643431";
  NinjaBlock.token = "youtoken";
  NinjaBlock.guid = "6";
  NinjaBlock.vendorID=0;
  NinjaBlock.deviceID=11;

  if (NinjaBlock.begin()==0)
    Serial.println("Unable to init NinjaBlock\n");
}

void loop() {
  if (keyboard.available()) {
    char c = keyboard.read();

    NinjaBlock.send(c);

    Serial.print("keypress input=");
    Serial.print(c);
  }
  // TODO Consider delay reduce power
}

