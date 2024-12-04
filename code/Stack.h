#pragma once
//ջ��ʹ�ã���Ҫ�����ȳ�ʱ�����Կ���ջ
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int STDataType;//ջ������������Ҫ�޸�ʱ���ӷ���

//ջ��ģ�����ǿ���ѡȡ��̬˳������飩��������˫����������ָ�룩
//�������ͷ��ͷɾ�ܷ��㣬��ͷ��Ϊջ�����ɡ�
//˳�����ã�ȱ��ֻ�����ݣ������CPU���ٻ�����ã�Ч�ʸ���

typedef struct Stack
{
	STDataType* a;
	int top;//ջ��Ԫ��
	int capacity;//����
}ST;

void STInit(ST* pst);//��ʼ��
void STDestroy(ST* pst);//����
void STPush(ST* pst,STDataType x);//ѹջ������
void STPop(ST* pst);//��ջɾ����
STDataType STTop(ST* pst);//��ȡջ������
bool STEmpty(ST* pst);
int STSize(ST* pst);
