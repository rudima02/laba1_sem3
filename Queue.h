#pragma once
#include <iostream>

struct NodeQueue {
    int key;
    NodeQueue* next;
};

void pushQueue(NodeQueue*& head, NodeQueue*& tail, int value);
void popQueue(NodeQueue*& head, NodeQueue*& tail);
void printQueue(NodeQueue* head);
