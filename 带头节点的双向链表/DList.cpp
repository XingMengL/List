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
//����һ��������  ��һ��ͷ�ڵ�
DListNode * CaterDList()
{
	DListNode * head = BuynewNode(0);
	head->next = head;
	head->prev = head;
	return head;
}

void PushBack(DListNode * head ,int data)//β��
{
	if(NULL == head)
		return;
	DListNode * newNode = BuynewNode(data);
	//���½ڵ�����������
	newNode->next = head;
	newNode->prev = head->prev;
	//�Ͽ�ԭ����
	newNode->prev->next = newNode;
	head->prev = newNode;
	
	
	newNode->val =data;


}
void PopBack(DListNode * head)
{
	if(NULL==head)
		return;
	//������
	if(NULL == head->next)
		return;
	DListNode * pos = head->prev;

	pos->prev->next = head;
	head->prev = pos->prev;
	free(pos);
}
//ͷ��/ɾ
void PushFront(DListNode * head, int data)
{
   if(NULL==head)
	   return;
   DListNode * newNode = BuynewNode(data);
   //���½ڵ����������
   newNode->prev = head;
   newNode->next = head->next;
   //�Ͽ�ԭ�����нڵ�
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
////��posλ��ǰ�����½ڵ�
void Insert(DListNode * pos, int data)
{
	if(NULL == pos)
		return;
	DListNode * newNode = BuynewNode(data);
	//���½ڵ�����������
	newNode->next = pos;
	newNode->prev = pos->prev;
	//��ԭ����Ͽ�
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
	//��֤�������
	if(NULL == head)
		return;
	//ͷɾ��
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