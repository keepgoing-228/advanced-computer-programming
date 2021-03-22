#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

#define NAME_MAX 10





void swap(int *smallest, int *first_element);
int compareInt(const void *pa, const void *pb);
int compareStr(const void *pa, const void *pb);
void selection_sorts(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
void bubble_sorts(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
void insertion_sorts(void *base, size_t num, size_t size, int(*compare)(const void *,const void *));



int main(){
    int array[] = {23, 78, 45, 8, 32, 56};
    char name[][20] = {"Tiffany","Adam","Tim","Julia","Mike","Kelly"};
    int n1 = sizeof(array)/sizeof(int);
    int n2 = sizeof(name) / 20;
    insertion_sorts(array,n1,sizeof(int),compareInt);
    printf("----after sorting Int array\n");
    for(int i = 0; i < n1; i++){
        printf("%d ",array[i]);
    }
    printf("\n");

    qsort(name,n2,20,compareStr);
    printf("----after qsorting String array\n");
    for(int j = 0; j < n2; j++){
        printf("%s\n",name[j]);
    }
    
    selection_sorts(name,n2,20,compareStr); 
    printf("----after selection sorting String array\n");
    for(int j = 0; j < n2; j++){
        printf("%s\n",name[j]);
    }
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
int compareStr(const void *pa, const void *pb){
    return strcmp(pa,pb);
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

