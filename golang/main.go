package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var headDLL *NodeDLL
	var headFL *NodeFL
	var topStack *NodeStack
	var headQueue, tailQueue *NodeQueue
	var arr Array
	initArray(&arr)

	loadDLLFromFile(&headDLL, "dll.txt")
	loadFLFromFile(&headFL, "fl.txt")
	loadStackFromFile(&topStack, "stack.txt")
	loadQueueFromFile(&headQueue, &tailQueue, "queue.txt")
	loadArrayFromFile(&arr, "array.txt")

	args := os.Args[1:]
	for i := 0; i < len(args); i++ {
		arg := args[i]
		if arg == "addHeadDLL" && i+1 < len(args) {
			addHeadDLL(&headDLL, args[i+1])
			i++
		} else if arg == "addTailDLL" && i+1 < len(args) {
			addTailDLL(&headDLL, args[i+1])
			i++
		} else if arg == "addAfterDLL" && i+2 < len(args) {
			ptr := findByValueDLL(headDLL, args[i+1])
			addAfterDLL(ptr, args[i+2])
			i += 2
		} else if arg == "addBeforeDLL" && i+2 < len(args) {
			ptr := findByValueDLL(headDLL, args[i+1])
			addBeforeDLL(&headDLL, ptr, args[i+2])
			i += 2
		} else if arg == "deleteHeadDLL" {
			deleteHeadDLL(&headDLL)
		} else if arg == "deleteTailDLL" {
			deleteTailDLL(&headDLL)
		} else if arg == "deleteAfterDLL" && i+1 < len(args) {
			ptr := findByValueDLL(headDLL, args[i+1])
			deleteAfterDLL(ptr)
			i++
		} else if arg == "deleteBeforeDLL" && i+1 < len(args) {
			ptr := findByValueDLL(headDLL, args[i+1])
			deleteBeforeDLL(&headDLL, ptr)
			i++
		} else if arg == "deleteByValueDLL" && i+1 < len(args) {
			deleteByValueDLL(&headDLL, args[i+1])
			i++
		} else if arg == "printDLL" {
			printNextValueDLL(headDLL)
		} else if arg == "printMemoryDLL" {
			printMemoryDLL(headDLL)
		} else if arg == "addHeadFL" && i+1 < len(args) {
			addHeadFL(&headFL, args[i+1])
			i++
		} else if arg == "addTailFL" && i+1 < len(args) {
			addTailFL(&headFL, args[i+1])
			i++
		} else if arg == "addAfterFL" && i+2 < len(args) {
			ptr := findByValueFL(headFL, args[i+1])
			addAfterFL(ptr, args[i+2])
			i += 2
		} else if arg == "addBeforeFL" && i+2 < len(args) {
			ptr := findByValueFL(headFL, args[i+1])
			addBeforeFL(&headFL, ptr, args[i+2])
			i += 2
		} else if arg == "deleteHeadFL" {
			deleteHeadFL(&headFL)
		} else if arg == "deleteTailFL" {
			deleteTailFL(&headFL)
		} else if arg == "deleteAfterFL" && i+1 < len(args) {
			ptr := findByValueFL(headFL, args[i+1])
			deleteAfterFL(ptr)
			i++
		} else if arg == "deleteBeforeFL" && i+1 < len(args) {
			ptr := findByValueFL(headFL, args[i+1])
			deleteBeforeFL(&headFL, ptr)
			i++
		} else if arg == "deleteByValueFL" && i+1 < len(args) {
			deleteByValueFL(&headFL, args[i+1])
			i++
		} else if arg == "printFL" {
			printNextValueFL(headFL)
		} else if arg == "printReverseFL" {
			printPrevValueFL(headFL)
		} else if arg == "pushStack" && i+1 < len(args) {
			pushStack(&topStack, args[i+1])
			i++
		} else if arg == "popStack" {
			popStack(&topStack)
		} else if arg == "printStack" {
			printStack(topStack)
		} else if arg == "pushQueue" && i+1 < len(args) {
			pushQueue(&headQueue, &tailQueue, args[i+1])
			i++
		} else if arg == "popQueue" {
			popQueue(&headQueue, &tailQueue)
		} else if arg == "printQueue" {
			printQueue(headQueue)
		} else if arg == "addArray" && i+1 < len(args) {
			addArray(&arr, args[i+1])
			i++
		} else if arg == "addIndexArray" && i+2 < len(args) {
			index, _ := strconv.Atoi(args[i+1])
			addIndexArray(&arr, args[i+2], index)
			i += 2
		} else if arg == "getArray" && i+1 < len(args) {
			index, _ := strconv.Atoi(args[i+1])
			fmt.Println(getArray(&arr, index))
			i++
		} else if arg == "removeArray" && i+1 < len(args) {
			index, _ := strconv.Atoi(args[i+1])
			removeArray(&arr, index)
			i++
		} else if arg == "changeArray" && i+2 < len(args) {
			index, _ := strconv.Atoi(args[i+1])
			changeArray(&arr, index, args[i+2])
			i += 2
		} else if arg == "lengthArray" {
			fmt.Println(lengthArray(&arr))
		} else if arg == "printArray" {
			printArray(&arr)
		} else if arg == "deleteArray" {
			deleteArray(&arr)
		}
	}

	saveDLLToFile(headDLL, "dll.txt")
	saveFLToFile(headFL, "fl.txt")
	saveStackToFile(topStack, "stack.txt")
	saveQueueToFile(headQueue, "queue.txt")
	saveArrayToFile(&arr, "array.txt")
}
