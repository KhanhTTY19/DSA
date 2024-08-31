#include<stdio.h>
#include<stdlib.h>

int c(int k, int n);
unsigned long long c2(int k, int n);
unsigned long long D[1000][1000];

int main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    memset(D, 0, sizeof(D));
    printf("%llu", c2(k, n));
}

unsigned long long c2(int k, int n) 
{
    if (n == k || k == 0) {
        D[k][n] = 1;
    }
    else {
        if (D[k][n] == 0) {
            D[k][n] = c2(k, n - 1)% 1000000007 + c2(k - 1, n - 1)% 1000000007;
        }
    }
    return (D[k][n] % 1000000007);
}

int c(int k, int n)
{
    if (k == n) {
        return 1;
    }
    else if (k == 0) {
        return 1;
    }
    else 
    {
        return (c(k - 1, n - 1) + c(k, n - 1))%(1000000000 + 7);
    }
}
