#include <stdio.h>
// 소스파일에는 헤더파일에서 선언했던 요소들을 정의한다.
// 따라서 헤더파일의 내용을 먼저 가져다 놓아야 한다.
// 이를 위해 사용자가 만든 사설 헤더파일을 #include한다.
#include "ArrayList.h"

void ListInit(List *plist) {
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List *plist, LData data) {
	if (plist->numOfData > LIST_LEN) {
		puts("저장이 불가능합니다.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List *plist, LData *pdata) {
	if (plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List *plist, LData *pdata) {
	if (plist->curPosition >= (plist->numOfData) - 1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List *plist) {
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List *plist) {
	return plist->numOfData;
}

//ArrayList.c