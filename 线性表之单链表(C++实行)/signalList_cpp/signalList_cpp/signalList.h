#ifndef SIGNALLIST_H
#define SIGNALLIST_H

typedef int  ElemType; /* "ElemType类型根据实际情况而定， 这里假设为int */

/* 线性表的单链表存储结构 */
typedef struct node
{
	ElemType data; // 数据域
	struct node *next; // 指针域
}Node, LinkList;

class SignalList
{
public:
	SignalList(int size = 0); // 构造函数
	~SignalList(); // 析构函数

	void clearList(); // 清空链表操作
	bool isEmpty(); // 判断是否为空操作	
	int getLength(); // 获取链表长度操作
	bool insertList(int i, const ElemType e); // 插入元素操作
	bool deleteList(int i, ElemType *e); // 删除元素操作
	bool getElem(int i, ElemType *e); // 获取元素操作
	bool insertListHead(const ElemType e); // 头部后插入元素操作
	bool insertListTail(const ElemType e); // 尾部后插入元素操作
	void traverseList(); // 遍历链表	
	int locateElem(const ElemType e); // 查找元素位置操作

private:
	LinkList *m_pList; // 单链表指针
};

#endif