#include <stdio.h>
#include <stdlib.h>

int n, a[100];

void input()
{
    scanf("%d", &n);
    for (int i = 1; i <=n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 2; i <= n; i++) {
        insertionSort(i);
    }
}

void insertionSort(int i){
    int j;
    for (j = 1; j < i; j++) {
        if (a[j] <= a[i] && a[i] <= a[j + 1]) {
            
        }
    }
}