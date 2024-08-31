#include<stdio.h>
#include<stdlib.h>


void Try(int k);

int n, c[50][50], x[50], visited[50], min_road = (int) 1e5, x_road[50], x_pass[50], road = 0;
int main()
{
    int i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        c[i][i] = 0;
        x[i] = 0;
        x_pass[i] = 0;
        visited[i] = 0;
        for (j = 1; j <= n; j++) {
            c[i][j] = (int) 1e5;
        }
    }
    for (i = 1; i <= 2*n+1; i++)
    for (j = 1; j <= 2*n+1; j++) {
        scanf("%d", &c[i][j]);
    }
    Try(1);
    printf("%d", min_road);
}



void Try(int k)
{
    int i;
    for (i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            x[k] = i;
            visited[i] = 1;
            if (k == 1) 
                road += c[0][x[k]] + c[x[k]][x[k] + n];
            else 
                road += c[n + x[k - 1]][x[k]] + c[x[k]][x[k] + n];
            if (k == n) {
                if (road + c[x[n] + n][0] < min_road) min_road = road + c[x[n] + n][0];
            }
            else Try(k + 1);
            visited[i] = 0;
            if (k == 1) 
                road -= c[0][x[k]] + c[x[k]][x[k] + n];
            else 
                road -= c[n + x[k - 1]][x[k]] + c[x[k]][x[k] + n];
        }
    }
}