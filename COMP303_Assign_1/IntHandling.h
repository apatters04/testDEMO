#pragma once
#ifndef INTHANDLING_H
#define INTHANDLING_H


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char menu_choice();

int num_exists(int array[], int size, int num);

void change_num(int array[], int index);

int* add_num(int array[], int size, int num);

int* remove_num(int array[], int size, int index);

#endif // !INTHANDLING_H