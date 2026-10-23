#include <iostream>
#include <string>

using namespace std;

// 1. ABSTRACTION: Abstract Base Class
class SmartDevice {
protected:
    string deviceName;

public:
    SmartDevice(string name) {
        deviceName = name;
    }

    virtual ~SmartDevice() {}

    // Pure Virtual Functions (Compulsory rules for all devices)
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void showStatus() = 0;
};

// 2. INHERITANCE & ENCAPSULATION: SmartLight Class
class SmartLight : public SmartDevice {
private:
    bool isLightOn; // Private variable for Encapsulation

public:
    SmartLight(string name) : SmartDevice(name) {
        isLightOn = false; // Default state is OFF
    }

    // 3. POLYMORPHISM: Overriding base class functions
    void turnOn() override {
        isLightOn = true;
        cout << "[Action] " << deviceName << " is now ON.\n";
    }

    void turnOff() override {
        isLightOn = false;
        cout << "[Action] " << deviceName << " is now OFF.\n";
    }

    void showStatus() override {
        cout << "[Status] Device: " << deviceName 
             << " | State: " << (isLightOn ? "ON" : "OFF") << "\n";
    }
};

// 2. INHERITANCE & ENCAPSULATION: SmartAC Class
class SmartAC : public SmartDevice {
private:
    bool isACOn;
    int temperature; // Private variable for Encapsulation

public:
    SmartAC(string name) : SmartDevice(name) {
        isACOn = false;
        temperature = 24; // Default temperature 24°C
    }

    // 3. POLYMORPHISM: Overriding base class functions
    void turnOn() override {
        isACOn = true;
        cout << "[Action] " << deviceName << " is now ON.\n";
    }

    void turnOff() override {
        isACOn = false;
        cout << "[Action] " << deviceName << " is now OFF.\n";
    }

    void setTemperature(int temp) {
        temperature = temp;
        cout << "[Action] " << deviceName << " temperature set to " << temperature << " C.\n";
    }

    void showStatus() override {
        cout << "[Status] Device: " << deviceName 
             << " | State: " << (isACOn ? "ON" : "OFF")
             << " | Temperature: " << temperature << " C\n";
    }
};

// 4. MAIN FUNCTION: Program Execution
int main() {
    cout << "========================================\n";
    cout << "     SMART HOME MANAGEMENT SYSTEM       \n";
    cout << "========================================\n\n";

    // Creating Objects
    SmartLight hallLight("Hall Light");
    SmartAC bedroomAC("Bedroom AC");

    // Controlling Hall Light
    hallLight.turnOn();
    hallLight.showStatus();

    cout << "----------------------------------------\n";

    // Controlling Bedroom AC
    bedroomAC.turnOn();
    bedroomAC.setTemperature(22);
    bedroomAC.showStatus();

    cout << "----------------------------------------\n";

    // Turning OFF devices
    hallLight.turnOff();
    bedroomAC.turnOff();

    cout << "\n--- Final Status of Devices ---\n";
    hallLight.showStatus();
    bedroomAC.showStatus();

    cout << "\n========================================\n";
    cout << "   System Execution Completed Safely    \n";
    cout << "========================================\n";

    return 0;
}
