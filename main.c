#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "estrutura_pergunta.h"
#include "listad.h"
#include "jogador.h"
#include "pilha.h"

#include "sm_unidade1.h"
#include "sm_unidade2.h"
#include "sm_unidade3.h"

#include "sm_control.h"

int main () { srand (time (NULL));

    pergunta perguntas1uni[6]; criartodas1 (perguntas1uni);
    pergunta perguntas2uni[6]; criartodas2 (perguntas2uni);
    pergunta perguntas3uni[6]; criartodas3 (perguntas3uni);

    tp_listad *caminho;
    caminho = inicializa_listad ();

    encadear1 (&caminho, perguntas1uni);
    encadear2 (&caminho, perguntas2uni);
    encadear3 (&caminho, perguntas3uni);

    tp_pilha pilha_perguntas1uni; inicializa_pilha (&pilha_perguntas1uni);
    tp_pilha pilha_perguntas2uni; inicializa_pilha (&pilha_perguntas2uni);
    tp_pilha pilha_perguntas3uni; inicializa_pilha (&pilha_perguntas3uni);

    tp_pilha lista_todas_perguntas[3]; 
    lista_todas_perguntas[0] = pilha_perguntas1uni; 
    lista_todas_perguntas[1] = pilha_perguntas2uni; 
    lista_todas_perguntas[2] = pilha_perguntas3uni;

    finalizar (caminho);

    tp_no *mov;
    mov = caminho->ini;



/*

    while (mov != NULL) {

        printf("%d\n", mov->info.numeracao); mov = mov->prox;

    }
    return 0;


*/



    int quantidade;
    while (1) {

        printf("\nQuantos jogadores? (Minimo 2, maximo 4) ");
        scanf("%d", &quantidade);

        if ((quantidade >= 2) && (quantidade <= 4)) break;

        printf("\nErro: a quantidade de jogadores deve ser no minimo 2 e no maximo 4.\n");

    }

    jogador jogadores[quantidade];

    for (int i = 0; i < quantidade; i ++) {

        jogadores[i].mov = caminho->ini;

        printf("\nQual o nome do jogador %d? ", i + 1); 
        scanf ("%s", jogadores[i].nome);

        printf("\nEntao o jogador %d eh %s", i + 1, jogadores[i].nome);

    }

    revezar (jogadores, quantidade, caminho);


   
    return 0;
}
