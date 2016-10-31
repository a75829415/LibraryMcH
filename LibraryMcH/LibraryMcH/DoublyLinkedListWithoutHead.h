/*
Author: McH
Date: 2016/10/27
Content: class template for doubly linked list without a "head node"
*/

#pragma once

#include "DoublyLinkedListBase.h"

namespace LinearList
{
	//class for doubly linked list without a "head node"
	template <typename T> class DoublyLinkedListWithoutHead : public DoublyLinkedListBase<T>
	{
	protected:
		// Get the pointer of the first element node
		inline DLNode<T> *GetFirst() const override { return head; }

		// Get the pointer of the end of the list
		inline DLNode<T> *GetEnd() const override { return nullptr; }

		// Get the pointer which is prior of head
		inline DLNode<T> *GetZeroth() const override { return nullptr; }

	public:
		// Create a new doubly linked list
		DoublyLinkedListWithoutHead()
		{
			head = rear = nullptr;
			length = 0;
		}

		// Create a new doubly linked list from an existing one
		// L: the existing doubly linked list
		DoublyLinkedListWithoutHead(const DoublyLinkedListWithoutHead<T> &L) : DoublyLinkedListWithoutHead()
		{
			if (L.length == 0)
			{
				return;
			}
			DLNode<T> *h = L.GetFirst();
			head = rear = new DLNode<T>{ h->data, GetZeroth(), GetEnd() };
			for (DLNode<T> *p = h->next; p != L.GetEnd(); p = p->next)
			{
				DLNode<T> *q = new DLNode<T>{ p->data, rear, GetEnd() };
				rear->next = q;
				rear = q;
			}
			head->pred = GetZeroth();
			length = L.length;
		}

		// Add a new element at the end of the singly linked list
		// element: element to add
		void Add(T element) override
		{
			DLNode<T> *p = new DLNode<T>{ element, rear, GetEnd() };
			if (head == nullptr)
			{
				head = p;
			}
			else
			{
				rear->next = p;
			}
			rear = p;
			head->pred = GetZeroth();
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
			if (index == 0)
			{
				DLNode<T> *p = new DLNode<T>{ element, GetZeroth(), head };
				head->pred = p;
				head = p;
				rear->next = GetEnd();
			}
			else
			{
				DLNode<T> *p = head;
				for (int i = 1; i < index; i++)
				{
					p = p->next;
				}
				DLNode<T> *q = new DLNode<T>{ element, p, p->next };
				p->next->pred = q;
				p->next = q;
				if (q->next == GetEnd())
				{
					rear = p;
				}
			}
			length++;
		}

		// Remove the designated element from the singly linked list
		// element: element to remove
		void Remove(T element) override
		{
			DLNode<T> *p = head;
			for (int i = 0; i < length; i++)
			{
				if (p->data == element)
				{
					if (length == 1)
					{
						head = rear = nullptr;
					}
					else
					{
						if (p->next != nullptr)
						{
							p->next->pred = p->pred;
						}
						if (p->pred != nullptr)
						{
							p->pred->next = p->next;
						}
						if (p->next == GetEnd())
						{
							rear = p->pred;
						}
						head->pred = GetZeroth();
						rear->next = GetEnd();
					}
					delete p;
					length--;
					return;
				}
				p = p->next;
			}
		}

		// Remove the designated element from the singly linked list
		// index: index of the element to remove
		void RemoveAt(int index) override
		{
			if (index < 0 || index > length - 1)
			{
				throw IndexOutOfBoundsException();
			}
			DLNode<T> *p = head;
			if (length == 1)
			{
				head = rear = nullptr;
			}
			else
			{
				for (int i = 0; i < index; i++)
				{
					p = p->next;
				}
				if (p->next != nullptr)
				{
					p->next->pred = p->pred;
				}
				if (p->pred != nullptr)
				{
					p->pred->next = p->next;
				}
				if (p == head)
				{
					head = p->next;
				}
				if (p == rear)
				{
					rear = p->pred;
				}
			}
			delete p;
			length--;
		}
	};
}