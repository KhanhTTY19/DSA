#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y);
int partitition(int a[100], int left, int right);
void sort(int a[100], int left, int right);

int n, a[100];
int main()
{
    srand(time(NULL));
    
    n = rand() % 10 + 1;
    for (int i = 1; i <= n; i++) {
        a[i] = rand() % (10) + 1;
    }
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    sort(a, 1, n);
    printf("\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
}

void swap(int *x, int *y)
{
    int p = *x;
    *x = *y;
    *y = p;
}

int partitition(int a[100], int left, int right)
{
    if (left < right) {
        int pivot = a[right], i = left - 1;
        for (int j = left; j < right; j++) {
            if (a[j] < pivot) {
                i++;
                swap(a + i, a + j);
            }
        }
        swap(a + i + 1, a + right);
        return i + 1;
    }
}

void sort(int a[100], int left, int right)
{
    if (left < right){
        int mid = partitition(a, left, right);
        sort(a, left, mid - 1);
        sort(a, mid + 1, right);
    }
}