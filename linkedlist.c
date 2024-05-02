// linked list implementation to practise pointers and dynamic memory allocation.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int val;
    struct Node*next;
}Node;

void append(Node**headRef,int val){
    Node * newNode = (Node *) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("memory allocation failed\n");
        return;
    }
    newNode->val = val;
    newNode->next= NULL;

    if(*headRef == NULL){
        *headRef = newNode;
        return;
    }

    Node * current = *headRef;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
}

void print_list(Node*head){
    Node*current = head;
    while(current!=NULL){
        printf("value: [ %d ]\n", (*current).val);
        current = current->next;
    }
}

void front(Node**head,int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("memory allocation failed\n");
        return;
    }
    newNode->val = val;
    newNode->next = *head;
    *head = newNode;
}

void insertAtIdx(Node**head,int val, int idx){
   Node* current = *head;
   if(current==NULL){
    append(head,val);
    return;
   }
int count = 1;
while(count <idx && current->next){
    current = current->next;
    count+=1;
}

Node * tmp = current->next;
Node * newN = malloc(sizeof(Node));
newN->val = val;
newN->next = tmp;
current->next = newN;
}

void insertAtValue(Node**headRef,int val,int newVal){
    Node*current = *headRef;
    printf("%d",(*current).val);
    while ((*current).val!=val && current->next)
    {
        current = current->next;
    }
    Node*newN = malloc(sizeof(Node));
    newN->val = newVal;
    newN->next = current->next;
    current->next = newN;
}

bool search(Node*head,int val){
    if(head==NULL) return false;
    if((*head).val == val) return true;
    return search(head->next,val);
}

int main(){
    Node * headRef = NULL;
    int nums [5] = {8,3,39,3,4};
    
    for(int i=0;i<5;i++){
        append(&headRef,nums[i]);
    }

    bool search_res =search(headRef,8);
    printf("the search value found %s\n",search_res?"true":"false");

   print_list(headRef);
    return 0;
}

