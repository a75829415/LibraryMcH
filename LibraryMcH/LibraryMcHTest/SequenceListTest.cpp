#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LibraryMcHTest
{
	TEST_CLASS(SequenceListTest)
	{
	private:
		const int n = 100;
		const unsigned seed = clock();
		SequenceList<int> *L;

	public:
		TEST_METHOD_INITIALIZE(SetUp)
		{
			L = new SequenceList<int>(n);
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
			SequenceList<int> testL(n);
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
			SequenceList<int> testL(n);
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
			SequenceList<int> testL(n);
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
			SequenceList<int> testL(n);
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

		TEST_METHOD(TestOperatorEqual)
		{
			SequenceList<int> testL(*L);
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

		TEST_METHOD(TestOperatorAssignment)
		{
			srand(seed);
			int *A = new int[n];
			for (int i = 0; i < n; i++)
			{
				A[i] = rand();
			}
			SequenceList<int> testL(n);
			testL = A;
			Assert::IsTrue(testL == *L);
			testL.DestroyList();
			Logger::WriteMessage("Operator \'=\'(assignment) tested.\n");
		}
	};
}