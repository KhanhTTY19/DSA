typedef struct queue
{
    int val;
    struct queue *next;   
} queue;

queue *makeNewNode(int v);
queue *enqueue(queue h, int v);

queue *makeNewNode(int v)
{
    queue *new_node = (queue*) malloc(sizeof(queue));
    new_node -> val = v;
    new_node -> next = NULL;
    return new_node;
}

queue *enqueue(queue h, int v)
{
    queue *q = makeNewNode(v);

}



