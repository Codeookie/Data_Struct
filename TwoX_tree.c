#include<stdio.h>
#include<stdlib.h>
typedef char DataType;
typedef struct TreeNode
{
    DataType Data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

void CreatTree(TreeNode** Root,DataType* data,int* index)
{
    DataType num;
    num=data[*index];
    *index+=1;
    if(num=='#')
    {
        *Root=NULL;
    }
    else{
        *Root=(TreeNode*)malloc(sizeof(TreeNode));
        (*Root)->Data=num;
        CreatTree(&((*Root)->lchild),data,index);
        CreatTree(&((*Root)->rchild),data,index);
    }
}
void PreOrder(TreeNode* Root)
{
    if(Root==NULL)
    {
        return;
    }
    else{
        printf("%c ",Root->Data);
        PreOrder(Root->lchild);
        PreOrder(Root->rchild);
    }
}
void InOrder(TreeNode* Root){
    if(Root==NULL)
    {
        return;
    }
    else{
        InOrder(Root->lchild);
        printf("%c ",Root->Data);
        InOrder(Root->rchild);
    }
}
void PostOrder(TreeNode* Root)
{
    if(Root==NULL)
    {
        return;
    }
    else{
        PostOrder(Root->lchild);
        PostOrder(Root->rchild); 
        printf("%c ",Root->Data);
    }
}

int main(DataType* Num[])
{
    TreeNode* T;
    int index=0;
    CreatTree(&T,Num[1],&index);
    PreOrder(T);
}