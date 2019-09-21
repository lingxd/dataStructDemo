#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int Status; // Status是函数结果状态，成功返回TRUE,失败返回FALSE

typedef int ElemType;
/* 线性表的单链表存储结构 */
typedef struct node
{
	ElemType data;
	struct node *next;
}Node, LinkList;

void initList(LinkList **pList); // 初始化单链表操作
Status insertList(LinkList *pList, int i, const ElemType e); // 插入元素操作
Status deleteList(LinkList *pList, int i, ElemType *e); // 删除元素操作
Status getElem(LinkList *pList, int i, ElemType *e); // 获取元素操作
Status insertListHead(LinkList *pList, const ElemType e); // 头部后插入元素操作
Status insertListTail(LinkList *pList, const ElemType e); // 尾部后插入元素操作
Status clearList(LinkList *pList); // 清空链表操作
void traverseList(LinkList *pList); // 遍历链表操作

// 初始化单链表操作
void initList(LinkList **pList) // 必须使用双重指针，一重指针申请会出错
{
	*pList = (LinkList *)malloc(sizeof(Node));
	if (!pList)
	{
		printf("malloc error!\n");
		return;
	}

	(*pList)->data = 0;
	(*pList)->next = NULL;
}

// 插入元素操作
Status insertList(LinkList *pList, int i, const ElemType e)
{
	Node *front; // 指向位置i所在的前一个结点
	int j; // 计数器

	// 判断链表是否存在
	if (!pList)
	{
		printf("list not exist!\n");
		return FALSE;
	}
	// 只能在位置1以及后面插入，所以i至少为1
	if (i < 1)
	{
		printf("i is invalid!\n");
		return FALSE;
	}

	// 找到i位置所在的前一个结点
	front = pList; // 这里是让front指向链表的第0个结点-头结点
	j = 1; // j为计数器，赋值为1，对应front指向的下一个结点，即插入位置结点
	while (front != NULL && j < i)
	{
		front = front->next;
		j++;
	}
	// 未找到i位置所在的前一个结点
	if (front == NULL)
	{
		printf("dont find front!\n");
		return FALSE;
	}
		
	// 创建一个空节点，存放要插入的新元素
	Node *temp = (Node *)malloc(sizeof(Node));
	if (!temp)
	{
		printf("malloc error!\n");
		return FALSE;
	}
	temp->data = e;

	// 插入结点
	temp->next = front->next;
	front->next = temp;

	return TRUE;
}

// 删除元素操作
Status deleteList(LinkList *pList, int i, ElemType *e)
{
	Node *front; // 指向位置i所在的前一个结点
	int j; // 计数器

	// 判断链表是否存在
	if (!pList)
	{
		printf("list not exist!\n");
		return FALSE;
	}
	// 只能删除位置1以及以后的结点
	if (i < 1)
	{
		printf("i is invalid!\n");
		return FALSE;
	}

	// 找到i位置所在的结点
	front = pList; // 这里是让front指向链表的第0个结点-头结点
	j = 1; // j为计数器，赋值为1，对应front指向的下一个结点，即插入位置结点
	while (front != NULL && j < i)
	{
		front = front->next;
		j++;
	}
	// 未找到i位置所在的前一个结点
	if (front == NULL)
	{
		printf("dont find front!\n");
		return FALSE;
	}

	// 提前保存要删除的结点
	Node *temp = front->next;
	*e = temp->data; // 将要删除结点的数据赋给e

	// 删除结点
	front->next = front->next->next;

	// 销毁结点	
	free(temp);
	temp = NULL;

	return TRUE;
}

// 获取元素操作
Status getElem(LinkList *pList, int i, ElemType *e)
{
	Node *cur;

	// 判断链表是否存在
	if (!pList)
	{
		printf("list not exist!\n");
		return FALSE;
	}
	// 只能获取位置1以及以后的元素
	if (i < 1)
	{
		printf("i is invalid!\n");
		return FALSE;
	}

	// 找到i位置所在的结点
	cur = pList->next; // 这里是让cur指向链表的第1个结点
	int j = 1; // j为计数器，赋值为1，对应cur指向结点
	while (cur != NULL && j < i)
	{
		cur = cur->next;
		j++;
	}
	// 未找到i位置所在的前一个结点
	if (cur == NULL)
	{
		printf("dont find front!\n");
		return FALSE;
	}

	// 取第i个结点的数据
	*e = cur->data;

	return TRUE;
}

// 头部后插入元素操作
Status insertListHead(LinkList *pList, const ElemType e)
{
	Node *head;
	Node *temp;

	// 判断链表是否存在
	if (!pList)
	{
		printf("list not exist!\n");
		return FALSE;
	}

	// 让head指向链表的头结点
	head = pList;

	// 创建存放插入元素的结点
	temp = (Node *)malloc(sizeof(Node));
	if (!temp)
	{
		printf("malloc error!\n");
		return FALSE;
	}
	temp->data = e;
	
	// 头结点后插入结点
	temp->next = head->next;
	head->next = temp;

	return TRUE;
}

// 尾部后插入元素操作
Status insertListTail(LinkList *pList, const ElemType e)
{
	Node *cur;
	Node *temp;

	// 判断链表是否存在
	if (!pList)
	{
		printf("list not exist!\n");
		return FALSE;
	}

	// 找到链表尾节点
	cur = pList;
	while (cur->next)
	{
		cur = cur->next;
	}

	// 创建存放插入元素的结点
	temp = (Node *)malloc(sizeof(Node));
	if (!temp)
	{
		printf("malloc error!\n");
		return -1;
	}
	temp->data = e;

	// 尾结点后插入结点
	temp->next = cur->next;
	cur->next = temp;

	return TRUE;
}

// 清空链表操作
Status clearList(LinkList *pList)
{
	Node *cur; // 当前结点
	Node *temp; // 事先保存下一结点，防止释放当前结点后导致“掉链”

	// 判断链表是否存在
	if (!pList)
	{
		printf("list not exist!\n");
		return FALSE;
	}

	cur = pList; // 指向头结点
	while (cur)
	{
		temp = cur->next; // 事先保存下一结点，防止释放当前结点后导致“掉链”
		free(cur); // 释放当前结点
		cur = temp; // 将下一结点赋给当前结点p
	}
	pList->next = NULL; // 头结点指针域指向空

	return TRUE;
}

// 遍历链表操作
void traverseList(LinkList *pList)
{
	// 判断链表是否存在
	if (!pList)
	{
		printf("list not exist!\n");
		return;
	}

	Node *cur = pList->next;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int main()
{
	LinkList *pList;

	// 初始化链表
	initList(&pList);
	printf("初始化链表!\n\n");

	// 插入结点
	insertList(pList, 1, 0);
	printf("在位置1插入元素0\n");
	insertList(pList, 2, 1);
	printf("在位置2插入元素1\n");
	insertList(pList, 1, 2);
	printf("在位置3插入元素2\n\n");

	// 删除结点
	int val;
	deleteList(pList, 2, &val);
	printf("删除位置2的结点，删除结点的数据为： %d\n", val);
	printf("\n");

	// 头部后插入元素
	insertListHead(pList, 5);
	printf("头部后插入元素5\n\n");

	// 尾部后插入元素
	insertListTail(pList, 8);
	printf("尾部后插入元素8\n\n");

	// 遍历链表并显示元素操作
	printf("遍历链表：");
	traverseList(pList);
	printf("\n");

	// 销毁链表
	clearList(pList);
	printf("销毁链表\n\n");

	return 0;
}