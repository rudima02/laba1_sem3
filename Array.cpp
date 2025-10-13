#include "Array.h"
#include <iostream>


void initArray(Array& arr) {
    arr.size = 0;
    arr.memorySize = 0;
    arr.memory = new std::string[0];
}

void addArray(Array& arr, const std::string& key) {
    if (arr.size + 1 > arr.memorySize) {
        int newMemorySize = arr.size * 2 + (arr.size == 0);
        std::string* newMemory = new std::string[newMemorySize];
        for (int i = 0; i < arr.size; i++)
            newMemory[i] = arr.memory[i];
        delete[] arr.memory;
        arr.memory = newMemory;
        arr.memorySize = newMemorySize;
    }
    arr.memory[arr.size] = key;
    arr.size++;
}

void addArray(Array& arr, const std::string& key, int index) {
    if (index < 0 || index > arr.size) return;

    if (arr.size + 1 > arr.memorySize) {
        int newMemorySize = arr.size * 2 + (arr.size == 0);
        std::string* newMemory = new std::string[newMemorySize];
        for (int i = 0; i < index; i++)
            newMemory[i] = arr.memory[i];
        newMemory[index] = key;
        for (int i = index + 1; i < arr.size + 1; i++)
            newMemory[i] = arr.memory[i - 1];
        delete[] arr.memory;
        arr.memory = newMemory;
        arr.memorySize = newMemorySize;
    }
    else {
        for (int i = arr.size; i > index; i--)
            arr.memory[i] = arr.memory[i - 1];
        arr.memory[index] = key;
    }
    arr.size++;
}

std::string getArray(Array& arr, int index) {
    if (index < 0 || index >= arr.size) return "";
    return arr.memory[index];
}

void removeArray(Array& arr, int index) {
    if (index < 0 || index >= arr.size) return;
    for (int i = index; i < arr.size - 1; i++)
        arr.memory[i] = arr.memory[i + 1];
    arr.size--;
}

void changeArray(Array& arr, int index, const std::string& key) {
    if (index < 0 || index >= arr.size) return;
    arr.memory[index] = key;
}

int lengthArray(Array& arr) {
    return arr.size;
}

void printArray(Array& arr) {
    for (int i = 0; i < arr.size; i++)
        std::cout << arr.memory[i] << ' ';
        std::cout << std::endl;
}

void deleteArray(Array& arr) {
    delete[] arr.memory;
    arr.memory = nullptr;
    arr.size = 0;
    arr.memorySize = 0;
}
