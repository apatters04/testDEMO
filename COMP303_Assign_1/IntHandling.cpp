
#include <iostream>
#include <fstream>
#include <string>
#include "IntHandling.h"

using namespace std;

char menu_choice() { //Display to user the actions they can take
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

int num_exists(int array[], int size, int num) { // Checking if a user input value exists in the array

	for (int i = 0; i < size; i++) {
		if (array[i] == num) {
			return i; //Return index of number if found
		}
	}

	return -1; //Return -1 if not found
}

void change_num(int array[], int index) { // Changing value of element at a user specified index
	int oldval = array[index];
	int newval;

	cout << "Enter a new value for index " << index << ": ";
	cin >> newval;

	array[index] = newval;

	cout << "Old Value at " << index << " is: " << oldval << endl; //User feedback
	cout << "New Value at " << index << " is: " << array[index] << endl;
}

int* add_num(int array[], int size, int num) { //Adds a value to the end of an array using pointers
	int* newarr = new int[size + 1];

	for (int i = 0; i < size; i++) { //Copying old array into the new array
		newarr[i] = array[i];
	}

	newarr[size] = num; //Adding the new value to the end

	cout << num << " was added to the end of the array." << endl; //User feedback

	return newarr;
}

int* remove_num(int array[], int size, int index) { //Removes a value at a given index using pointers
	int* newarr = new int[size - 1];

	for (int i = 0; i < size; i++) {
		if (i >= index) { //Skipping over given index to 'remove' and shifting the following values accordingly
			newarr[i] = array[i + 1];
		}
		else {
			newarr[i] = array[i];
		}
	}

	cout << "Value at index " << index << " was removed, array has been updated." << endl; //User feedback

	return newarr;
}