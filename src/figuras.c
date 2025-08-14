#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headers/figuras.h"

void figura_asterisco() {
    char figura_asterisco[1][1] = { "*" };
    int linha_inicial, coluna_inicial;
    do {
        linha_inicial = rand() % (LINHAS - 2) + 1; // -2 evita que seja printado nas bordas do quadro (LINHAS - altura_figura - 1)
                                                   // +1 faz com que sempre inicie, pelo menos, a partir da primeira linha/coluna
        coluna_inicial = rand() % (COLUNAS - 2) + 1;
    } while (!verificar_posicao(linha_inicial, coluna_inicial, 1, 1, figura_asterisco)); // Se ja existir uma figura na posicao do quadro, randomiza novamente
                                                                            // Caso contrário, sai do loop e desenha a figura.
    desenhar_figura(linha_inicial, coluna_inicial, 1, 1, figura_asterisco);
}

void figura_soma() {
    char figura_soma[3][3] = {
        {' ', '*', ' '},
        {'*', '*', '*'},
        {' ', '*', ' '}
    };
    int linha_inicial, coluna_inicial;
    do {
        linha_inicial = rand() % (LINHAS - 4) + 1;
        coluna_inicial = rand() % (COLUNAS - 4) + 1;
    } while (!verificar_posicao(linha_inicial, coluna_inicial, 3, 3, figura_soma));
    desenhar_figura(linha_inicial, coluna_inicial, 3, 3, figura_soma);
}

void figura_x() {
    char figura_x[3][3] = {
        {'*', ' ', '*'},
        {' ', '*', ' '},
        {'*', ' ', '*'}
    };
    int linha_inicial, coluna_inicial;
    do {
        linha_inicial = rand() % (LINHAS - 4) + 1;
        coluna_inicial = rand() % (COLUNAS - 4) + 1;
    } while (!verificar_posicao(linha_inicial, coluna_inicial, 3, 3, figura_x));
    desenhar_figura(linha_inicial, coluna_inicial, 3, 3, figura_x);
}

// Figuras Personalizadas
void estrela_diamante() {
    char estrela_diamante[5][5] = {
        {' ', ' ', '*', ' ', ' ',},
        {' ', '*', '*', '*', ' ',},
        {'*', '*', '*', '*', '*',},
        {' ', '*', '*', '*', ' ',},
        {' ', ' ', '*', ' ', ' ',},
    };
    int linha_inicial, coluna_inicial;
    do {
        linha_inicial = rand() % (LINHAS - 6) + 1;
        coluna_inicial = rand() % (COLUNAS - 6) + 1;
    } while (!verificar_posicao(linha_inicial, coluna_inicial, 5, 5, estrela_diamante));
    desenhar_figura(linha_inicial, coluna_inicial, 5, 5, estrela_diamante);
}
void estrela_x() {
    char estrela_x[5][5] = {
        {'*', ' ', ' ', ' ', '*'},
        {' ', '*', ' ', '*', ' '},
        {' ', ' ', '*', ' ', ' '},
        {' ', '*', ' ', '*', ' '},
        {'*', ' ', ' ', ' ', '*'}
    };
    int linha_inicial, coluna_inicial;
    do {
        linha_inicial = rand() % (LINHAS - 6) + 1;
        coluna_inicial = rand() % (COLUNAS - 6) + 1;
    } while (!verificar_posicao(linha_inicial, coluna_inicial, 5, 5, estrela_x));
    desenhar_figura(linha_inicial, coluna_inicial, 5, 5, estrela_x);
}
void estrela_cruz() {
    char estrela_cruz[5][5] = {
        {' ', ' ', '*', ' ', ' '},
        {' ', ' ', '*', ' ', ' '},
        {'*', '*', '*', '*', '*'},
        {' ', ' ', '*', ' ', ' '},
        {' ', ' ', '*', ' ', ' '}
    };
    int linha_inicial, coluna_inicial;
    do {
        linha_inicial = rand() % (LINHAS - 6) + 1;
        coluna_inicial = rand() % (COLUNAS - 6) + 1;
    } while (!verificar_posicao(linha_inicial, coluna_inicial, 5, 5, estrela_cruz));
    desenhar_figura(linha_inicial, coluna_inicial, 5, 5, estrela_cruz);
}
void estrela_belem() {
    char estrela_belem[5][5] = {
        {'*', ' ', '*', ' ', '*'},
        {' ', '*', '*', '*', ' '},
        {'*', '*', '*', '*', '*'},
        {' ', '*', '*', '*', ' '},
        {'*', ' ', '*', ' ', '*'}
    };
    int linha_inicial, coluna_inicial;
    do {
        linha_inicial = rand() % (LINHAS - 6) + 1;
        coluna_inicial = rand() % (COLUNAS - 6) + 1;
    } while (!verificar_posicao(linha_inicial, coluna_inicial, 5, 5, estrela_belem));
    desenhar_figura(linha_inicial, coluna_inicial, 5, 5, estrela_belem);
}