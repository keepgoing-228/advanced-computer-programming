#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define FILE_NAME "data.txt"

void write_generate_data(FILE *fp, int number);

int main(){
    srand(time(NULL));

    FILE *fp;
    fp = fopen(FILE_NAME,"w");
    write_generate_data(fp,100);
    fclose(fp);

    return 0;
}

void write_generate_data(FILE *fp,int number){
    for (int i = 0; i< number;i++){
        fprintf(fp,"%2d %c %.2f\n",(rand()%10+1),(rand()%4+65),(double)rand()/(RAND_MAX + 1.0));
    }
}