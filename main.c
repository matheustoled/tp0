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
            // else if (figura[i][j] == 'C') {
            //     quadro[linha_inicial+i][coluna_inicial+j] = 'C';
            // }
            // else if (figura[i][j] == 'A') {
            //     quadro[linha_inicial+i][coluna_inicial+j] = 'A';
            // }
            // else if (figura[i][j] == 'M') {
            //     quadro[linha_inicial+i][coluna_inicial+j] = 'M';
            // }
        }
    }
}

// Figuras
void figura_asterisco() {
    char fig[1][1] = { "*" };
    int linha_inicial, coluna_inicial;
    do {
        linha_inicial = rand() % (LINHAS - 2) + 1; // -2 evita que seja printado nas bordas do quadro (LINHAS - altura_figura - 1)
                                                   // +1 faz com que sempre inicie, pelo menos, a partir da primeira linha/coluna
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

int main() {
    srand(time(NULL));
    int tipo, qnt, opcao_final;
    int loop1 = 1;

    while(loop1){
        int loop2 = 1;
        printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n");
        printf("=================================\n");
        printf("Figuras basicas a serem usadas para criar a obra:\n");
        printf("1 - asterisco simples\n");
        printf("2 - simbolo de soma\n");
        printf("3 - letra X\n");
        printf("4 - figuras aleatorias\n");
        printf("Figuras personalizadas a serem usadas para criar a obra:\n");
        printf("5 - estrela diamante\n");
        printf("6 - estrela X\n");
        printf("7 - estrela cruz\n");
        printf("8 - estrela de Belem\n");
        printf("9 - figuras personalizadas aleatorias (Variadas - Quadro: Ceu Estrelado)\n");
        printf("Digite o tipo: ");
        scanf("%d", &tipo);
        printf("Digite a quantidade (<=0 para aleatorio): ");
        scanf("%d", &qnt);

        if(0 < tipo < 5){
            if (qnt <= 0) qnt = rand() % 100 + 1;
            if (qnt > 100) qnt = 100;
        }

        else if(5 <= tipo < 10){
            if (qnt <= 0) qnt = rand() % 52 + 1;
            if (qnt > 52) qnt = 52;
        }

        inicializar_quadro();

        for (int i = 0; i < qnt; i++) {
            int escolha = tipo;
            if (tipo == 4) escolha = rand() % (3) + 1;
            if (tipo == 9) escolha = rand() % (4) + 5;

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
                    estrela_diamante();
                    break;
                case 6:
                    estrela_x();
                    break;
                case 7:
                    estrela_cruz();
                    break;
                case 8:
                    estrela_belem();
                    break;
            }
        }
        imprimir_quadro();
        while(loop2){
            printf("O que deseja fazer agora?\n");
            printf("1 - Criar novo quadro com as mesmas configuracoes (tipo e quantidade)\n");
            printf("2 - Criar novo quadro com novas configuracoes\n");
            printf("3 - Sair\n");
            scanf("%d", &opcao_final);

            switch (opcao_final)
            {
            case 1:
                inicializar_quadro();
                for (int i = 0; i < qnt; i++) {
                    int escolha = tipo;
                    if (tipo == 4) escolha = rand() % (3) + 1;
                    if (tipo == 9) escolha = rand() % (4) + 5;

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
                            estrela_diamante();
                            break;
                        case 6:
                            estrela_x();
                            break;
                        case 7:
                            estrela_cruz();
                            break;
                        case 8:
                            estrela_belem();
                            break;
                    }
                }
                imprimir_quadro();
                loop1 = 0;
                loop2 = 1;
                break;
            case 2:
                loop1 = 1;
                loop2 = 0;
            break;
            case 3:
                loop1 = 0;
                loop2 = 0;
                break;
            default:
                loop1 = 0;
                loop2 = 0;
                break;
            }
        }
    }
    return 0;
}
