///By Rizky Rahmatullah/////
///Channel YT : https://www.youtube.com/channel/UCWMOPvAoXK8wpMlHVDjYobQ ///
#include <SPI.h>
#include <MFRC522.h>
#define SDA 10
#define RST 9
MFRC522 RFID(SDA, RST);
void setup() {
  Serial.begin(9600);
  SPI.begin();
  RFID.PCD_Init();
  Serial.println("PERCOBAAN MEMBACA KARTU");
  Serial.println("");
  Serial.println("SILAHKAN TAP KARTU ANDA");
  Serial.println();
}
void loop() {
  if ( ! RFID.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! RFID.PICC_ReadCardSerial()) {
    return;
  }
  Serial.print("ID Tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < RFID.uid.size; i++) {
    Serial.print(RFID.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(RFID.uid.uidByte[i], HEX);
    content.concat(String(RFID.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(RFID.uid.uidByte[i], HEX));
  }
  Serial.println();
  delay(1000);
}
