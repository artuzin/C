#include <stdio.h>

int main()
{
    char curso[20] = "Hello World";
    int count;

    for(count = 0; count < 20; count++)
        printf("%c", curso[count]);
    
    for(count = 0; curso[count] != '\0'; count++);

    printf("\nO '\\0' esta na posicao %d da string\n", count);

    return 0;
}