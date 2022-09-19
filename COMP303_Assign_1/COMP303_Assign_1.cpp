
#include <iostream>
#include <fstream>
#include "IntHandling.h"

using namespace std;


int main()
{
	ifstream fin;
	string filename;
	const int ARRAY_SIZE = 100;
	int int_array[ARRAY_SIZE];
	int size = ARRAY_SIZE; //Array size that can be incremented/changed based on user action
	int hold;
	char user_action = ' ';

	/*
		Reading file of 10 lines of 10 integers in each line into an array - array size is 100
	*/
	cout << "Please enter name of file: ";
	cin >> filename;

	fin.open(filename);

	while (!fin.is_open()) { //Check for valid file name, keep asking user until file opens
		cout << "Error: File Not Found" << endl;
		cout << endl;

		cout << "Please enter name of file: ";
		cin >> filename;
		cout << endl;
		fin.open(filename);
	}

	for (int i = 0; i < ARRAY_SIZE; i++) {
		fin >> hold;
		int_array[i] = hold;
	}
	fin.close();
	cout << endl;


	int* arraypointer; //Creating an array pointer to modify array
	arraypointer = int_array;

	while (user_action != 'Q') { //Menu for user to enter choice of modification to the array
		user_action = toupper(menu_choice());
		switch (user_action) {
		case 'C': //Change action
			int usernum;
			cout << "Enter user number you would like to search for: ";
			cin >> usernum;
			cout << endl;

			if (num_exists(arraypointer, size, usernum) == -1) { //If not found, tell user
				cout << "Number not found." << endl;
			}
			else {
				cout << usernum << " was found at index " << num_exists(arraypointer, size, usernum) << endl; //If found, tell user where val was found
			}
			cout << endl;

			continue;

		case 'M': //Modify action
			int userindex;
			cout << "Enter the index value you would like to modify: ";
			cin >> userindex;
			cout << endl;

			change_num(arraypointer, userindex);
			cout << endl;

			continue;
		
		case 'A': //Add action
			int useradd;
			cout << "Enter the value to be added to the end of the array: ";
			cin >> useradd;
			cout << endl;

			arraypointer = add_num(arraypointer, size, useradd);
			size++; //Incrementing array size to be used in other functions

			cout << endl;
			
			continue;

		case 'R': //Remove action
			int user_removeindex;
			cout << "Enter the index of the value you'd like to remove: ";
			cin >> user_removeindex;
			cout << endl;

			arraypointer = remove_num(arraypointer, size, user_removeindex);
			size--; //Decrementing array size to be used in other functions
			
			cout << endl;
			continue;

		case 'Q':
			cout << "Ending program. Goodbye!";
			break;
		}
		cout << "Error: no action for choice input." << endl; //If user enters an invalid choice
		cout << endl;
	}

}
