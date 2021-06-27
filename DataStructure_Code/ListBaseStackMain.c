#include <stdio.h>
#include "ListBaseStack.h"

int main(void) {
	// Stack�� ���� �� �ʱ�ȭ
	Stack stack;
	StackInit(&stack);
	printf("����� �ڷ��� ���� : %d \n", StackCount(&stack));
	// ������ �ֱ�
	SPush(&stack, 1);   SPush(&stack, 2);
	SPush(&stack, 3);
	printf("����� �ڷ��� ���� : %d \n", StackCount(&stack));
	SPush(&stack, 4);
	SPush(&stack, 5);

	// ������ ������
	while (!SIsEmpty(&stack)) {
		printf("����� �ڷ��� ���� : %d \n", StackCount(&stack));
		printf("%d \n", SPop(&stack));
	}
	return 0;
}
