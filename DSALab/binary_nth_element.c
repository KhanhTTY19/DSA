#include<stdio.h>
#include<stdlib.h>

int n;
int *a, *mark;
void bina(int i);
int main()
{
    scanf("%d", &n);
    a = (int*) malloc((n + 1) * sizeof(int));
    mark = (int*) malloc((n + 1) * sizeof(int));
    int i = 1;
    for (i = 1; i <= n; i++) mark[i] = 0;
    bina(1);
}

void bina(int i)
{
    for (int j = 1; j <= n; j++) {
        if (i > 1) {
            if (mark[a[i - 1]] == 1)
                continue;
            a[i] = j;
            mark[a[i]] = 1;
            bina(i + 1);
            mark[a[i]] = 0;
        }
        else {
            a[i] = j;
            mark[a[i]] = 1;
            bina(i + 1);
            mark[a[i]] = 0;
        }
        if (i == n) {
            for (int j = 1; j <= n; j++) {
                printf("%d", a[j]);
            }
            printf("\n");
        } 
    }
}

