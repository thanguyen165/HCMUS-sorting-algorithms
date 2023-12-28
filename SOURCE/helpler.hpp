#ifndef HELPLER_HPP
#define HELPLER_HPP

#include<iostream>
#include<cstring>

/*
 allocate memory for arr and read data from file
 return -1 if file does not exist
 */
int readArray(int *&arr, int &size, char *fileName);
int writeData(int *&arr, int &size, char *fileName);

bool is_number(char *str);

int getOutputParameterID(char *flag);
bool isOutputParameterID(char *flag);

#endif // HELPLER_HPP