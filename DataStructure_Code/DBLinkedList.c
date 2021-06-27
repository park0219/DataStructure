#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List *plist) {
	plist->head = NULL;
	plist->numOfData = 0;
}
void LInsert(List *plist, Data data) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head;
	if (plist->head != NULL)
		plist->head->prev = newNode;

	newNode->prev = NULL;
	plist->head = newNode;
}

int LFirst(List *plist, Data *pdata) {
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List *plist, Data *pdata) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LPrevious(List *plist, Data *pdata) {
	if (plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

int LCount(List *plist) {
	return plist->numOfData;
}


// ���� ����
// cur��ġ�� rpos��� �����ͺ����� �߰��� ��ġ�մϴ�
// ���� �����͸� Ȯ���ϱ� ���� rpos->data�� int(Data)�� �ڷ��� rData�� ������ �������ݴϴ�
// �����ϴ� �����Ͱ� ù���� ���(head�� ��ġ)�� ���� 
// head�� head�� next��, head�� prev�� NULL�� ó��
// cur�� null�� �����ϴ�
// �׷��� ���� ���� ��������� ���� ���� ���� ��带 �������ְ�, cur�� prev�� �����ݴϴ�
// numOfdData�� 1���ҽ�Ű�� rpos�� �����Ҵ� ������ ���� ���������� rData�� �������ش�
Data LRemove(List *plist) {

	Node *rpos = plist->cur;
	Data rdata = rpos->data;

	if (rpos == plist->head) {
		plist->head = plist->head->next;
		plist->head->prev = NULL;
		plist->cur = NULL;
	}
	else {
		plist->cur->prev->next = plist->cur->next;
		plist->cur->next->prev = plist->cur->prev;
		plist->cur = plist->cur->prev;
	}

	(plist->numOfData)--;
	free(rpos);
	return rdata;
}