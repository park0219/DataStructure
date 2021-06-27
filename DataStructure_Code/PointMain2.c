#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

//pointerlistmain.c�� �����ؼ� point ����ü 6���� �����ϴ� �ڵ带 ���弼��
//6���� ��� ������ ���� 2�� ����� �ش��ϴ� y�� ���� ����ü�� ����Ʈ���� �ּ� ���� �� �����Ҵ��ϵ��� �ڵ带 �������ּ���
//point.c�� pointcomp �Լ��� �Ϻ� �����ؾ��Ѵ�


int main() {

	List list;
	Point compPos;
	Point *ppos;

	ListInit(&list);

	/*** 6���� ������ ���� ***/
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
	/*** ����� �������� ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	/*** ypos�� ����� ��� ������ ���� ***/
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

	/*** ���� �� ���� ������ ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");


	return 0;
}