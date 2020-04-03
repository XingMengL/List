#include "SList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����һ���µĽڵ� 
SLNode * BuySLNode( Datatype data)
{
	SLNode * newNode = (SLNode*)malloc(sizeof(SLNode));
	if(NULL == newNode)
	{
		printf("����ڵ�ʧ��\n");
	}
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}
//β��
void PushBack(SLNode ** head, Datatype data)
{
	SLNode * newNode = BuySLNode(data);

	if(*head==NULL)
	{
	//��һ���ڵ�Ĳ��뷽ʽ
	*head = newNode;
	}
	else
	{
		// �������Ѿ��нڵ���
		// β��
		//1  ���������е����һ���ڵ�
		SLNode * tail = *head;
		while(tail->next)
		{
			tail = tail->next;
		}
		// �½ڵ����������һ���ڵ����

		tail->next = newNode;

	}
}
//βɾ
void PopBack(SLNode ** head)
{
	//�ж������Ƿ����
	 assert(head);
	//������
	 if(NULL == *head)//*head = L
	 return; 
	//����ֻ��һ���ڵ�
	 else  if(NULL == (*head)->next)
	 {
		free(*head);
		*head = NULL;
	 }
	//�����ж���ڵ�
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
//ͷ��
void PushFront(SLNode ** head ,Datatype data)
{
	assert(head);
	SLNode *newNode = BuySLNode(data);
	//������
	if(NULL==*head)
	{
		*head = newNode;
		return;
	}
	else //ֻ��һ���ڵ�
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
void Destroy(SLNode ** head)//���������
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
//����ֵdata�ڵ�
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
//��posλ��֮�����data
void InsertAfter(SLNode *pos, int data)
{
	if(NULL == pos)
		return;
	SLNode* newNode = BuySLNode(data);
	newNode -> next = pos->next;
	pos->next = newNode;
}
//ɾ��posλ�õĽڵ�
void Erase(SLNode * pos)
{
	SLNode*cur =NULL;
	if(NULL==pos||NULL==pos->next)
	   return;
	cur = pos->next;
	pos->next = cur->next;
	free(cur);
}
void TestSL1()//β����
{
	SLNode * L = NULL;
	PushBack(&L,1);
	PushBack(&L,2);
	PushBack(&L,3);
	PushBack(&L,4);
	PushBack(&L,5);
	Print(L);
	printf("�����нڵ�ĸ���%d\n",Size(L));
	//PopBack(&L);
	//Print(L);
}
void TestSL2()//ͷ����
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
void TestSL3()// InsertAfter����
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
