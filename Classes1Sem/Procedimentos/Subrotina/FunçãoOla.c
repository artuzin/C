#include <stdio.h>

void Ola ( )
{
    printf("\n Olá mundo !!! \n");
}

int main(){
    printf("\n Programa Principal!!");
    Ola ( );
    printf("\n Posso chamar o procedimento de novo: ");
    Ola ( );

    return 0;
}