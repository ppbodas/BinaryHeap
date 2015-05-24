#include "BinaryHeap.h"
#include "HeapUtil.h"
#include <iomanip>

template <typename T>
CBinaryHeap<T>::CBinaryHeap(bool bSupportId = false):m_bSupportId(bSupportId)
{
}

template <typename T>
void CBinaryHeap<T>::insert(T data, int id)
{
	m_rHeapItems.push_back(std::make_shared<CHeapItem<T>>(data,id));

	int pos = m_rHeapItems.size() - 1;

	if (m_bSupportId)
	{
		//Set current location of item in map
		m_idPosMap.insert(std::make_pair<int,int>(std::forward<int>(id), std::forward<int>(pos)));
	}

	percolateUp(pos);
}
template <typename T>
std::shared_ptr <CHeapItem<T>> CBinaryHeap<T>::getMin()
{
	return m_rHeapItems[0];
}
template <typename T>
void CBinaryHeap<T>::deleteMin()
{
	if(m_rHeapItems.empty())
		return;

	int lastNode = m_rHeapItems.size() - 1;
	
	//Swap with last node
	swap(0,lastNode);
	if (m_bSupportId)
	{
		int nodeToDeleteId = m_rHeapItems[lastNode]->id;
		m_idPosMap.erase(nodeToDeleteId);
	}
	//Now remove last node
	m_rHeapItems.pop_back();

	//Now rearrange root
	percolateDown(0);
}
template <typename T>
void CBinaryHeap<T>::changeKey(int id, T value)
{
	auto iter = m_idPosMap.find(id);
	
	//Get position in heap from id
	if(iter == m_idPosMap.end())
		return;

	auto pos = iter->second;
	
	auto originalValue = m_rHeapItems[pos]->data;
	if (originalValue == value)
		return;
	//Change value here
	m_rHeapItems[pos]->data = value;

	if (value < originalValue)
		percolateUp(pos);
	else
		percolateDown(pos);

}

template <typename T>
void CBinaryHeap<T>::percolateUp(int pos)
{
	int parentPos = HeapUtil::getParent(pos);
	if (pos != parentPos)		//Equal means we reached root
	{
		std::shared_ptr <CHeapItem<T>> rParent = m_rHeapItems[parentPos];
		if (rParent->data > m_rHeapItems[pos]->data)
		{
			swap(pos,parentPos);
			percolateUp(parentPos);
		}
	}
}

template <typename T>
void CBinaryHeap<T>::percolateDown(int pos)
{
	int l = HeapUtil::getLeftChild(pos);
	int r = HeapUtil::getRightChild(pos);

	int size = m_rHeapItems.size();
	if (l >= size)
		return;

	int minPos = l;
	if (r < size)
	{
		if (m_rHeapItems[r]->data < m_rHeapItems[l]->data)
			minPos = r;
	}
	if (m_rHeapItems[pos]->data > m_rHeapItems[minPos]->data)
	{
		swap(pos, minPos);
		percolateDown(minPos);
	}
}
template <typename T>
void CBinaryHeap<T>::swap(int p1, int p2)
{
	if (p1 == p2)
		return;

	int id1 = m_rHeapItems[p1]->id;
	int id2 = m_rHeapItems[p2]->id;

	std::shared_ptr <CHeapItem<T>> rTemp = m_rHeapItems[p1];
	m_rHeapItems[p1] = m_rHeapItems[p2];
	m_rHeapItems[p2] = rTemp;

	if (m_bSupportId)
	{
		//Update new location after swap of ids
		m_idPosMap[id1] = p2;
		m_idPosMap[id2] = p1;
	}
}

template <typename T>
void CBinaryHeap<T>::postOrderPrint(int pos, int indent)
{
	auto size = m_rHeapItems.size();
	if (pos >= size)
		return;

	auto l = HeapUtil::getLeftChild(pos);
	auto r = HeapUtil::getRightChild(pos);

	if(r < size) 
	{
		postOrderPrint(r, indent+4);
	}
	if (indent) 
	{
		std::cout << std::setw(indent) << ' ';
	}
	if (r <size)
		std::cout<<" /\n" << std::setw(indent) << ' ';

	std::cout<< m_rHeapItems[pos]->data << "\n ";

	if(l < size) 
	{
		std::cout << std::setw(indent) << ' ' <<" \\\n";
		postOrderPrint(l, indent+4);
	}
}

template <typename T>
void CBinaryHeap<T>::print()
{
	postOrderPrint(0,0);
}