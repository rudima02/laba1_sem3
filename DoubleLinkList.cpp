#include <iostream>
#include "DoubleLinkList.h"

void printPrevValueDLL(NodeDLL* ptr) {
    std::cout << "Value :";
    while (ptr != nullptr) {
        std::cout << ptr->key << " ";
        ptr = ptr->prev;
    }
    std::cout << std::endl;
}

void printNextValueDLL(NodeDLL* ptr) {
    std::cout << "Value: ";
    while (ptr != nullptr) {
        std::cout << ptr->key << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

void addHeadDLL(NodeDLL*& headDLL, int value) {
    NodeDLL* newNode = new NodeDLL;
    newNode->key = value;
    newNode->next = headDLL;
    newNode->prev = nullptr;
    if (headDLL != nullptr) headDLL->prev = newNode;
    headDLL = newNode;
}

void addTailDLL(NodeDLL*& headDLL, int value) {
    NodeDLL* newNode = new NodeDLL;
    newNode->key = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if (headDLL == nullptr) {
        headDLL = newNode;
        return;
    }
    NodeDLL* ptr = headDLL;
    while (ptr->next != nullptr) ptr = ptr->next;
    ptr->next = newNode;
    newNode->prev = ptr;
}

void addAfterDLL(NodeDLL* ptr, int value) {
    if (ptr == nullptr) return;
    NodeDLL* newNode = new NodeDLL;
    newNode->key = value;
    newNode->next = ptr->next;
    newNode->prev = ptr;
    if (ptr->next != nullptr) ptr->next->prev = newNode;
    ptr->next = newNode;
}

void addBeforeDLL(NodeDLL*& headDLL, NodeDLL* ptr, int value) {
    if (ptr == nullptr) return;
    NodeDLL* newNode = new NodeDLL;
    newNode->key = value;
    newNode->next = ptr;
    newNode->prev = ptr->prev;
    if (ptr->prev != nullptr) ptr->prev->next = newNode;
    else headDLL = newNode;
    ptr->prev = newNode;
}

void deleteHeadDLL(NodeDLL*& headDLL) {
    if (headDLL == nullptr) return;
    NodeDLL* toDelete = headDLL;
    headDLL = headDLL->next;
    if (headDLL != nullptr) headDLL->prev = nullptr;
    delete toDelete;
}

void deleteTailDLL(NodeDLL*& headDLL) {
    if (headDLL == nullptr) return;
    NodeDLL* ptr = headDLL;
    while (ptr->next != nullptr) ptr = ptr->next;
    if (ptr->prev != nullptr) ptr->prev->next = nullptr;
    else headDLL = nullptr;
    delete ptr;
}

void deleteBeforeDLL(NodeDLL*& headDLL, NodeDLL* ptr) {
    if (ptr == nullptr || ptr->prev == nullptr) return;
    NodeDLL* toDelete = ptr->prev;
    ptr->prev = toDelete->prev;
    if (toDelete->prev != nullptr) toDelete->prev->next = ptr;
    else headDLL = ptr;
    delete toDelete;
}

void deleteAfterDLL(NodeDLL* headDLL, NodeDLL* ptr) {
    if (ptr == nullptr || ptr->next == nullptr) return;
    NodeDLL* toDelete = ptr->next;
    ptr->next = toDelete->next;
    if (toDelete->next != nullptr) toDelete->next->prev = ptr;
    delete toDelete;
}

NodeDLL* findByValueDLL(NodeDLL* headDLL, int value) {
    NodeDLL* ptr = headDLL;
    while (ptr != nullptr) {
        if (ptr->key == value) return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}

void deleteByValueDLL(NodeDLL*& headDLL, int value) {
    NodeDLL* ptr = findByValueDLL(headDLL, value);
    if (ptr == nullptr) return;
    if (ptr->prev == nullptr) {
        deleteHeadDLL(headDLL);
        return;
    }
    if (ptr->next == nullptr) {
        deleteTailDLL(headDLL);
        return;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    delete ptr;
}

void printMemoryDLL(NodeDLL* ptr) {
    std::cout << "Address:";
    while (ptr != nullptr) {
        std::cout << &(ptr->key) << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}
