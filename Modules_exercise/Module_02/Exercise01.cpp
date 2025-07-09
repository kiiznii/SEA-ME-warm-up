#include <iostream>
#include <string>

using namespace std;

class Part{
    public:
    virtual void print() const = 0;
    virtual ~Part() {}
};

class Engine : public Part{
    public:
    void print() const override{
        cout << "- Engine : Twin- turbocharged flat-six\n";
    }
};

class Wheel : public Part{
    public:
    void print() const override{
        cout <<"- Wheel : 20-inch front / 21-inch rear alloy wheels\n";
    }
};

class Brake : public Part{
    public:
    void print() const override{
        cout << "- Brake : Carbon ceramic brakes\n";
    }
};

class Transmission : public Part {
    public:
    void print() const override{
        cout << "- Transmission : 8-speed PDK automatic\n";
    }
};

class Car{
private:
    string make;
    string model;
    int year;

    Engine* engine;
    Wheel* wheels[4];
    Brake* brakes[4];
    Transmission* transmission;

public:
    Car(string mk, string mdl, int yr)
        : make(mk), model(mdl), year(yr){
        
        engine = new Engine();
        transmission = new Transmission();

        for(int i = 0; i<4; ++i){
            wheels[i] = new Wheel();
            brakes[i] = new Brake();
        }
        cout << "[Car Created] " << make << " "<< model << " " << " (" << year << ")\n";
    }

    void printParts() const {
        cout << "\n--- Parts of " << make << " " << model << " ---\n";
        engine->print();
        wheels[0]->print();  // 첫 번째 것만 출력
        cout << "  (x4)\n";
        brakes[0]->print();  // 첫 번째 것만 출력
        cout << "  (x4)\n";
        transmission->print();
        cout << "----------------------------\n";
}
    void drive() const{
        cout<< "[Drive] " << make << " " << model << " is now driving with power!\n";
    }

    ~Car(){
        delete engine;
        delete transmission;
        for(int i =0; i < 4; ++i){
            delete wheels[i];
            delete brakes[i];
        }
        cout << "[Car Destroyed] " << make << " " << model << " destroyed.\n";
    }
};

int main() {
    Car myCar("Porsche", "911 Turbo", 2022);
    myCar.printParts();
    myCar.drive();

    return 0;
}