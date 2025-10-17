#pragma once
#include <string>

struct NodeStack {
    std::string key;
    NodeStack* next;
};

void pushStack(NodeStack*& topStack, std::string value);
std::string popStack(NodeStack*& topStack);
void printStack(NodeStack* topStack);
