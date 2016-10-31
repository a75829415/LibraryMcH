/*
Author: McH
Date: 2016/10/26
Content: class template for circular singly linked list without a "head node"
*/

#pragma once

#include "SinglyLinkedListWithoutHead.h"

namespace LinearList
{
	// class for circular singly linked list without a "head node"
	template <typename T> class CircularSinglyLinkedListWithoutHead : public SinglyLinkedListWithoutHead<T>
	{
	protected:
		// Get the pointer of the end of the list
		inline SLNode<T> *GetEnd() const override { return head; }

	public:
		// Create a new circular singly linked list
		CircularSinglyLinkedListWithoutHead() : SinglyLinkedListWithoutHead<T>() {}

		// Create a new circular singly linked list from an existing one
		// L: the existing singly linked list
		CircularSinglyLinkedListWithoutHead(const CircularSinglyLinkedListWithoutHead<T> &L) : SinglyLinkedListWithoutHead<T>(L) {}
	};
}