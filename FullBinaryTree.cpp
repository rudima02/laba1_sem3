#include "FullBinaryTree.h"
#include <iostream>
void pushQueueFBT(NodeQueueFBT*& head, NodeQueueFBT*& tail, NodeFBT* node) {
    NodeQueueFBT* newNode = new NodeQueueFBT{ node, nullptr };
    if (tail) tail->next = newNode;
    else head = newNode;
    tail = newNode;
}

NodeFBT* popQueueFBT(NodeQueueFBT*& head, NodeQueueFBT*& tail) {
    if (!head) return nullptr;
    NodeFBT* node = head->node;
    NodeQueueFBT* tmp = head;
    head = head->next;
    if (!head) tail = nullptr;
    delete tmp;
    return node;
}

NodeFBT* addNodeFBT(NodeFBT* root, std::string value) {
    NodeFBT* newNode = new NodeFBT{ value, nullptr, nullptr };
    if (!root) return newNode;

    NodeQueueFBT* head = nullptr;
    NodeQueueFBT* tail = nullptr;
    pushQueueFBT(head, tail, root);

    while (head) {
        NodeFBT* temp = popQueueFBT(head, tail);

        if (!temp->left) {
            temp->left = newNode;
            return root;
        }
        if (!temp->right) {
            temp->right = newNode;
            return root;
        }

        pushQueueFBT(head, tail, temp->left);
        pushQueueFBT(head, tail, temp->right);
    }
    return root;
}

NodeFBT* findNodeFBT(NodeFBT* root, std::string value) {
    if (!root) return nullptr;
    if (root->key == value) return root;

    NodeFBT* leftRes = findNodeFBT(root->left, value);
    if (leftRes) return leftRes;

    return findNodeFBT(root->right, value);
}

bool isFullFBT(NodeFBT* root) {
    if (!root) return true;
    if ((root->left == nullptr && root->right != nullptr) ||
        (root->left != nullptr && root->right == nullptr))
        return false;
    return isFullFBT(root->left) && isFullFBT(root->right);
}

void printTreeFBT(NodeFBT* root) {
    if (!root) return;
    printTreeFBT(root->left);
    std::cout << root->key << " ";
    printTreeFBT(root->right);
}
