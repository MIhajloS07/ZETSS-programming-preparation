#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next_addr;
} Node;


int main() {
	struct node* head = NULL;
	head = (Node*)malloc(sizeof(Node));
	head->data = 10;
	head->next_addr = NULL;
	printf("%d\n", head->data);
	free(head);
	return 0;
}