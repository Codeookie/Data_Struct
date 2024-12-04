#include"queue.h"
//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}
//队尾插入
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* Node=(QNode*)malloc(sizeof(QNode));
	Node->next = NULL;
	Node->val = x;
	if (pq->ptail==NULL)
	{
		pq->phead = pq->ptail = Node;
	}
	else {
		pq->ptail->next = Node;
		pq->ptail = Node;
	}
	pq->size++;
}
//队头删除
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->size != 0);
	if (!pq->phead->next)//一个节点
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else//多个节点
	{
		QNode* Next = pq->phead->next;
		free(pq->phead);
		pq->phead = Next;
	}
	pq->size--;
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->phead);
	return q->phead->val;
}

QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->ptail);
	return q->ptail->val;
}

int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

bool QueueEmpty(Queue* q)
{
	assert(q);

	return q->size == 0;
}

void QueueDestroy(Queue* q)
{
	assert(q);
	assert(q->size != 0);

	while (q->phead)
	{
		QNode* Next = q->phead->next;
		free(q->phead);
		q->phead = Next;
		q->size--;
	}

	q->phead = NULL;
	q->ptail = NULL;
	q->size = 0;
}



