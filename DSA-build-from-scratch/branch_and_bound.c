#include <stdio.h>
#include <stdlib.h>

int shortest, save[17], visit[17];
FILE* out;
void findway(int node, int ith, int size, int weight[17][17]);
void travellingSaleman(int n)
{
    out = fopen("out.txt", "w");
    int i, size, j, jj, weight[17][17];
    for (i = 0; i < n; i++) {
        scanf("%d", &size);
        for (j = 1; j <= size; j++) {
            for (jj = 1; jj <= size; jj++)
            scanf("%d", &weight[j][jj]);
        }
        shortest = 10000000;
        save[1] = 1;
        visit[1] = weight[1][1];
        findway(1, 2, size, weight);
        fprintf(out, "%d\n", shortest);
    }
}

void findway(int node, int ith, int size, int weight[17][17])
{
    int i;
    if (node == 1) {
        for (i = 1; i <= size; i++) {
            visit[i] = 0;
        }
    }
    for (i = 2; i <= size; i++) {
        if (visit[i] == 0 && weight[node][i] != 0) {
            save[ith] = i;
            visit[i] = visit[save[ith - 1]] + weight[node][i];
            //printf("i = %d, visit i = %d\n ", i, visit[i]);
            if (ith == size) {
                //printf("___%d", visit[i]+weight[i][1]);
                if (visit[i] + weight[i][1] < shortest) shortest = visit[i] + weight[i][1];
                visit[i] = 0;
                return;
            }
            else {
                findway(i, ith + 1, size, weight);
                //printf("_i = %d, visit i = %d\n ", i, visit[i]);
                visit[i] = 0;
            }
        }
    }
}