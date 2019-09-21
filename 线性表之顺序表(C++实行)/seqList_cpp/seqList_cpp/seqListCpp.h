#ifndef SEQLIST_H
#define SEQLIST_H

typedef int  ElemType; /* "ElemType类型根据实际情况而定， 这里假设为int */

class SeqList
{
public:
	SeqList(int size = 0); // 构造函数
	~SeqList(); // 析构函数

	bool isEmpty(); // 判断是否为空操作
	void clearList(); // 清空顺序表操作
	int getLength(); // 获取顺序表长度操作
	bool getElem(int i, ElemType *e); // 获取元素操作
	int locateElem(const ElemType e); // 查找元素位置操作
	bool appendList(const ElemType e); // 附加元素操作
	bool insertList(int i, const ElemType e); // 插入元素操作
	bool deleteList(int i, ElemType *e); // 删除元素操作
	void traverseList(); // 遍历顺序表

private:
	ElemType *m_pDataArr; // 指向存放顺序表元素的数组
	int m_length; // 顺序表的当前长度
	int m_maxSize; // 顺序表的最大容量
};

#endif