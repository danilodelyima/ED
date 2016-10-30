#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

/*----------------------------------------------------------*/
void inserir(int pos, int valor, t_lista * lista){
    if( pos <= 0 ){
        insereInicio(valor, lista);
    }else{
        t_elemento* ptr = lista->primeiro;
        int i = 0;

        for(i = 0; i < (pos-1) && ptr != NULL; i++){
            ptr = ptr->proximo;
        }

        if(ptr == NULL || ptr == lista->ultimo){
            insereFinal(valor, lista);
        }else{
            t_elemento* elemento = (t_elemento *) malloc(sizeof(t_elemento));
            elemento->dado       = valor;
            elemento->proximo    = ptr->proximo;
            ptr->proximo         = elemento;
        }
    }
}


/*----------------------------------------------------------*/
void apaga_lista(t_lista* lista){
    t_elemento* ptr = lista->primeiro;

    while( ptr != NULL ){
        lista->primeiro = lista->primeiro->proximo;

        free(ptr);

        ptr = lista->primeiro;
    }
    free(lista);
}


/*----------------------------------------------------------*/
t_lista* aloca_lista(){
    t_lista* lista  =  (t_lista *)  malloc(sizeof(t_lista));
    lista->primeiro = NULL;
    lista->ultimo   = NULL;

    return lista;
}/*end aloca_lista()*/


/*----------------------------------------------------------*/
void imprime_lista( t_lista* lista){
    t_elemento* ptr = lista->primeiro;

    if(ptr == NULL){
        printf("LISTA VAZIA\n");
        return;
    }

    for(ptr = lista->primeiro; ptr != NULL; ptr = ptr->proximo){
        printf("%d", ptr->dado);

        if(ptr->proximo != NULL)
            printf(" -> ");

    }

    printf("\n");


}/*end imprime_lista()*/


/*----------------------------------------------------------*/
void insereFinal(int valor, t_lista * lista){

    t_elemento* elemento = (t_elemento *)  malloc(sizeof(t_elemento));
    elemento->dado       = valor;
    elemento->proximo    = NULL;

    if( lista->primeiro == NULL ){
        lista->primeiro = elemento;
    }else{
        lista->ultimo->proximo = elemento;
    }

    lista->ultimo = elemento;
}/*end insereFinal()*/


/*----------------------------------------------------------*/
void insereInicio(int valor, t_lista* lista){

    t_elemento* elemento = (t_elemento *)  malloc(sizeof(t_elemento));

    elemento->dado    = valor;
    elemento->proximo = lista->primeiro;
    lista->primeiro   = elemento;

    if(lista->ultimo == NULL)
        lista->ultimo = lista->primeiro;


}/*end insereInicio()*/


int removeInicio(t_lista* lista){

    if(lista->primeiro == NULL){
        printf("Lista vazia\n");
        return 0;
    }
    t_elemento* elemento = lista->primeiro;
    lista->primeiro = lista->primeiro->proximo;
    free(elemento);

    return 1;
}


int removeFinal(t_lista *lista){

	if(lista->primeiro == NULL){
		printf("Lista vazia\n");
		return 0;
	}

	t_elemento *aux = lista->primeiro;

	while(aux->proximo != lista->ultimo){
		aux = aux->proximo;
	}
	aux->proximo = NULL;
	free(lista->ultimo);
	lista->ultimo = aux;
	
	return 1;
}

int remover(int pos, t_lista *lista){
    t_elemento *aux = lista->primeiro;

    if(lista->primeiro == NULL){
        printf("LISTA VAZIA\n");
        return 0;
    }
    else{
        int i;
        for(i=0; i < pos && aux != NULL; i++){
            aux = aux->proximo;
        }

         aux->proximo 
    }
}