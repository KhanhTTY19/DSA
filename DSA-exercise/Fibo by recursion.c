#include<stdio.h>
#include<stdlib.h>

int fib(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", fib(n));
}

int fib(int n)
{
    if (n == 1 || n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}