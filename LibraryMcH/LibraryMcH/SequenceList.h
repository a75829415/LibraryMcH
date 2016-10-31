/*
Author: McH
Date: 2016/10/24
Content: class template of sequence list
*/

#pragma once

#include "NonRestrictiveLinearListBase.h"

namespace LinearList
{
	// class for sequence list
	template <typename T> class SequenceList : public NonRestrictiveLinearListBase<T>
	{
	protected:
		T *data;
		int capacity;

	public:
		// Create a new sequence list
		// capacity: max length of the new sequence list
		SequenceList(int capacity)
		{
			this->capacity = capacity;
			data = new T[this->capacity];
			length = 0;
		}

		// Create a new sequence list from an existing one
		// L: the existing sequence list
		SequenceList(const SequenceList<T> &L)
		{
			capacity = L.capacity;
			data = new T[capacity];
			length = L.length;
			for (int i = 0; i < length; i++)
			{
				data[i] = L.data[i];
			}
		}
		// Destroy the given sequence list
		void DestroyList() override
		{
			delete data;
		}

		// Get the designated element
		// index: index of the element
		T &operator[](const int &index) const override
		{
			if (index < 0 || index > length - 1)
			{
				throw IndexOutOfBoundsException();
			}
			return data[index];
		}

		// Check if the sequence list is equal to a given non-restrictive linear list
		// L: the given list
		bool operator==(const NonRestrictiveLinearListBase<T> &L) override
		{
			if (length != L.GetLength())
			{
				return false;
			}
			for (int i = 0; i < length; i++)
			{
				if (data[i] != L[i])
				{
					return false;
				}
			}
			return true;
		}

		// Find the designated element
		// element: element to find
		int Find(T element) override
		{
			for (int i = 0; i < length; i++)
			{
				if (data[i] == element)
				{
					return i;
				}
			}
			return -1;
		}

		// Add a new element at the end of the sequence list
		// element: element to add
		void Add(T element) override
		{
			if (length == capacity)
			{
				throw OverFlowException();
			}
			data[length] = element;
			length++;
		}

		// Add a new element at the designated place of the sequence list
		// element: element to add
		// index: index to add the new element
		void AddAt(T element, int index) override
		{
			if (index < 0 || index > length)
			{
				throw IndexOutOfBoundsException();
			}
			if (length == capacity)
			{
				throw OverFlowException();
			}
			for (int i = length; i > index; i--)
			{
				data[i] = data[i - 1];
			}
			data[index] = element;
			length++;
		}

		// Remove the designated element from the sequence list
		// element: element to remove
		void Remove(T element) override
		{
			int index = Find(element);
			if (index == -1)
			{
				return;
			}
			for (int i = index; i < length; i++)
			{
				data[i] = data[i + 1];
			}
			length--;
		}

		// Remove the designated element from the sequence list
		// index: index of the element to remove
		void RemoveAt(int index) override
		{
			if (index < 0 || index > length - 1)
			{
				throw IndexOutOfBoundsException();
			}
			for (int i = index; i < length; i++)
			{
				data[i] = data[i + 1];
			}
			length--;
		}

		// Copy the first this->capacity values of the given array A
		// A: the given array
		SequenceList<T> &operator=(const T *A)
		{
			for (int i = 0; i < capacity; i++)
			{
				Add(A[i]);
			}
			return *this;
		}

		// Get the max length of the sequence list
		inline int GetCapacity() { return capacity; }
	};
}