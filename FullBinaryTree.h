#pragma once
#include <string>
#include <iostream>

struct NodeFBT {
    std::string key;
    NodeFBT* left;
    NodeFBT* right;
};

NodeFBT* addNodeFBT(NodeFBT* root, std::string value);
NodeFBT* findNodeFBT(NodeFBT* root, std::string value);
bool isFullFBT(NodeFBT* root);

void printLevelFBT(NodeFBT* root);
void printLeftRight(NodeFBT* root);      
void printTopBot(NodeFBT* root);         
void printBotTop(NodeFBT* root);         
