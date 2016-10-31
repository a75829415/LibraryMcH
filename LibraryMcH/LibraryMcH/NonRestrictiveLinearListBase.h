/*
Author: McH
Date: 2016/10/26
Content: base class template for non-restrictive linear lists
		 e.g. sequence list, linked list, etc.
*/

#pragma once

#include "LinearListBase.h"

namespace LinearList
{
	// base class for non-restrictive linear lists
	template <typename T> class NonRestrictiveLinearListBase : public LinearListBase<T>
	{
	protected:
		int length;

	public:
		// Get the designated element
		// index: index of the element
		virtual T &operator[](const int &index) const = 0;

		// Check if the non-restrictive linear list is equal to another one
		// L: the list to check
		virtual bool operator==(const NonRestrictiveLinearListBase<T> &L) = 0;

		// Find the designated element
		// element: element to find
		virtual int Find(T element) = 0;

		// Check if the singly linked list contains the designated element
		// element: element to check
		inline virtual bool Contains(T element) { return Find(element) > -1; }

		// Add a new element at the end of the singly linked list
		 //element: element to add
		virtual void Add(T element) = 0;

		// Add a new element at the designated place of the singly linked list
		// element: element to add
		// index: index to add the new element
		virtual void AddAt(T element, int index) = 0;

		// Remove the designated element from the singly linked list
		// element: element to remove
		virtual void Remove(T element) = 0;

		// Remove the designated element from the singly linked list
		// index: index of the element to remove
		virtual void RemoveAt(int index) = 0;

		// Get the length of the linear list
		int GetLength() const
		{
			return length;
		}
	};
}