package main

import "fmt"

type NodeFL struct {
	key  string
	next *NodeFL
}

func addHeadFL(head **NodeFL, value string) {
	n := &NodeFL{key: value, next: *head}
	*head = n
}

func addTailFL(head **NodeFL, value string) {
	n := &NodeFL{key: value}
	if *head == nil {
		*head = n
		return
	}
	p := *head
	for p.next != nil {
		p = p.next
	}
	p.next = n
}

func addAfterFL(ptr *NodeFL, value string) {
	if ptr == nil {
		return
	}
	n := &NodeFL{key: value, next: ptr.next}
	ptr.next = n
}

func addBeforeFL(head **NodeFL, ptr *NodeFL, value string) {
	if ptr == nil {
		return
	}
	if *head == ptr {
		addHeadFL(head, value)
		return
	}
	p := *head
	for p.next != ptr && p.next != nil {
		p = p.next
	}
	if p.next == ptr {
		n := &NodeFL{key: value, next: ptr}
		p.next = n
	}
}

func deleteHeadFL(head **NodeFL) {
	if *head == nil {
		return
	}
	*head = (*head).next
}

func deleteTailFL(head **NodeFL) {
	if *head == nil {
		return
	}
	if (*head).next == nil {
		*head = nil
		return
	}
	p := *head
	for p.next.next != nil {
		p = p.next
	}
	p.next = nil
}

func deleteAfterFL(ptr *NodeFL) {
	if ptr == nil || ptr.next == nil {
		return
	}
	t := ptr.next
	ptr.next = t.next
}

func deleteBeforeFL(head **NodeFL, ptr *NodeFL) {
	if ptr == nil || *head == nil || *head == ptr {
		return
	}
	if (*head).next == ptr {
		deleteHeadFL(head)
		return
	}
	p := *head
	for p.next.next != ptr && p.next != nil {
		p = p.next
	}
	if p.next.next == ptr {
		p.next = ptr
	}
}

func findByValueFL(head *NodeFL, value string) *NodeFL {
	p := head
	for p != nil {
		if p.key == value {
			return p
		}
		p = p.next
	}
	return nil
}

func deleteByValueFL(head **NodeFL, value string) {
	if *head == nil {
		return
	}
	if (*head).key == value {
		deleteHeadFL(head)
		return
	}
	p := *head
	for p.next != nil && p.next.key != value {
		p = p.next
	}
	if p.next != nil {
		p.next = p.next.next
	}
}

func printNextValueFL(head *NodeFL) {
	p := head
	for p != nil {
		fmt.Print(p.key, " ")
		p = p.next
	}
	fmt.Println()
}

func printPrevValueFL(head *NodeFL) {
	if head == nil {
		return
	}
	printPrevValueFL(head.next)
	fmt.Print(head.key, " ")
}
