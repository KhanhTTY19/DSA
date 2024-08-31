#include <stdio.h>
#include <stdlib.h>

int count = 0, now, n, k, curr[100];
int main()
{
    int n, i, k;
    scanf("%d %d", &n, &k);
    for (i = 1; i <= n; i++) {
        scanf("%d", curr[i]);
    }
}

void backtrack(int i)
{
    int j;
    for (i = 1; i <= n; i++) {
        now += curr[i];
        if (now > k) {
            now -= curr[i];
            return;
        }
        else if (now == k)
        {
            now -= curr[i];
        }
        
    }
}