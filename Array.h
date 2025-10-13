#pragma once

#include <string>

struct Array {
    std::string* memory;
    int size;        
    int memorySize; 
};

void initArray(Array& arr);
void addArray(Array& arr, const std::string& key);
void addArray(Array& arr, const std::string& key, int index);
std::string getArray(Array& arr, int index);
void removeArray(Array& arr, int index);
void changeArray(Array& arr, int index, const std::string& key);
int lengthArray(Array& arr);
void printArray(Array& arr);
void deleteArray(Array& arr);
