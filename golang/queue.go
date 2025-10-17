package main

import "fmt"

type NodeQueue struct {
	key  string
	next *NodeQueue
}

func pushQueue(head **NodeQueue, tail **NodeQueue, value string) {
	n := &NodeQueue{key: value}
	if *tail != nil {
		(*tail).next = n
	} else {
		*head = n
	}
	*tail = n
}

func popQueue(head **NodeQueue, tail **NodeQueue) {
	if *head == nil {
		return
	}
	*head = (*head).next
	if *head == nil {
		*tail = nil
	}
}

func printQueue(head *NodeQueue) {
	p := head
	for p != nil {
		fmt.Print(p.key, " ")
		p = p.next
	}
	fmt.Println()
}
