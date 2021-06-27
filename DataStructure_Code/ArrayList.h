// ��������� ����� ���α׷��� "����" �ؾ��ϴ� ��Ҹ�
// ���� �ۼ��صδ� �����Դϴ�.
// �ʱ�ȭ�� ���� ���õ� ������ "�ҽ�����"����, �������
// ������ "��������" ���� ����ϱ� ������ �ҽ��ڵ带
// �����ϱ� �������ϴ�.
// ��������� ���� #ifndef�� #define�� ��ܿ� �����ؾ�
// ����� �� �ֽ��ϴ�.
// #ifndef __���ϸ�_H__ �ۼ�, #define���� �����ϰ� �ۼ��մϴ�.
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
//////////////////////////////////////////////////////////////
#include "Point.h"   //Point.h ������ ����ü�� Ÿ���ڷ�� �����Ƿ�
//////////////////////////////////////////////////////////////
#define   TRUE   1
#define   FALSE   0

/*** ArrayList�� ���� ***/
#define   LIST_LEN   100
typedef int LData;///////////////////////
//typedef Point * LData;   //LData�� Point �ڷ������� ����
//////////////////////////////////////////
typedef struct __ArrayList {
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;

/*** ArrayList�� ���õ� ����� ***/
typedef ArrayList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);
//�������ٿ��� #endif�� �ۼ��ϸ� #ifndef�� ¦�� �̷��,
#endif
//ArrayList.h