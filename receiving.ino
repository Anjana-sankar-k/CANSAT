#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

char receivedData[32];
char sendCommand = '0'; // Default OFF

void setup() {
    Serial.begin(115200);
    radio.begin();
    radio.openWritingPipe(address);
    radio.openReadingPipe(1, address);
    radio.setPALevel(RF24_PA_MIN);
    radio.startListening();
}

void loop() {
    // Receive DHT11 data
    if (radio.available()) {
        radio.read(&receivedData, sizeof(receivedData));
        Serial.print("Received DHT Data: ");
        Serial.println(receivedData);
    }

    // Command Input via Serial Monitor (or button)
    if (Serial.available()) {
        char input = Serial.read();
        if (input == '1' || input == '0') {
            sendCommand = input;
            Serial.print("Sending Command: ");
            Serial.println(sendCommand);

            radio.stopListening();
            radio.write(&sendCommand, sizeof(sendCommand));
            radio.startListening();
        }
    }
}
