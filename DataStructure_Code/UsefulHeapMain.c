#include <stdio.h>
#include "UsefulHeap.h"

int DataPriorityComp(char ch1, char ch2) {
	return ch2 - ch1;   //오름차순
	//return ch1 - ch2;   //내림차순
}

int main(void) {
	Heap heap;
	HeapInit(&heap, DataPriorityComp);

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));

	while (!HIsEmpty(&heap))
		printf("%c \n", HDelete(&heap));

	return 0;
}
//UsefulHeapMain.c