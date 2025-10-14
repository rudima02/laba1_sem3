#pragma once
#include <string>

struct NodeFBT {
    std::string key;
    NodeFBT* left;
    NodeFBT* right;
};

struct NodeQueueFBT {
    NodeFBT* node;
    NodeQueueFBT* next;
};

void pushQueueFBT(NodeQueueFBT*& head, NodeQueueFBT*& tail, NodeFBT* node);
NodeFBT* popQueueFBT(NodeQueueFBT*& head, NodeQueueFBT*& tail);

NodeFBT* addNodeFBT(NodeFBT* root, std::string value);
NodeFBT* findNodeFBT(NodeFBT* root, std::string value);
bool isFullFBT(NodeFBT* root);
void printTreeFBT(NodeFBT* root);
