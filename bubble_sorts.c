#include<stdio.h>
#include<stdlib.h>

void swap(int *smallest, int *first_element){
    int middle;
    middle = *smallest;
    *smallest = *first_element;
    *first_element = middle;
}

void bubble_sorts(int list[], int num_in_list){
    int i,j;
    for(i = num_in_list-1; i>0; i--){
        for(j = 0; j< i; j++){
            if (list[i] < list[j]){
                swap(&list[i],&list[j]);
            }
        }
    }
}

int main(){
    int array[] = {23, 78, 45, 8, 32, 56};
    bubble_sorts(array,6);
    for(int i = 0; i < 6; i++){
        printf("%d ",array[i]);
    }
    return 0;
}