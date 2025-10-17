package main

import "fmt"

type NodeStack struct {
	key  string
	next *NodeStack
}

func pushStack(top **NodeStack, value string) {
	n := &NodeStack{key: value, next: *top}
	*top = n
}

func popStack(top **NodeStack) {
	if *top == nil {
		return
	}
	*top = (*top).next
}

func printStack(top *NodeStack) {
	p := top
	for p != nil {
		fmt.Print(p.key, " ")
		p = p.next
	}
	fmt.Println()
}
