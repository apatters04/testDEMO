
#include <iostream>
#include <fstream>
#include <string>
#include "IntHandling.h"

using namespace std;

char menu_choice() {
	char userinput = ' ';
	cout << "(C) check if an integer exists in the array" << endl;
	cout << "(M) modify the value of an integer at a certain index" << endl;
	cout << "(A) add new integer to end of the array" << endl;
	cout << "(R) remove an integer from the array" << endl;
	cout << "(Q) Exit" << endl;
	cout << endl;

	cout << "Please select how you would like to modify the array:" << endl;
	cin >> userinput;

	return userinput;
}

int num_exists(int array[], int ARRAY_SIZE, int num) { // Checking if a user input value exists in the array

	for (int i = 0; i < 100; i++) {
		if (array[i] == num) {
			return i;
		}
	}

	return -1;
}

void change_num(int array[], int index) { // Changing value of element at a user specified index
	int oldval = array[index];
	int newval;

	cout << "Enter a new value for index " << index << ": ";
	cin >> newval;

	array[index] = newval;

	cout << "Old Value at " << index << " is: " << oldval << endl;
	cout << "New Value at " << index << " is: " << array[index] << endl;
}

int add_num(int array[], int size, int num) {
	int* newarray[101];

	for (int i = 0; i < size; i++) {
		newarray[i] = &array[i];
	}

	newarray[100] = num;

	return newarray;
}
