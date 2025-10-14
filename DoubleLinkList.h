#pragma once
#include <iostream>
#include <string>

struct NodeDLL {
    std::string key;
    NodeDLL* next;
    NodeDLL* prev;
};

void printPrevValueDLL(NodeDLL* ptr);
void printNextValueDLL(NodeDLL* ptr);

void addHeadDLL(NodeDLL*& headDLL, std::string value);
void addTailDLL(NodeDLL*& headDLL, std::string value);
void addAfterDLL(NodeDLL* ptr, std::string value);
void addBeforeDLL(NodeDLL*& headDLL, NodeDLL* ptr, std::string value);

void deleteHeadDLL(NodeDLL*& headDLL);
void deleteTailDLL(NodeDLL*& headDLL);
void deleteBeforeDLL(NodeDLL*& headDLL, NodeDLL* ptr);
void deleteAfterDLL(NodeDLL* headDLL, NodeDLL* ptr);
void deleteByValueDLL(NodeDLL*& headDLL, std::string value);

NodeDLL* findByValueDLL(NodeDLL* headDLL, std::string value);
void printMemoryDLL(NodeDLL* ptr);
