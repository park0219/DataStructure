#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void) {
	// Stack의 생성 및 초기화 //
	Stack stack;
	StackInit(&stack);

	// 데이터 넣기 //
	SPush(&stack, 5.5);   SPush(&stack, 4.4);
	SPush(&stack, 3.3);   SPush(&stack, 2.2);
	SPush(&stack, 1.1);

	// 데이터 꺼내기 //
	while (!SIsEmpty(&stack)) {
		printf("현재 적재된 데이터 개수는 %d개 입니다\n", StackCount(&stack));
		printf("%.1lf \n", SPop(&stack));
	}
	printf("현재 적재된 데이터 개수는 %d개 입니다\n", StackCount(&stack));


	return 0;
}