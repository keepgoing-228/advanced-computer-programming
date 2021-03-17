#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAME_MAX 10


struct piggies{
    int num;
    char name;
    float weight;
};

void read_data(struct piggies *pig, int len);
void write_result(struct piggies **pig, int len);
void swap(int *smallest, int *first_element, size_t size);
int compare(const void *pa, const void *pb);
void selection_sorts(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
void bubble_sorts(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
void insertion_sorts(void *base, size_t num, size_t size, int(*compare)(const void *,const void *));



int main(){
    printf("initailization-----\n");
    int len = 30;
    int size = sizeof(struct piggies *);

    printf("reading data-------\n");
    struct piggies pig[len];
    read_data(pig, len);

    printf("making pointer-----\n");
    struct piggies *pigptr[len];
    for(int i = 0 ; i < len; i++){
        pigptr[i] = &pig[i];//pigptr[i] = pig + i;
    }

    printf("sorting------------\n");
    selection_sorts(pigptr, len, size, compare);

    printf("write result-------\n");
    write_result(pigptr ,len);//寫出的是指標陣列

    printf("see ya-------------\n");

    return 0;
}


void read_data(struct piggies *pig, int len){
    FILE *fp;
    fp = fopen("data.txt", "r");
    for(int i = 0 ; i < len ; i++){
        fscanf(fp,"%d %c %f",&(pig->num), &(pig->name) , &(pig->weight));
        fgetc(fp);
        // debug 吃進來就吃錯了
        // printf("%d %c %f\n",(pig->num), (pig->name) , (pig->weight));
        pig++;

    }
    fclose(fp);

}

void write_result(struct piggies **pigptr, int len){
    FILE *fresult;
    fresult = fopen("result.txt","w");
    for (int i = 0; i < len ; i++){
        fprintf(fresult, "%2d %c %.2f\n", ((*pigptr)->num),((*pigptr)->name),((*pigptr)->weight));
        pigptr++;
    }
}


void swap(int *smallest, int *first_element, size_t size){
    void *middle = malloc(size);
    memcpy(middle, smallest,size);
    memcpy(smallest, first_element, size);
    memcpy(first_element, middle, size);
    free(middle);
    
}
int compare(const void *pa, const void *pb){
    const struct piggies **p1 = pa;
    const struct piggies **p2 = pb;
    if(((*p1)->num) != ((*p2)->num))
        return (*p1)->num - (*p2)->num;
    if(((*p1)->name) != ((*p2)->name))
        return (*p1)->name - (*p2)->name;
    if (((*p1)->weight - (*p2)->weight)>0)
        return 1;
    return 0;
}
void selection_sorts(void *base, size_t num, size_t size, int (*compare)(const void *, const void *)){
    int i,j;
    for(i = 0; i < num; i++ ){
        for (j = i + 1 ; j < num ;j++){
            if((*compare)((base + (i * size)), (base + (j * size))) > 0 ){//compareSize控制
                swap((base + (i * size)), (base + (j * size)),size);
            }
        }
    }
} 


void bubble_sorts(void *base, size_t num, size_t size, int (*compare)(const void *, const void *)){
    int i, j;
    for(i = num - 1; i > 0; i--){
        for(j = 0; j < 1; j++){
            if(((*compare)(base + (i * size), base + (j * size))) < 0){
                swap((base + (i * size)),(base + (j * size)),size);
            }
        }
    }
}

void insertion_sorts(void *base, size_t num, size_t size, int(*compare)(const void *,const void *)){
    int i;
    for(i = 1; i < num; i++){
        int j = i - 1;
        while((((*compare)(base + (j * size), base + ((j+1) * size))) > 0) && (j>=0)){
            swap((base + (j * size)),(base + ((j+1) * size)),size);
            j--;
        }
    }
}

