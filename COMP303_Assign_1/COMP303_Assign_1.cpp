
#include <iostream>
#include <fstream>
#include <string>
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
		cout << endl;

		switch (user_action) {
		case 'C': //Check action
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
			
			try {
				cout << "Enter the index value you would like to modify: ";
			
				if (!(cin >> userindex)) { //if user enters a value that is not an integer, throw exception
					throw invalid_argument("Invalid type!");
				}
				else if (userindex > size) {
					throw (userindex); //Throwing exception for an index greater than array size
				}
				else{
					cout << endl;
					change_num(arraypointer, userindex);
				}
			}
			catch (int badIndex) {
				cout << endl;
				cerr << "Error: Out of range for index  " << badIndex << endl; //Error message to user
			}

			catch (invalid_argument) {
				cout << endl;
				cout << "Invalid Data Type! Please enter an integer." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl;
			}
						
			cout << endl;

			continue;
		
		case 'A': //Add action
			int useradd;

			try {
				cout << "Enter the value to be added to the end of the array: ";
				if (!(cin >> useradd)) { //if user enters a value that is not an integer, throw exception
					throw invalid_argument("Invalid data type");
				}
				cout << endl;
				arraypointer = add_num(arraypointer, size, useradd);
				size++; //Incrementing array size to be used in other functions

				cout << endl;
			}
			catch (invalid_argument) {
				cout << "Invalid Data Type! Please enter an integer." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl;
			}
			
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
			continue;
			break;
		}
		
		cout << "Error: Invalid choice." << endl;
		cout << endl;
		
	}

}
