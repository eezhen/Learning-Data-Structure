//____________________________________________________________________________________________________
// eezhen
// Data Structure
// 3/24/2023 (~3/27)

// C Static Array Project Learning
// C's Array length is fixed once it was declared;
// Here 0 represents NULL, that cannot be added or removed.
// Using "del_ct" to keep along with the number of 0s in array.
//____________________________________________________________________________________________________
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // For generating random numbers
//____________________________________________________________________________________________________
void push_to_end(int arr[], int len); // Input digit once a time till the array is full
void uniform_num(int arr[], int len); // Input once for an uniform-digit array
void random_num(int arr[], int len); // Fill the array up with random numbers
void remove_digit(int arr[], int len, int to_del, int* del_ct); // To remove given (repeatitve) digit(s) from array
void remove_element(int arr[], int len, int index, int* del_ct); // To remove element at the given position
void add_element(int arr[], int len, int index, int to_add, int* del_ct); // Choose to Do [O]Overwrite / [L]Left-shifted / [R]Right-shifted
void printf_arr(int arr[], int len, int del_ct); // Wrote a print function to make main() more readable.
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
    printf("***Array Length=%d\n",arrlen);

    while(option==0){
        printf("=== Step 2: Initialize Array\n");
        printf("- Option 1: Push until the end\n");
        printf("- Option 2: Uniform Numbers\n");
        printf("- Option 3: Random Numbers\n");
        printf("- Option 9: EXIT\n");
        printf("***Option=");
        scanf("%d",&option);
        if(option==1){push_to_end(arr,arrlen);printf_arr(arr,arrlen,del_ct);}
        else if(option==2){uniform_num(arr,arrlen);printf_arr(arr,arrlen,del_ct);}
        else if(option==3){random_num(arr,arrlen);printf_arr(arr,arrlen,del_ct);}
        else if(option==9){printf("Program ending......");del_ct=-1;break;}
        else{option = 0;}
    }

    while(del_ct>=0){
        printf("=== Step 3: Removing/Adding Elements\n");
        printf("- Action 1: Remove a repeatitive digit(s) from the list\n");
        printf("- Action 2: Remove an element at given position\n");
        printf("- Action 3: Add a digit to a given position (OW/LS/RS)\n");
        printf("- Action 9: EXIT\n");
        printf("***Action=");
        scanf("%d",&action);
        if(action==1){
            int to_del;
            printf("***Removing a digit(s)=");
            scanf("%d",&to_del);
            if(to_del==0){
                printf("***0 represents NULL that cannot be removed!!!");
            }
            else{
                printf("***The digit(s) to be removed is(are) %d\n",to_del);
                remove_digit(arr, arrlen, to_del, &del_ct);
                
            }
            printf_arr(arr,arrlen,del_ct);
            action=0;
        }
        if(action==2){
            int index_r;
            printf("***Removing a digit at position=");
            scanf("%d",&index_r);
            if(arr[index_r]==0){
                printf("***0 represents NULL that cannot be removed!!!");
            }
            else{
                remove_element(arr, arrlen, index_r, &del_ct);
                
            }
            printf_arr(arr,arrlen,del_ct);
            action=0;
        }
        if(action==3){
            int index_a, to_add;
            printf("***Adding a digit=");
            scanf("%d",&to_add);
            if(to_add==0){
                printf("***0 represents NULL that cannot be added!!!\n");
            }
            else{
                printf("***Adding a digit=%d at position=", to_add);
                scanf("%d",&index_a);
                if(index_a>=arrlen){
                    printf("***The selected position is out of range !!!\n");
                }
                else{
                    add_element(arr,arrlen,index_a,to_add,&del_ct);
                }
            }           
            printf_arr(arr,arrlen,del_ct);
            action=0;
        }
        if(action==9){
            printf_arr(arr,arrlen,del_ct);
            printf("***Program ending......\n");
            break;
        }
    }    
}
//____________________________________________________________________________________________________
void push_to_end(int arr[], int len){
// Input digit once a time till the array is full
    int input;
    printf("***Starts Input...\n");
    for(int i=0 ; i < len ; i++){
        scanf("%d",&input);
        arr[i] = input;
    }
}

void uniform_num(int arr[], int len){
// Input once for an uniform-digit array
    int input;
    printf("***Uniform number=");
    scanf("%d",&input);
    for(int i=0 ; i < len ; i++){
        arr[i] = input;
    }    
}

void random_num(int arr[], int len){
// Fill the array up with random numbers
    int r;
    srand(time(NULL));
    for(int i=0 ; i < len ; i++){
        r = rand()%10000;
        arr[i] = r;
    } 
}

