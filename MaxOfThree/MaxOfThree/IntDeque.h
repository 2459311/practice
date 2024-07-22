#pragma once
//=========================================================
//	Int�f�b�N
//==========================================================
#ifndef __IntDeque
#define __IntDeque

typedef struct {
	int max;  // �L���[�̗e��
	int num;  // ���݂̃f�[�^��
	int front; // �擪�v�f�̃J�[�\��
	int rear;  // �����v�f�̃J�[�\��
	int* que;  // �L���[�{��
} IntDeque;

typedef enum {
	SUCCESS = 0,
	INITIALIZE_FAIL = 1,
	ENQUE_NO_SPACE = 2,
	DEQUE_NO_DATA = 3,
	PEEK_NO_DATA = 4,
} IntDequeResult;

#define SEARCH_NOT_FOUND (-1)

// �L���[�̏�����
IntDequeResult Initialize(IntDeque* q, int max);
// �L���[�t�����g�Ƀf�[�^���G���L���[����
IntDequeResult EnqueFront(IntDeque* q, int x);
// �L���[���A�Ƀf�[�^���G���L���[����
IntDequeResult EnqueRear(IntDeque* q, int x);
// �L���[�t�����g����f�[�^���f�L���[����
IntDequeResult DequeFront(IntDeque* q, int* x);
// �L���[���A����f�[�^���f�L���[����
IntDequeResult DequeRear(IntDeque* q, int* x);
// �L���[�t�����g����f�[�^���s�[�N����
IntDequeResult PeekFront(const IntDeque* q, int* x);
// �L���[���A����f�[�^���s�[�N����
IntDequeResult PeekRear(const IntDeque* q, int* x);
// �S�f�[�^���폜
void Clear(IntDeque* q);
// �L���[�̗e��
int Capacity(const IntDeque* q);
// �L���[��̃f�[�^��
int Size(const IntDeque* q);
// �L���[�͋�?
bool IsEmpty(const IntDeque* q);
// �L���[�͖��t��?
bool IsFull(const IntDeque* q);
// �L���[����f�[�^��T������
int Search(const IntDeque* q, int x);
// �S�f�[�^�̕\��
void Print(const IntDeque* q);
// �L���[�̌�n��
void Terminate(IntDeque* q);

#endif // __IntDeque