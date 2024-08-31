#include <stdio.h>
#include <stdlib.h>

void bina(int n);
void fibo(int n, int* mark);

int main()
{
    int n, a;
    scanf("%d", &n);
    int *mark;
    mark = (int*) malloc((n + 1) * sizeof(int));
    fibo(n, mark);
    printf("%d", mark[n]);
}

void bina(int n)
{
    if (n == 0) return;
    else {
        bina(n/2);
        printf("%d", n % 2);
    }
}

void fibo(int n, int *mark)
{
    if (n == 1 || n == 2) mark[n] = 1;
    else {
        if (!mark[n - 1]) fibo(n - 1, mark);
        if (!mark[n - 2]) fibo(n - 2, mark);
        mark[n] = mark[n - 1] + mark[n - 2];
    }
}