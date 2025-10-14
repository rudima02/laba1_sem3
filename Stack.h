#pragma once
#include <string>

struct NodeStack {
    std::string key;
    NodeStack* next;
};

void pushStack(NodeStack*& topStack, std::string value);
void popStack(NodeStack*& topStack);
void printStack(NodeStack* topStack);
