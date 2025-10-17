package main

import "fmt"

type Array struct {
	memory []string
	size   int
}

func initArray(arr *Array) {
	arr.memory = []string{}
	arr.size = 0
}

func addArray(arr *Array, value string) {
	arr.memory = append(arr.memory, value)
	arr.size++
}

func addIndexArray(arr *Array, value string, index int) {
	if index < 0 || index > arr.size {
		return
	}
	arr.memory = append(arr.memory[:index], append([]string{value}, arr.memory[index:]...)...)
	arr.size++
}

func getArray(arr *Array, index int) string {
	if index < 0 || index >= arr.size {
		return ""
	}
	return arr.memory[index]
}

func removeArray(arr *Array, index int) {
	if index < 0 || index >= arr.size {
		return
	}
	arr.memory = append(arr.memory[:index], arr.memory[index+1:]...)
	arr.size--
}

func changeArray(arr *Array, index int, value string) {
	if index < 0 || index >= arr.size {
		return
	}
	arr.memory[index] = value
}

func lengthArray(arr *Array) int {
	return arr.size
}

func printArray(arr *Array) {
	for _, v := range arr.memory {
		fmt.Print(v, " ")
	}
	fmt.Println()
}

func deleteArray(arr *Array) {
	arr.memory = nil
	arr.size = 0
}
