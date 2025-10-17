#pragma once
#include <iostream>
#include <string>

struct NodeQueue {
    std::string key;
    NodeQueue* next;
};

void pushQueue(NodeQueue*& head, NodeQueue*& tail, std::string value);
std::string popQueue(NodeQueue*& head, NodeQueue*& tail);
void printQueue(NodeQueue* head);
