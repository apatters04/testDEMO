
#include <iostream>
#include <fstream>
#include "IntHandling.h"

using namespace std;


int main()
{
	ifstream fin;
	string filename;
	int int_array[100];
	int hold;
	char user_action = ' ';

	/*
		Reading file of 10 lines of 10 integers in each line into an array
	*/
	cout << "Please enter name of file: ";
	cin >> filename;

	fin.open(filename);

	while (!fin.is_open()) {
		cout << "Error: File Not Found" << endl;
		cout << endl;

		cout << "Please enter name of file: ";
		cin >> filename;
		cout << endl;
		fin.open(filename);
	}

	for (int i = 0; i < 100; i++) {
		fin >> hold;
		int_array[i] = hold;
	}
	fin.close();

	while (user_action != 'Q') { //Menu for user to enter choice of modification to the array
		user_action = toupper(menu_choice());
		switch (user_action) {
		case 'C':
			int usernum;
			cout << "Enter user number you would like to search for: ";
			cin >> usernum;
			cout << endl;

			if (num_exists(int_array, usernum) == -1) {
				cout << "Number not found." << endl;
			}
			else {
				cout << usernum << " was found at index " << num_exists(int_array, usernum) << endl;
			}
			cout << endl;
			continue;

		case 'M':
			int userindex;
			cout << "Enter the index value you would like to modify: ";
			cin >> userindex;
			cout << endl;
			change_num(int_array, userindex);
			cout << endl;
			continue;
		
		case 'A':
			cout << "Adds integer to the end cutely" << endl;
			cout << endl;
			continue;

		case 'R':
			cout << "Removes integer cutely" << endl;
			cout << endl;
			continue;

		case 'Q':
			cout << "Ending program. Goodbye!";
			break;
		}
	}

}
