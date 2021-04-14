#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print_list(int *arr, int num){
    for (int  i = 0; i < num; i++)
    {
        printf("%d ", *(arr + i));
    }
        printf("\n");
}

void permutation(int *array, int l, int r){
    int i ;
    if(l == r){
        print_list(array,r+1);
    }
    else{
        for(i = l; i <= r; i++){
            swap((array + l),(array + i));
            permutation(array, l + 1, r);
            swap((array + l),(array + i));
        }
    }
}

void combination(int* arr, int* data, int n, int k, int level, int index){
    
    if (level == k){
        print_list(data, k);
    } else {
        for (int i = index + 1; i < n; i++){
            if (level == 0 && i == (n - k + 1))
                break;
            *(data + level) = *(arr + i);
            combination(arr, data, n, k, level + 1, i);
        }
    }

}

int main(){
    int list[5] = {1,2,3};
    printf("permutation\n");
    permutation(list, 0, 2);
    printf("combination\n");
    int data[2];
    combination(list,data,3,2,0,-1);
    return 0;
}