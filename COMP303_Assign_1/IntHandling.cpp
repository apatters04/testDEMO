
#include <iostream>
#include <fstream>
#include <string>
#include "IntHandling.h"

using namespace std;

void read_file() {
	fstream user_file;
	string filename;

	cout << "Enter name of file: ";
	cin >> filename;

	user_file.open(filename);

	while (!user_file.is_open()) {
		cout << "Error: file not found." << endl;
		cout << "Please enter another filename: ";

		cin >> filename;

		user_file.open(filename);

	}


}