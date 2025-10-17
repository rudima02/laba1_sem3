package main

import (
	"bufio"
	"os"
	"strings"
)

func saveDLLToFile(head *NodeDLL, filename string) {
	file, _ := os.Create(filename)
	defer file.Close()
	p := head
	for p != nil {
		file.WriteString(p.key)
		if p.next != nil {
			file.WriteString(" ")
		}
		p = p.next
	}
}

func loadDLLFromFile(head **NodeDLL, filename string) {
	file, err := os.Open(filename)
	if err != nil {
		return
	}
	defer file.Close()
	*head = nil
	s := bufio.NewScanner(file)
	s.Split(bufio.ScanWords)
	for s.Scan() {
		addTailDLL(head, s.Text())
	}
}

func saveFLToFile(head *NodeFL, filename string) {
	file, _ := os.Create(filename)
	defer file.Close()
	p := head
	for p != nil {
		file.WriteString(p.key)
		if p.next != nil {
			file.WriteString(" ")
		}
		p = p.next
	}
}

func loadFLFromFile(head **NodeFL, filename string) {
	file, err := os.Open(filename)
	if err != nil {
		return
	}
	defer file.Close()
	*head = nil
	s := bufio.NewScanner(file)
	s.Split(bufio.ScanWords)
	for s.Scan() {
		addTailFL(head, s.Text())
	}
}

func saveStackToFile(top *NodeStack, filename string) {
	file, _ := os.Create(filename)
	defer file.Close()
	p := top
	for p != nil {
		file.WriteString(p.key)
		if p.next != nil {
			file.WriteString(" ")
		}
		p = p.next
	}
}

func loadStackFromFile(top **NodeStack, filename string) {
	file, err := os.Open(filename)
	if err != nil {
		return
	}
	defer file.Close()
	*top = nil
	var temp []string
	s := bufio.NewScanner(file)
	s.Split(bufio.ScanWords)
	for s.Scan() {
		temp = append(temp, s.Text())
	}
	for i := len(temp) - 1; i >= 0; i-- {
		pushStack(top, temp[i])
	}
}

func saveQueueToFile(head *NodeQueue, filename string) {
	file, _ := os.Create(filename)
	defer file.Close()
	p := head
	for p != nil {
		file.WriteString(p.key)
		if p.next != nil {
			file.WriteString(" ")
		}
		p = p.next
	}
}

func loadQueueFromFile(head **NodeQueue, tail **NodeQueue, filename string) {
	file, err := os.Open(filename)
	if err != nil {
		return
	}
	defer file.Close()
	*head = nil
	*tail = nil
	s := bufio.NewScanner(file)
	s.Split(bufio.ScanWords)
	for s.Scan() {
		pushQueue(head, tail, s.Text())
	}
}

func saveArrayToFile(arr *Array, filename string) {
	file, _ := os.Create(filename)
	defer file.Close()
	file.WriteString(strings.Join(arr.memory, " "))
}

func loadArrayFromFile(arr *Array, filename string) {
	file, err := os.Open(filename)
	if err != nil {
		return
	}
	defer file.Close()
	initArray(arr)
	s := bufio.NewScanner(file)
	s.Split(bufio.ScanWords)
	for s.Scan() {
		addArray(arr, s.Text())
	}
}
