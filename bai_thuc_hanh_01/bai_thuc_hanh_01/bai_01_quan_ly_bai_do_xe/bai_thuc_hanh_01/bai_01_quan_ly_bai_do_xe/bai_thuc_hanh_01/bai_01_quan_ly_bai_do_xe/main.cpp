#include <iostream>
#include <string>
using namespace std;

//lop xe
class Vehicle {
private:
    int vehicleID;
    string vehicleType;
    int entryTime;
    int parkingDuration;
    double parkingFee;
    bool noSlot;

public:
    Vehicle();

    Vehicle(int id, string type, int time, int duration);

    int getVehicleID() const;
    string getVehicleType() const;
    int getEntryTime() const;
    int getParkingDuration() const;
    double getParkingFee() const;
    bool noSlot() const;

    void setVehicleID(int id);
    void setVehicleType(string type);
    void setEntryTime(int time);
    void setParkingDuration(int duration);
    void setParkingFee(double fee);
    void noSlot(bool status);

    void calculateFee();
    void display() const;
};

//lop bai do xe
class ParkingLot {
private:
    int parkID;
    char size;

    Vehicle vehicle1;
    Vehicle vehicle2;
    Vehicle vehicle3;

    bool hasVehicle1;
    bool hasVehicle2;
    bool hasVehicle3;

public:
    ParkingLot();

    ParkingLot(int id, char s);

    bool addVehicle(const Vehicle& v);
    bool removeVehicle(int vID);

    void displayLotInfo();
};

//lop nay dung de dieu hanh (tam thoi 3 bai)
class SystemInterface {
private:
    ParkingLot parkingLot1;
    ParkingLot parkingLot2;
    ParkingLot parkingLot3;

    bool hasLot1;
    bool hasLot2;
    bool hasLot3;

public:
    SystemInterface();

    void runMenu();
};

int main() {
    SystemInterface system;
    system.runMenu();

    return 0;
}
