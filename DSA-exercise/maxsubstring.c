#include<stdio.h>
#include<stdlib.h>

int n;
int max(int a, int b);
int* a, s[1000];

int main()
{
    scanf("%d", &n);
    a = (int*) malloc((n + 1) * sizeof(int));
    int i;
    scanf("%d", &a[0]);
    s[0] = a[0];
    for (i = 1; i < n; i++) {
        scanf("%d", &a[i]);
        printf("%d %d %d\n", s[i - 1], s[i - 1] + a[i], a[i]);
        if (s[i - 1] > 0) s[i] = s[i - 1] + a[i];
        else s[i] = a[i];
    }
    for (i  = 1; i < n; i++) 
        s[0] = max(s[0], s[i]);
    printf("%d", s[0]);
    free(a);
}

int max(int a, int b)
{
    if (a >= b) return a;
    return b;
}