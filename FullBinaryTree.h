#pragma once

using namespace std;

struct NodeFBT {
    int key;
    NodeFBT* left;
    NodeFBT* right;
};

struct NodeQueueFBT {
    NodeFBT* node;
    NodeQueueFBT* next;
};

void pushQueueFBT(NodeQueueFBT*& head, NodeQueueFBT*& tail, NodeFBT* node);
NodeFBT* popQueueFBT(NodeQueueFBT*& head, NodeQueueFBT*& tail);

NodeFBT* addNodeFBT(NodeFBT* root, int value);
NodeFBT* findNodeFBT(NodeFBT* root, int value);
bool isFullFBT(NodeFBT* root);
void printTreeFBT(NodeFBT* root);
