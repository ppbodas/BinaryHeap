#include "HeapUtil.h"

int HeapUtil::getParent(int pos)
{
	return (pos -1)/2;
}
int HeapUtil::getLeftChild(int pos)
{
	return 2*pos + 1;
}
int HeapUtil::getRightChild(int pos)
{
	return 2*pos + 2;
}