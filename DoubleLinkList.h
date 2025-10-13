#pragma once
#include <iostream>

struct NodeDLL {
    int key;
    NodeDLL* next;
    NodeDLL* prev;
};

void printPrevValueDLL(NodeDLL* ptr);
void printNextValueDLL(NodeDLL* ptr);

void addHeadDLL(NodeDLL*& headDLL, int value);
void addTailDLL(NodeDLL*& headDLL, int value);
void addAfterDLL(NodeDLL* ptr, int value);
void addBeforeDLL(NodeDLL*& headDLL, NodeDLL* ptr, int value);

void deleteHeadDLL(NodeDLL*& headDLL);
void deleteTailDLL(NodeDLL*& headDLL);
void deleteBeforeDLL(NodeDLL*& headDLL, NodeDLL* ptr);
void deleteAfterDLL(NodeDLL* headDLL, NodeDLL* ptr);
void deleteByValueDLL(NodeDLL*& headDLL, int value);

NodeDLL* findByValueDLL(NodeDLL* headDLL, int value);
void printMemoryDLL(NodeDLL* ptr);
