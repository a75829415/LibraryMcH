/*
Author: McH
Date: 2016/11/1
Content: class template for doubly linked list with a "head node"
*/

#pragma once

#include "DoublyLinkedListBase.h"

namespace LinearList
{
	// class for doubly linked list with a "head node"
	template <typename T> class DoublyLinkedListWithHead : public DoublyLinkedListBase<T>
	{
	protected:
		// Get the pointer of the first element node
		inline DLNode<T> *GetFirst() const override { return head->next; }

		// Get the pointer of the end of the list
		inline DLNode<T> *GetEnd() const override { return nullptr; }

		// Get the pointer which is prior of head
		inline DLNode<T> *GetZeroth() const override { return head; }

	public:
		// Create a new doubly linked list
		DoublyLinkedListWithHead()
		{
			head = rear = new DLNode<T>{ T(), GetEnd(), GetEnd() };
			length = 0;
		}

		// Create a new doubly linked list from an existing one
		// L: the existing doubly linked list
		DoublyLinkedListWithHead(const DoublyLinkedListWithHead<T> &L) : DoublyLinkedListWithHead()
		{
			if (L.length == 0)
			{
				return;
			}
			for (DLNode<T> *p = L.GetFirst(); p != L.GetEnd(); p = p->next)
			{
				DLNode<T> *q = new DLNode<T>{ p->data, rear, GetEnd() };
				rear->next = q;
				rear = q;
			}
			head->pred = GetZeroth();
			length = L.length;
		}
	};
}