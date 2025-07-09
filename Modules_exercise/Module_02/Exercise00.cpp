 
#include <iostream>
#include <string>
#include <memory>  // required for smart pointers

using namespace std;

class Car {
private:
    string make;
    string model;
    int year;

public:
    Car(string mk, string mdl, int yr) : make(mk), model(mdl), year(yr) {
        cout << "[Car Constructor] Car object created.\n";
    }

    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }

    void setMake(const string& mk) { make = mk; }
    void setModel(const string& mdl) { model = mdl; }
    void setYear(int yr) { year = yr; }

    virtual void drive() {
        cout << "[Car::drive] Driving " << make << " " << model << " " << year << " edition.\n";
    }

    virtual ~Car() {
        cout << "[Car Destructor] Car object destroyed.\n";
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

    void setTopSpeed(int spd) { topSpeed = spd; }
    int getTopSpeed() const { return topSpeed; }

    void drive() override {
        cout << "[SportsCar::drive] Sports mode activated!\n";
        cout << "[SportsCar::drive] Driving " << getMake() << " " << getModel() << " " << getYear() << " edition.\n";
        cout << "[SportsCar::drive] Top speed is " << topSpeed << " km/h.\n";
    }

    ~SportsCar() {
        cout << "[SportsCar Destructor] SportsCar object destroyed.\n";
    }
};

void testDrive(Car* car);
// testDrive now accepts a reference to a smart pointer
void testDrive(Car* car) {
    car->drive();
    cout << "-----------------------------\n";
}

int main() {
    // Use std::unique_ptr instead of raw pointer
    unique_ptr<SportsCar> myCar = make_unique<SportsCar>("Porsche", "911", 2022, 310);

    testDrive(myCar.get());

    string newMake, newModel;
    int newYear, newSpeed;

    cout << "\n=== Update Car Info ===\n";
    cout << "Enter new make: ";
    cin >> ws; getline(cin, newMake);
    cout << "Enter new model: ";
    getline(cin, newModel);
    cout << "Enter new year: ";
    cin >> newYear;
    cout << "Enter new top speed: ";
    cin >> newSpeed;

    myCar->setMake(newMake);
    myCar->setModel(newModel);
    myCar->setYear(newYear);
    myCar->setTopSpeed(newSpeed);

    cout << "\n=== After Update ===\n";
    testDrive(myCar.get());

    // No need to delete manually — unique_ptr does it automatically!
    return 0;
}
