#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int Status; // Status是函数结果状态，成功返回TRUE,失败返回FALSE

#define MAX_SIZE 100  /* 数组长度 */
typedef int  ElemType; /* "ElemType类型根据实际情况而定， 这里假设为int */
// 顺序表结构定义
typedef struct
{
	ElemType  data[MAX_SIZE];  /* 存放顺序表元素的数组，最大值为MAXSIZE */
	int length; /* 顺序表的当前长度 */
}SeqList;

SeqList *initList(); // 初始化操作
Status appendList(SeqList *pSeqList, const ElemType e); // 附加元素操作
Status insertList(SeqList *pSeqList, int i, const ElemType e); // 插入元素操作
Status deleteList(SeqList *pSeqList, int i, ElemType *e); // 删除元素操作
Status getElem(SeqList *pSeqList, int i, ElemType *e); // 获取元素操作
int locateElem(SeqList *pSeqList, const ElemType e); // 查找元素位置操作
void traverseList(SeqList *pSeqList); // 遍历顺序表
Status isEmpty(SeqList *pSeqList); // 检测是否为空操作
int getLength(SeqList *pSeqList); // 获取元素个数操作
void clearList(SeqList *pSeqList); // 清空顺序表操作
void destroyList(SeqList *pSeqList); // 销毁顺序表操作

// 初始化操作
SeqList *initList()
{
	SeqList *pSeqList = (SeqList *)malloc(sizeof(SeqList));
	if (pSeqList == NULL)
	{
		printf("initList malloc error!\n");
		exit(-1);
	}

	pSeqList->length = 0;
	return pSeqList;
}

// 附加元素操作
Status appendList(SeqList *pSeqList, const ElemType e)
{
	// 判断顺序表长度是否大于等于数组长度，是则抛出异常或动态增加容量
	if (pSeqList->length >= MAX_SIZE)
		return FALSE;

	// 在表尾后面添加元素e
	pSeqList->data[pSeqList->length] = e;

	// 表长加1
	pSeqList->length++;

	return TRUE;
}

// 插入元素操作
Status insertList(SeqList *pSeqList, int i, const ElemType e)
{
	// 判断顺序表是否已满，且插入位置是否合理
	if (pSeqList->length >= MAX_SIZE || i < 0 || i > pSeqList->length) // 可以在表尾的下一个位置插入元素
		return FALSE;

	// 从最后一个元素开始向前遍历到第i个位置，分别将它们都向后移动一个位置
	// 这种特殊情况不用后移：在表尾的下一个位置插入元素(包含第一次在位置0插入元素的情况)
	if (i != pSeqList->length)
	{
		// 将插入位置及后面元素向后移动一位
		for (int k = pSeqList->length - 1; k >= i; k--)
			pSeqList->data[k + 1] = pSeqList->data[k];
	}

	// 将要插入元素填入位置i处
	pSeqList->data[i] = e;
	// 表长加1
	pSeqList->length++;

	return TRUE;
}

// 删除元素操作
Status deleteList(SeqList *pSeqList, int i, ElemType *e)
{
	// 判断顺序表是否为空，且删除位置是否合理
	if (pSeqList->length == 0 || i < 0 || i > pSeqList->length - 1)
		return FALSE;

	// 取出删除元素
	*e = pSeqList->data[i];

	// 从删除元素的下一个位置开始遍历到最后一个元素位置，分别将它们都向前移动一个位置
	// 这种特殊情况不用前移：删除位置在表尾
	if (i != pSeqList->length - 1)
	{
		// 将删除元素的下一个位置及后面元素向前移动一位
		for (int k = i; k < pSeqList->length - 1; k++)
			pSeqList->data[k] = pSeqList->data[k + 1];
	}

	// 表长减1
	pSeqList->length--;

	return TRUE;
}

// 获取元素操作
Status getElem(SeqList *pSeqList, int i, ElemType *e)
{
	// 判断顺序表是否存在，且删除位置是否合理
	if (pSeqList == NULL || i < 0 || i > pSeqList->length - 1)
		return FALSE;

	*e = pSeqList->data[i];

	return TRUE;
}

// 查找元素位置操作
int locateElem(SeqList *pSeqList, const ElemType e)
{
	// 遍历并显示顺序表元素
	for (int i = 0; i < pSeqList->length; i++)
	{
		if (pSeqList->data[i] == e)
			return i;
	}

	return -1;
}


// 遍历操作
void traverseList(SeqList *pSeqList)
{
	for (int i = 0; i < pSeqList->length; i++)
		printf("%d ", pSeqList->data[i]);
	printf("\n");
}

// 检测是否为空操作
Status isEmpty(SeqList *pSeqList)
{
	return pSeqList->length == 0 ? TRUE : FALSE;
}

// 获取元素个数操作
int getLength(SeqList *pSeqList)
{
	return pSeqList->length;
}

// 清空顺序表操作
void clearList(SeqList *pSeqList)
{
	pSeqList->length = 0;
}

// 销毁顺序表操作
void destroyList(SeqList *pSeqList)
{
	free(pSeqList);
	pSeqList = NULL;
}

int main()
{
	// 初始化顺序表
	SeqList *pSeqList = initList();

	// 检测顺序表是否为空
	if (isEmpty(pSeqList))
		printf("顺序表为空！\n\n");
	else
		printf("顺序表不为空！\n\n");

	// 附加元素0-2到顺序表
	printf("附加元素0-2到顺序表!\n\n");
	for (int i = 0; i<3; i++)
	{
		appendList(pSeqList, i);
	}
	printf("\n");

	// 在位置2插入元素到顺序表
	printf("在位置2插入元素9到顺序表!\n\n");
	insertList(pSeqList, 2, 9);

	// 在顺序表中删除元素
	int value1;
	if (deleteList(pSeqList, 3, &value1) == FALSE)
	{
		printf("delete error!\n\n");
		return -1;
	}
	printf("在位置3删除元素，删除的元素为：%d\n\n", value1);

	// 获取元素个数
	printf("当前元素个数为%d个\n\n", getLength(pSeqList));

	// 查找元素位置
	printf("查找到元素0的位置为：%d\n\n", locateElem(pSeqList, 0));

	// 遍历并显示顺序表元素
	printf("遍历顺序表： ");
	traverseList(pSeqList);
	printf("\n");

	// 清空顺序表
	clearList(pSeqList);
	printf("清空顺序表!\n");

	// 销毁顺序表
	destroyList(pSeqList);
	printf("\n");

	return 0;
}