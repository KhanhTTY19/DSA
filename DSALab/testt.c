#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
 
Info* head;
FILE* in;
 
int main()
{
    in = fopen("inp.txt", "r");
    head = makeNewNode();
    Info* p = makeNewNode();
    head -> next = p;
    printAllInfo(head);
 
    insertAtFirst();
    insertAtFirst();
    printAllInfo(head);
 
    deleteFirst();
    printAllInfo(head);
    
    printf("inverse\n");
    head = reverse_Node();
    printAllInfo(head);
 
    freeInfo();
    printf("after free\n");
    printAllInfo(head);
    return 0;
}
 
Info* makeNewNode()
{
    Info *new_node = (Info*) malloc(sizeof(Info));
    char n[20], t[12], e[30];
    fgets(n, 20, in); //getchar();
    n[strlen(n) - 1] = '\0';
    fgets(t, 12, in); //getchar();
    t[strlen(t) - 1] = '\0';
    fgets(e, 30, in); //getchar();
    e[strlen(e) - 1] = '\0';
    strcpy(new_node -> name, n);
    strcpy(new_node -> tel, t);
    strcpy(new_node -> email, e);
    new_node -> next = NULL;
    return new_node;
}
 
void print1Info(Info* xxx)
{
 
    printf("%10s %12s %10s\n", xxx -> name, xxx ->tel, xxx ->email);
}
 
void insertAtFirst(){
    Info* new_node = makeNewNode();
    new_node -> next = head;
    head = new_node;
}
 
void freeInfo()
{
    Info* tmp = head;
    while (tmp != NULL){
        head = head -> next;
        free(tmp);
        tmp = head;
    }
}
 
void printAllInfo(Info *xxx)
{
    Info* p = xxx;
    printf("%10s %12s %10s\n", "Name", "Tel", "Email");
    while(p != NULL) {
        print1Info(p);
        p = p->next;
    }
    printf("\n");
}
 
void insertAtTail()
{
    Info* new_node = makeNewNode();
    if (head == NULL) {
        head = new_node;
        return;
    }
    else {
        Info* p = head;
        while (p -> next != NULL) {
            p = p-> next;
        }
        p -> next = new_node;
    }
}
 
void deleteFirst()
{
    Info* p = head;
    p = head -> next;
    free(head);
    head = p;
}
 
Info* reverse_Node()
{
    Info* p = head, *pre = NULL, *cur = NULL;
    while (p != NULL) {
        //printf("%s %s %s\n", pre -> name, cur -> name, p -> name);
        cur = p;
        p = p -> next;
        //printf("%s %s %s\n", pre -> name, cur -> name, p -> name);
        cur -> next = pre;
        pre = cur;
    }
    return pre;
}