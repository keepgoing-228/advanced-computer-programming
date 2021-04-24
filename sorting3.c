#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 10

struct piggies
{
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
void insertion_sorts(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
void merge_sorts(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
void merge(void *base, int head, int mid, int tail, size_t size, int (*compare)(const void *, const void *));
void merge_sort(void *base, int head, int tail, size_t size, int (*compare)(const void *, const void *));


int main()
{
    printf("initailization-----\n");
    int len = 100;
    int size = sizeof(struct piggies *);

    printf("reading data-------\n");
    struct piggies pig[len];
    read_data(pig, len);

    printf("making pointer-----\n");
    struct piggies *pigptr[len];
    for (int i = 0; i < len; i++)
    {
        pigptr[i] = &pig[i]; //pigptr[i] = pig + i;
    }

    printf("sorting------------\n");
    heap_sorts(pigptr, len, size, compare);

    printf("write result-------\n");
    write_result(pigptr, len); //寫出的是指標陣列

    printf("see ya-------------\n");

    return 0;
}

void read_data(struct piggies *pig, int len)
{
    FILE *fp;
    fp = fopen("data.txt", "r");
    for (int i = 0; i < len; i++)
    {
        fscanf(fp, "%d %c %f", &(pig->num), &(pig->name), &(pig->weight));
        fgetc(fp);
        // debug 吃進來就吃錯了
        // printf("%d %c %f\n",(pig->num), (pig->name) , (pig->weight));
        pig++;
    }
    fclose(fp);
}

void write_result(struct piggies **pigptr, int len)
{
    FILE *fresult;
    fresult = fopen("result.txt", "w");
    for (int i = 0; i < len; i++)
    {
        fprintf(fresult, "%2d %c %.2f\n", ((*pigptr)->num), ((*pigptr)->name), ((*pigptr)->weight));
        pigptr++;
    }
}

void swap(int *smallest, int *first_element, size_t size)
{
    void *middle = malloc(size);
    memcpy(middle, smallest, size);
    memcpy(smallest, first_element, size);
    memcpy(first_element, middle, size);
    free(middle);
}
int compare(const void *pa, const void *pb)
{
    const struct piggies **p1 = pa;
    const struct piggies **p2 = pb;
    float test;
    if (((*p1)->num) != ((*p2)->num))
        return (*p1)->num - (*p2)->num;
    if (((*p1)->name) != ((*p2)->name))
        return (*p1)->name - (*p2)->name;
    if(((*p1)->weight) != ((*p2)->weight))
        test = (*p1)->weight - (*p2)->weight;
        if(test > 0)
            return 1;
        else
            return 0;
}
void selection_sorts(void *base, size_t num, size_t size, int (*compare)(const void *, const void *))
{
    int i, j;
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if ((*compare)((base + (i * size)), (base + (j * size))) > 0)
            { //compareSize控制
                swap((base + (i * size)), (base + (j * size)), size);
            }
        }
    }
}

void bubble_sorts(void *base, size_t num, size_t size, int (*compare)(const void *, const void *))
{
    int i, j;
    for (i = num - 1; i > 0; i--)
    {
        for (j = 0; j < 1; j++)
        {
            if (((*compare)(base + (i * size), base + (j * size))) < 0)
            {
                swap((base + (i * size)), (base + (j * size)), size);
            }
        }
    }
}

void insertion_sorts(void *base, size_t num, size_t size, int (*compare)(const void *, const void *))
{
    int i;
    for (i = 1; i < num; i++)
    {
        int j = i - 1;
        while ((((*compare)(base + (j * size), base + ((j + 1) * size))) > 0) && (j >= 0))
        {
            swap((base + (j * size)), (base + ((j + 1) * size)), size);
            j--;
        }
    }
}

void merge_sorts(void *base, size_t num, size_t size, int (*compare)(const void *, const void *))
{
    merge_sort(base, 0, num-1, size, compare);
}

void merge_sort(void *base, int head, int tail, size_t size, int (*compare)(const void *, const void *))
{
    //只剩下一個元素停止
    //其他持續切割
    if (head < tail)
    {
        int mid = (head + tail) / 2;
        merge_sort(base, head, mid, size, compare);
        merge_sort(base, mid + 1, tail, size, compare);
        merge(base, head, mid, tail, size, compare);
        printf("merged!!\n");
    }
}

void merge(void *base, int head, int mid, int tail, size_t size, int (*compare)(const void *, const void *))
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid + 1) + 1;
    void *A = malloc(lenA * size);
    void *B = malloc(lenB * size);
    printf("lenA: %d, lenB: %d\n", lenA, lenB);
    
    //Copy data to temp A and B
    memcpy(A, (base + head *size), lenA * size);
    memcpy(B, (base + (mid + 1) *size), lenB * size);
    
    // Merge two temp arrays back into arr[head..tail]
    int i, j, k;
    i = 0;
    j = 0;
    k = head;
    //while array A and B haven't finished scanning
    while (i < lenA && j < lenB)
    {
        if ((*compare)((A + (i * size)), (B + (j * size))) <= 0)
        {
            memcpy(base + (k * size), A + (i *size), size);
            i++;
            // printf("%d %d %d\n",i, j ,k);
        }
        else
        {
            memcpy(base + (k * size), B + (j *size), size);
            j++;
            // printf("%d %d %d\n",i, j ,k);
        }
        k++;
        // printf("%d %d %d\n",i, j ,k);
    }
    //Copy the remaing elements into arr[], if A[] haven't finished scanning
    if (i < lenA)
    {
        memcpy(base + (k * size), A + (i * size), (lenA - i)*size);
    }
    //Copy the remaing elements into arr[], if B[] haven't finished scanning
    if (j < lenB)
    {
        memcpy(base + (k * size), B + (j * size), (lenB - j)*size);
    }
    free(A);
    free(B);
}



void heap_sorts(void *base, size_t num, size_t size, int(*compare)(const void *, const void *)){
    int i;
    //build heap
    for(i = num/2 -1 ; i>= 0; i--){
        heapify(base,num,size,i,compare);
    }
    //one by one extract an element from heap
    for (i = num - 1; i > 0; i--){
        swap(base, (base + i*size) , size);
        heapify(base,i,size,0,compare);
    }
    
}

void heapify(void *base, size_t num, size_t size, int i , int(*compare)(const void *, const void *)){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < num && ((*compare)(base + (largest*size),base + (left*size))>0 )){
        largest = left;
    }
    if(right < num && ((*compare)(base + (largest*size),base + (right*size))>0 )){
        largest = right;
    }
    if(largest != i){
        swap(base + largest * size, base + i*size, size);

        heapify(base, num, size, largest, compare);
    }
}