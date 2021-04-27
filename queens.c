#include<stdio.h>

int array[8];
int count = 0;//C no need to static




void print_array(int n, int *array){
    for(int i = 0; i < n ; i++){
        printf("%d ",*(array+i));
    }
}

void print_result(){
    int line;
    for (line = 0; line < 8; line++){
        int list_index;
        for (list_index = 0; list_index < array[line]; list_index++)
            printf("0");
        printf("1");
        for (list_index = array[line] + 1; list_index < 8; list_index++){
            printf("0");
        }
        printf("\n");
    }
    printf("================\n");
}

int check(int line,int list_index){
    int index;
    for (index=0; index<line; index++) {
        int data = array[index];
        if (list_index==data) 
            return 0;
        else if ((index+data)==(line+list_index))//index:原本第X層的row，data:原本第X層的column
            return 0;
        else if ((index-data)==(line-list_index))
            return 0;
    }
    return 1;
}

void queens(int line){
    int list_index;
    for(list_index = 0; list_index < 8; list_index++){
        if(check(line,list_index)){
            array[line] = list_index;
            if(line == 7){
                count++;
                print_result();
                array[line] = 0;//clear the value of data
                return;
            }
            queens(line+1);
            array[line]= 0;//backtracking
        }
    }
}


int main(){
    queens(0);
    // print_array(8,array);
    printf("Have %d solutions!",count);
    return 0;
}