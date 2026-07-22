#ifndef SM_CONTROL_H
#define SM_CONTROL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "estrutura_pergunta.h"
#include "listad.h"
#include "jogador.h"
#include "pilha.h"

void finalizar (tp_listad *caminho) {


    casa v1, v2, v3, v4, v5, v6;
    v1.conteudo = v2.conteudo = v3.conteudo = v4.conteudo = v5.conteudo = v6.conteudo =  "v";

    v1.numeracao = 31; v2.numeracao = 32; v3.numeracao = 33; v4.numeracao = 34; v5.numeracao = 35; v6.numeracao = 36;

    insere_listad_no_fim (caminho, v1);
    insere_listad_no_fim (caminho, v2);
    insere_listad_no_fim (caminho, v3);
    insere_listad_no_fim (caminho, v4);
    insere_listad_no_fim (caminho, v5);
    insere_listad_no_fim (caminho, v6);

}

void ver (tp_listad *caminho) {

    tp_no *mov;
    mov = caminho->ini;

    for (int i = 0; i < 16; i ++) {

        printf("| %s | -> ", mov->info.conteudo);

        mov = mov->prox;

    } printf("| NULL |\n");

    for (int i = 0; i < 16; i ++) {

        if (i < 10) printf("  %d      ", i);
        else printf("  %d     ", i);
    }

}

void perguntar (pergunta perguntan, jogador *j) {

    printf("\n\nPergunta de nivel %s ", perguntan.nivel);
    printf("(Essa eh a casa %d)\n", j->mov->info.numeracao);

    printf("\n%s\n", perguntan.enunciado);

    for (int i = 0; i < 5; i++) {
        printf("\n%s\n", perguntan.alternativas[i]);
    }

    printf("\nGabarito: %c", perguntan.gabarito);

    char resposta;

    printf("\nQual eh a resposta? "); scanf(" %c", &resposta);

    if (tolower(resposta) == perguntan.gabarito) {

        for (int i = 0; i < perguntan.recompensa; i ++) (*j).mov = (*j).mov->prox;
        
        printf("\nAcertou. Voce avancou %d casas no tabuleiro ", perguntan.recompensa);
    }
    
    else {

        for (int i = 0; i < perguntan.punicao; i ++) (*j).mov = (*j).mov->ant;

        printf("\nErrou. Voce voltou %d casas no tabuleiro ", perguntan.punicao);
    }

    printf("(Agora %s esta na casa %d)\n", j->nome, j->mov->info.numeracao);

    return;
}

void aplicar (especial e, jogador *j) {

    printf("\nCasa especial de %s\n", e.caracteristica);

    if (e.caracteristica == "sorte") {

        for (int i = 0; i < e.deslocamento; i ++) (*j).mov = (*j).mov->prox;
    
        printf("\nVoce avancou %d casas no tabuleiro ", e.deslocamento);
    }
    

    else {

        for (int i = 0; i < e.deslocamento; i ++) (*j).mov = (*j).mov->ant;

        printf("\nVoce voltou %d casas no tabuleiro ", e.deslocamento);

    }

    printf("(Agora %s esta na casa %d)\n", j->nome, j->mov->info.numeracao);

}

void operar (jogador *j, casa c) {
    if (c.conteudo == "p") perguntar (c.p, j);
    if (c.conteudo == "e") aplicar (c.e, j);
    //if (c.conteudo == "v") printf("\nVoce chegou ao fim do tabuleiro");
}

void jogar (jogador *j, tp_listad *caminho) {


    if ((*j).mov->info.conteudo == "v") return;
    

    printf("\n-----\nVEZ DE %s\n-----\n", j->nome);

    if (j->mov->info.conteudo == "c") printf("\n%s acabou de comecar na casa 0\n", j->nome);

        operar (j, (*j).mov->info);

        printf("Pressione qualquer letra para jogar o dado (Nao vale Enter): "); scanf(" %c");
        int avanco = (rand ()%6) + 1;
        
        for (int i = 0; i < avanco; i ++) j->mov = j->mov->prox; 

        printf("O dado caiu em %d ", avanco);
        printf("(Agora %s esta na casa %d)\n", j->nome, j->mov->info.numeracao);

        if ((*j).mov->info.conteudo == "v") {

            printf("\nParabens! %s chegou ao final do tabuleiro.\n", j->nome);
            return;

        }

}

void revezar (jogador jogadores[], int quantidade, tp_listad *caminho) {


    int i = 0;
    while (1) { int stop = 0;

        if (i%quantidade == 0) {

            for (int i = 0; i < quantidade; i ++) if (jogadores[i].mov->info.conteudo == "v") stop = 1;

        }

        if (stop) break;

        jogar (&jogadores[i%quantidade], caminho); i ++;

    }

    printf("\nFim de jogo\n");

    for (int i = 0; i < quantidade; i ++) if (jogadores[i].mov->info.conteudo == "v") printf("\n%s eh vencedor\n", jogadores[i].nome);

}

#endif