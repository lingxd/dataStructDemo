#include <iostream>
#include "seqListCpp.h"

using namespace std;

// 构造函数
SeqList::SeqList(int size)
{
	// 初始化顺序表的最大容量
	m_maxSize = size; 
	// 初始化存放顺序表元素的数组
	m_pDataArr = new ElemType[m_maxSize];
	// 初始化顺序表的当前长度
	m_length = 0;
}

// 析构函数
SeqList::~SeqList()
{
	delete[] m_pDataArr;
	m_pDataArr = NULL;
}

// 判断是否为空操作
bool SeqList::isEmpty()
{
	return m_length == 0 ? true : false;
}

// 获取顺序表长度操作
int SeqList::getLength() 
{
	return m_length;
}

// 清空顺序表操作
void SeqList::clearList()
{
	m_length = 0;
}

// 获取元素操作
bool SeqList::getElem(int i, ElemType *e)
{
	// 前提条件: 顺序表已存在，且i在合理范围内：0 <= i <= m_length
	if (m_length == 0 || i < 0 || i > m_length) // 若m_length==0，则说明顺序表不存在
		return false;

	*e = m_pDataArr[i];

	return true;
}

// 查找元素位置操作
int SeqList::locateElem(const ElemType e)
{
	// 遍历并显示顺序表元素
	for (int i = 0; i < m_length; i++)
	{
		if (m_pDataArr[i] == e)
			return i;
	}

	return -1;
}

// 附加元素操作
bool SeqList::appendList(const ElemType e)
{
	// 判断顺序表长度是否大于等于数组长度，是则抛出异常或动态增加容量
	if (m_length >= m_maxSize)
		return false;

	// 在表尾后面添加元素e
	m_pDataArr[m_length] = e;

	// 表长加1
	m_length++;

	return true;
}

// 插入元素操作
bool SeqList::insertList(int i, const ElemType e)
{
	// 判断顺序表是否未满 且 i是否在合法范围内
	if (m_length >= m_maxSize || i < 0 || i > m_length) // 允许i在表尾下一个位置插入
		return false;

	// 从最后一个元素开始向前遍历到第i个位置，分别将它们都向后移动一个位置
	if (i <= m_length - 1) // 在表尾下一个位置插入的这种情况，不用后移
	{
		for (int k = m_length - 1; k >= i; k--)
		{
			m_pDataArr[k + 1] = m_pDataArr[k];
		}
	}

	// 将要插入元素填入位置i处
	m_pDataArr[i] = e;
	// 表长+1
	m_length++;

	return true;
}

// 删除元素操作
bool SeqList::deleteList(int i, ElemType *e)
{
	// 判断顺序表是否未满 且 i是否在合法范围内
	if (m_length == 0 || i<0 || i > m_length - 1)
		return false;

	// 取出删除元素
	*e = m_pDataArr[i];

	// 从删除元素的下一个位置开始遍历到最后一个元素位置，分别将它们都向前移动一个位置
	if (i != m_length - 1) // 【若删除位置在表尾，则不需要前移】
	{
		// 将删除元素的下一个位置及后面元素向前移动一位
		for (int k = i; k < m_length - 1; k++)
			m_pDataArr[k] = m_pDataArr[k + 1];
	}

	// 表长减1
	m_length--;

	return true;
}

// 遍历顺序表
void SeqList::traverseList()
{	
	// 判断顺序表是否存在，以及是否为空表
	if (m_pDataArr == NULL || m_length == 0)
		return;

	for (int i = 0; i < m_length; i++)
	{
		cout << m_pDataArr[i] << " ";
	}
	cout << endl;
}

