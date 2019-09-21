#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "signalList.h"

using namespace std;

int main()
{
	// 初始化链表
	SignalList signleList(20);

	cout << "插入元素0-2到链表!" << endl;
	for (int i = 0; i<3; i++)
	{
		signleList.insertList(i+1, i);
	}
	cout << endl;

	// 在位置2插入元素9到链表
	cout << "在位置2插入元素9到链表!" << endl << endl;
	signleList.insertList(2, 9);

	// 在位置3删除元素
	int value1;
	if (signleList.deleteList(3, &value1) == false)
	{
		cout << "delete error!" << endl;
		return -1;
	}
	else
	{
		cout << "在位置3删除元素，删除的元素为：" << value1 << endl << endl;
	}

	// 查找元素位置
	int index = signleList.locateElem(9);
	if (index == -1)
	{
		cout << "locate error!" << endl;
		return -1;
	}
	else
	{
		cout << "查找到元素9的位置为：" << index << endl << endl;
	}

	// 遍历链表
	cout << "遍历链表： ";
	signleList.traverseList();
	cout << endl << endl;

	// 清空链表
	cout << "清空链表!" << endl << endl;
	signleList.clearList();

	return 0;
}

