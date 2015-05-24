#include <iostream>
#include <string>
#include "BinaryHeap.h"
#include "BinaryHeap.cpp"
using namespace std;

void setStream()
{
	cout << std::setfill('*') << std::setw(30);
}
void resetStream()
{
	cout <<std::setfill(' ')<< setw(0);
}
void printSeperator()
{
	setStream();
	cout << "*" << endl;
	resetStream();
}
int main()
{
	CBinaryHeap<int> heap(true);
	int arr[] = {100, 4, 10, -1000, 300, 20};

	int num = sizeof(arr)/ sizeof(int);
	
	for (int i = 0; i < num; ++i)
	{
		heap.insert(arr[i], i);
		heap.print();
		printSeperator();
	}
	cout << "Insert Complete" << endl;
	vector<int> outPut;
	outPut.reserve(num);
	for (int i = 0; i < num; ++i)
	{
		auto out = heap.getMin();
		outPut.push_back(out->data);
		
		heap.deleteMin();
		
		printSeperator();

		heap.print();
	}

	for(auto elm : outPut)
		cout << elm << endl;
}