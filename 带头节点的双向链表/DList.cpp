#include "DList.h"


DListNode * BuynewNode(int data)
{
	DListNode * newNode = (DListNode*)malloc(sizeof DListNode);
	if(NULL == newNode)
	{
		assert(0);
		return NULL;
	}
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->val = data;

	return newNode;
}
//创建一个空链表  有一个头节点
DListNode * CaterDList()
{
	DListNode * head = BuynewNode(0);
	head->next = head;
	head->prev = head;
	return head;
}

void PushBack(DListNode * head ,int data)//尾插
{
	if(NULL == head)
		return;
	DListNode * newNode = BuynewNode(data);
	//将新节点连入链表内
	newNode->next = head;
	newNode->prev = head->prev;
	//断开原链表
	newNode->prev->next = newNode;
	head->prev = newNode;
	
	
	newNode->val =data;


}
void PopBack(DListNode * head)
{
	if(NULL==head)
		return;
	//空链表
	if(NULL == head->next)
		return;
	DListNode * pos = head->prev;

	pos->prev->next = head;
	head->prev = pos->prev;
	free(pos);
}
//头插/删
void PushFront(DListNode * head, int data)
{
   if(NULL==head)
	   return;
   DListNode * newNode = BuynewNode(data);
   //将新节点插入链表中
   newNode->prev = head;
   newNode->next = head->next;
   //断开原链表中节点
   head->next = newNode;
   newNode->next->prev = newNode;

   newNode->val = data;
}
void PopFront(DListNode *head)
{
	if(NULL == head)
		return;

	DListNode * pos = head->next;
	head->next = pos->next;
	pos->next->prev = head;
	free(pos);
}
////在pos位置前插入新节点
void Insert(DListNode * pos, int data)
{
	if(NULL == pos)
		return;
	DListNode * newNode = BuynewNode(data);
	//将新节点连入链表中
	newNode->next = pos;
	newNode->prev = pos->prev;
	//将原链表断开
	pos->prev->next = newNode;
	pos->prev = newNode;
}
void Eraser(DListNode * pos)
{
	if(NULL == pos)
	return;
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);

}
DListNode * Find(DListNode * head, int data)
{
	if(NULL==head)
		return NULL;
	DListNode * cur = head->next;
	while(cur!=head)
	{
		if(data == cur->val)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void Destroy(DListNode ** head)
{ 
	//保证链表存在
	if(NULL == head)
		return;
	//头删法
	DListNode * cur = (*head)->next;
	while(cur != *head)
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	
	}
	free(*head);
	*head = NULL;
}
void Test1()
{
	DListNode * head = CaterDList();
	PushBack(head,1);
	PushBack(head,2);
	PushBack(head,3);
	PushBack(head,4);
	//PopBack(head);
	Destroy(&head);
}
void TestDL()
{
	Test1();	
}