#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"
int main()
{
	////顺序表扩容
	////原地扩容
	////异地扩容
	//int* p1 = (int*)malloc(8);
	//int* p2 = (int*)realloc(p1, 80);
	////扩容位置是随机的，扩大很多一般异地，很小一般原地

	////寄存器和缓冲区
	//int i = 0;
	//++i;//把i放入eax寄存器中，然后对寄存器++,再将值放回到i中
	//	//为什么？：cpu太快，直接访问内存对数据++太慢了，把内存加载到寄存器里运算，最后整合到内存里
	//	//当数据较小（4-8byte）时会放入寄存器，大数据加载到三级缓存区中
	//i++;
	//printf("%p\n", p1);
	//printf("%p\n", p2);
	ST S;

	//入栈1,2,3,4
	//出栈：不一定是4321，有很多种，可以边进边出，比如入一个出一个，所以出栈的顺序是相对在栈中的顺序
	STInit(&S);
	STPush(&S, 1);
	STPush(&S, 2);
	STPush(&S, 3);
	STPush(&S, 4);

	int top = STTop(&S);
	printf("%d\n", top);
	STPop(&S);
	top = STTop(&S);
	printf("%d", top);

}