// Q. Reverse an array using extra space 
#include <stdio.h>

void reverseArrayWithExtraSpace(int arr[], int n) {
    int reversedArr[n];  

    
    for (int i = 0; i < n; i++) {
        reversedArr[i] = arr[n - i - 1];
    }

    
    for (int i = 0; i < n; i++) {
        arr[i] = reversedArr[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    reverseArrayWithExtraSpace(arr, n);

    printf("Reversed array: ");
    printArray(arr, n);

    return 0;
}