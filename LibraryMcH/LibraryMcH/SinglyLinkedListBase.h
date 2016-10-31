/*
Author: McH
Date: 2016/10/27
Content: base class template for singly linked list
*/

#pragma once

#include "LinkedListBase.h"

namespace LinearList
{
	// base class for singly linked list
	template <typename T> class SinglyLinkedListBase : public LinkedListBase<T>
	{
	protected:
		SLNode<T> *head, *rear;

		// Get the head pointer
		inline SLNode<T> *GetHead() const override { return head; }
	};
}
