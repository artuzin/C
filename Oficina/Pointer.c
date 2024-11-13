#include <stdio.h>

int main(){
    int num = 8;
    int* pointer;
    pointer = &num;

    printf("%p\n", pointer);
    printf("%d\n", *pointer);
}