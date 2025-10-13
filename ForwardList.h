#pragma once 

#include <iostream>

struct NodeFL {
    int key;
    NodeFL* next;
};

void addHeadFL(NodeFL*& headFL, int value);
void addTailFL(NodeFL*& headFL, int value);
void addAfterFL(NodeFL* ptr, int value);
void addBeforeFL(NodeFL*& headFL, NodeFL* ptr, int value);

void deleteHeadFL(NodeFL*& headFL);
void deleteTailFL(NodeFL*& headFL);
void deleteAfterFL(NodeFL* ptr);
void deleteBeforeFL(NodeFL*& headFL, NodeFL* ptr);
void deleteByValueFL(NodeFL*& headFL, int value);

NodeFL* findByValueFL(NodeFL* headFL, int value);

void printNextValueFL(NodeFL* headFL);
void printMemoryFL(NodeFL* headFL);
