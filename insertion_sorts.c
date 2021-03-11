#include<stdio.h>
#include<stdlib.h>


void swap(int *smallest, int *first_element){
    int middle;
    middle = *smallest;
    *smallest = *first_element;
    *first_element = middle;
}
void insertion_sorts(int list[],int num_in_list){
    int i;
    for(i = 1; i<num_in_list; i++){
        // int temp = list[i];//也是可以用swap喇只是記憶體存取多
        // int j = i-1;
        // while((temp < list[j]) && j >= 0){
        //     list[j+1]= list[j];
        //     j--;
        // }
        // list[j+1] = temp;
        int j = i-1;
        while((list[j]>list[j+1]) && j>=0){
            swap(&list[j],&list[j+1]);
            j--;
        }
    }
}

int main(){
    int array[] = {23, 78, 45, 8, 32, 56};
    insertion_sorts(array,6);
    for(int i = 0; i< 6; i++){
        printf("%d ", array[i]);
    }
}