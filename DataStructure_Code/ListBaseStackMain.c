#include <stdio.h>
#include "ListBaseStack.h"

int main(void) {
	// Stack의 생성 및 초기화
	Stack stack;
	StackInit(&stack);
	printf("적재된 자료의 갯수 : %d \n", StackCount(&stack));
	// 데이터 넣기
	SPush(&stack, 1);   SPush(&stack, 2);
	SPush(&stack, 3);
	printf("적재된 자료의 갯수 : %d \n", StackCount(&stack));
	SPush(&stack, 4);
	SPush(&stack, 5);

	// 데이터 꺼내기
	while (!SIsEmpty(&stack)) {
		printf("적재된 자료의 갯수 : %d \n", StackCount(&stack));
		printf("%d \n", SPop(&stack));
	}
	return 0;
}
