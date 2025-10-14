#include "IO.h"
#include <fstream>
#include <vector>
#include <queue>

void deleteAllDLL(NodeDLL*& head) {
    while (head) deleteHeadDLL(head);
}

void deleteAllFL(NodeFL*& head) {
    while (head) deleteHeadFL(head);
}

void deleteStack(NodeStack*& top) {
    while (top) popStack(top);
}

void deleteQueue(NodeQueue*& head, NodeQueue*& tail) {
    while (head) popQueue(head, tail);
}

void saveDLLToFile(NodeDLL* head, const std::string& filename) {
    std::ofstream file(filename);
    while (head) {
        file << head->key;
        if (head->next) file << " ";
        head = head->next;
    }
}

void loadDLLFromFile(NodeDLL*& head, const std::string& filename) {
    std::ifstream file(filename);
    deleteAllDLL(head);
    head = nullptr;

    int value;
    while (file >> value) addTailDLL(head, value);
}

void saveFLToFile(NodeFL* head, const std::string& filename) {
    std::ofstream file(filename);
    while (head) {
        file << head->key;
        if (head->next) file << " ";
        head = head->next;
    }
}

void loadFLFromFile(NodeFL*& head, const std::string& filename) {
    std::ifstream file(filename);
    deleteAllFL(head);
    head = nullptr;

    int value;
    while (file >> value) addTailFL(head, value);
}

void saveStackToFile(NodeStack* top, const std::string& filename) {
    std::ofstream file(filename);
    NodeStack* ptr = top;
    while (ptr) {
        file << ptr->key;
        if (ptr->next) file << " ";
        ptr = ptr->next;
    }
}

void loadStackFromFile(NodeStack*& top, const std::string& filename) {
    std::ifstream file(filename);
    deleteStack(top);
    top = nullptr;

    std::vector<int> temp;
    int value;
    while (file >> value) temp.push_back(value);

    for (auto it = temp.rbegin(); it != temp.rend(); ++it) pushStack(top, *it);
}

void saveQueueToFile(NodeQueue* head, const std::string& filename) {
    std::ofstream file(filename);
    while (head) {
        file << head->key;
        if (head->next) file << " ";
        head = head->next;
    }
}

void loadQueueFromFile(NodeQueue*& head, NodeQueue*& tail, const std::string& filename) {
    std::ifstream file(filename);
    deleteQueue(head, tail);
    head = tail = nullptr;

    int value;
    while (file >> value) pushQueue(head, tail, value);
}

void saveFBTToFile(NodeFBT* root, const std::string& filename) {
    std::ofstream file(filename);
    if (!root) return;

    std::queue<NodeFBT*> q;
    q.push(root);
    bool first = true;
    while (!q.empty()) {
        NodeFBT* node = q.front(); q.pop();
        if (!first) file << " ";
        file << node->key;
        first = false;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

void loadFBTFromFile(NodeFBT*& root, const std::string& filename) {
    std::ifstream file(filename);
    root = nullptr;

    int value;
    while (file >> value) root = addNodeFBT(root, value);
}

void saveArrayToFile(const Array& arr, const std::string& filename) {
    std::ofstream file(filename);
    for (int i = 0; i < arr.size; ++i) {
        file << arr.memory[i];
        if (i != arr.size - 1) file << " ";
    }
}

void loadArrayFromFile(Array& arr, const std::string& filename) {
    std::ifstream file(filename);
    deleteArray(arr);
    initArray(arr);

    std::string value;
    while (file >> value) addArray(arr, value);
}
