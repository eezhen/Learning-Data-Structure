#include <stdio.h>
#include <stdlib.h>

// kindof get it why resources out there mostly use struct to achieve the implementation of dynamic array in C.
// not only because C does not have it built-in, but also the length of array is out of control as it cannot be read by sizeof().
// so when trying to do such an implementation, we need to carefully count the array length by our own.
// some use struct{arr, size}, some use struct{arr, size, capacity}, where the 'capacity' represents the initialized length.

// Function of inserting, we will first double the arr space by realloc(), 
//                        then shift the data and put it on right position, 
//                        finally don't forget to change the size(++).

// Function of removing, normally it is unsafe to reduce the arr space by realloc(),
//                        as it has the possibility to cause additional data loss,
//                        to ease the pain, update the length(the ‘size’), and set it to '\0'.
 
int main(){
    int arr[20];    // 空间20*4(bytes)
    arr[0]= 1;      // 长度20
    int* arr2 = (int*)malloc(20*sizeof(int)); // 空间4(bytes)
    int* arr3 = (int*)calloc(20,sizeof(int)); // 空间4(bytes)
    int* arr4 = (int*)realloc(arr,20*sizeof(int)); // 空间4(bytes)
    char str[20] = "Hello, World!"; // 空间20*1(bytes)
    int len = strlen(str); // 长度13
    char* str2 = (char*)malloc(20*sizeof(char)); // 空间4(bytes)
    char* str3 = (char*)calloc(20,sizeof(char)); // 空间4(bytes)
    char* str4 = (char*)realloc(str,20*sizeof(char)); // 空间4(bytes)
    
    printf("\n%d",sizeof(arr));
    printf("\n%d",sizeof(arr)/sizeof(arr[0]));
    printf("\n%d",sizeof(arr2));
    printf("\n%d",sizeof(arr3));
    printf("\n%d",sizeof(arr4));
    printf("\n%d",sizeof(str));
    printf("\n%d",len);
    printf("\n%d",sizeof(str2));
    printf("\n%d",sizeof(str3));
    printf("\n%d",sizeof(str4));
    printf("\n");

    return 0;
}
