#include <stdio.h>
#include "CircularQueue.h"

int main() {


	Queue q;
	QueueInit(&q);

	Enqueue(&q, 1);
	Enqueue(&q, 2);

	printf("%d ", Dequeue(&q));

	Enqueue(&q, 3);

	while (!QIsEmpty(&q)) {
		printf("%d ", Dequeue(&q));
	}

	return 0;
}