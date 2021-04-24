#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int list[5] = {9,4,6,11,1};
    merge_sort(list,0,4); //warning
    printf("after sorting: ");
    for(int i = 0; i < 5; i++){
        printf(" %d",list[i]);
    }

    return 0;
}

// int main()
// {
//     int count, i;
//     scanf("%d", &count);
//     int list[count];
//     printf("Numbers to be sorted: ");
//     for (i = 0; i < count; i++)
//     {
//         scanf("%d", &list[i]);
//         printf("%d ", list[i]);
//     }
//     printf("\n");
//     merge_sort(list, 0, count - 1);
//     printf("Numbers Sorted: ");
//     for (i = 0; i < count; i++)
//     {
//         printf("%d ", list[i]);
//     }
//     return 0;
// }

void merge(int arr[], int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid + 1) + 1;
    int A[lenA];
    int B[lenB];
    //Copy data to temp arrays A[] and B[]
    int i, j, k;
    for (i = 0; i < lenA; i++)
    {
        A[i] = arr[head + i];
    }
    for (j = 0; j < lenB; j++)
    {
        B[j] = arr[mid + 1 + j];
    }
    // Merge two temp arrays back into arr[head..tail]
    i = 0;
    j = 0;
    k = head;
    //while array A and B haven't finished scanning
    while (i < lenA && j < lenB)
    {
        if (A[i] < B[j])
        {
            arr[k] = A[i];
            i++;
            // printf("%d %d %d %d %d\n",i ,lenA , j, lenB, k);
        }
        else
        {
            arr[k] = B[j];
            j++;
            // printf("%d %d %d %d %d\n",i ,lenA , j, lenB, k);
        }
        k++;
    }
    //Copy the remaing elements into arr[], if A[] haven't finished scanning
    while (i < lenA)
    {
        arr[k] = A[i];
        i++;
        k++;
    }
    //Copy the remaing elements into arr[], if B[] haven't finished scanning
    while (j < lenB)
    {
        arr[k] = B[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[], int head, int tail)
{
    if (head < tail)
    {
        int mid = (head + tail) / 2;
        merge_sort(arr, head, mid);
        merge_sort(arr, mid + 1, tail);
        merge(arr, head, mid, tail);
    }
}