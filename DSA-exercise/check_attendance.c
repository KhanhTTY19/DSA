#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1000

int main()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening the file.");
        return 1;
    }
    char s[MAXSIZE];
    char** lines;
    int len, order_line = 0;
    while (fgets(s, sizeof(s), fp) != NULL)
    {
        lines = realloc(lines, (order_line + 1) * sizeof(char*));
        lines[order_line] = malloc(strlen(s) + 1);
        strcpy(lines[order_line], s);
        order_line ++;
    }
    int i = 0, word = 0;
    for (i = 0; i < order_line; i++)
    {
        int j = 0;
        len = strlen(lines[i]);
        while (j < len)
        {
            if ((s[j] > 'a' && s[j] < 'z') || (s[j] > 'A' && s[j] < 'Z')) {
                word++;
                while ((s[j] > 'a' && s[j] < 'z') || (s[j] > 'A' && s[j] < 'Z'))
                {
                    j++;
                }
            } 
            else j++;
        }
    }
    printf("%d", word);
}