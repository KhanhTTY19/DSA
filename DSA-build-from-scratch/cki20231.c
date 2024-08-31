#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN_INT -10000

int max(int, int);
int isequal(int, int, int);
int a[4][366], n;
int main()
{
    char name[10];
    scanf("%d", &n);
    int i, j, day, change, maxday = MIN_INT, maxchange, count = 0;
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 365; j++) a[i][j] = MIN_INT;
    }
    for (i = 0; i < n; i++) {
        scanf("%d %s %d", &day, name, &change);
        if (day > maxday) maxday = day;
        if (!strcmp(name, "Sind")) {
            a[1][day] = change;
        } else if (!strcmp(name, "Vang"))
        {
            a[2][day] = change;
        }
        else if (!strcmp(name, "Jersey"))
        {
            a[3][day] = change;
        }
    }
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= maxday; j++) {
            if (a[i][j] == MIN_INT) {
                a[i][j] = a[i][j - 1];
            }
            else {
                a[i][j] += a[i][j - 1];
            }
        }
    }
    
    //printf("%d", maxchange);
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= maxday; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    i = 1;
    j = 1;
    while (1) {
        maxchange = max(max(a[1][j], a[2][j]), a[3][j]);
        if (maxchange == 0) i++;
        else break;
    }
    //printf("maxchane%d", maxchange);
    count ++;
    //printf("    ");
    for (j = i + 1; j <= maxday; j++) {
        int newmax = max(max(a[1][j], a[2][j]), a[3][j]);
        //printf("%4d", newmax);
        if (maxchange != newmax) {
            maxchange = newmax;
            count ++;
            
            
        }
        else {
            if (isequal(a[1][j], a[2][j], a[3][j]) != isequal(a[1][j - 1], a[2][j - 1], a[3][j - 1])) {count ++;
            printf("j %d %d %d", j, isequal(a[1][j], a[2][j], a[3][j]), isequal(a[1][j - 1], a[2][j - 1], a[3][j - 1]));}
        }
    }
    printf("%d", count);
}

int isequal(int a, int b, int c)
{
    if ((a == b) && (a == c)) return 3;
    else if (((a == b) && (max(max(a, b), c) == a)) || ((b == c) && (max(max(a, b), c) == b)) || ((c == a) && (max(max(a, b), c) == a)))
    {
        printf("%d %d %d\n", a, b, c);
        return 2;
    }
    return 1;    
} 

int max(int a, int b)
{
    if (a > b) return a;
    return b;
}