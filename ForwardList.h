#pragma once 
#include <iostream>
#include <string>

struct NodeFL {
    std::string key;
    NodeFL* next;
};

void addHeadFL(NodeFL*& headFL, std::string value);
void addTailFL(NodeFL*& headFL, std::string value);
void addAfterFL(NodeFL* ptr, std::string value);
void addBeforeFL(NodeFL*& headFL, NodeFL* ptr, std::string value);

void deleteHeadFL(NodeFL*& headFL);
void deleteTailFL(NodeFL*& headFL);
void deleteAfterFL(NodeFL* ptr);
void deleteBeforeFL(NodeFL*& headFL, NodeFL* ptr);
void deleteByValueFL(NodeFL*& headFL, std::string value);

NodeFL* findByValueFL(NodeFL* headFL, std::string value);

void printNextValueFL(NodeFL* headFL);
void printMemoryFL(NodeFL* headFL);
