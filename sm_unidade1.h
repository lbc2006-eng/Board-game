#ifndef SM_UNIDADE1_H
#define SM_UNIDADE1_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "estrutura_pergunta.h"
#include "listad.h"
#include "jogador.h"
#include "pilha.h"

void criarprimeira1(pergunta p[6]) {

    p[0].nivel = "Facil";

    p[0].enunciado = "Estruturas de dados lineares como Pilhas e Filas possuem regras estritas sobre como os elementos entram e saem da memoria.\n" 
    "Quais sao as respectivas politicas de acesso para uma Pilha e para uma Fila padrao?";

    p[0].alternativas[0] = "a) Pilha segue a politica FIFO (First-In, First-Out); Fila segue a politica LIFO (Last-In, First-In).";
    p[0].alternativas[1] = "b) Pilha segue a politica LIFO (Last-In, First-Out); Fila segue a politica FIFO (First-In, First-Out).";
    p[0].alternativas[2] = "c) Ambas seguem a politica FIFO (First-In, First-Out), diferenciando-se apenas pela alocacao estatica.";
    p[0].alternativas[3] = "d) Ambas seguem a politica LIFO (Last-In, First-Out), diferenciando-se apenas pelo uso de ponteiros.";
    p[0].alternativas[4] = "e) Pilha permite remocao em qualquer extremidade; Fila permite insercao apenas no meio da estrutura.";

    p[0].gabarito = 'b';

    p[0].recompensa = 1;
    p[0].punicao = 1;
}

void criarsegunda1 (pergunta p[6]) {

    p[1].nivel = "Facil";

    p[1].enunciado = "Ao projetar uma funcao recursiva em C (uma funcao que chama a si mesma),\n" 
    "qual eh o componente obrigatorio que impede que o programa entre em um loop infinito e sofra um estouro de pilha (stack overflow)?";

    p[1].alternativas[0] = "a) Um comando de topo de arquivo do tipo #define MAX 1000.";
    p[1].alternativas[1] = "b) Uma variavel global declarada com o modificador static int.";
    p[1].alternativas[2] = "c) Um caso base (ou condicao de parada), que consiste em um teste condicional que interrompe as chamadas recursivas.";
    p[1].alternativas[3] = "d) O uso obrigatorio do comando break ao final de cada iteracao da funcao.";
    p[1].alternativas[4] = "e) A passagem de parametros obrigatoriamente por referencia utilizando o operador &.";

    p[1].gabarito = 'c';

    p[1].recompensa = 1;
    p[1].punicao = 1;
}

void criarterceria1 (pergunta p[6]) {

    p[2].nivel = "Medio";

    p[2].enunciado = "Considere uma funcao comum em C definida como void atualiza(int x) { x = x + 10; }.\n" 
    "Se no programa principal declararmos int numero = 5; e chamarmos atualiza(numero);,\n" 
    "qual sera o valor impresso se executarmos printf(\"%d\", numero); logo após a chamada da funcao?";

    p[2].alternativas[0] = "a) O valor sera 15, pois a funcao altera diretamente o escopo da variavel declarada na main.";
    p[2].alternativas[1] = "b) O valor sera 5, pois em C a passagem de parametros padrão eh por valor, significando que a funcao recebe apenas uma copia da variável original.";
    p[2].alternativas[2] = "c) O programa apresentara erro de compilacao, pois funcoes do tipo void nao podem alterar o valor de variaveis locais.";
    p[2].alternativas[3] = "d) O valor sera 10, correspondente a constante somada dentro do bloco de execucao.";
    p[2].alternativas[4] = "e) O valor sera indeterminado (lixo de memoria), pois a memoria da variável foi liberada ao termino da funcao";

    p[2].gabarito = 'b';

    p[2].recompensa = 2;
    p[2].punicao = 2;
}

void criarquarta1 (pergunta p[6]) {

    p[3].nivel = "Medio";

    p[3].enunciado = "Em um sistema operacional ou arquitetura de software, a escolha entre Pilha ou Fila depende estritamente do problema a ser resolvido.\n" 
    "Qual das seguintes alternativas apresenta um cenario tipico de uso para uma Pilha e um cenario tipico para uma Fila, respectivamente?";
    
    p[3].alternativas[0] = "a) Pilha: Gerenciamento de uma fila de impressao de documentos; Fila: Historico de navegacao para o botao 'Voltar' do navegador.";
    p[3].alternativas[1] = "b) Pilha: Armazenamento de dados em disco rigido; Fila: Alocação dinamica de memoria via malloc.";
    p[3].alternativas[2] = "c) Pilha: Controle de chamadas de funcoes e execucao de funcoes recursivas; Fila: Gerenciamento de processos em espera por tempo de CPU (Escalonamento).";
    p[3].alternativas[3] = "d) Pilha: Busca em largura em uma arvore binaria; Fila: Algoritmos de ordenacao baseados em divisao e conquista como o Quick Sort.";
    p[3].alternativas[4] = "e) Ambas sao usadas de forma intercambiavel no gerenciamento de memoria cache de navegadores de internet.";

    p[3].gabarito = 'c';

    p[3].recompensa = 2;
    p[3].punicao = 2;
}

