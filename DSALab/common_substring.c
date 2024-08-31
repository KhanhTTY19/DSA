#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int loc[10001][10001], s1[10001], s2[10001], ls1, ls2;
int max(int a, int b){
    if (a >= b) return a;
    return b;
}
int main()
{
    int i, j;
    scanf("%d", &ls1);
    scanf("%d", &ls2);
    for (i = 1; i < ls1; i++) {
        scanf("%d", s1 + i);
    }
    
    for (i = 1; i < ls2; i++) {
        scanf("%d", s2 + i);
    }
    for (i = 1; i < ls1; i++) {
        for (j = 0; j < ls2; j++) {
            loc[i][j] = max(loc[i - 1][j - 1] + (s1[i] == s2[j]), max(loc[i - 1][j], loc[i][j - 1]));
        }
    }
    printf("%d", loc[ls1 - 1][ls2 - 1]);
}


