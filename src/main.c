#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headers/quadro.h"
#include "headers/figuras.h"

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
            if (qnt <= 0) qnt = rand() % 20 + 1;
            if (qnt > 20) qnt = 20;
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
