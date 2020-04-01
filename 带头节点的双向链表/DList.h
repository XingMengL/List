#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <windows.h>

typedef int DataType;


typedef struct DListNode
{
	struct DListNode * next;
	struct DListNode * prev;
	DataType val;

}DListNode;

DListNode * CaterDList();
//β�� βɾ
void PushBack(DListNode * head ,int data);
void PopBack(DListNode * head);
//ͷ�� ͷɾ
void PushFront(DListNode * head, int data);
void PopFront(DListNode *head);
//��posλ��ǰ�����½ڵ�
void Insert(DListNode * pos, int data);
//ɾ��posλ�õĽڵ�
void Eraser(DListNode * pos);

DListNode * Find(DListNode * head, int data);
void Destroy(DListNode ** head);

void TestDL();