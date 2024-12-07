
#include<stdio.h>
int findmin(int* nums, int numssize){
    int left = 0, right = numssize-1;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(nums[mid] < nums[right])
            right = mid;
        else{
            left = mid + 1;
    }
}
}int main()
{
    int nums[] = {3, 4, 5, 1, 2};
    int result=findmin(nums,5);
    printf("Minimum element is %d\n", nums[result]);
    return 0;
}