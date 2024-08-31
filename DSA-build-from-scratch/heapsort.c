#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100

void heapify(int a[], int, int);
void buildMaxHeap(int a[MAX_SIZE], int n);
void heapSort(int a[], int);
void swap(int*, int*);
int a[MAX_SIZE], n;
int main()
{
    srand(time(NULL));
    n = rand() % 10 + 1;
    int i;
    for (i = 1; i <= n; i++) {
        a[i] = rand() % 10;
        printf("%d ", a[i]);
    }
    printf("\n");
    heapSort(a, n);
    for (i = 1; i <= n; i++) printf("%d ", a[i]); 
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void heapify(int a[MAX_SIZE], int n, int i)
{
    int maxx = i, left = i * 2, right = i * 2 + 1;
    if (left <= n && a[left] < a[maxx]) maxx = left;
    if (right <= n && a[right] < a[maxx]) maxx = right;
    if (maxx != i) {
        swap(a + i, a + maxx);
        heapify(a, n, maxx);
    }
}

void buildMaxHeap(int a[MAX_SIZE], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--) {
        heapify(a, n, i);
    }
}

void heapSort(int a[MAX_SIZE], int n)
{
    buildMaxHeap(a, n);
    int i;
    for (i = n; i > 1; i--) {
        swap(a + i, a + 1);
        heapify(a, i - 1, 1);
    }
}