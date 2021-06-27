#include <stdio.h>
#include "ListBaseQueue.h"

int main() {

	Queue q;
	QueueInit(&q);

	Enqueue(&q, 10);
	Enqueue(&q, 20);
	Enqueue(&q, 30);
	Enqueue(&q, 40);

	printf("%d ", Dequeue(&q));
	printf("%d ", Dequeue(&q));

	Enqueue(&q, 50);
	Enqueue(&q, 60);
	Enqueue(&q, 70);

	while (!QIsEmpty(&q)) {
		printf("%d ", Dequeue(&q));
	}

	return 0;
}