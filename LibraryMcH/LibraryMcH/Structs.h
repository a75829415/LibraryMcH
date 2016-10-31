/*
Author: McH
Date: 2016/10/29
Content: structs used in linear lists
*/

#pragma once

namespace LinearList
{
	// base struct for all linked list nodes
	template <typename T> struct LNode
	{
		T data;

		LNode(T data) : data(data) {}

		inline virtual LNode *GetNext() = 0;
	};

	// struct for singly linked list node
	template <typename T> struct SLNode : public LNode<T>
	{
		SLNode *next;

		SLNode(T data, SLNode<T> *next) : LNode<T>(data), next(next) {}

		inline SLNode *GetNext() override { return next; }
	};

	// struct for doubly linked list node
	template <typename T> struct DLNode : public LNode<T>
	{
		DLNode *pred, *next;

		DLNode(T data, DLNode<T> *pred, DLNode<T> *next) : LNode<T>(data), pred(pred), next(next) {}

		inline DLNode *GetNext() override { return next; }
	};
}
