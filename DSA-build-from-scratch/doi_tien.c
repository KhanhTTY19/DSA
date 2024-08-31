#include <stdio.h>
#include <stdlib.h>

int denomin[1001], way_to_change[1001][11], saved[1001], n, s;
void try(int i);
int build(int money);

int main()
{
    int i;
    scanf("%d %d", &n, &s);
    for (i = 0; i < n; i++) {
        scanf("%d", &denomin[i]);
        way_to_change[0][i] = 1;
    }
    for (i = 1; i <= s; i++) {
        if (!(i % denomin[0])) way_to_change[i][0] = 1;
        
    }
    for (i = 1; i < n; i++) {
        for (int money = 1; money <= s; money ++){
            way_to_change[money][i] = way_to_change[money - denomin[i]][i] + way_to_change[money][i - 1];
            printf("%d ", way_to_change[money][i]);
        }
        printf("\n");
    }
    
    //for (i = 10; i <= s; i++) if (way_to_change[i]) printf("%d_%d ", i, way_to_change[i]);
    //printf("\n");
    //for (i = 10; i <= s; i++) printf("%4d ", way_to_change[i]);
    printf("%d", way_to_change[s][n - 1]);
}
