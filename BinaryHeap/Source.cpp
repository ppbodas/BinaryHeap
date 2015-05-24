#include <iostream>
#include <string>
#include "BinaryHeap.h"
#include "BinaryHeap.cpp"
using namespace std;


int main()
{
	CBinaryHeap<int> heap(true);
	int arr[] = {100, 4, 10, -1000, 300, 20};

	int num = sizeof(arr)/ sizeof(int);
	
	for (int i = 0; i < num; ++i)
	{
		heap.insert(arr[i], i);
	}
	heap.print();

	//heap.changeKey(3, 1000);
	
	heap.print();
	for (int i = 0; i < num; ++i)
	{
		auto out = heap.getMin();
		cout << out->data << endl;
		heap.deleteMin();

		//heap.print();
	}

}