#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE (int) 1e6

int maxsum(int i);
int max(int a, int b);
int n, s[MAXSIZE], comp[MAXSIZE], a[MAXSIZE];

int main()
{
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = 0;
        comp[i] = 0;
    }
    s[1] = a[1];
    int maxsu = a[1];
    for(i = 2; i <= n; i++) {
        s[i] = max(a[i], s[i - 1] + a[i]);
    }
    for(i = 2; i <= n; i++) {
        s[1] = max(s[1], s[i]);
    }
    printf("%d", s[1]);
}

int maxsum(int i)
{
    if (i == 1) return s[i];
    if (comp[i]) return s[i];
    int res = max(a[i], a[i] + maxsum(i - 1));
    s[i] = res;
    comp[i] = 1;
    return res;
}

int max(int a, int b)
{
    if (a >= b) return a;
    return b;
}