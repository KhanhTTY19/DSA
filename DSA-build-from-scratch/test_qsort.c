#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return(strcmp((char*) a, (char*) b));
}

int main()
{
    char s[20];
    scanf("%s", s);
    char x[5][20] = {"B", "E", "A", "c"};
    qsort(x, 5, 20*sizeof(char), cmp);
    for (int i = 0; i <= 4; i++) printf("%s ", x[i]);
}