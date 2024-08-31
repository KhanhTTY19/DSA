#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void travel(int i);
int price[MAX_SIZE][MAX_SIZE], mark[MAX_SIZE], n, save, min = 100000;
int main()
{
    scanf("%d", &n);
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &price[i][j]);
        }
    }
    travel(1);
    printf("%d", min);
}

void travel(int i)
{
    for (int j = 1; j <= n; j++) {
        if (!mark[j] && price[i][j]) {
            
            save += price[i][j];
            mark[j] = 1;

            if (i == n) {
                if (save + price[j][1] < min) min  = save + price[j][1];
            } else 
            travel(i + 1);
            mark[j] = 0;
            save -= price[i][j];
        }
    }
}