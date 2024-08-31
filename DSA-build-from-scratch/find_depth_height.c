#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct student {
	char mssv[7];
	int score;
}Student;

typedef struct Node{
	char name[21];
	struct Node *next;
	struct Node * tail;
}Node;


Node* makeNode(char name[21])
{
	Node *p = (Node*) malloc(sizeof(Node));
	strcpy (p->name, name);
	p->next = NULL;
	p->tail = NULL;
	return p;
}

void push(Node** qe, Node ** qetail, Node* x)
{
	if ((*qe) == NULL) {
		*qe = x;
		*qetail = NULL;
		//printf("ss");
		return;
	}
	(*qetail)->next = x;
	*qetail = x;
	(*qe)->tail = *qetail;
	//printf("ss");
}

Node* pop(Node** qe)
{
	if ((*qe) == NULL)  {
		return NULL;
	}
	Node* p = *qe;
	*qe = (*qe)->next;
	return p;
}

void bai3()
{
	int n;
	char a[8], c[21];
	scanf("%d", &n);
	char x[7], y[8];
	Node* boy, *girl, *btail, *gtail;
	boy = (Node*) malloc(sizeof(Node));
	girl = (Node*) malloc(sizeof(Node));
	boy = NULL;
	girl = NULL;
	btail = (Node*) malloc(sizeof(Node));
	gtail = (Node*) malloc(sizeof(Node));
	btail = NULL;
	gtail = NULL;
	while(1) {
		scanf("%s", a);
		if (strcmp(a, "#") == 0) break;
		scanf("%d",&n);
		scanf("%s", c);
		if (strcmp(a, "ENQUEUE") == 0){
			if (n == 0) push(&boy, &btail, makeNode(c));
			if (n == 1) push(&girl, &gtail, makeNode(c));
		}
		else {
			if (n == 0) {
				if (boy != NULL) printf("Welcome %s\n", pop(&boy)->name);
				else printf("NULL");
			}
			else {
				if (girl != NULL) printf("Welcome %s\n", pop(&girl)->name);
				else printf("NULL");
			}
		}
	}	
}


void swap(Student *a, Student *b)
{
	Student t = *a;
	*a = *b;
	*b = t;
}

void qqsort(Student arr[100000], int low, int high)
{
	if (low >= high) return;
	int pivot = arr[high].score;
	int i = low, j = high;
	while(i <= j) {
		while(arr[i].score <= pivot) i++;
		while(arr[j].score > pivot) j--;
		if (i <= j) {
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}
	qqsort(arr, low, j);
	qqsort(arr, i, high);
}

int partition(Student arr[], int low, int high)
{
	int pivot = arr[high].score;
	int i = low - 1;
	int j = low;
	while (j < high) {
		if (arr[j].score >= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i+1], &arr[high]);
	return i + 1;
}

void quicksort(Student arr[], int low, int high)
{
	if (low < high) {
		int p = partition(arr, low, high);
		quicksort(arr, low, p - 1);
		quicksort(arr, p+1, high);
	}
}
Student stu[100000];

void bai4()
{
	
	int x;
	scanf("%d", &x);
	int n = 0;
	while(1){
		scanf("%s", stu[n].mssv);
		if (stu[n].mssv[0] == '#') break;
		scanf("%d", &stu[n].score);
		n++;
	}
	qqsort(stu, 0, n - 1);
	int i = 0;
	while(i < x) {
		printf("%s %d\n", stu[i].mssv, stu[i].score);
		i++;
	}
}


int main(int argc, char *argv[]) {
	bai4();
	return 0;
}
