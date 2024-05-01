#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node*next;
}Node;

void append(Node**,int);
void print_list(Node*);
void front(Node**,int);
void insertAtIdx(Node**head,int val,int idx);
void insertAtValue(Node**headRef,int val,int newVal);

int main(){
    Node * headRef = NULL;
    int nums [5] = {8,3,39,3,4};
insertAtValue(&headRef,23,99);
    insertAtIdx(&headRef,88,1);
    
    for(int i=0;i<5;i++){
        append(&headRef,nums[i]);
    }
   front(&headRef,13);
   front(&headRef,1);
   insertAtIdx(&headRef,0,5);
    insertAtValue(&headRef,99,99);
    insertAtValue(&headRef,88,19);
   print_list(headRef);
  
    
    return 0;
}

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