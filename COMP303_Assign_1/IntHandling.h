#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char menu_choice();

int num_exists(int array[], int ARRAY_SIZE, int num);

void change_num(int array[], int index);

int add_num(int array[], int size, int num);