// double linked list implementation, just to practise c pointers and dynamic memory allocation;
// code not guaranteed to be optimal

#include <stdio.h>
#include<stdlib.h>

typedef struct Node
{
   int val;
   struct Node * next;
   struct Node * prev; 
}Node;

void insertAtHead(Node**head,Node**tail,int val){
    if(*head==NULL){
        *head = malloc(sizeof(Node));
        (*head)->next = NULL;
        (*head)->prev = NULL;
        (*head)->val = val;
        *tail = malloc(sizeof(Node));
        *tail = *head;
        return;
    }
    Node*newn = malloc(sizeof(Node));
    newn->val = val;
    newn->next = *head;
    (*head)->prev = newn;
    *head = newn;

}

void insertAtTail(Node**tail,Node**head, int val){
   if(*tail==NULL){
        *tail = malloc(sizeof(Node));
        (*tail)->next = NULL;
        (*tail)->prev = NULL;
        (*tail)->val = val;
        *head = malloc(sizeof(Node));
        *head = *tail;
        return;
    }
    Node*newn = malloc(sizeof(Node));
    newn->next = NULL;
    newn->val = val;
    newn->prev = *tail;
    (*tail)->next = newn;
    *tail = newn;
}

void removeFromHead(Node**head,Node**tail){
    if(*head ==NULL) return;
   *head = (*head)->next;
   (*head)->prev = NULL;
}

void removeFromTail(Node**tail,Node**head){
    if(*tail==NULL) return;
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
}

void printFromHead(Node*head){
    if(head==NULL) return;
    printf("value from head: %d\n",(*head).val);
    printFromHead(head->next);
}

void printFromTail(Node*tail){
    if(tail==NULL) return;
    printf("value from tail: %d\n",(*tail).val);
    printFromTail(tail->prev);
}

int main(){
    Node * headRef = NULL;
    Node * tailRef = NULL;
    insertAtHead(&headRef,&tailRef,9);
    insertAtHead(&headRef,&tailRef,20);
    insertAtHead(&headRef,&tailRef,10);
    insertAtTail(&tailRef,&headRef,13);
    insertAtTail(&tailRef,&headRef,45);
   
    removeFromHead(&headRef,&tailRef);
    removeFromTail(&tailRef,&headRef);
    removeFromTail(&tailRef,&headRef);
    printf("====== printing from Head =========\n");
    printFromHead(headRef);
    printf("======= printing from Tail ========\n");
    printFromTail(tailRef);
    return 0;
}