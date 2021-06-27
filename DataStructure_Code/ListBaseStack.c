#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack *pstack) {
	pstack->head = NULL;
	pstack->numOfData = 0;
}

int SIsEmpty(Stack *pstack) {
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack *pstack, Data data) {
	Node *newNode = (Node *)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
	pstack->numOfData += 1;
}

Data SPop(Stack *pstack) {
	Data rdata;
	Node *rnode;

	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);
	pstack->numOfData -= 1;
	return rdata;
}

Data SPeek(Stack *pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}

int StackCount(Stack *pstack) {
	return pstack->numOfData;
}
//ListBaseStack.c