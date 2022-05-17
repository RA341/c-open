#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int ele;
    struct Node *next;
};

typedef struct Node node;

node* insertfirst(node *head,int ele){

    node* temp= (node*) malloc(sizeof(node));

    temp -> ele = ele;
    temp ->next=head;
    temp = head;
    return head;
}

node* insertlast(node *head,int ele){

    node* temp= (node*) malloc(sizeof(node));

    temp -> ele = ele;
    temp ->next=NULL;

    node* cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur ->next = temp;
    return head;
}

void delete(node *head,int ele){

    if (head == NULL)
    {
        printf("Empty list");
        return;
    }
    
    node* pre = NULL;
    node* cur = head;
    while (cur->ele != ele)
    {   
        pre = cur;
        cur = cur->next;
    }

    if (pre == NULL){
        printf("Element not found");
        return;
    }

    node* temp = cur;
    pre ->next = cur -> next;
    temp ->next = NULL;
    free(temp);
    return head;
}

void display(node* head){

    if (head== NULL)
    {
        printf("Empty");
        return;
    }

    node* temp = head;
    while (temp->next != NULL)
    {
        printf("%d \n",temp->ele);
        temp = temp->next;
    }

    printf("%d \n",temp->ele);

    
}

