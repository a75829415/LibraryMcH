/*
Author: McH
Date: 2016/10/30
Content: class template for circular doubly linked list without a "head node"
*/

#pragma once

#include "DoublyLinkedListWithoutHead.h"

namespace LinearList
{
	// class for circular doubly linked list without a "head node"
	template <typename T> class CircularDoublyLinkedListWithoutHead : public DoublyLinkedListWithoutHead<T>
	{
	protected:
		// Get the pointer of the end of the list
		inline DLNode<T> *GetEnd() const override { return head; }

		// Get the pointer which is prior of head
		inline DLNode<T> *GetZeroth() const override { return rear; }

	public:
		// Create a new circular singly linked list
		CircularDoublyLinkedListWithoutHead() : DoublyLinkedListWithoutHead<T>() {}

		// Create a new circular singly linked list from an existing one
		// L: the existing singly linked list
		CircularDoublyLinkedListWithoutHead(const CircularDoublyLinkedListWithoutHead<T> &L) : DoublyLinkedListWithoutHead<T>(L) {}
	};
}