#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//�Ǽ��� �Էµǵ��� ����
//%g 0�� �Ҽ��� ǥ�� ����

typedef struct _node {
	double data;
	struct _node *next;
} Node;

int main(void) {
	Node *head = NULL;   //NULL�� �����ͺ��� �ʱ�ȭ
	Node *tail = NULL;
	Node *cur = NULL;

	Node *newNode = NULL;
	double readData;

	/*�����͸� �Է¹޴� ����*/
	while (1) {
		printf("�Ǽ� �Է�: ");
		scanf("%lf", &readData);
		if (readData < 1)
			break;
		/* ����� �߰����� */
		newNode = (Node *)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;
	}
	printf("\n");

	/* �Է� ���� �������� ��°��� */
	printf("�Է� ���� �������� ��ü���! \n");
	if (head == NULL) {
		printf("����� �Ǽ��� �������� �ʽ��ϴ�. \n");
	}
	else {
		cur = head;
		printf("%g ", cur->data);   //ù ��° ������ ���

		while (cur->next != NULL) {   //�� ��° ������ ������ ���
			cur = cur->next;
			printf("%g ", cur->data);
		}
	}
	printf("\n\n");

	/*�޸��� ��������*/
	if (head == NULL) {
		return 0;   //������ ��尡 �������� �ʴ´�.
	}
	else {
		Node *delNode = head;
		Node *delNextNode = head->next;

		printf("%g��(��) �����մϴ�. \n", head->data);
		free(delNode); // ù ��° ����� ����

		while (delNextNode != NULL) {   //�� ��° ���� ������
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%g��(��) �����մϴ�. \n", delNode->data);
			free(delNode);   //�� ��° ���� ��� ����
		}
	}
	return 0;
}
//LinkedRead.c