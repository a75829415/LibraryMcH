/*
Author: McH
Date: 2016/10/27
Content: class template for doubly linked list
*/

#pragma once

#include "LinkedListBase.h"

namespace LinearList
{
	// base class for doubly linked list
	template <typename T> class DoublyLinkedListBase : public LinkedListBase<T>
	{
	protected:
		DLNode<T> *head, *rear;

		// Get the head pointer
		inline DLNode<T> *GetHead() const override { return head; }

		// Get the pointer which is prior of head
		inline virtual DLNode<T> *GetZeroth() const = 0;
	};
}