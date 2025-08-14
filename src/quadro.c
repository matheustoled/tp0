#include <stdio.h>
#include <stdlib.h>

#include "headers/quadro.h"

void inicializar_quadro() {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (i == 0 || i == LINHAS - 1) // Se for primeira ou última linhas, digita '-'
                quadro[i][j] = '-';
            else if (j == 0 || j == COLUNAS - 1)
                quadro[i][j] = '|'; // Se for primeira ou última colunas, digita '|'
            else
                quadro[i][j] = ' ';
        }
    }
}

void imprimir_quadro() {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%c", quadro[i][j]);
        }
        printf("\n");
    }
}

int verificar_posicao(int linha_inicial, int coluna_inicial, int altura_figura, int largura_figura, char figura[altura_figura][largura_figura]) {
    for (int i = 0; i < altura_figura; i++) {
        for (int j = 0; j < largura_figura; j++) {
            if (figura[i][j] == '*') {
                if (quadro[linha_inicial+i][coluna_inicial+j] != ' ') // Verificar se no quadro ja existe uma figura nos mesmos espaços
                    return 0;
            }
        }
    }
    return 1;
}

void desenhar_figura(int linha_inicial, int coluna_inicial, int altura_figura, int largura_figura, char figura[altura_figura][largura_figura]) {
    for (int i = 0; i < altura_figura; i++) {
        for (int j = 0; j < largura_figura; j++) {
            if (figura[i][j] == '*') {
                quadro[linha_inicial+i][coluna_inicial+j] = '*';
            }
        }
    }
}