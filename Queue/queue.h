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

typedef struct Queue //���ڴ��ͷ����β�ڵ�,���Ч��
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

//��ʼ��
void QueueInit(Queue* pq);

//��β����
void QueuePush(Queue* pq ,QDataType x);//��ҪͷҲҪβ��ֻ��ͷҪ��βЧ�ʺܵ�
//ԭ��Ҫ��ͷ����β�ڵ�ĵ�ַ�����ڴ��洢�����������ݵĽṹ��ĵ�ַ�����޸�ͷ����β�ڵ�
void QueuePop(Queue* pq);//��ҪͷҲҪβ��ֻ��ͷҪ��βЧ�ʺܵ�

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* q);
// ���ٶ���
void QueueDestroy(Queue* q);
