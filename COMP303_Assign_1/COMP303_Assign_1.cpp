
#include <iostream>
#include <fstream>
#include "IntHandling.h"

using namespace std;


int main()
{
	ifstream fin;
	string filename;

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


	

	/*user_file.open(filename);

	while (!user_file.is_open()) {
		cout << "Error: file not found." << endl;
		cout << endl;
		cout << "Please enter name of file: ";

		cin >> filename;

		user_file.open(filename);

	}
	*/



}
