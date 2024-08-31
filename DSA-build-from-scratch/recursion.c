#include <stdio.h>
#include <stdlib.h>

void hanoiTower(int n, char begin, char temp, char des)
{
    if (n == 1) {
        printf("%c -> %c\n", begin, des);
        return;
    }
    else {
        hanoiTower(n - 1, begin, des, temp);
        hanoiTower(1, begin, temp, des);
        hanoiTower(n - 1, temp, begin, des);
    }
}
int onstart = 0, a[1000][1000];
int combination(int k, int n) // to hop chap k cua n
{
    int i;
    if (onstart == 0){
        for (i = 0; i <= k; i++){
            for (int j = 0; j <= n; j++) {
                a[i][j] = 0;
            }
        }
        onstart = 1;
    }
    if (a[k][n] != 0) return a[k][n];
    else if (k == 0 || k == n)
    {
        a[k][n] = 1;
        return a[k][n];
    }
    else {
        a[k][n] = combination(k - 1, n - 1) + combination(k, n - 1);
        return a[k][n];
    }
    free(a);
}