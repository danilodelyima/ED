t_pilha getPilha(int tamanho){
	t_pilha *pilha = (t_pilha*) malloc(sizeof(t_pilha));
	pilha->item    = (int*) malloc(tamanho*sizeof(int));
	pilha->tamanho = tamamho;
	pilha->topo    = VAZIA;

	return pilha;
}

int pilhaCheia(t_pilha *pilha){
	return (pilha->topo == pilha->tamanho);
}

int pilhaVazia(t_pilha *pilha){
	return (pilha->topo == VAZIA);
}

int push(t_pilha *pilha, int valor){
	if(pilhaCheia(pilha)){
		printf("PILHA CHEIA\n");
		return 0;
	}
	pilha->item[++pilha->topo] = valor;

	return 1;
}

int pop(t_pilha *pilha){
	if(pilhaVazia(pilha)){
		printf("PILHA VAZIA\n");
		return 0;
	}
	return (pilha->item[pilha->topo--]);
}

void liberaPilha(t_pilha *pilha){
	free(pilha->item);
	free(pilha);
}

int topo(t_pilha pilha){
	if(pilhaVazia(pilha)){
		printf("PILHA VAZIA\n");
		return 0;
	}
	return (pilha->item[pilha->topo])
}