/*
Author: McH
Date: 2016/10/26
Content: class template for singly linked list with a "head node"
*/

#pragma once

#include "SinglyLinkedListBase.h"

namespace LinearList
{
	// class for singly linked list with a "head node"
	template <typename T> class SinglyLinkedListWithHead : public SinglyLinkedListBase<T>
	{
	protected:
		// Get the pointer of the first element node
		inline SLNode<T> *GetFirst() const override { return head->next; }

		// Get the pointer of the end of the list
		inline SLNode<T> *GetEnd() const override { return nullptr; }

	public:
		// Create a new singly linked list
		SinglyLinkedListWithHead()
		{
			head = rear = new SLNode<T>{ T(), GetEnd() };
			length = 0;
		}

		// Create a new singly linked list from an existing one
		// L: the existing singly linked list
		SinglyLinkedListWithHead(const SinglyLinkedListWithHead<T> &L) :SinglyLinkedListWithHead()
		{
			for (SLNode<T> *p = L.GetFirst(); p != L.GetEnd(); p = p->next)
			{
				SLNode<T> *q = new SLNode<T>{ p->data, GetEnd() };
				rear->next = q;
				rear = q;
			}
			length = L.length;
		}

		// Add a new element at the end of the singly linked list
		// element: element to add
		void Add(T element) override
		{
			SLNode<T> *p = new SLNode<T>{ element, GetEnd() };
			rear->next = p;
			rear = p;
			length++;
		}

		// Add a new element at the designated place of the singly linked list
		// element: element to add
		// index: index to add the new element
		void AddAt(T element, int index) override
		{
			if (index < 0 || index > length)
			{
				throw IndexOutOfBoundsException();
			}
			SLNode<T> *p = head;
			for (int i = 0; i < index; i++)
			{
				p = p->next;
			}
			SLNode<T> *q = new SLNode<T>{ element, p->next };
			p->next = q;
			if (q == rear)
			{
				rear = p;
			}
			length++;
		}

		// Remove the designated element from the singly linked list
		// element: element to remove
		void Remove(T element) override
		{
			SLNode<T> *p = head;
			while ((p->next != GetEnd()) && (p->next->data != element))
			{
				p = p->next;
			}
			if (p->next == GetEnd())
			{
				return;
			}
			SLNode<T> *q = p->next;
			p->next = p->next->next;
			if (p->next == GetEnd())
			{
				rear = p;
				rear->next = GetEnd();
			}
			delete q;
			length--;
		}

		// Remove the designated element from the singly linked list
		// index: index of the element to remove
		void RemoveAt(int index) override
		{
			if (index < 0 || index > length - 1)
			{
				throw IndexOutOfBoundsException();
			}
			SLNode<T> *p = head;
			for (int i = 0; i < index; i++)
			{
				p = p->next;
			}
			SLNode<T> *q = p->next;
			p->next = q->next;
			if (q == rear)
			{
				rear = p;
			}
			delete q;
			length--;
		}
	};
}