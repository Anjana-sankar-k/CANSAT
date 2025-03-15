# **CanSat Project 🚀**  
*A Compact, Low-Cost Atmospheric Data Acquisition System*  

## **Overview**  
The **CanSat** is a compact, can-sized satellite prototype designed for atmospheric data collection. It integrates **sensor technology, wireless telemetry, and embedded systems** to measure **temperature and humidity** during descent. Using an **ESP32 microcontroller**, **NRF24L01 wireless module**, and **DHT11/DHT22 sensor**, the CanSat transmits real-time telemetry to a ground station. A **servo-actuated parachute system** ensures a controlled descent, preventing damage and extending flight duration.  

## **Core Components**  

### **1️⃣ Structural Frame**  
- Lightweight can-based design ensuring durability and compactness.  

### **2️⃣ Sensor System**  
- **DHT11/DHT22** – Measures temperature and humidity.  

### **3️⃣ Power System**  
- **3.7V Li-Po Battery** – Provides stable power.  

### **4️⃣ Communication System**  
- **NRF24L01 Wireless Module** – Enables real-time telemetry.  
- **ESP32** – Controls onboard data processing and transmission.  
- **Arduino Uno** – Processes and logs received data at the ground station.  

### **5️⃣ Parachute Deployment System**  
- **Servo motor-based release mechanism** for controlled parachute deployment.  
- **Spring or burn-wire assistance** for smooth deployment.  

## **Deployment & Operation**  
1️⃣ **Launch** – CanSat is deployed from a height (building/drone).  
2️⃣ **Descent & Data Collection** – Sensor readings are transmitted in real time.  
3️⃣ **Parachute Deployment** – Activated at a defined altitude or time delay.  
4️⃣ **Data Reception & Analysis** – Ground station logs and processes incoming telemetry.  

## **Software Implementation**  
- **Embedded C++** for ESP32 and Arduino Uno.  
- **Sensor Data Acquisition** – Reads and processes environmental data.  
- **Wireless Communication** – Manages NRF24L01 telemetry transmission.  
- **Parachute Control** – Automates servo-based deployment.  
- **Data Processing & Logging** – Logs received data for analysis.  

## **Setup & Usage**  
1. **Assemble hardware components** as per the circuit diagram.  
2. **Flash transmitting.ino** to the ESP32 in the CanSat.  
3. **Flash receiving.ino** to the Arduino on the ground station.  
4. **Deploy CanSat** from a height and monitor real-time data via Serial Monitor.  

## **License**  
This project is open-source under the **MIT License**.  

## **Contributors**  
 IRES-SEDS CUSAT'25
  
