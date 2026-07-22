#ifndef CASA_H
#define CASA_H

#include <stdio.h>

#include "estrutura_pergunta.h"

typedef struct casa {

    const char *conteudo;

    pergunta p;
    
    especial e;

    int numeracao;

} casa;

#endif