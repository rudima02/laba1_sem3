#include "FullBinaryTree.h"

NodeFBT* addNodeFBT(NodeFBT* root, std::string value) {
    if (!root) return new NodeFBT{ value, nullptr, nullptr };

    if (value < root->key)
        root->left = addNodeFBT(root->left, value);
    else if (value > root->key)
        root->right = addNodeFBT(root->right, value);

    return root;
}

NodeFBT* findNodeFBT(NodeFBT* root, std::string value) {
    if (!root) return nullptr;
    if (root->key == value) return root;
    if (value < root->key) return findNodeFBT(root->left, value);
    return findNodeFBT(root->right, value);
}

bool isFullFBT(NodeFBT* root) {
    if (!root) return true;
    if ((root->left == nullptr && root->right != nullptr) ||
        (root->left != nullptr && root->right == nullptr))
        return false;
    return isFullFBT(root->left) && isFullFBT(root->right);
}

int heightFBT(NodeFBT* root) {
    if (!root) return 0;
    int lh = heightFBT(root->left);
    int rh = heightFBT(root->right);
    return 1 + (lh > rh ? lh : rh);
}

void printLevel(NodeFBT* root, int level) {
    if (!root) return;
    if (level == 1)
        std::cout << root->key << " ";
    else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void printLevelFBT(NodeFBT* root) {
    int h = heightFBT(root);
    for (int i = 1; i <= h; ++i) {
        printLevel(root, i);
    }
}

void printLeftRight(NodeFBT* root) {
    if (!root) return;
    printLeftRight(root->left);
    std::cout << root->key << " ";
    printLeftRight(root->right);
}

void printTopBot(NodeFBT* root) {
    if (!root) return;
    std::cout << root->key << " ";
    printTopBot(root->left);
    printTopBot(root->right);
}

void printBotTop(NodeFBT* root) {
    if (!root) return;
    printBotTop(root->left);
    printBotTop(root->right);
    std::cout << root->key << " ";
}
