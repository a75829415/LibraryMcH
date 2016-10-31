/*
Author: McH
Date: 2016/10/25
Content: class template for singly linked list without a "head node"
*/

#pragma once

#include "SinglyLinkedListBase.h"

namespace LinearList
{
	// class for singly linked list without a "head node"
	template <typename T> class SinglyLinkedListWithoutHead : public SinglyLinkedListBase<T>
	{
	protected:
		// Get the pointer of the first element node
		inline SLNode<T> *GetFirst() const override { return head; }

		// Get the pointer of the end of the list
		inline SLNode<T> *GetEnd() const override { return nullptr; }

	public:
		// Create a new singly linked list
		SinglyLinkedListWithoutHead()
		{
			head = rear = nullptr;
			length = 0;
		}

		// Create a new singly linked list from an existing one
		// L: the existing singly linked list
		SinglyLinkedListWithoutHead(const SinglyLinkedListWithoutHead<T> &L) : SinglyLinkedListWithoutHead()
		{
			if (L.length == 0)
			{
				return;
			}
			SLNode<T> *h = L.GetFirst();
			head = rear = new SLNode<T>{ h->data, GetEnd() };
			for (SLNode<T> *p = h->next; p != L.GetEnd(); p = p->next)
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
			if (head == nullptr)
			{
				head = p;
			}
			else
			{
				rear->next = p;
			}
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
			if (index == 0)
			{
				head = new SLNode<T>{ element, head };
				rear->next = GetEnd();
			}
			else
			{
				SLNode<T> *p = head;
				for (int i = 1; i < index; i++)
				{
					p = p->next;
				}
				SLNode<T> *q = new SLNode<T>{ element, p->next };
				p->next = q;
				if (q == rear)
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
			SLNode<T> *p = head;
			if (head->data == element)
			{
				head = head->next;
				rear->next = GetEnd();
				delete p;
			}
			else
			{
				for (int i = 1; i < length; i++)
				{
					if (p->next->data == element)
					{
						SLNode<T> *q = p->next;
						p->next = p->next->next;
						if (p->next == GetEnd())
						{
							rear = p;
							rear->next = GetEnd();
						}
						delete q;
						break;
					}
					p = p->next;
				}
			}
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
			if (index == 0)
			{
				if (length == 1)
				{
					head = rear = nullptr;
				}
				else
				{
					head = head->next;
					rear->next = GetEnd();
				}
				delete p;
			}
			else
			{
				for (int i = 1; i < index; i++)
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
			}
			length--;
		}
	};
}