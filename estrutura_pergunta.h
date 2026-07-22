#ifndef ESTRUTURA_PERGUNTA_H
#define ESTRUTURA_PERGUNTA_H

#include <stdio.h>
#include <ctype.h>


typedef struct pergunta {

    const char *nivel;

    const char *enunciado;

    const char *alternativas[5];

    char gabarito;

    int recompensa;
    int punicao;

} pergunta;

typedef struct especial {

    const char *caracteristica;

    int deslocamento;

} especial;

#endif