#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

#include "estrutura_pergunta.h"

#define MAX 100	

typedef pergunta
	tp_ytem;
	
typedef struct {
	int topo;
	tp_ytem item[MAX];
} tp_pilha;

void inicializa_pilha (tp_pilha *p) {
	p->topo = -1;
}

int pilha_vazia (tp_pilha *p) {
	if (p->topo == -1) {
		return 1;
	}
	
	else {
		return 0;
	}
}

int pilha_cheia (tp_pilha *p) {
	if ( p->topo == (MAX - 1) ) {
		return 1;
	}
	
	else {
		return 0;
	}
}

int push (tp_pilha *p, tp_ytem e) {
	if ( pilha_cheia(p) ) {
		return 0;
	}
	
	else {
		p->topo++;
		p->item[p->topo] = e;
		return 1;
	}
}

int pop (tp_pilha *p, tp_ytem *e) {
	if ( pilha_vazia (p) ) {
		return 0;
	}
	
	else {
		*e = p->item[p->topo];
		p->topo--;
		return 1;
	}
}

int top (tp_pilha *p, tp_ytem *e) {
	if ( pilha_vazia(p) ) {
		return 0;
	}
	
	else {
		*e = p->item[p->topo];
		return 1;
	}
}

void imprime_pilha (tp_pilha p) {
	tp_ytem e;
	printf("\n");
	while ( !pilha_vazia(&p) ) {
		pop (& p, & e);
		printf("%d ", e);
	}
}

void embaralhar(pergunta p[6]) {
    
    for (int i = 5; i > 0; i--) {
        int j = rand() % (i + 1);


        pergunta temp = p[i];
        p[i] = p[j];
        p[j] = temp;
    }
}

void empilhar (pergunta perguntasnuni[], tp_pilha *pilha_perguntasnuni) {

    embaralhar (perguntasnuni);

    for (int i = 0; i < 6; i ++) push (pilha_perguntasnuni, perguntasnuni[i]);

}

#endif