#include "Stack.h"

void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	//ջΪ�գ�top��ʼ��Ϊ0ʱ��ջ��ָ��ָ��ջ��data[0],ָ��ջ��Ԫ�أ���ʱջΪ�գ�ʵ��λ��Ϊdata[-1]������һ��λ�á����磺ջ��Ԫ��Ϊ0��topָ��1λ�á��൱��size
	pst->top = 0;//a[top]ָ��ջ��Ԫ�ص���һ������Ϊ��ʱջ��Ԫ��Ϊ�ա�
	//��ʼ��Ϊ-1ʱ��ջ��ָ��ָ��data[-1]��ջ����data[0].ָ��ջ��Ԫ�ص��±ꡣ
	//pst->top = -1;a[top]����ջ��Ԫ��
	pst->capacity = 0;  
}

void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;
}

//�������ݣ���ջ
void STPush(ST* pst, STDataType x)
{
	assert(pst);
	//����
	if (pst->top == pst->capacity)
	{
		int newcapacity = (pst->capacity==0?4: pst->capacity * 2);
		STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity* sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	//����
	pst->a[pst->top] = x;
	pst->top++;
}
//ɾ�����ݣ���ջ
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	pst->top--;//ֱ��ɾ�����һ������Ԫ��
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	//topָ��ջ��Ԫ����һ����a[top-1]����ջ��
	return pst->a[pst->top - 1];
}

bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}

int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}
