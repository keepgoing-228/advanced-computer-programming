#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

#define NAME_MAX 10


struct piggies{
    int num;
    char name[NAME_MAX];
    float weight;
}part1;


void swap(int *smallest, int *first_element);
int compareInt(const void *pa, const void *pb);
void selection_sorts(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
void bubble_sorts(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
void insertion_sorts(void *base, size_t num, size_t size, int(*compare)(const void *,const void *));



int main(){
    int array[] = {23, 78, 45, 8, 32, 56};
    int n = sizeof(array)/sizeof(int);
    insertion_sorts(array,n,sizeof(int),compareInt);
    printf("this is after sorting array\n");
    for(int i = 0; i < n; i++){
        printf("%d ",array[i]);
    }
    struct piggies part1 = {"acho" , 3};
    printf("\n%d",part1.weight);
    
    return 0;
}


void swap(int *smallest, int *first_element){
    int middle;
    middle = *smallest;
    *smallest = *first_element;
    *first_element = middle;
}
int compareInt(const void *pa, const void *pb){
    const int *p1 = pa;
    const int *p2 = pb;
    return *p1 - *p2;
}
void selection_sorts(void *base, size_t num, size_t size, int (*compare)(const void *, const void *)){
    int i,j;
    for(i = 0; i < num; i++ ){
        for (j = i + 1 ; j < num ;j++){
            if(((*compare)(base + (i * size), base + (j * size))) > 0 ){//compareSize控制
                swap((base + (i * size)), (base + (j * size)));
            }
        }
    }
} 

void bubble_sorts(void *base, size_t num, size_t size, int (*compare)(const void *, const void *)){
    int i, j;
    for(i = num - 1; i > 0; i--){
        for(j = 0; j < 1; j++){
            if(((*compare)(base + (i * size), base + (j * size))) < 0){
                swap((base + (i * size)),(base + (j * size)));
            }
        }
    }
}

void insertion_sorts(void *base, size_t num, size_t size, int(*compare)(const void *,const void *)){
    int i;
    for(i = 1; i < num; i++){
        int j = i - 1;
        while((((*compare)(base + (j * size), base + ((j+1) * size))) > 0) && (j>=0)){
            swap((base + (j * size)),(base + ((j+1) * size)));
            j--;
        }
    }
}

