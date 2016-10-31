#include <iostream>
#include <random>
#include <time.h>
#include "LinearList.h"
using namespace std;

int main()
{
	int n(100000);
	clock_t start(0), finish(0);
	double duration(0);

	start = clock();
	SequenceList<int> L1(n);
	for (int i = 0; i < n; i++)
	{
		L1.Add(rand());
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Insert " << n << " integers into the rear of a sequent list takes "
		<< duration << " seconds" << endl;
	L1.DestroyList();

	start = clock();
	SequenceList<int> L2(n);
	for (int i = 0; i < n; i++)
	{
		L2.AddAt(rand(), rand() % (L2.GetLength() + 1));
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Insert " << n << " integers into a sequent list at a random place takes "
		<< duration << " seconds" << endl;
	L2.~SequenceList();
	L2.DestroyList();

	SinglyLinkedListWithoutHead<int> L3;
	L3.Add(0);

	getchar();
	return 0;
}