#include <stdio.h>
#include <stdlib.h>


void selection_sorts(int list[], int num_in_list);
void swap(int *smallest, int *first_element);


int main(){
    int array[] = {23, 78, 45, 8, 32, 56};
    selection_sorts(array,6);
    for(int i = 0; i < 6; i++){
        printf("%d ",array[i]);
    }
    // int a = 10;
    // int b = 20;
    // swap(&a,&b);
    // printf("%d %d",a, b);
    return 0;
}


void swap(int *smallest, int *first_element){
    int middle;
    middle = *smallest;
    *smallest = *first_element;
    *first_element = middle;
}
void selection_sorts(int list[], int num_in_list){
    int i,j;
    for(i = 0; i < num_in_list; i++ ){
        for (j = i + 1 ; j < num_in_list ;j++){
            if(list[i] > list[j]){
                swap(&list[i], &list[j]);
            }
        }
        // wall is invisible, don't need to declare
        // swap(find_the_smallest(list,i), list[i]);
    }
}