#pragma once
#include "DoubleLinkList.h"
#include "ForwardList.h"
#include "Stack.h"
#include "Queue.h"
#include "FullBinaryTree.h"
#include "Array.h"
#include <string>

void deleteAllDLL(NodeDLL*& head);
void deleteAllFL(NodeFL*& head);
void deleteStack(NodeStack*& top);
void deleteQueue(NodeQueue*& head, NodeQueue*& tail);
void saveDLLToFile(NodeDLL* head, const std::string& filename);
void loadDLLFromFile(NodeDLL*& head, const std::string& filename);
void saveFLToFile(NodeFL* head, const std::string& filename);
void loadFLFromFile(NodeFL*& head, const std::string& filename);
void saveStackToFile(NodeStack* top, const std::string& filename);
void loadStackFromFile(NodeStack*& top, const std::string& filename);
void saveQueueToFile(NodeQueue* head, const std::string& filename);
void loadQueueFromFile(NodeQueue*& head, NodeQueue*& tail, const std::string& filename);
void saveFBTToFile(NodeFBT* root, const std::string& filename);
void loadFBTFromFile(NodeFBT*& root, const std::string& filename);
void saveArrayToFile(const Array& arr, const std::string& filename);
void loadArrayFromFile(Array& arr, const std::string& filename);
