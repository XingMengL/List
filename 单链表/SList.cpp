#include "SList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//构建一个新的节点 
SLNode * BuySLNode( Datatype data)
{
	SLNode * newNode = (SLNode*)malloc(sizeof(SLNode));
	if(NULL == newNode)
	{
		printf("申请节点失败\n");
	}
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}
//尾插
void PushBack(SLNode ** head, Datatype data)
{
	SLNode * newNode = BuySLNode(data);

	if(*head==NULL)
	{
	//第一个节点的插入方式
	*head = newNode;
	}
	else
	{
		// 链表中已经有节点了
		// 尾插
		//1  先找链表中的最后一个节点
		SLNode * tail = *head;
		while(tail->next)
		{
			tail = tail->next;
		}
		// 新节点连接在最后一个节点后面

		tail->next = newNode;

	}
}
//尾删
void PopBack(SLNode ** head)
{
	//判断链表是否存在
	 assert(head);
	//空链表
	 if(NULL == *head)//*head = L
	 return; 
	//链表只有一个节点
	 else  if(NULL == (*head)->next)
	 {
		free(*head);
		*head = NULL;
	 }
	//链表有多个节点
	 else
	 {
		 SLNode * cur = *head;
		 SLNode * prev = NULL;
		 while(cur->next)
		 {
			 prev = cur;
			 cur = cur->next;
		 }
		
		 prev->next = cur->next;
	     free(cur);
	 }
	

}

void Print(SLNode *head)
{
	SLNode *cur = head;
	while(cur)
	{
		printf("%d->",cur->data);
		cur = cur->next;
	
	}
	printf("NULL\n");
}
//头插
void PushFront(SLNode ** head ,Datatype data)
{
	assert(head);
	SLNode *newNode = BuySLNode(data);
	//空链表
	if(NULL==*head)
	{
		*head = newNode;
		return;
	}
	else //只有一个节点
	{
		newNode->next = *head;
		*head = newNode;

	}
}
void PopFront(SLNode ** head)
{
	assert(head);
	SLNode *cur = NULL;
	if(NULL == *head)
	return;
	else if(NULL==(*head)->next)
	{
	  free(*head);
	  *head = NULL;
	}
	else
	{
	 cur = *head;
	 *head = (*head)->next;
	 free(cur);
	 cur =NULL;
	}
}
void Destroy(SLNode ** head)//链表的销毁
{
	assert(head);
	SLNode * cur = *head;
	while(cur)
	{
		*head = cur->next;
		free(cur);
		cur = *head;
	}

}
int Size(SLNode *head)
{
	int count = 0;
	SLNode * cur = head;
	while(cur)
	{
	count++;
	cur = cur->next;
	}
	return count;
}
//查找值data节点
SLNode* Find(SLNode*head,int data)
{
	assert(head);
	SLNode * cur = head;
	while(cur)
	{
		if(cur->data ==data)
			return cur;
		
		cur = cur->next;
	}
	return NULL;

}
//在pos位置之后插入data
void InsertAfter(SLNode *pos, int data)
{
	if(NULL == pos)
		return;
	SLNode* newNode = BuySLNode(data);
	newNode -> next = pos->next;
	pos->next = newNode;
}
//删除pos位置的节点
void Erase(SLNode * pos)
{
	SLNode*cur =NULL;
	if(NULL==pos||NULL==pos->next)
	   return;
	cur = pos->next;
	pos->next = cur->next;
	free(cur);
}
void TestSL1()//尾测试
{
	SLNode * L = NULL;
	PushBack(&L,1);
	PushBack(&L,2);
	PushBack(&L,3);
	PushBack(&L,4);
	PushBack(&L,5);
	Print(L);
	printf("链表中节点的个数%d\n",Size(L));
	//PopBack(&L);
	//Print(L);
}
void TestSL2()//头测试
{
	SLNode * L = NULL;
	PushFront(&L,1);
	PushFront(&L,2);
	PushFront(&L,3);
	PushFront(&L,4);
	PushFront(&L,5);
	Print(L);
	PopFront(&L);
	Print(L);
}
void TestSL3()// InsertAfter测试
{
	SLNode * L = NULL;
	PushBack(&L,1);
	PushBack(&L,2);
	PushBack(&L,3);
	PushBack(&L,4);
	InsertAfter(Find(L,3),6);
	PushBack(&L,5);
	Print(L);
	
}

void TestSL()
{
	//TestSL1();
	//TestSL2();
	TestSL3();
}
