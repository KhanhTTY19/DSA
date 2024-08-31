#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue *head, *tail;

int main()
{
    head = makeNewNode(1);
    printf("%d", head -> val);
}