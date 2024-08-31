#include<stdio.h>

int main()
{
    int A[] = {5, 10, 15, 20};
    int row = 4;
    for (int i = 0; i < row; i++) {
        printf("%u %d\n", &A[i], A[i]);
    }
}