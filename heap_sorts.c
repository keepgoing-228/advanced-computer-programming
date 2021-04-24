#include<stdio.h>

int main(){
    int ar[]= {10,2,4,12,45,21};
    printf("before heap sorting:");
    print_list(ar, 6);
    heapsort(ar,6);
    printf("\nbefore heap sorting:");
    print_list(ar, 6);
}

void print_list(int ar[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", ar[i]);
    }
}

void heapsort(int ar[], int num){
    int i;
    //build heap
    for(i = num/2 -1 ; i>= 0; i--){
        heapify(ar,num,i);
    }
    //one by one extract an element from heap
    for (i = num - 1; i > 0; i--){
        swap(&ar[0], &ar[i]);
        heapify(ar,i,0);
    }
    
}

void heapify(int ar[], int num, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < num && ar[left] > ar[largest]){
        largest = left;
    }
    if(right < num && ar[right] > ar[largest]){
        largest = right;
    }
    if(largest != i){
        swap(&ar[largest], &ar[i]);

        heapify(ar, num, largest);
    }
}
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}