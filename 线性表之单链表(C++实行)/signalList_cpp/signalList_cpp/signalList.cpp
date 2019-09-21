#include <iostream>
#include "signalList.h"

using namespace std;

// 构造函数
SignalList::SignalList(int size)
{
	// 初始化单链表
	m_pList = new Node;
	m_pList->data = 0;
	m_pList->next = NULL;
}

// 析构函数
SignalList::~SignalList()
{
	clearList(); // 清空链表
	delete m_pList;
	m_pList = NULL;
}

// 清空链表操作
void SignalList::clearList()
{
	Node *cur; // 当前结点
	Node *temp; // 事先保存下一结点，防止释放当前结点后导致“掉链”

	cur = m_pList->next; //指向头结点
	while (cur)
	{
		temp = cur->next; // 事先保存下一结点，防止释放当前结点后导致“掉链”
		delete cur; // 释放当前结点
		cur = temp; // 将下一结点赋给当前结点
	}

	cur->next = NULL; // 注意还要将头结点的指针域指向空
}

// 判断是否为空操作
bool SignalList::isEmpty()
{
	return m_pList->next == NULL ? true : false;
}

// 获取链表长度操作
int SignalList::getLength()
{
	Node *cur = m_pList;
	int length = 0;

	while (cur->next)
	{
		cur = cur->next;
		length++;
	}

	return length;
}

// 插入元素操作
bool SignalList::insertList(int i, const ElemType e)
{
	// 判断链表是否存在
	if (!m_pList)
	{
		cout << "list not exist!" << endl;
		return false;
	}
	// 只能在位置1以及后面插入，所以i至少为1
	if (i < 1)
	{
		cout << "i is invalid!" << endl;
		return false;
	}

	// 找到位置i的前一个结点
	Node *front = m_pList; // 这里是让front指向链表的第0个结点-头结点
	int j = 1; // j为计数器，赋值为1，对应front指向的下一个结点，即插入位置结点
	while (front != NULL && j < i)
	{
		front = front->next;
		j++;
	}
	// 未找到i位置所在的前一个结点
	if (front == NULL)
	{
		cout << "dont find front!" << endl;
		return false;
	}		

	// 创建一个空节点，存放要插入的新元素
	Node *temp = new Node;
	temp->data = e;
	temp->next = NULL;

	// 插入结点s
	temp->next = front->next;
	front->next = temp;

	return true;
}

// 删除元素操作
bool SignalList::deleteList(int i, ElemType *e)
{
	// 判断链表是否存在
	if (!m_pList)
	{
		cout << "list not exist!" << endl;
		return false;
	}
	// 只能删除位置1以及后面的结点
	if (i < 1)
	{
		cout << "i is invalid!" << endl;
		return false;
	}

	// 找到位置i的前一个结点
	Node *front = m_pList; // 这里是让front指向链表的第0个结点-头结点
	int j = 1; // j为计数器，赋值为1，对应front指向的下一个结点，即插入位置结点
	while (front != NULL && j < i)
	{
		front = front->next;
		j++;
	}
	// 未找到i位置所在的前一个结点
	if (front == NULL)
	{
		cout << "dont find front!" << endl;
		return false;
	}

	// 提前保存要删除的结点
	Node *temp = front->next;
	*e = temp->data; // 将要删除结点的数据赋给e

	// 删除结点
	front->next = front->next->next;	

	// 销毁结点
	delete temp;
	temp = NULL;

	return true;
}

// 获取元素操作
bool SignalList::getElem(int i, ElemType *e)
{
	// 判断链表是否存在
	if (!m_pList)
	{
		cout << "list not exist!" << endl;
		return false;
	}
	// 只能获取位置1以及后面的元素
	if (i < 1)
	{
		cout << "i is invalid!" << endl;
		return false;
	}

	// 找到i位置所在的结点
	Node *cur = m_pList->next; // 这里是让cur指向链表的第1个结点
	int j = 1; // j为计数器，赋值为1，对应cur指向结点
	while (cur != NULL && j<i)
	{
		cur = cur->next;
		j++;
	}
	// 未找到i位置所在的前一个结点
	if (cur == NULL)
	{
		cout << "dont find front!" << endl;
		return false;
	}

	// 取第i个元素的数据
	*e = cur->data;
}

// 头部后插入元素操作
bool SignalList::insertListHead(const ElemType e)
{
	// 判断链表是否存在
	if (!m_pList)
	{
		cout << "list not exist!" << endl;
		return false;
	}

	// 让head指向链表的头结点
	Node *head = m_pList;

	// 创建存放插入元素的结点
	Node *temp = new Node;
	if (!temp)
	{
		cout << "malloc error!" << endl;
		return false;
	}
	temp->data = e;

	// 头结点后插入结点
	temp->next = head->next;
	head->next = temp;

	return true;
}

// 尾部后插入元素操作
bool SignalList::insertListTail(const ElemType e)
{
	// 判断链表是否存在
	if (!m_pList)
	{
		cout << "list not exist!" << endl;
		return false;
	}

	// 找到尾结点
	Node *cur = m_pList;
	while (cur->next)
	{
		cur = cur->next;
	}

	// 创建存放插入元素的结点
	Node *temp = new Node;
	if (!temp)
	{
		cout << "malloc error!" << endl;
		return false;
	}
	temp->data = e;

	// 尾结点后插入结点
	temp->next = cur->next;
	cur->next = temp;

	return true;
}

// 遍历链表
void SignalList::traverseList()
{
	// 判断链表是否存在
	if (!m_pList)
	{
		cout << "list not exist!" << endl;
		return;
	}

	Node *cur = m_pList->next;
	while (cur)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
}

// 查找元素位置操作
int SignalList::locateElem(const ElemType e)
{
	Node *cur = m_pList; // 当前结点
	int i = 0; // 位置索引

	while (cur->next)
	{
		cur = cur->next;
		i++;
		if (cur->data == e)
			return i;		
	}

	return -1;
}
