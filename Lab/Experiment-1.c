// Experiment 1: WAP to insert an element in the array at the beginning, at the end, and at a specific 
// position. Use a menu-driven approach to define the user-defined function for the given task. 
#include<stdio.h>
int maxsize = 5;
int crrSize=1;
int value;
int value1;
int value2;
int idx;

void addend(int arr[]){
        if(crrSize<maxsize){
        arr[crrSize]=value;
        crrSize++;
    }
    else{
        printf("Array is full \n");
    }
}

void addbegining(int arr[]){
    if(crrSize<maxsize){
        for(int i=crrSize;i>0;i--){
            arr[i]=arr[i-1];
            
        }
        arr[0]=value1;
            crrSize++;
    }
    else{
        printf("Array is full \n");
    }

}

void addspecificIndex(int arr[]){
    if(crrSize<maxsize){
        for(int i=crrSize;i>=idx;i--){
            arr[i]=arr[i-1];
            
        }
        arr[idx]=value2;
            crrSize++;
    }
    else{
        printf("Array is full \n");
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}


int main(){
    int arr[maxsize];
    // for(int i=0;i<crrSize;i++){
    //     printf("Enter a number ");
    //     scanf("%d",&arr[i]);
    // }
    // print(arr,crrSize);
    arr[0]=1;
    printf("\n");

    printf("Enter a value add  in the end of the array \n");
    scanf("%d",&value);
    addend(arr);
    print(arr,crrSize);
    printf("\n");
    
    printf("Enter a value add in the beginning in the array \n");\
    scanf("%d",&value1);
    addbegining(arr);
    print(arr,crrSize);
    printf("\n");

    printf("Enter a value and index where to be add in the array ");
    scanf("%d%d",&value2,&idx);
    addspecificIndex(arr);
    print(arr,crrSize);
    printf("\n");
}