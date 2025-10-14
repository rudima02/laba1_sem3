#include "Queue.h"

void pushQueue(NodeQueue*& head, NodeQueue*& tail, std::string value) {
    NodeQueue* newNode = new NodeQueue;
    newNode->key = value;
    newNode->next = nullptr;
    if (tail != nullptr) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
}

void popQueue(NodeQueue*& head, NodeQueue*& tail) {
    if (head == nullptr) return;
    NodeQueue* toDelete = head;
    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete toDelete;
}

void printQueue(NodeQueue* head) {
    std::cout << "Queue: ";
    while (head != nullptr) {
        std::cout << head->key << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
