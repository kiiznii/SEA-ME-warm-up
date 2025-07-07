#include <iostream>
#include <string>

using namespace std;

class Car{
private:
	string name;
	int speed;
public:
	Car(const string&name = "IONIQ", int speed = 0)
		:name(name), speed(speed){
		cout << "[Constructor] Car created: " << this -> name <<", speed: " << this -> speed <<endl;
		}

	Car(const Car&other){
	cout << "[Copy Constructor] Copied Car created: " << name <<", speed: "<<speed<<endl;
	}

	Car& operator=(const Car &other){
		if (this != &other){
			name = other.name;
			speed = other.speed;
			cout << "[Assignment Operator] Assigned Car: " << name << ", speed: " << speed <<endl;
		}
		return *this;
	}
	
	~Car(){
		cout << "[Destructor] Destroying Car: " << name << endl;
	}

	void showInfo() const{
		cout << "Car Name: " << name << ", speed: " << speed << endl;
	}
};

int main(){
	Car car1("BMW", 120);
	Car car2 = car1;
	Car car3;
	car3 = car1;

	car1.showInfo();
	car2.showInfo();
	car3.showInfo();

	return 0;
}