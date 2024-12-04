#pragma once
//栈的使用：当要求后进先出时，可以考虑栈
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int STDataType;//栈中数据类型需要修改时更加方便

//栈的模拟我们可以选取动态顺序表（数组），单链表，双向链表（两个指针）
//单链表的头插头删很方便，把头作为栈顶即可。
//顺序表更好，缺点只有扩容，数组的CPU高速缓存更好，效率更高

typedef struct Stack
{
	STDataType* a;
	int top;//栈顶元素
	int capacity;//容量
}ST;

void STInit(ST* pst);//初始化
void STDestroy(ST* pst);//销毁
void STPush(ST* pst,STDataType x);//压栈入数据
void STPop(ST* pst);//出栈删数据
STDataType STTop(ST* pst);//获取栈顶数据
bool STEmpty(ST* pst);
int STSize(ST* pst);
