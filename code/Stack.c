#include "Stack.h"

void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	//栈为空，top初始化为0时，栈顶指针指向栈底data[0],指向栈顶元素（此时栈为空，实际位置为data[-1]）的下一个位置。例如：栈顶元素为0，top指向1位置。相当于size
	pst->top = 0;//a[top]指向栈顶元素的下一个，因为此时栈顶元素为空。
	//初始化为-1时，栈顶指针指向data[-1]，栈底是data[0].指向栈顶元素的下标。
	//pst->top = -1;a[top]就是栈顶元素
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

//插入数据，入栈
void STPush(ST* pst, STDataType x)
{
	assert(pst);
	//扩容
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
	//插入
	pst->a[pst->top] = x;
	pst->top++;
}
//删除数据，出栈
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	pst->top--;//直接删除最后一个数组元素
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	//top指向栈顶元素下一个，a[top-1]才是栈顶
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
