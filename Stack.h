#pragma once

struct NodeStack {
    int key;
    NodeStack* next;
};

void pushStack(NodeStack*& topStack, int value);
void popStack(NodeStack*& topStack);
void printStack(NodeStack* topStack);
