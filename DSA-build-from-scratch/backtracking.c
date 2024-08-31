#include <stdio.h>
#include <stdlib.h>

int *a, *mark;
void listBinaryString(int n);
void try(int, int);
void listingPermutation(int);
void permutation(int, int);
void checkSudoku();
int check3x3(int, int, int p[10][10]);

void listBinaryString(int n){
    a = (int*) malloc((n + 1) * sizeof(int));
    try(1, n);
    free(a);
}

void try(int i, int n)
{
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n) {
            for (int jj = 1; jj <= n; jj++) 
                printf("%d", a[jj]);
            printf("\n");
        }
        else {
            try(i + 1, n);
        }
    }
}

void listingPermutation(int n)
{
    a = (int*) malloc((n + 1) * sizeof(int));
    mark = (int*) malloc((n + 1) * sizeof(int));
    permutation(1, n);
    free(a);
    free(mark);
}

void permutation(int i, int n)
{
    int j;
    if (i == 1) {
        for (j = 1; j <= n; j++) mark[j] = 0;
    }
    for (j = 1; j <= n; j++) {
        if (mark[j] == 0) {
            a[i] = j;
            mark[j] = 1;
            if (i == n) {
                for (int jj = 1; jj <= n; jj++) 
                    printf("%d", a[jj]);
                printf("\n");
                mark[j] = 0;
            }
            else {
                permutation(i + 1, n);
                mark[j] = 0;
            }
        }
    }
}

void checkSudoku()
{
    int puzzle[10][10],mark_col[10][10], mark_row[10][10], i, j;
    int out = 0;
    for (i = 1; i <= 9; i++)
    for (j = 1; j <= 9; j++) {
        mark_col[i][j] = 0;
        mark_row[i][j] = 0;
    }
    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9; j++)
        {
            scanf("%d", &puzzle[i][j]);
            mark_row[i][puzzle[i][j]] ++;
            mark_col[j][puzzle[i][j]] ++;
            if (mark_row[i][puzzle[i][j]] > 1 || mark_col[j][puzzle[i][j]] > 1) {
                out = 1;
            }
        }
    }
    if (out == 1) {
        printf("0");
        return 0;
    }
    if (check3x3(1, 1, puzzle) == 0) {
        printf("0");
        return 0;
    }
    printf("1");
    return 0;
}

int check3x3(int ith, int jth, int p[10][10]) 
{
    int i, j;
    if (ith <= 2 && jth <= 2) {
        mark =  (int*) malloc(10 * sizeof(int));
        for (i = 1; i <= 9; i++) {
            mark[i] = 0;
        }
        for (i = 3 * ith + 1; i <= ith * 3 + 3; i ++) {
            for (j = 3 * jth + 1; j <= 3 * jth + 3; j++) {
                mark[p[i][j]] ++;
                if (mark[p[i][j]] > 1) return 0;
            }
        }
        if (jth <= 1) return check3x3(ith, jth + 1, p);
        else return check3x3(ith + 1, 0, p);
        return 1;
    }
}