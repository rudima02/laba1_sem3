#include "DoubleLinkList.h"
#include "ForwardList.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <string>
#include "FullBinaryTree.h"
#include "Array.h"
#include "IO.h" 

using namespace std;

int main(int argc, char* argv[]) {
    NodeDLL* headDLL = nullptr;
    NodeFL* headFL = nullptr;
    NodeStack* topStack = nullptr;
    NodeQueue* headQueue = nullptr;
    NodeQueue* tailQueue = nullptr;
    NodeFBT* root = nullptr;
    Array arr;
    initArray(arr);

    loadDLLFromFile(headDLL, "dll.txt");
    loadFLFromFile(headFL, "fl.txt");
    loadStackFromFile(topStack, "stack.txt");
    loadQueueFromFile(headQueue, tailQueue, "queue.txt");
    loadFBTFromFile(root, "fbt.txt");
    loadArrayFromFile(arr, "array.txt");

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];

        // DLL
        if (arg == "addHeadDLL" && i + 1 < argc) {
            std::string value = (argv[++i]);
            addHeadDLL(headDLL, value);
        }
        else if (arg == "addTailDLL" && i + 1 < argc) {
            std::string value = (argv[++i]);
            addTailDLL(headDLL, value);
        }
        else if (arg == "addAfterDLL" && i + 2 < argc) {
            std::string target = (argv[++i]);
            std::string value = (argv[++i]);
            NodeDLL* ptr = findByValueDLL(headDLL, target);
            addAfterDLL(ptr, value);
        }
        else if (arg == "addBeforeDLL" && i + 2 < argc) {
            std::string target = (argv[++i]);
            std::string value = (argv[++i]);
            NodeDLL* ptr = findByValueDLL(headDLL, target);
            addBeforeDLL(headDLL, ptr, value);
        }
        else if (arg == "deleteHeadDLL") {
            deleteHeadDLL(headDLL);
        }
        else if (arg == "deleteTailDLL") {
            deleteTailDLL(headDLL);
        }
        else if (arg == "deleteAfterDLL" && i + 1 < argc) {
            std::string target = (argv[++i]);
            NodeDLL* ptr = findByValueDLL(headDLL, target);
            deleteAfterDLL(headDLL, ptr);
        }
        else if (arg == "deleteBeforeDLL" && i + 1 < argc) {
            std::string target = (argv[++i]);
            NodeDLL* ptr = findByValueDLL(headDLL, target);
            deleteBeforeDLL(headDLL, ptr);
        }
        else if (arg == "deleteByValueDLL" && i + 1 < argc) {
            std::string value = (argv[++i]);
            deleteByValueDLL(headDLL, value);
        }
        else if (arg == "printDLL") {
            printNextValueDLL(headDLL);
        }
        else if (arg == "printMemoryDLL") {
            printMemoryDLL(headDLL);
        }

        // FL
        else if (arg == "addHeadFL" && i + 1 < argc) {
            std::string value = (argv[++i]);
            addHeadFL(headFL, value);
        }
        else if (arg == "addTailFL" && i + 1 < argc) {
            std::string value = (argv[++i]);
            addTailFL(headFL, value);
        }
        else if (arg == "addAfterFL" && i + 2 < argc) {
            std::string target = (argv[++i]);
            std::string value = (argv[++i]);
            NodeFL* ptr = findByValueFL(headFL, target);
            addAfterFL(ptr, value);
        }
        else if (arg == "addBeforeFL" && i + 2 < argc) {
            std::string target = (argv[++i]);
            std::string value = (argv[++i]);
            NodeFL* ptr = findByValueFL(headFL, target);
            addBeforeFL(headFL, ptr, value);
        }
        else if (arg == "deleteHeadFL") {
            deleteHeadFL(headFL);
        }
        else if (arg == "deleteTailFL") {
            deleteTailFL(headFL);
        }
        else if (arg == "deleteAfterFL" && i + 1 < argc) {
            std::string target = (argv[++i]);
            NodeFL* ptr = findByValueFL(headFL, target);
            deleteAfterFL(ptr);
        }
        else if (arg == "deleteBeforeFL" && i + 1 < argc) {
            std::string target = (argv[++i]);
            NodeFL* ptr = findByValueFL(headFL, target);
            deleteBeforeFL(headFL, ptr);
        }
        else if (arg == "deleteByValueFL" && i + 1 < argc) {
            std::string value = (argv[++i]);
            deleteByValueFL(headFL, value);
        }
        else if (arg == "printFL") {
            printNextValueFL(headFL);
        }
        else if (arg == "printReverseFL"){
            printPrevValueFL(headFL);
        }


        // Stack
        if (arg == "pushStack" && i + 1 < argc) {
            std::string value = (argv[++i]);
            pushStack(topStack, value);
        }
        else if (arg == "popStack") {
            popStack(topStack);
        }
        else if (arg == "printStack") {
            printStack(topStack);
        }

        // Queue
        else if (arg == "pushQueue" && i + 1 < argc) {
            std::string value = (argv[++i]);
            pushQueue(headQueue, tailQueue, value);
        }
        else if (arg == "popQueue") {
            popQueue(headQueue, tailQueue);
        }
        else if (arg == "printQueue") {
            printQueue(headQueue);
        }

        // FBT
        if (arg == "addFBT" && i + 1 < argc) {
            std::string value = (argv[++i]);
            root = addNodeFBT(root, value);
        }
        else if (arg == "findFBT" && i + 1 < argc) {
            std::string value = (argv[++i]);
            NodeFBT* node = findNodeFBT(root, value);
            if (node)
                cout << "Found: " << node->key << endl;
            else
                cout << "Not found" << endl;
        }
        /*else if (arg == "printFBT") {
            printTreeFBT(root);
        }*/
        else if (arg == "isFullFBT") {
            if (isFullFBT(root))
                cout << "Tree is FULL" << endl;
            else
                cout << "Tree is NOT full" << endl;
        }
        else if (arg == "printLevelFBT") {
            printLevelFBT(root);  
        }
        else if (arg == "printLeftRight") {
            printLeftRight(root);
        }
        else if (arg == "printTopBot") {
            printTopBot(root);
        }
        else if (arg == "printBotTop") {
            printBotTop(root);
        }
        

        // Array
        if (arg == "addArray" && i + 1 < argc) {
            string value = argv[++i];
            addArray(arr, value);
        }
        else if (arg == "addArrayIndex" && i + 2 < argc) {
            int index = stoi(argv[++i]);
            string value = argv[++i];
            addIndexArray(arr, value, index);
        }
        else if (arg == "getArray" && i + 1 < argc) {
            int index = stoi(argv[++i]);
            cout << getArray(arr, index) << endl;
        }
        else if (arg == "removeArray" && i + 1 < argc) {
            int index = stoi(argv[++i]);
            removeArray(arr, index);
        }
        else if (arg == "changeArray" && i + 2 < argc) {
            int index = stoi(argv[++i]);
            string value = argv[++i];
            changeArray(arr, index, value);
        }
        else if (arg == "lengthArray") {
            cout << lengthArray(arr) << endl;
        }
        else if (arg == "printArray") {
            printArray(arr);
        }
        else if (arg == "deleteArray") {
            deleteArray(arr);
        }
    }

    saveDLLToFile(headDLL, "dll.txt");
    saveFLToFile(headFL, "fl.txt");
    saveStackToFile(topStack, "stack.txt");
    saveQueueToFile(headQueue, "queue.txt");
    saveFBTToFile(root, "fbt.txt");
    saveArrayToFile(arr, "array.txt");

    return 0;
}
