#include <iostream>
#include "ForwardList.h" 

void printNextValueFL(NodeFL* ptr) {
    while (ptr != nullptr) {
        std::cout << ptr->key << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

void addHeadFL(NodeFL*& headFL, std::string value) {
    NodeFL* newNode = new NodeFL;
    newNode->key = value;
    newNode->next = headFL;
    headFL = newNode;
}

void addTailFL(NodeFL*& headFL, std::string value) {
    NodeFL* newNode = new NodeFL;
    newNode->key = value;
    newNode->next = nullptr;

    if (headFL == nullptr) {
        headFL = newNode;
        return;
    }

    NodeFL* ptr = headFL;
    while (ptr->next != nullptr) ptr = ptr->next;
    ptr->next = newNode;
}

void addAfterFL(NodeFL* ptr, std::string value) {
    if (ptr == nullptr) return;
    NodeFL* newNode = new NodeFL;
    newNode->key = value;
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void addBeforeFL(NodeFL*& headFL, NodeFL* ptr, std::string value) {
    if (ptr == nullptr) return;
    if (headFL == ptr) {
        addHeadFL(headFL, value);
        return;
    }
    NodeFL* temp = headFL;
    while (temp->next != ptr && temp->next != nullptr) temp = temp->next;
    if (temp->next == ptr) {
        NodeFL* newNode = new NodeFL;
        newNode->key = value;
        newNode->next = ptr;
        temp->next = newNode;
    }
}

void deleteHeadFL(NodeFL*& headFL) {
    if (headFL == nullptr) return;
    NodeFL* toDelete = headFL;
    headFL = headFL->next;
    delete toDelete;
}

void deleteTailFL(NodeFL*& headFL) {
    if (headFL == nullptr) return;
    if (headFL->next == nullptr) {
        delete headFL;
        headFL = nullptr;
        return;
    }
    NodeFL* ptr = headFL;
    while (ptr->next->next != nullptr) ptr = ptr->next;
    delete ptr->next;
    ptr->next = nullptr;
}

void deleteAfterFL(NodeFL* ptr) {
    if (ptr == nullptr || ptr->next == nullptr) return;
    NodeFL* toDelete = ptr->next;
    ptr->next = toDelete->next;
    delete toDelete;
}

void deleteBeforeFL(NodeFL*& headFL, NodeFL* ptr) {
    if (ptr == nullptr || headFL == nullptr || headFL == ptr) return;
    if (headFL->next == ptr) {
        deleteHeadFL(headFL);
        return;
    }
    NodeFL* temp = headFL;
    while (temp->next->next != ptr && temp->next != nullptr) temp = temp->next;
    if (temp->next->next == ptr) {
        NodeFL* toDelete = temp->next;
        temp->next = ptr;
        delete toDelete;
    }
}

NodeFL* findByValueFL(NodeFL* headFL, std::string value) {
    NodeFL* ptr = headFL;
    while (ptr != nullptr) {
        if (ptr->key == value) return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}

void deleteByValueFL(NodeFL*& headFL, std::string value) {
    if (headFL == nullptr) return;
    if (headFL->key == value) {
        deleteHeadFL(headFL);
        return;
    }
    NodeFL* ptr = headFL;
    while (ptr->next != nullptr && ptr->next->key != value) ptr = ptr->next;
    if (ptr->next != nullptr) {
        NodeFL* toDelete = ptr->next;
        ptr->next = toDelete->next;
        delete toDelete;
    }
}

void printPrevValueFL(NodeFL* ptr) {
    if (ptr == nullptr) return;
    printPrevValueFL(ptr->next);
    std::cout << ptr->key << " ";
}
