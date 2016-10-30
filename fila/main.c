#include "filha.h"
#include <stdio.h>

int main(){
    t_fila* fila = getFila(20);
    int i = 0;

    for(i = 0; i < 19; i++)
        inserirFila(fila, i+1);

    imprimirFila(fila);

    for(i = 0; i < 19; i++)
        printf("item removido: %d \n",  removerFila(fila));

    for(i = 20; i < 39; i++)
        inserirFila(fila, i+1);

    imprimirFila(fila);

    liberaFila(fila);
}
