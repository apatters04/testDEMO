
#include <iostream>
#include <fstream>
#include <string>
#include "IntHandling.h"

using namespace std;

int read_to_array() {
	ifstream fin;
	string filename;
	const int ARRAY_SIZE = 10;
	int intArray[ARRAY_SIZE];
	int holdint;

	cout << "Please enter name of file: ";
	cin >> filename;

	fin.open(filename);

	while (!fin.is_open()) {
		cout << "Error: File Not Found" << endl;
		cout << endl;

		cout << "Please enter name of file: ";
		cin >> filename;

		fin.open(filename);
	}


	for (int i = 0; i < ARRAY_SIZE; ++i) {
		fin >> holdint;
		intArray[i] = holdint;
	}

	fin.close();

	return intArray[ARRAY_SIZE];
}