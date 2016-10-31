#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LibraryMcHTest
{
	TEST_CLASS(CircularSinglyLinkedListWithoutHeadTest)
	{
	private:
		const int n = 10;
		const unsigned seed = clock();
		CircularSinglyLinkedListWithoutHead<int> *L;

	public:
		TEST_METHOD_INITIALIZE(SetUp)
		{
			L = new CircularSinglyLinkedListWithoutHead<int>();
			srand(seed);
			for (int i = 0; i < n; i++)
			{
				L->Add(rand());
			}
			Logger::WriteMessage("Test initialized.\n");
		}

		TEST_METHOD_CLEANUP(TearDown)
		{
			L->DestroyList();
			delete L;
			Logger::WriteMessage("Test completed.\n");
		}

		TEST_METHOD(TestFind)
		{
			srand(seed);
			for (int i = 0; i < n; i++)
			{
				int r = rand();
				Assert::AreEqual<int>(r, L->operator[](i));
				Assert::AreEqual<int>(i, L->Find(r));
				Assert::AreEqual<int>(i, L->Find(L->operator[](i)));
			}
			Logger::WriteMessage("Find tested.\n");
		}

		TEST_METHOD(TestContains)
		{
			srand(seed);
			for (int i = 0; i < n; i++)
			{
				int r = rand();
				Assert::AreEqual<int>(r, L->operator[](i));
				Assert::AreEqual<int>(1, L->Contains(r));
				Assert::AreEqual<int>(1, L->Contains(L->operator[](i)));
			}
			Logger::WriteMessage("Contains tested.\n");
		}

		TEST_METHOD(TestAdd)
		{
			CircularSinglyLinkedListWithoutHead<int> testL;
			srand(seed);
			for (int i = 0; i < n; i++)
			{
				testL.Add(rand());
			}
			srand(seed);
			for (int i = 0; i < n; i++)
			{
				Assert::AreEqual<int>(rand(), testL[i]);
			}
			testL.DestroyList();
			Logger::WriteMessage("Add tested.\n");
		}

		TEST_METHOD(TestAddAt)
		{
			CircularSinglyLinkedListWithoutHead<int> testL;
			srand(seed);
			for (int i = 0; i < n / 2; i++)
			{
				testL.Add(rand());
			}
			for (int i = 0; i < n / 2; i++)
			{
				testL.AddAt(rand(), i);
			}
			srand(seed);
			for (int i = 0; i < n; i++)
			{
				Assert::AreEqual(rand(), testL[(i + n / 2) % n]);
			}
			testL.DestroyList();
			Logger::WriteMessage("AddAt tested.\n");
		}

		TEST_METHOD(TestRemove)
		{
			int t = rand() % n;
			int r;
			CircularSinglyLinkedListWithoutHead<int> testL;
			srand(seed);
			for (int i = 0; i < n; i++)
			{
				if (i != t)
				{
					testL.Add(rand());
				}
				else
				{
					r = rand();
				}
			}
			Assert::IsFalse(testL == *L);
			L->Remove(r);
			Assert::IsTrue(testL == *L);
			testL.DestroyList();
			Logger::WriteMessage("Remove tested.\n");
		}

		TEST_METHOD(TestRemoveAt)
		{
			int t = rand() % n;
			CircularSinglyLinkedListWithoutHead<int> testL;
			srand(seed);
			for (int i = 0; i < n; i++)
			{
				if (i != t)
				{
					testL.Add(rand());
				}
				else
				{
					rand();
				}
			}
			Assert::IsFalse(testL == *L);
			L->RemoveAt(t);
			Assert::IsTrue(testL == *L);
			testL.DestroyList();
			Logger::WriteMessage("RemoveAt tested.\n");
		}

		TEST_METHOD(TestOperatorIndexing)
		{
			srand(seed);
			for (int i = 0; i < n; i++)
			{
				Assert::AreEqual<int>(rand(), L->operator[](i));
			}
			Logger::WriteMessage("Operator \'[]\'(indexing) tested.\n");
		}

		TEST_METHOD(TestOperatorEqual)
		{
			CircularSinglyLinkedListWithoutHead<int> testL(*L);
			Assert::IsTrue(testL == *L);
			testL[0]++;
			Assert::IsFalse(testL == *L);
			testL[0]--;
			Assert::IsTrue(testL == *L);
			testL.RemoveAt(0);
			Assert::IsFalse(testL == *L);
			testL.DestroyList();
			Logger::WriteMessage("Operator \'==\'(equal) tested.\n");
		}

		TEST_METHOD(TestRear)
		{
			for (int i = 0; i < n; i++)
			{
				L->RemoveAt(n - 1);
				L->Add(1);
			}
			Assert::AreEqual<int>(1, L->operator[](n - 1));
			CircularSinglyLinkedListWithoutHead<int> testL;
			for (int i = 0; i < n; i++)
			{
				testL.Add(1);
				testL.Remove(1);
			}
			srand(seed);
			for (int i = 0; i < n - 1; i++)
			{
				testL.Add(rand());
			}
			testL.Add(1);
			Assert::IsTrue(testL == *L);
			testL.DestroyList();
		}

		TEST_METHOD(TestOther)
		{
			CircularSinglyLinkedListWithoutHead<int> testL;
			testL.Add(1);
			Assert::IsTrue(testL.Contains(1));
			Assert::IsFalse(testL.Contains(2));
		}
	};
}