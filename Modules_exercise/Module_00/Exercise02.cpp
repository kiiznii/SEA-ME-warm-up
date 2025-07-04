#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
	string command;
	string input;
	
	cout << "Command(up or down):";
	cin >> command;
	cin.ignore();

	cout << "Input:";
	getline(cin, input);

	for (int i = 0 ; i < input.length(); i++){
		
		if(command == "up"){
			input[i] = toupper(input[i]);
		}
		else if(command =="down"){
			input[i] = tolower(input[i]);
		}
	}
	cout << "Result :" << input<< endl;
	return 0;
}
		

