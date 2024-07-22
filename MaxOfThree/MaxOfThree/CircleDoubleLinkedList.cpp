//=========================================================
//	�z�E�d�A�����X�g
// --------------------------------------------------------
//  list.head 
//        ��     (�擪)                       (����)
//     �_�~�[ �� �f�[�^1 �� �f�[�^2 ��.... �� �f�[�^N 
//        ��                                    �b
//        �{??????????????????�{
//=========================================================
#include "CircleDoubleLinkedList.h"
#include <stdio.h>  // printf()
#include <stdlib.h> // exit()

// �֐��v���g�^�C�v
static DblNode* allocDblNode();
static void setDblNode(DblNode* node, const Member* x, const DblNode* prev, const DblNode* next);
static bool isEmpty(const DblList* list);

// ������
void Initialize(DblList* list)
{
	// �_�~�[�m�[�h���g�b�v�A���ڂɂ���
	DblNode* dummy = allocDblNode();
	dummy->prev = dummy;
	dummy->next = dummy;
	list->head = dummy;
	list->current = dummy;
}
// ���ڃm�[�h�̃f�[�^��\��
void PrintCurrent(const DblList* list)
{
	if (isEmpty(list)) {
		printf("���ڃm�[�h�͂���܂���");
	}
	else {
		PrintMember(&list->current->data);
	}
}
// ���ڃm�[�h�̃f�[�^��\��(���s��)
void PrintLnCurrent(const DblList* list)
{
	PrintCurrent(list);
	putchar('\n');
}
DblNode* Search(DblList* list, const Member* x, int compare(const Member* a, const Member* b))
{
	DblNode* ptr = list->head->next;
	while (ptr != list->head) {
		if (compare(&ptr->data, x) == 0) {
			list->current = ptr;
			return ptr;
		}
		ptr = ptr->next;
	}
	return nullptr;
}
// �S�m�[�h�̕\��
void Print(const DblList* list)
{
	if (isEmpty(list)) {
		puts("�m�[�h������܂���");
	}
	else {
		DblNode* head = list->head;
		DblNode* ptr = head->next;
		puts("�y�ꗗ�\�z");
		while (ptr != head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->next;
		}
	}
}
// �S�m�[�h�̕\��(�t��)
// �S�m�[�h�̃f�[�^�����X�g�̋t���ɕ\�� 
void PrintReverse(const DblList* list)
{
	if (isEmpty(list)) {
		puts("�m�[�h������܂���");
	}
	else {
		DblNode* head = list->head;
		DblNode* ptr = head->prev;
		puts("�y�ꗗ�\�z");
		while (ptr != head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->prev;
		}
	}
}
// ���ڃm�[�h��1����ɐi�߂�(�����t���O��Ԃ�)
bool Next(DblList* list)
{
	DblNode* cur = list->current;
	if (isEmpty(list) || cur->next == list->head) {
		// �i�߂邱�Ƃ͂ł��Ȃ�
		return false;
	}
	list->current = cur->next;
	return true;
}
// ���ڃm�[�h��1�O���ɖ߂�(�����t���O��Ԃ�)
bool Prev(DblList* list)
{
	DblNode* cur = list->current;
	if (isEmpty(list) || cur->prev == list->head) {
		// �߂����Ƃ͂ł��Ȃ�
		return false;
	}
	list->current = cur->prev;
	return true;
}
// p���w���m�[�h�̒���Ƀm�[�h��}��
void InsertAfter(DblList* list, DblNode* p, const Member* x)
{
	DblNode* newNode = allocDblNode();
	DblNode* next = p->next;
	setDblNode(newNode, x, p, p->next);
	p->next = newNode;
	next->prev = newNode;
	list->current = newNode;
}
// �擪�Ƀm�[�h��}��
void InsertFront(DblList* list, const Member* x)
{
	InsertAfter(list, list->head, x);
}
// �����Ƀm�[�h��}��
void InsertRear(DblList* list, const Member* x)
{
	InsertAfter(list, list->head->prev, x);
}
// p���w���m�[�h���폜
void Remove(DblList* list, DblNode* p)
{
	DblNode* prev = p->prev;
	DblNode* next = p->next;
	prev->next = next;
	next->prev = prev;
	free(p);
	// ���ڂ́A�폜�m�[�h�̎�O
	list->current = prev;
	if (list->current == list->head) {
		list->current = list->head->next;
	}
}
// �擪�m�[�h���폜
void RemoveFront(DblList* list)
{
	if (isEmpty(list) == false) {
		Remove(list, list->head->next);
	}
}
// �����m�[�h���폜
void RemoveRear(DblList* list)
{
	if (isEmpty(list) == false) {
		Remove(list, list->head->prev);
	}
}
void RemoveCurrent(DblList* list)
{
	DblNode* cur = list->current;
	if (cur != list->head) {
		Remove(list, cur);
	}
}
// �S�m�[�h���폜
void Clear(DblList* list)
{
	while (isEmpty(list) == false) {
		RemoveFront(list);
	}
}
// �z�E�d�A�����X�g�̌�n��
void Terminate(DblList* list)
{
	Clear(list);
	free(list->head);
	list->head = nullptr;
}
// �m�[�h����
static DblNode* allocDblNode()
{
	DblNode* node = (DblNode*)calloc(1, sizeof(DblNode));
	if (node == nullptr) {
		puts("calloc���s");
		exit(1);
	}
	return node;
}
// �m�[�h�̃����o�[�ݒ�
static void setDblNode(DblNode* node, const Member* x, const DblNode* prev, const DblNode* next)
{
	node->data = *x;
	node->prev = (DblNode*)prev;
	node->next = (DblNode*)next;
}
// ���X�g�͋�?
static bool isEmpty(const DblList* list)
{
	DblNode* head = list->head;
	return head->next == head;
}
