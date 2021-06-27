#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

//pointerlistmain.c를 참조해서 point 구조체 6개를 저장하는 코드를 만드세요
//6개를 모두 저장한 다음 2의 배수에 해당하는 y를 가진 구조체만 리스트에서 주소 삭제 및 동적할당하도록 코드를 구현해주세요
//point.c의 pointcomp 함수를 일부 수정해야한다


int main() {

	List list;
	Point compPos;
	Point *ppos;

	ListInit(&list);

	/*** 6개의 데이터 저장 ***/
	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 6);
	LInsert(&list, ppos);

	ppos = (Point *)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 4);
	LInsert(&list, ppos);
	/*** 저장된 데이터의 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	/*** ypos의 배수인 모든 데이터 삭제 ***/
	compPos.xpos = 0;
	compPos.ypos = 2;

	if (LFirst(&list, &ppos)) {
		if (PointComp(ppos, &compPos) == 1) {
			ppos = LRemove(&list);
			free(ppos);
		}

		while (LNext(&list, &ppos)) {
			if (PointComp(ppos, &compPos) == 1) {
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	/*** 삭제 후 남은 데이터 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");


	return 0;
}