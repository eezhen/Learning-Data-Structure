//____________________________________________________________________________________________________
// eezhen
// Data Structure
// C Static Array Project Learning
// 3/24/2023
//____________________________________________________________________________________________________
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//____________________________________________________________________________________________________
void push_to_end(int arr[], int len);
void uniform_num(int arr[], int len);
void random_num(int arr[], int len);
void remove_digit(int arr[], int len, int to_del, int* del_ct);
void remove_element(int arr[], int len, int index, int* del_ct);
void reformat_bef_add(int arr[], int len, int* del_ct);
void add_element(int arr[], int len, int index, int to_add, int* del_ct);
void add_first(int arr[], int len, int to_add, int* del_ct);
void add_last(int arr[], int len, int to_add, int* del_ct);
void printf_arr(int arr[], int len, int del_ct);
//____________________________________________________________________________________________________
void main(){
    int arrlen;
    int del_ct = 0;
    int option = 0;
    int action = 0;

    printf("=== C Static Array Project Learning ===\n");

    printf("=== Step 1: Create an Array (Fixed Length)=");
    scanf("%d",&arrlen);
    arrlen %= 100;
    int arr[arrlen];
    printf("=   arr length=%d\n",arrlen);

    while(option==0){
        printf("=== Step 2: Initialize Array\n");
        printf("- Option 1: Push until the end\n");
        printf("- Option 2: Uniform Numbers\n");
        printf("- Option 3: Random Numbers\n");
        printf("- Option=");
        scanf("%d",&option);
        if(option==1){push_to_end(arr,arrlen);printf_arr(arr,arrlen,del_ct);}
        else if(option==2){uniform_num(arr,arrlen);printf_arr(arr,arrlen,del_ct);}
        else if(option==3){random_num(arr,arrlen);printf_arr(arr,arrlen,del_ct);}
        else{option = 0;}
    }

    while(del_ct>=0){
        printf("=== Step 3: Removing/Adding Elements\n");
        printf("- Action 1: Remove a digit(s) from the list\n");
        printf("- Action 2: Remove an element at given position\n");
        printf("- Action 3: Add a digit to a given position\n");
        printf("- Action 4: Add a digit to the first position\n");
        printf("- Action 5: Add a digit to the last position\n");
        printf("- Action 6: EXIT\n");
        printf("- Action=");
        scanf("%d",&action);
        if(action==1){
            int to_del;
            printf("Removing a digit(s)=");
            scanf("%d",&to_del);
            printf("The digit(s) to be removed is(are) %d\n",to_del);
            remove_digit(arr, arrlen, to_del, &del_ct);
            printf_arr(arr,arrlen,del_ct);
            action=0;}
        if(action==2){
            int index_r;
            printf("Removing a digit at position=");
            scanf("%d",&index_r);
            remove_element(arr, arrlen, index_r, &del_ct);
            printf_arr(arr,arrlen,del_ct);
            action=0;}
        if(action==3){
            int index_a, to_add;
            printf("Adding a digit=");
            scanf("%d",&to_add);
            printf("Adding a digit=%d at position=", to_add);
            scanf("%d",&index_a);
            if(index_a>=arrlen){printf("The selected position is out of range !!!\n");}
            else if(index_a==0){
                reformat_bef_add(arr, arrlen, &del_ct);
                add_first(arr, arrlen, to_add, &del_ct);}
            else if(index_a==arrlen-1){
                add_last(arr, arrlen, to_add, &del_ct);}
            else{
                reformat_bef_add(arr, arrlen, &del_ct);
                add_element(arr, arrlen, index_a, to_add, &del_ct);}            
            printf_arr(arr,arrlen,del_ct);
            action=0;}
        if(action==4){
            int to_add;
            printf("Adding a digit=");
            scanf("%d",&to_add);
            reformat_bef_add(arr, arrlen, &del_ct);
            add_first(arr, arrlen, to_add, &del_ct);
            printf_arr(arr,arrlen,del_ct);
            action=0;}
        if(action==5){
            int to_add;
            printf("Adding a digit=");
            scanf("%d",&to_add);
            add_last(arr, arrlen, to_add, &del_ct);
            printf_arr(arr,arrlen,del_ct);
            action=0;}
        if(action==6){
            break;}
    }    
}
//____________________________________________________________________________________________________
void push_to_end(int arr[], int len){
    int input;
    printf("Starts Input...\n");
    for(int i=0 ; i < len ; i++){
        scanf("%d",&input);
        arr[i] = input;
    }
}

void uniform_num(int arr[], int len){
    int input;
    printf("Uniform number=");
    scanf("%d",&input);
    for(int i=0 ; i < len ; i++){
        arr[i] = input;
    }    
}

void random_num(int arr[], int len){
    int r;
    srand(time(NULL));
    for(int i=0 ; i < len ; i++){
        r = rand()%10000;
        arr[i] = r;
    } 
}

void remove_digit(int arr[], int len, int to_del, int* del_ct){
// To remove given element from array with ending 0s.
    int temp_ct = *del_ct;  // Pass deleted counts by reference.
    if(temp_ct==len){
        printf("NOthing can be removed as the array is empty !!!\n");
    }
    else{
        for(int i=0 ; i<len ; i++){ // Traverse arr[]  
            if(arr[i]==to_del){ // Encounter the element to be deleted
                arr[i] = 0;
                temp_ct += 1;
            }
        }
    }
    *del_ct = temp_ct;  // Pass by reference.
}

void remove_element(int arr[], int len, int index, int* del_ct){
    int temp_ct = *del_ct;
    if(temp_ct==len){
        printf("NOthing can be removed as the array is empty !!!\n");
    }
    else if(index>len){
        printf("The selected position is out of range !!!\n");
    }
    else{
        arr[index] = 0;
        temp_ct += 1;
    }
    *del_ct = temp_ct;
}

void reformat_bef_add(int arr[], int len, int* del_ct){
    int tracker = *del_ct;
    int zero_ct = 0;
    for(int i = 0; (i<len)&&(zero_ct<tracker); i++){
        if(arr[i] == 0){
            zero_ct += 1;
            for(int j = 0; j<len-1 ; j++){
                arr[j] = arr[j+1];
            }
        }
    }
}

void add_element(int arr[], int len, int index, int to_add, int* del_ct){
    int temp_ct = *del_ct;
    if(temp_ct==0){
        printf("The element cannot be inserted as the array is full !!!\n");
    }
    else{
        for(int i=len-1 ; i>index ; i--){arr[i]=arr[i-1];}
        arr[index] = to_add;
        temp_ct -= 1;
    }
    *del_ct = temp_ct;
}

void add_first(int arr[], int len, int to_add, int* del_ct){
    int temp_ct = *del_ct;
    if(temp_ct==0){
        printf("The element cannot be inserted as the array is full !!!\n");
    }
    else{
        for(int i=len-1; i>0 ; i--){
            arr[i]=arr[i-1];
        }
        arr[0] = to_add;
        temp_ct -= 1;
    }
    *del_ct = temp_ct;
}

void add_last(int arr[], int len, int to_add, int* del_ct){
    int temp_ct = *del_ct;
    if(temp_ct==0){
        printf("The element cannot be inserted as the array is full !!!\n");
    }
    else{
        arr[len-1] = to_add;
        temp_ct -= 1;
    }
    *del_ct = temp_ct; 
}

void printf_arr(int arr[], int len, int del_ct){
// Wrote a print function to make main() more readable.
    printf("Array Length : %d \n",len);
    printf("Array Content: ");
    for(int i=0 ; i<len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Delete Counts: %d\n", del_ct);
}