void remove_digit(int arr[], int len, int to_del, int* del_ct){
// To remove given (repeatitve) digit(s) from array
    int temp_ct = *del_ct;  // Pass deleted counts by reference
    int temp_copy = 0;
    if(temp_ct==len){
        printf("NOthing can be removed as the array is empty !!!\n");
    }
    else{
        for(int i=0 ; i<len ; i++){ // Traverse arr[]  
            if(arr[i]==to_del){ // Encounter the element to be deleted
                arr[i] = 0; // Delete the digit to be NULL(0)
            }
        }
    }
    for(int i=0 ; i<len ; i++){
        if(arr[i]==0){
            temp_copy += 1; // Count 0s
        }
    }
    temp_ct = temp_copy;
    *del_ct = temp_ct;  // Pass by reference.
}

void remove_element(int arr[], int len, int index, int* del_ct){
// To remove element at the given position
    int temp_ct = *del_ct;
    int temp_copy = 0;
    if(temp_ct==len){
        printf("***NOthing can be removed as the array is empty !!!\n");
    }
    else if(index>len){
        printf("***The selected position is out of range !!!\n");
    }
    else{
        arr[index] = 0;
    }
    for(int i=0 ; i<len ; i++){
        if(arr[i]==0){
            temp_copy += 1;
        }
    }
    temp_ct = temp_copy;
    *del_ct = temp_ct;
}

void add_element(int arr[], int len, int index, int to_add, int* del_ct){
// Choose to Do [O]Overwrite / [L]Left-shifted / [R]Right-shifted
    char decision_made;
    int temp_ct = *del_ct;
    int temp_copy = 0;
    if(arr[index]==0){ // Directly Overwriting since the place is empty
        arr[index]=to_add;
    }
    else{
        if(index==0){ // ADDing to the leftmost, so either [O]Overwrite / [R]Right-shifted
            printf("***Adding a digit to the leftmost position\n");
            printf("***[o]Overwrite || [r]Right-shifted\n");
            printf("***Doing=");
            scanf(" %c",&decision_made);
            if(decision_made=='o' || decision_made == 'O'){
                arr[index]=to_add;
            }
            else if(decision_made=='r' || decision_made == 'R'){
                for(int i=len-1 ; i>index ; i--){
                    arr[i] = arr[i-1];
                }
                arr[index]=to_add;
            }
            else{
                printf("***Invalid decision made, Action resumed !!!\n");
            }
        }
        else if(index==(len-1)){ // ADDing to the rightmost, so either [O]Overwrite / [L]Left-shifted
            printf("***Adding a digit to the rightmost position\n");
            printf("***[o]Overwrite || [l]Left-shifted\n");
            printf("***Doing=");
            scanf(" %c",&decision_made);
            if(decision_made=='o' || decision_made == 'O'){
                arr[index]=to_add;
            }
            else if(decision_made=='l' || decision_made == 'L'){
                for(int i=0 ; i<index ; i++){
                    arr[i] = arr[i+1];
                }
                arr[index]=to_add;
            }
            else{
                printf("***Invalid decision made, Action resumed !!!\n");
            }
        }
        else{ // Do [O]Overwrite / [L]Left-shifted / [R]Right-shifted
            printf("***Adding a digit to the [%d] position\n",index);
            printf("***[o]Overwrite || [l]Left-shifted || [r]Right-shifted\n");
            printf("***Doing=");
            scanf(" %c",&decision_made);
            if(decision_made=='o' || decision_made =='O'){
                arr[index]=to_add;
            }
            else if(decision_made=='r' || decision_made == 'R'){
                for(int i=len-1 ; i>index ; i--){
                    arr[i] = arr[i-1];
                }
                arr[index]=to_add;
            }
            else if(decision_made=='l' || decision_made == 'L'){
                for(int i=0 ; i<index ; i++){
                    arr[i] = arr[i+1];
                }
                arr[index]=to_add;
            }
            else{
                printf("***Invalid decision made, Action resumed !!!\n");
            }
        }
    }
    for(int i=0 ; i<len ; i++){
        if(arr[i]==0){
            temp_copy += 1;
        }
    }
    temp_ct = temp_copy;
    *del_ct = temp_ct;
}

void printf_arr(int arr[], int len, int del_ct){
// Wrote a print function to make main() more readable
    printf(">>>\n");
    printf(">>>Array Length : %d \n",len);
    printf(">>>Array Content: ");
    for(int i=0 ; i<len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n>>>Delete Counts: %d\n", del_ct);
    printf(">>>\n");
}
