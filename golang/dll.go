package main

import "fmt"

type NodeDLL struct {
	key  string
	next *NodeDLL
	prev *NodeDLL
}

func addHeadDLL(head **NodeDLL, value string) {
	n := &NodeDLL{key: value, next: *head}
	if *head != nil {
		(*head).prev = n
	}
	*head = n
}

func addTailDLL(head **NodeDLL, value string) {
	n := &NodeDLL{key: value}
	if *head == nil {
		*head = n
		return
	}
	p := *head
	for p.next != nil {
		p = p.next
	}
	p.next = n
	n.prev = p
}

func addAfterDLL(ptr *NodeDLL, value string) {
	if ptr == nil {
		return
	}
	n := &NodeDLL{key: value, next: ptr.next, prev: ptr}
	if ptr.next != nil {
		ptr.next.prev = n
	}
	ptr.next = n
}

func addBeforeDLL(head **NodeDLL, ptr *NodeDLL, value string) {
	if ptr == nil {
		return
	}
	n := &NodeDLL{key: value, next: ptr, prev: ptr.prev}
	if ptr.prev != nil {
		ptr.prev.next = n
	} else {
		*head = n
	}
	ptr.prev = n
}

func deleteHeadDLL(head **NodeDLL) {
	if *head == nil {
		return
	}
	*head = (*head).next
	if *head != nil {
		(*head).prev = nil
	}
}

func deleteTailDLL(head **NodeDLL) {
	if *head == nil {
		return
	}
	p := *head
	for p.next != nil {
		p = p.next
	}
	if p.prev != nil {
		p.prev.next = nil
	} else {
		*head = nil
	}
}

func deleteAfterDLL(ptr *NodeDLL) {
	if ptr == nil || ptr.next == nil {
		return
	}
	t := ptr.next
	ptr.next = t.next
	if t.next != nil {
		t.next.prev = ptr
	}
}

func deleteBeforeDLL(head **NodeDLL, ptr *NodeDLL) {
	if ptr == nil || ptr.prev == nil {
		return
	}
	t := ptr.prev
	ptr.prev = t.prev
	if t.prev != nil {
		t.prev.next = ptr
	} else {
		*head = ptr
	}
}

func deleteByValueDLL(head **NodeDLL, value string) {
	p := *head
	for p != nil && p.key != value {
		p = p.next
	}
	if p == nil {
		return
	}
	if p.prev == nil {
		deleteHeadDLL(head)
		return
	}
	if p.next == nil {
		deleteTailDLL(head)
		return
	}
	p.prev.next = p.next
	p.next.prev = p.prev
}

func findByValueDLL(head *NodeDLL, value string) *NodeDLL {
	p := head
	for p != nil {
		if p.key == value {
			return p
		}
		p = p.next
	}
	return nil
}

func printNextValueDLL(head *NodeDLL) {
	p := head
	for p != nil {
		fmt.Print(p.key, " ")
		p = p.next
	}
	fmt.Println()
}

func printMemoryDLL(head *NodeDLL) {
	p := head
	for p != nil {
		fmt.Printf("%p ", p)
		p = p.next
	}
	fmt.Println()
}
