// #include<stdio.h>

// struct  PriorityQ
// {
//     int data;
//     int p;
// };

// int max_size=10;
// struct PriorityQ arr[10];
// int cur_size=0;

// void insert(int data, int p){
//     if(cur_size==max_size){
//         printf("Overflow Condition");
//     }

//     for(int i=cur_size-1;i>=0;i--){
//         if(arr[i].p>p){
//             arr[i+1].data=arr[i].data;
//             arr[i+1].p=arr[i].p;
//         }
//         else{
//             break;
//         }
//         arr[i+1].data=data;
//         arr[i+1].p=p;
//         cur_size++;
//     }
// }
// int main(){
//     insert(10,2);
//     insert(5,3);
//     insert(15,1);
//     insert(20,0);
//     display();
    
//     return 0;

// }





#include<stdio.h>
typedef struct PriorityQueue{
    int data;
    int p;
}PQ;

int max_size = 10;
PQ arr[10];
int crr_size = 0;
void insert(int data,int p){
    if(crr_size == max_size ){
        printf("JAgh bhar gyi");
    }
    else{
        int i;
        for(i=crr_size-1;i>=0;i--){
            if(arr[i].p > p){
                arr[i+1].data = arr[i].data;
                arr[i+1].p = arr[i].p;
               // crr_size++;
               
        }
        else{
            break;
        }
         

    }
    arr[i+1].data = data;
    arr[i+1].p = p;
    crr_size++;
    
}
}



void display(){
    for(int i=0;i<crr_size;i++){
        printf("%d ",arr[i].data);
        }
}

int main(){

insert(10,1);
insert(20,2);
insert(30,1);
insert(50,3);
insert(60,2);

display();

return 0;
}