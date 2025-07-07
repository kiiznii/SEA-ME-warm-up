#include <iostream>
#include <string>

using namespace std;

class Car {
protected:
    string make;
    string model;
    int year;

public:
    Car(string mk, string mdl, int yr) : make(mk), model(mdl), year(yr) {
        cout << "[Car Constructor] Car object created.\n";
    }

    virtual void drive() {
        cout << "[Car::drive] Driving " << make << " " << model << " " << year << " edition.\n";
    }
};

class SportsCar : public Car {
private:
    int topSpeed;

public:
    SportsCar(string mk, string mdl, int yr, int spd)
        : Car(mk, mdl, yr), topSpeed(spd) {
        cout << "[SportsCar Constructor] SportsCar object created.\n";
    }

    void drive() override {
        cout << "[SportsCar::drive] Overriding drive function.\n";
        Car::drive();
        cout << "[SportsCar::drive] Top speed is " << topSpeed << " km/h.\n";
    }
};

int main() {
    Car myCar("Toyota", "Corolla", 2020);
    myCar.drive();
    cout << endl;

    SportsCar mySportsCar("Ferrari", "488 GTB", 2022, 330);
    mySportsCar.drive();

    return 0;
}