void criarquinta1 (pergunta p[6]) {

    p[4].nivel = "Dificil";

    p[4].enunciado = "Considere o seguinte trecho de código escrito na linguagem C:\n\n"

    "int a = 10;\n"
    "int b = 20;\n"
    "int *p = &a;\n"
    "*p = 30;\n"
    "p = &b;\n"
    "*p = 40;\n\n"

    "Apos a execucao sequencial dessas linhas, quais serao os valores finais armazenados nas variáveis a e b, respectivamente?";

    p[4].alternativas[0] = "a) a = 10 e b = 20";
    p[4].alternativas[1] = "b) a = 30 e b = 20";
    p[4].alternativas[2] = "c) a = 30 e b = 40";
    p[4].alternativas[3] = "d) a = 40 e b = 40";
    p[4].alternativas[4] = "e) a = 10 e b = 40";

    p[4].gabarito = 'c';

    p[4].recompensa = 3;
    p[4].punicao = 3;
    
}

void criarsexta1 (pergunta p[6]) {

    p[5].nivel = "Dificil";

    p[5].enunciado = "Para que uma funcao em C consiga modificar de fato o valor de uma variavel que pertence a função main,\n" 
    "precisamos implementar uma passagem de parametros por referencia.\n" 
    "Qual das alternativas abaixo apresenta a assinatura correta da funcao e a sua respectiva chamada na main para zerar o valor de uma variavel inteira utilizando ponteiros?";

    p[5].alternativas[0] = "a) Assinatura: void zerar(int x); | Chamada na main: zerar(var);";
    p[5].alternativas[1] = "b) Assinatura: void zerar(int *x); | Chamada na main: zerar(&var);";
    p[5].alternativas[2] = "c) Assinatura: void zerar(int &x); | Chamada na main: zerar(*var);";
    p[5].alternativas[3] = "d) Assinatura: void zerar(int *x); | Chamada na main: zerar(*var);";
    p[5].alternativas[4] = "e) Assinatura: void zerar(int &x); | Chamada na main: zerar(var);";

    p[5].gabarito = 'b';

    p[5].recompensa = 3;
    p[5].punicao = 3;

}

void criartodas1 (pergunta p[6]) {

    criarprimeira1(p);
    criarsegunda1(p);
    criarterceria1(p);
    criarquarta1(p);
    criarquinta1(p);
    criarsexta1(p);
}

void encadear1 (tp_listad **caminho, pergunta perguntas1uni[]) {

    casa lista_caminho[10];

    especial sorte1uni;
    sorte1uni.caracteristica = "sorte";
    sorte1uni.deslocamento = 1;

    especial azar1uni;
    azar1uni.caracteristica = "azar";
    azar1uni.deslocamento = 1;

    lista_caminho[1].conteudo = "e";
    lista_caminho[1].e = sorte1uni;

    lista_caminho[3].conteudo = "e";
    lista_caminho[3].e = sorte1uni;

    lista_caminho[5].conteudo = "e";
    lista_caminho[5].e = azar1uni;

    lista_caminho[7].conteudo = "e";
    lista_caminho[7].e = azar1uni;

    casa comeco;
    comeco.conteudo = "c";

    insere_listad_no_fim (*caminho, comeco);

    int j = 0;
    for (int i = 0; i < 10; i ++) {

        if (lista_caminho[i].conteudo != "e") {
            
            lista_caminho[i].conteudo = "p"; 
            lista_caminho[i].p = perguntas1uni[j];
            j ++;

        } lista_caminho[i].numeracao = i + 1;

    }

    for (int i = 0; i < 10; i ++) insere_listad_no_fim (*caminho, lista_caminho[i]);

    tp_no *mov;
    mov = (*caminho)->ini;

    for (int i = 0; i < 10; i ++) {

        mov->info.numeracao = i; // i + 1
        mov = mov->prox;

    }


}

#endif
