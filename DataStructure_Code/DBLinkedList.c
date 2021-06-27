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


// 삭제 연산
// cur위치에 rpos라는 포인터변수를 추가로 배치합니다
// 삭제 데이터를 확인하기 위해 rpos->data를 int(Data)형 자료인 rData를 선언해 저장해줍니다
// 삭제하는 데이터가 첫번쨰 노드(head와 일치)할 경우는 
// head를 head의 next로, head의 prev는 NULL로 처리
// cur는 null로 보냅니다
// 그렇지 않은 경우는 삭제노드의 이전 노드와 다음 노드를 연결해주고, cur는 prev로 보내줍니다
// numOfdData를 1감소시키고 rpos를 동적할당 해제한 다음 마지막으로 rData를 리턴해준다
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