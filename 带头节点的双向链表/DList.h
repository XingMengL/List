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
//尾插 尾删
void PushBack(DListNode * head ,int data);
void PopBack(DListNode * head);
//头插 头删
void PushFront(DListNode * head, int data);
void PopFront(DListNode *head);
//在pos位置前插入新节点
void Insert(DListNode * pos, int data);
//删除pos位置的节点
void Eraser(DListNode * pos);

DListNode * Find(DListNode * head, int data);
void Destroy(DListNode ** head);

void TestDL();