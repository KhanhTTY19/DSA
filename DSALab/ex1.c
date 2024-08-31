#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void bits(int i);
int x[100], n;
int main()
{
    scanf("%d", &n);
    bits(1);
}

void bits(int i) 
{
    int j;
    for (j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            for (int t = 1; t < n; t++) 
                if (x[t] == 1 && x[t+1] == 1) return;
            for (int t = 1; t <= n; t++) printf("%d", x[t]);
                printf("\n");
        }
        else bits(i + 1);
    }
}