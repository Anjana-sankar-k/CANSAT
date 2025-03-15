#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <DHT.h>
#include <Servo.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

Servo myServo;
int servoPin = 6;
float temperature, humidity;
char receivedCommand;

void setup() {
    Serial.begin(115200);
    dht.begin();
    myServo.attach(servoPin);
    myServo.write(0); // Start position

    radio.begin();
    radio.openWritingPipe(address);
    radio.openReadingPipe(1, address);
    radio.setPALevel(RF24_PA_MIN);
}

void loop() {
    // Read DHT11 data
    humidity = dht.readHumidity();
    temperature = dht.readTemperature();

    if (!isnan(humidity) && !isnan(temperature)) {
        String data = String(temperature) + "," + String(humidity);
        radio.stopListening(); // Switch to transmit mode
        radio.write(data.c_str(), data.length() + 1);
        Serial.println("Sent: " + data);
    }

    delay(1000); // Wait before reading again

    // Check for servo control command
    radio.startListening();
    if (radio.available()) {
        radio.read(&receivedCommand, sizeof(receivedCommand));
        Serial.print("Received Command: ");
        Serial.println(receivedCommand);

        if (receivedCommand == '1') {
            myServo.write(90); // Move Servo to 90°
            delay(1000);
            myServo.write(0); // Reset
        }
    }
}
