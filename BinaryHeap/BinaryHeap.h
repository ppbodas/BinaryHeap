#pragma once
#include <vector> 
#include <map> 
#include <memory>

//Fwd Declaration
template<typename T>
struct CHeapItem
{
	CHeapItem(T d, int i):data(d), id(i){}

	T data;
	int id;
};
namespace HeapUtil
{
	
};

template<typename T>
class CBinaryHeap
{
public:
	
	explicit CBinaryHeap(bool bSupportId = false);
	~CBinaryHeap(){};

	//Interface
	void insert(T data, int id = -1);
	std::shared_ptr <CHeapItem<T>> getMin();
	void deleteMin();
	void changeKey(int id, T value);
	void print();

private:

	void percolateUp(int pos);
	void percolateDown(int pos);
	void swap(int p1, int p2);
	int getParent(int pos){return (pos -1)/2;};
	int getLeftChild(int pos){return 2*pos + 1;};
	int getRightChild(int pos){return 2*pos + 2;};

private:
	std::vector<std::shared_ptr <CHeapItem<T>>> m_rHeapItems;
	std::map<int,int>							m_idPosMap;

	bool										m_bSupportId;
};

