#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int QDataType;

typedef struct QueuqNode
{
	struct QueueNode* next;
	QDataType val;
}QNode;

typedef struct Queue //用于存放头结点和尾节点,提高效率
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

//初始化
void QueueInit(Queue* pq);

//队尾插入
void QueuePush(Queue* pq ,QDataType x);//既要头也要尾，只有头要找尾效率很低
//原本要传头结点和尾节点的地址，现在传存储它们两个数据的结构体的地址，来修改头结点和尾节点
void QueuePop(Queue* pq);//既要头也要尾，只有头要找尾效率很低

// 获取队列头部元素
QDataType QueueFront(Queue* q);
// 获取队列队尾元素
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
bool QueueEmpty(Queue* q);
// 销毁队列
void QueueDestroy(Queue* q);
