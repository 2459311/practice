//=========================================================
//	Intキュー
//==========================================================
#include "IntQueue.h"
#include <stdio.h> // printf()
#include <stdlib.h> // calloc(),free()

IntQueueResult Initialize(IntQueue* q, int max)
{
	q->num = q->front = q->rear = 0;
	q->que = (int*)calloc(max, sizeof(int));
	if (q->que == nullptr) {
		q->max = 0;
		return INITIALIZE_FAIL;
	}
	q->max = max;
	return SUCCESS;
}

IntQueueResult Enque(IntQueue* q, int x)
{
	if (q->num >= q->max) {
		return ENQUE_NO_SPACE;
	}
	else {
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max) {
			q->rear = 0;
		}
		return SUCCESS;
	}
}
IntQueueResult Deque(IntQueue* q, int* x)
{
	if (q->num <= 0) {
		return	DEQUE_NO_DATA;
	}
	else {
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max) {
			q->front = 0;
		}
		return SUCCESS;
	}
}
IntQueueResult Peek(const IntQueue* q, int* x)
{
	if (q->num <= 0) {
		return	PEEK_NO_DATA;
	}
	else {
		*x = q->que[q->front];
		return SUCCESS;
	}
}
void Clear(IntQueue* q)
{
	q->num = q->front = q->rear = 0;
}
int Capacity(const IntQueue* q)
{
	return q->max;
}
int Size(const IntQueue* q)
{
	return q->num;
}
bool IsEmpty(const IntQueue* q)
{
	return q->num <= 0;
}
bool IsFull(const IntQueue* q)
{
	return q->num == q->max;
}
int Search(const IntQueue* q, int x)
{
	for (int i = 0; i < q->num; i++) {
		int idx = (q->front + i) % q->max;
		if (q->que[idx] == x) {
			return idx;
		}
	}
	return SEARCH_NOT_FOUND; // -1
}
void Print(const IntQueue* q)
{
	for (int i = 0; i < q->num; i++) {
		int idx = (q->front + i) % q->max;
		printf("%d ", q->que[idx]);
	}
	putchar('\n');
}
void Terminate(IntQueue* q)
{
	if (q->que != nullptr) {
		free(q->que);
		q->que = nullptr;
	}
	q->max = q->num = q->front = q->rear = 0;
}
[戻る]
Daily
Front
private
Menu編集
最新の20件
2024 - 06 - 21
DailyPage / 20240621
2024 - 06 - 20
GP1 / Chapter09 / EndOfChapter
GP1 / Chapter09
GP1 / Chapter09 / BinaryTreeSample_Bug / BinaryTreeSample_Bug.cpp
GP1 / Chapter09 / BinaryTreeSample_Bug
GP1 / Chapter09 / BinaryTreeSample_Bug / BinaryTree.cpp
GP1 / Chapter09 / BinaryTreeSample_Bug / Exercise9 - 3
GP1 / Chapter09 / BinarayTreeSample_MinMax / BinaryTree.cpp
GP1 / Chapter09 / BinarayTreeSample_MinMax / BinaryTree.h
GP1 / Chapter09 / BinarayTreeSample_MinMax
GP1 / Chapter09 / BinarayTreeSample_PrintReverse / BinaryTreeSample_PrintReverse.cpp
GP1 / Chapter09 / BinarayTreeSample_PrintReverse / BinaryTree.cpp
GP1 / Chapter09 / BinarayTreeSample_PrintReverse / BinaryTree.h
GP1 / Chapter09 / BinarayTreeSample_PrintReverse
GP1 / Chapter09 / BinarayTreeSample_PrintReverse / Exercise9 - 1
GP1 / Chapter09 / BinaryTreeSample
GP1 / Chapter09 / BinarayTreeSample_MinMax / Exercise9 - 2
RecentDeleted
GP1 / Chapter09 / BinaryTreeSample / BinaryTreeSample.cpp
GP1 / Chapter09 / BinaryTreeSample / BinaryTree.cpp
