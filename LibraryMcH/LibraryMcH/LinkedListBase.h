/*
Author: McH
Date: 2016/10/25
Content: base class template for all linked lists
*/

#pragma once

#include "NonRestrictiveLinearListBase.h"

namespace LinearList
{
	// base class for linked lists
	template <typename T> class LinkedListBase : public NonRestrictiveLinearListBase<T>
	{
	protected:
		// Get the head pointer
		inline virtual LNode<T> *GetHead() const = 0;

		// Get the pointer of the first element
		inline virtual LNode<T> *GetFirst() const = 0;

		// Get the pointer of the end of the list
		inline virtual LNode<T> *GetEnd() const = 0;

	public:
		// Destroy the given linked list
		void DestroyList() override
		{
			while (length > 0)
			{
				RemoveAt(0);
			}
			if (GetHead() != nullptr)
			{
				delete GetHead();
			}
		}

		// Get the designated element
		// index: index of the element
		T &operator[](const int &index) const override
		{
			if (index < 0 || index > length - 1)
			{
				throw IndexOutOfBoundsException();
			}
			LNode<T> *p = GetFirst();
			for (int i = 0; i < index; i++)
			{
				p = p->GetNext();
			}
			return p->data;
		}

		// Check if the sequence list is equal to a given non-restrictive linear list
		// L: the given list
		bool operator==(const NonRestrictiveLinearListBase<T> &L) override
		{
			if (length != L.GetLength())
			{
				return false;
			}
			LNode<T> *p = GetFirst();
			for (int i = 0; i < length; i++)
			{
				if (p->data != L[i])
				{
					return false;
				}
				p = p->GetNext();
			}
			return true;
		}

		// Find the designated element
		// element: element to find
		int Find(T element) override
		{
			LNode<T> *p = GetFirst();
			for (int i = 0; i < length; i++, p = p->GetNext())
			{
				if (p->data == element)
				{
					return i;
				}
			}
			return -1;
		}
	};
}
