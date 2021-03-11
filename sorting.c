#include<stdio.h>
#include<stdlib.h>


int compareSize(const void *pa, const void *pb){
    const int *p1 = pa;
    const int *p2 = pb;
    return *p1 - *p2;
}
void swap(int *smallest, int *first_element){
    int middle;
    middle = *smallest;
    *smallest = *first_element;
    *first_element = middle;
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

int main(){
    
    return 0;
}
