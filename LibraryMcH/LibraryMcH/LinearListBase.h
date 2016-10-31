/*
Author: McH
Date: 2016/10/26
Content: base class template for all linear lists
*/

#pragma once

#include "Exceptions.h"
#include "Structs.h"

namespace LinearList
{
	// base class for all linear lists
	template <typename T> class LinearListBase
	{
	public:
		// Destroy the given linear list
		virtual void DestroyList() = 0;
	};
}