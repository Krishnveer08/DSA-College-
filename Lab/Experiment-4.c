// Experiment 4: Implement Queue using an Array: Customer Service Queue Management System
// WAP to develop a simple customer service queue management system for a retail store. The system should manage 
// customers waiting in line to be served. You need to implement this functionality using both an array.
// Requirements:
// 1.
// Queue Operations: Implement the following operations:
// Enqueue: Add a customer to the end of the queue when they arrive.
// Dequeue: Remove the customer at the front of the queue when they are served.
// Peek: View the customer at the front of the queue without removing them.
// Display: Show all customers currently in the queue.
// 2.
// Input Validation: Ensure the user can’t dequeue from an empty queue or enqueue into a full queue.
#include<stdio.h>
#include<stdlib.h>
int front = -1;
int rear = -1;
int queue[10];
int size = sizeof(queue)/sizeof(queue[0]);

int addKaro(int data_){
    if((rear+1)%size==front){
        printf("Not Add any customer!");
    }
    if(front==-1 && rear==-1){
        front = 0;
        rear = 0;
        queue[rear]=data_;
        printf("ADD Successfully!");

    }
    else{
        rear = (rear+1)%size;
        queue[rear] = data_;
        printf("ADD Successfully!");
    }
}

int hatado(){
    if(rear = -1 && front == -1){
        printf("Queue is empty");
    }
    int ele;
    if(front == rear){
        ele = queue[front];
        front = -1;
        rear = -1;
        printf("Customer deleted ID : %d\n",ele);
        return ele;

    }
    else{
        ele = queue[front];
        printf("Customer deleted ID : %d\n",ele);
        front = (front+1)%size;
        return ele;
    }
}


void dikhao(){
    int i = front;
    while(i!=rear){
        printf("%d. Customer : %d\n",i+1,queue[i]);
        i = (i+1)%size;
    }
    printf("%d. Customer : %d\n",i+1,queue[rear]);
    printf("\n");
}


int main(){

    int choice;
    printf("*****************************************");
    printf("\n");
    printf("1. ADD A CUSTOMER\n");
    printf("2. DELETE A CUSTOMER\n");
    printf("3. SHOW ALL CUSTOMERS\n");
    printf("4. EXIT\n");
    
    int id;
     while (1) {
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter Customer Id: ");
                scanf("%d",&id);
                addKaro(id);
                break;
            case 2:
                hatado();
                break;
            case 3:
                dikhao();
                break;
            case 4:
                printf("Thank you for your visit!\n");
                exit(0);
            default:
                printf("Enter valid choice!!\n");
                break;
        }

            

     }
    printf("****************************************************\n");


    
}