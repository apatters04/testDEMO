
#include <iostream>
#include <fstream>
#include "IntHandling.h"

using namespace std;


int main()
{
	fstream user_file;
	string filename;
	const int ARRAY_SIZE = 10;
	int intArray[ARRAY_SIZE];

	cout << "Please enter name of file: ";
	cin >> filename;

	user_file.open(filename);

	while (!user_file.is_open()) {
		cout << "Error: file not found." << endl;
		cout << endl;
		cout << "Please enter name of file: ";

		cin >> filename;

		user_file.open(filename);

	}

	for (int i = 0; i < ARRAY_SIZE; i++) {
		getline(user_file, intArray[i]);
	}


}
