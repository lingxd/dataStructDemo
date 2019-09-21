#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "seqListCpp.h"

using namespace std;

int main()
{
	// 初始化顺序表
	SeqList seqList(20);

	// 附加元素0-2到顺序表
	cout << "附加元素0-2到顺序表!" << endl;
	for (int i = 0; i<3; i++)
	{
		seqList.appendList(i);
	}
	cout << endl;

	// 在位置2插入元素到9顺序表
	cout << "在位置2插入元素9到顺序表!" << endl << endl;
	seqList.insertList(2, 9);

	// 在位置3删除元素
	int value1;
	if (seqList.deleteList(3, &value1) == false)
	{
		cout << "delete error!" << endl;
		return -1;
	}
	else
	{
		cout << "在位置3删除元素，删除的元素为：" << value1 << endl << endl;
	}

	// 查找元素位置
	int index = seqList.locateElem(0);
	if (index == -1)
	{
		cout << "locate error!" << endl;
		return -1;
	}
	else
	{
		cout << "查找到元素0的位置为：" << index << endl << endl;
	}

	// 遍历顺序表
	cout << "遍历顺序表： ";
	seqList.traverseList();
	cout << endl;

	// 清空顺序表
	cout << "清空顺序表!" << endl << endl;
	seqList.clearList();

	return 0;
}

