
#include<stdio.h>
#include<stdlib.h>
typedef struct  node{
    int data;
    struct node* next;
}node;

node* createnode(int data_){
    node* newnode = (node*)malloc(sizeof(node));
    if(!newnode){
        printf("Memory Nahi mili");
        exit(0);
    }
    else{
        newnode->data = data_;
        newnode->next = NULL;
        return newnode;
    }
}

void insertNode(node** head,int data_){
    node* newnode = createnode(data_);
    newnode->next = *head;
    *head = newnode;
}

int cycle(node* head){
    
    if(head==NULL || head->next==NULL){
        return 0;
    }
    else{
        node *fast=head;
        node *slow = head;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                return 1;
            }
        }
        return 0;
    }
}


int main(){
    node* head = NULL;
    insertNode(&head,10);
    insertNode(&head,20);
    insertNode(&head,40);
    head->next->next=head;
    if(cycle(head)){
        printf("True");
    }
    else{
        printf("False");
    }

}