#include "Stack.h"
#include <iostream>

void pushStack(NodeStack*& topStack, std::string value) {
    NodeStack* newNode = new NodeStack;
    newNode->key = value;
    newNode->next = topStack;
    topStack = newNode;
}

void popStack(NodeStack*& topStack) {
    if (topStack == nullptr) return;
    NodeStack* temp = topStack;
    topStack = topStack->next;
    delete temp;
}

void printStack(NodeStack* topStack) {
    std::cout << "Stack: ";
    while (topStack != nullptr) {
        std::cout << topStack->key << " ";
        topStack = topStack->next;
    }
    std::cout << std::endl;
}
