#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void) {
	// Stack�� ���� �� �ʱ�ȭ //
	Stack stack;
	StackInit(&stack);

	// ������ �ֱ� //
	SPush(&stack, 5.5);   SPush(&stack, 4.4);
	SPush(&stack, 3.3);   SPush(&stack, 2.2);
	SPush(&stack, 1.1);

	// ������ ������ //
	while (!SIsEmpty(&stack)) {
		printf("���� ����� ������ ������ %d�� �Դϴ�\n", StackCount(&stack));
		printf("%.1lf \n", SPop(&stack));
	}
	printf("���� ����� ������ ������ %d�� �Դϴ�\n", StackCount(&stack));


	return 0;
}