#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 20
#define COLUNAS 80

char quadro[LINHAS][COLUNAS];

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
            else if (figura[i][j] == 'C') {
                quadro[linha_inicial+i][coluna_inicial+j] = 'C';
            }
            else if (figura[i][j] == 'A') {
                quadro[linha_inicial+i][coluna_inicial+j] = 'A';
            }
            else if (figura[i][j] == 'M') {
                quadro[linha_inicial+i][coluna_inicial+j] = 'M';
            }
        }
    }
}

// Figuras
void figura_asterisco() {
    char fig[1][1] = { "*" };
    int linha_inicial, coluna_inicial;
    do {
        linha_inicial = rand() % (LINHAS - 2) + 1;
        coluna_inicial = rand() % (COLUNAS - 2) + 1;
    } while (!verificar_posicao(linha_inicial, coluna_inicial, 1, 1, fig)); // Se existir ja existir uma figura na posicao do quadro, randomiza novamente
                                                                            // Caso contrário, sai do loop e desenha a figura.
    desenhar_figura(linha_inicial, coluna_inicial, 1, 1, fig);
}

void figura_soma() {
    char fig[3][3] = {
        {' ', '*', ' '},
        {'*', '*', '*'},
        {' ', '*', ' '}
    };
    int linha_inicial, coluna_inicial;
    do {
        linha_inicial = rand() % (LINHAS - 4) + 1;
        coluna_inicial = rand() % (COLUNAS - 4) + 1;
    } while (!verificar_posicao(linha_inicial, coluna_inicial, 3, 3, fig));
    desenhar_figura(linha_inicial, coluna_inicial, 3, 3, fig);
}

void figura_x() {
    char fig[3][3] = {
        {'*', ' ', '*'},
        {' ', '*', ' '},
        {'*', ' ', '*'}
    };
    int linha_inicial, coluna_inicial;
    do {
        linha_inicial = rand() % (LINHAS - 4) + 1;
        coluna_inicial = rand() % (COLUNAS - 4) + 1;
    } while (!verificar_posicao(linha_inicial, coluna_inicial, 3, 3, fig));
    desenhar_figura(linha_inicial, coluna_inicial, 3, 3, fig);
}

void figura_personalizada() { // Escudo do galao da massa
    char escudo[9][9] = {
        {' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ',},
        {' ', '*', '*', '*', '*', '*', '*', '*', ' ',},
        {'*', ' ', 'C', ' ', 'A', ' ', 'M', ' ', '*',},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*',},
        {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*',},
        {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*',},
        {' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ',},
        {' ', ' ', '*', '*', '*', '*', '*', ' ', ' ',},
        {' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ',} 
    };
    int linha_inicial, coluna_inicial;
    do {
        linha_inicial = rand() % (LINHAS - 10) + 1;
        coluna_inicial = rand() % (COLUNAS - 10) + 1;
    } while (!verificar_posicao(linha_inicial, coluna_inicial, 9, 9, escudo));
    desenhar_figura(linha_inicial, coluna_inicial, 9, 9, escudo);
}

int main() {
    srand(time(NULL));
    int tipo, qtd;

    printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n");
    printf("=================================\n");
    printf("Escolha o tipo de figura basica a ser usada para criar a obra:\n");
    printf("1 - asterisco simples\n");
    printf("2 - simbolo de soma\n");
    printf("3 - letra X\n");
    printf("4 - figuras aleatorias\n");
    printf("5 - figura personalizada\n");
    printf("Digite o tipo: ");
    scanf("%d", &tipo);
    printf("Digite a quantidade (<=0 para aleatorio): ");
    scanf("%d", &qtd);

    if (qtd <= 0) qtd = rand() % 100 + 1;
    if (qtd > 100) qtd = 100;

    inicializar_quadro();

    for (int i = 0; i < qtd; i++) {
        int escolha = tipo;
        if (tipo == 4) escolha = rand() % 3 + 1;

        switch (escolha) {
            case 1: 
                figura_asterisco(); 
                break;
            case 2: 
                figura_soma(); 
                break;
            case 3: 
                figura_x(); 
                break;
            case 5: 
                figura_personalizada(); 
                break;
        }
    }

    imprimir_quadro();
    return 0;
}
