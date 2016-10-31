/*
Author: McH
Date: 2016/10/27
Content: class template for circular singly linked list with a "head node"
*/

#pragma once

#include "SinglyLinkedListWithHead.h"

namespace LinearList
{
	// class for circular singly linked list with a "head node"
	template <typename T> class CircularSinglyLinkedListWithHead : public SinglyLinkedListWithHead<T>
	{
	protected:
		// Get the pointer of the end of the list
		inline SLNode<T> *GetEnd() const override { return head; }

	public:
		// Create a new circular singly linked list
		CircularSinglyLinkedListWithHead() : SinglyLinkedListWithHead<T>() {}

		// Create a new circular singly linked list from an existing one
		// L: the existing singly linked list
		CircularSinglyLinkedListWithHead(const CircularSinglyLinkedListWithHead<T> &L) : SinglyLinkedListWithHead<T>(L) {}
	};
}