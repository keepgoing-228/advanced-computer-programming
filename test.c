#include<stdio.h>
#include<string.h>


int main(){
    char a = 'A';
    char b = 'B';
    if (strcmp(&a,&b) < 0)
        printf("%d",strcmp(&a,&b));
    return 0;
}